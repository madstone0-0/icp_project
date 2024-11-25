#pragma once
#include "../db/Database.h"
#include "../utils.h"
#include "AuditService.h"
#include "UserService.h"

namespace icpproject {
    using namespace std;
    using namespace System;
    using namespace System::Data;
    using namespace System::Collections::Generic;
    using PreReqList = List<System::Int64>;

    value struct NewCourse {
        STR cname;
        double credits;
        Semester sem;
        int capacity;
        PreReqList ^ prereqs;

        NewCourse(STR c, double cr, Semester s, int cap, PreReqList ^ p) {
            cname = c;
            credits = cr;
            sem = s;
            capacity = cap;
            prereqs = p;
        }

        NewCourse(STR c, double cr, Semester s, int cap) {
            cname = c;
            credits = cr;
            sem = s;
            capacity = cap;
            prereqs = gcnew PreReqList(0);
        }

        NewCourse(STR c, double cr, Semester s) {
            cname = c;
            credits = cr;
            sem = s;
            capacity = 40;
            prereqs = gcnew PreReqList(0);
        }
    };

    value struct Course {
        int cid;
        STR cname;
        double credits;
        Semester sem;
        int capacity;
        PreReqList ^ prereqs;

        Course(int c, STR cn, double cr, Semester s, int cap, PreReqList ^ p) {
            cid = c;
            cname = cn;
            credits = cr;
            sem = s;
            capacity = cap;
            prereqs = p;
        }

        Course(int c, STR cn, double cr, Semester s, int cap) {
            cid = c;
            cname = cn;
            credits = cr;
            sem = s;
            capacity = cap;
            prereqs = gcnew PreReqList(0);
        }
    };

