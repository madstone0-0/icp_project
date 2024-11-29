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

    value struct NewEnrollment {
        long long uid;
        long long cid;
        Semester sem;
        Grade grade;

        NewEnrollment(long long u, long long c, Semester s, Grade g) {
            uid = u;
            cid = c;
            sem = s;
            grade = g;
        }

        NewEnrollment(long long u, long long c, Grade g) {
            uid = u;
            cid = c;
            sem = Semester::S1;
            grade = g;
        }
    };

    value struct Enrollment {
        long long eid;
        long long uid;
        long long cid;
        Semester sem;
        Grade grade;

        Enrollment(long long e, long long u, long long c, Semester s, Grade g) {
            eid = e;
            uid = u;
            cid = c;
            sem = s;
            grade = g;
        }
    };

    value struct EnrollmentWithCourseName {
        long long eid;
        long long uid;
        long long cid;
        STR cname;
        Semester sem;
        double credits;
        Grade grade;

        EnrollmentWithCourseName(long long e, long long u, long long c, STR cn, Semester s, Grade g, double cr) {
            eid = e;
            uid = u;
            cid = c;
            cname = cn;
            sem = s;
            grade = g;
            credits = cr;
        }
    };

    ref class EnrollService : public UserService {
       private:
        value struct RequireRes {
            bool status;
            List<Course> ^ required;
        };

        RequireRes meetsRequirements(long long uid, long long cid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    preqid ,
    cname,
    credits,
    sem,
    capacity
FROM
    prerequisites p
JOIN course c ON
    p.preqid = c.cid
WHERE
    p.cid = {0};
)";
                reader = db::Ins()->execute(String::Format(query, cid));
                List<Course> ^ required = gcnew List<Course>(0);
                while (reader->Read()) {
                    auto preqid = Convert::ToInt64(reader->GetBodyDefinition("preqid"));
                    auto cname = reader->GetBodyDefinition("cname");
                    auto credits = Convert::ToDouble(reader->GetBodyDefinition("credits"));
                    auto sem = parseStrSemester(reader->GetBodyDefinition("sem"));
                    auto capacity = Convert::ToInt32(reader->GetBodyDefinition("capacity"));
                    required->Add(Course(preqid, cname, credits, sem, capacity, gcnew PreReqList(0)));
                }

                List<Course> ^ requiredRes = gcnew List<Course>(0);
                for each (auto preReq in required) {
                    if (!isAlreadyEnrolled(uid, preReq.cid)) {
                        requiredRes->Add(preReq);
                    }
                }

                if (requiredRes->Count != 0) {
                    return {false, requiredRes};
                }

                return {true, requiredRes};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        bool isAlreadyEnrolled(long long uid, long long cid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute(
                    String::Format("select * from enrollment where uid = {0} and cid = {1}", uid, cid));
                return reader->HasRows;
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        bool doesEnrollmentExistId(long long eid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute(String::Format("select * from enrollment where eid = {0}", eid));
                return reader->HasRows;
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        void checkCapacity(long long cid) {
            CourseService ^ courseService = gcnew CourseService(user);
            auto remaining = courseService->GetRemainingCapacity(cid);

            if (!remaining.status || remaining.data <= 0) {
                throw gcnew Exception("Course is full");
            }
            delete courseService;
        }

       public:
        EnrollService(IUser ^ user) : UserService{user} {}

        ServiceReturn<List<EnrollmentWithCourseName> ^> GetByUId(long long uid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR q = R"(
SELECT
e.cid,
eid,
    cname AS Course_Name,
    credits AS Credits,
    e.sem AS Semester,
    grade AS Grade
FROM
    enrollment e
INNER JOIN course c ON
    e.cid = c.cid
WHERE e.uid = {0}
)";
                reader = db::Ins()->execute(String::Format(q, uid));
                List<EnrollmentWithCourseName> ^ dt = gcnew List<EnrollmentWithCourseName>(0);
                while (reader->Read()) {
                    auto eid = Convert::ToInt64(reader->GetBodyDefinition("eid"));
                    auto cid = Convert::ToInt64(reader->GetBodyDefinition("cid"));
                    auto sem = parseStrSemester(reader->GetBodyDefinition("Semester"));
                    auto grade = parseStrGrade(reader->GetBodyDefinition("Grade"));
                    auto cname = reader->GetBodyDefinition("Course_Name");
                    auto credits = Convert::ToDouble(reader->GetBodyDefinition("Credits"));
                    dt->Add(EnrollmentWithCourseName(eid, uid, cid, cname, sem, grade, credits));
                }

                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<Enrollment ^> GetById(long long eid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute(String::Format("select * from enrollment where eid = {0}", eid));
                reader->Read();
                auto uid = Convert::ToInt64(reader->GetBodyDefinition("uid"));
                auto cid = Convert::ToInt64(reader->GetBodyDefinition("cid"));
                auto sem = parseStrSemester(reader->GetBodyDefinition("sem"));
                auto grade = parseStrGrade(reader->GetBodyDefinition("grade"));
                auto enrollment = gcnew Enrollment(eid, uid, cid, sem, grade);

                Audit::Ins()->Log("Viewed enrollment", user->UID, "Enrollment ID: " + eid);
                return {true, enrollment};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<DataTable ^> GetAllEnrolledIn(long long cid, Semester sem) {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute(
                    String::Format("select * from enrollment where cid = {0} and sem = {1}", cid, parseSemester(sem)));
                DataTable ^ dt = gcnew DataTable();
                dt->Load(reader);

                Audit::Ins()->Log("Viewed all enrollments in course", user->UID, "Course ID: " + cid);
                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<DataTable ^> GetAll() {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    eid AS EID,
    uid AS UID,
    e.cid AS CID,
    cname AS Course_Name,
    credits AS Credits,
    e.sem AS Semester,
    grade AS Grade
FROM
    enrollment e
INNER JOIN course c ON
    e.cid = c.cid
)";
                reader = db::Ins()->execute(query);
                DataTable ^ dt = gcnew DataTable();
                dt->Load(reader);

                Audit::Ins()->Log("Viewed all enrollments", user->UID);
                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> Enroll(NewEnrollment newEnrollment) {
            ParamsH params = gcnew Params(1);
            MySqlDataReader ^ reader = nullptr;
            try {
                if (isAlreadyEnrolled(newEnrollment.uid, newEnrollment.cid)) {
                    throw gcnew Exception("User is already enrolled in this course");
                }

                checkCapacity(newEnrollment.cid);

                auto reqRes = meetsRequirements(newEnrollment.uid, newEnrollment.cid);
                if (!reqRes.status) {
                    STR msg = "User does not meet the following prerequisites: ";
                    for each (auto course in reqRes.required) {
                        msg += course.cname + "\n";
                    }
                    errorMsg(msg, "EnrollService");
                    throw gcnew Exception(msg);
                }

                params->Add("@uid", newEnrollment.uid);
                params->Add("@cid", newEnrollment.cid);
                params->Add("@sem", parseSemester(newEnrollment.sem));
                params->Add("@grade", parseGrade(newEnrollment.grade));

                reader = db::Ins()->execute(
                    "insert into enrollment (uid, cid, sem, grade) values (@uid, @cid, @sem, @grade)", params);
                auto eid = db::Ins()->getCmd()->LastInsertedId;
                reader->Close();

                Audit::Ins()->Log("Enrolled user in course", user->UID,
                                  "Course: " + String::Format("UID: {0} CID: {1} EID: {2}", newEnrollment.uid,
                                                              newEnrollment.cid, eid));
                return {true, "User Enrolled successfully"};

            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> Update(Enrollment enrollment) {
            ParamsH params = gcnew Params(1);
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!isAlreadyEnrolled(enrollment.uid, enrollment.cid)) {
                    throw gcnew Exception("User is not enrolled in this course");
                }

                checkCapacity(enrollment.cid);

                params->Add("@eid", enrollment.eid);
                params->Add("@uid", enrollment.uid);
                params->Add("@cid", enrollment.cid);
                params->Add("@sem", parseSemester(enrollment.sem));
                params->Add("@grade", parseGrade(enrollment.grade));

                db::Ins()->executeNoRet(
                    "update enrollment set uid = @uid, cid = @cid, sem = @sem, grade = @grade where eid = @eid",
                    params);

                Audit::Ins()->Log("Updated enrollment", user->UID, String::Format("EID: {0}", enrollment.eid));
                return {true, "Enrollment updated successfully"};

            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> Delete(long long eid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesEnrollmentExistId(eid)) {
                    throw gcnew Exception("Enrollment does not exist");
                }

                db::Ins()->executeNoRet("delete from enrollment where eid = " + eid);

                Audit::Ins()->Log("Deleted enrollment", user->UID, "EID: " + eid);
                return {true, "Enrollment deleted successfully"};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }
    };
}  // namespace icpproject