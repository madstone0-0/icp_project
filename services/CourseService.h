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

        ServiceReturn<List<Course> ^> GetByFaculty(long long uid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    course.cid AS CID,
    course.cname AS Course_Name,
    course.credits AS Credits,
    course.sem AS Semester,
    course.capacity AS Capacity
FROM
    course
INNER JOIN course_faculty ON
    course.cid = course_faculty.cid
INNER JOIN faculty ON
    course_faculty.uid = faculty.uid
WHERE
    faculty.uid = {0};
)";
                reader = db::Ins()->execute(String::Format(query, uid));
                List<Course> ^ courses = gcnew List<Course>(0);
                while (reader->Read()) {
                    auto cid = Convert::ToInt32(reader->GetBodyDefinition("CID"));
                    auto cname = reader->GetBodyDefinition("Course_Name");
                    auto credits = Convert::ToDouble(reader->GetBodyDefinition("Credits"));
                    auto sem = parseStrSemester(reader->GetBodyDefinition("Semester"));
                    auto capacity = Convert::ToInt32(reader->GetBodyDefinition("Capacity"));
                    courses->Add(Course(cid, cname, credits, sem, capacity));
                }

                Audit::Ins()->Log("Viewed courses by faculty", user->UID, "Faculty ID: " + uid);
                return {true, courses};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> AssignFaculty(long long uid, long long cid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesCourseExistId(cid)) {
                    throw gcnew Exception("Course does not exist");
                }

                db::Ins()->executeNoRet(
                    String::Format("insert into course_faculty (cid, uid) values ({0}, {1})", cid, uid));

                Audit::Ins()->Log("Assigned faculty to course", user->UID, "Faculty ID: " + uid + " Course ID: " + cid);
                return {true, "Faculty assigned to course"};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<Faculty ^> GetTeachingFaculty(long long cid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesCourseExistId(cid)) {
                    throw gcnew Exception("Course does not exist");
                }
                STR q = R"(
SELECT
    f.uid,
    c.cid,
    fname AS "First Name",
    lname AS "Last Name",
email AS "Email",
    dept AS "Department",
    appdate AS "Appointment Date"
FROM
    faculty f
INNER JOIN course_faculty cf ON
    cf.uid = f.uid
INNER JOIN course c ON
    c.cid = cf.cid
INNER JOIN `user` u ON
    u.uid = f.uid 
    WHERE c.cid = {0};
)";
                reader = db::Ins()->execute(String::Format(q, cid));
                reader->Read();
                if (!reader->HasRows) return {true, gcnew Faculty(-1, "N/A", "N/A", "N/A", "N/A", Department::CS)};

                auto uid = Convert::ToInt64(reader->GetBodyDefinition("uid"));
                auto fname = reader->GetBodyDefinition("First Name");
                auto lname = reader->GetBodyDefinition("Last Name");
                auto email = reader->GetBodyDefinition("Email");
                auto dept = parseStrDept(reader->GetBodyDefinition("Department"));
                auto appdate = reader->GetBodyDefinition("Appointment Date");

                return {true, gcnew Faculty(uid, fname, lname, email, appdate, dept)};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> GetAll(List<Course> ^ % courses) {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute("select * from course");
                while (reader->Read()) {
                    auto cid = Convert::ToInt32(reader->GetBodyDefinition("cid"));
                    auto cname = reader->GetBodyDefinition("cname");
                    auto credits = Convert::ToDouble(reader->GetBodyDefinition("credits"));
                    auto sem = parseStrSemester(reader->GetBodyDefinition("sem"));
                    auto capacity = Convert::ToInt32(reader->GetBodyDefinition("capacity"));
                    courses->Add(Course(cid, cname, credits, sem, capacity));
                }

                Audit::Ins()->Log("Viewed all courses", user->UID);
                return {true, "Retrived all courses"};
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

        ServiceReturn<List<Course> ^> GetPrereqCourses(long long cid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesCourseExistId(cid)) {
                    throw gcnew Exception("Course does not exist");
                }

                List<Course> ^ courses = gcnew List<Course>(0);
                reader = db::Ins()->execute(
                    "select * from course where cid in (select preqid from prerequisites where cid = " + cid + ")");
                if (!reader->HasRows) {
                    return {true, courses};
                }

                while (reader->Read()) {
                    auto cid = Convert::ToInt32(reader->GetBodyDefinition("cid"));
                    auto cname = reader->GetBodyDefinition("cname");
                    auto credits = Convert::ToDouble(reader->GetBodyDefinition("credits"));
                    auto sem = parseStrSemester(reader->GetBodyDefinition("sem"));
                    auto capacity = Convert::ToInt32(reader->GetBodyDefinition("capacity"));
                    auto c = Course(cid, cname, credits, sem, capacity);
                    courses->Add(c);
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