    ref class CourseService : public UserService {
       private:
        bool doesCourseExist(STR name) {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute(String::Format("select cid from course where cname = '{0}'", name));
                return reader->HasRows;
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        bool doesCourseExistId(long long id) {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute(String::Format("select cid from course where cid = {0}", id));
                return reader->HasRows;
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

       public:
        CourseService(IUser ^ user) : UserService{user} {}

        ServiceReturn<Course ^> GetById(long long cid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesCourseExistId(cid)) {
                    reader->Close();
                    throw gcnew Exception("Course does not exist");
                }

                reader = db::Ins()->execute(String::Format("select * from course where cid = {0}", cid));
                reader->Read();
                auto cname = reader->GetBodyDefinition("cname");
                auto credits = Convert::ToDouble(reader->GetBodyDefinition("credits"));
                auto sem = parseStrSemester(reader->GetBodyDefinition("sem"));
                auto capacity = Convert::ToInt16(reader->GetBodyDefinition("capacity"));

                auto course = gcnew Course(cid, cname, credits, sem, capacity);
                return {true, course};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<DataTable ^> GetAll() {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute("select * from course");
                DataTable ^ dt = gcnew DataTable();
                dt->Load(reader);
                reader->Close();

                Audit::Ins()->Log("Viewed all courses", user->UID);
                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<int> GetRemainingCapacity(long long cid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesCourseExistId(cid)) {
                    throw gcnew Exception("Course does not exist");
                }

                reader = db::Ins()->execute(String::Format("select capacity from course where cid = {0}", cid));
                reader->Read();
                auto cap = Convert::ToInt32(reader->GetBodyDefinition("capacity"));
                reader->Close();
                reader =
                    db::Ins()->execute("select count(*) as count from enrollment where cid = " + cid + " group by cid");
                auto enrolled = reader->Read() ? Convert::ToInt32(reader->GetBodyDefinition("count")) : 0;

                Audit::Ins()->Log("Viewed remaining capacity", user->UID, "Course ID: " + cid);
                return {true, cap - enrolled};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> Add(NewCourse newCourse) {
            ParamsH params = gcnew Params(1);
            MySqlDataReader ^ reader = nullptr;
            try {
                if (doesCourseExist(newCourse.cname)) {
                    throw gcnew Exception("Course already exists");
                }

                params->Add("@n", newCourse.cname);
                params->Add("@cred", newCourse.credits);
                params->Add("@s", parseSemester(newCourse.sem));
                params->Add("@cap", newCourse.capacity);

                db::Ins()->beginTransaction();
                reader = db::Ins()->execute(
                    "insert into course (cname, credits, sem, capacity) values (@n, @cred, @s, @cap)", params);
                auto cid = db::Ins()->getCmd()->LastInsertedId;
                reader->Close();

                for each (auto p in newCourse.prereqs) {
                    if (p == cid) {
                        throw gcnew Exception("Course cannot be a prerequisite of itself");
                        db::Ins()->rollback();
                    }

                    params->Clear();
                    params->Add("@cid", cid);
                    params->Add("@pid", p);
                    db::Ins()->executeNoRet("insert into prerequisites (cid, preqid) values (@cid, @pid)", params);
                }

                db::Ins()->commit();
                Audit::Ins()->Log("Added new course", user->UID, "Course: " + newCourse.cname);
                return {true, "Course added successfully"};

            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> Update(Course course) {
            ParamsH params = gcnew Params(1);
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesCourseExistId(course.cid)) {
                    throw gcnew Exception("Course does not exist");
                }

                params->Add("@n", course.cname);
                params->Add("@cred", course.credits);
                params->Add("@s", parseSemester(course.sem));
                params->Add("@cap", course.capacity);
                params->Add("@cid", course.cid);

                db::Ins()->beginTransaction();
                db::Ins()->executeNoRet(
                    "update course set cname = @n, credits = @cred, sem = @s, capacity = @cap where cid = @cid",
                    params);

                db::Ins()->executeNoRet("delete from prerequisites where cid = " + course.cid);
                for each (auto p in course.prereqs) {
                    if (p == course.cid) {
                        throw gcnew Exception("Course cannot be a prerequisite of itself");
                        db::Ins()->rollback();
                    }
                    params->Clear();
                    params->Add("@cid", course.cid);
                    params->Add("@pid", p);
                    db::Ins()->executeNoRet("insert into prerequisites (cid, preqid) values (@cid, @pid)", params);
                }

                db::Ins()->commit();
                Audit::Ins()->Log("Updated course", user->UID, "Course: " + course.cname);
                return {true, "Course updated successfully"};

            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> Delete(long long cid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesCourseExistId(cid)) {
                    throw gcnew Exception("Course does not exist");
                }

                db::Ins()->executeNoRet("delete from course where cid = " + cid);

                Audit::Ins()->Log("Deleted course", user->UID, "Course ID: " + cid);
                return {true, "Course deleted successfully"};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<cli::array<Course> ^> GetPrereqCourses(long long cid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesCourseExistId(cid)) {
                    throw gcnew Exception("Course does not exist");
                }

                cli::array<Course> ^ courses = gcnew cli::array<Course>(0);
                reader = db::Ins()->execute(
                    "select * from course where cid in (select preqid from prerequisites where cid = " + cid + ")");
                reader->Read();
                auto cid = Convert::ToInt32(reader->GetBodyDefinition("cid"));
                auto cname = reader->GetBodyDefinition("cname");
                auto credits = Convert::ToDouble(reader->GetBodyDefinition("credits"));
                auto sem = parseStrSemester(reader->GetBodyDefinition("sem"));
                auto capacity = Convert::ToInt32(reader->GetBodyDefinition("capacity"));

                while (reader->Read()) {
                    auto c = Course(cid, cname, credits, sem, capacity);
                    Array::Resize(courses, courses->Length + 1);
                    courses[courses->Length - 1] = c;
                }

                Audit::Ins()->Log("Viewed prerequisite courses", user->UID, "Course ID: " + cid);
                return {true, courses};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }
    };
}  // namespace icpproject