#pragma once
#include "../db/Database.h"
#include "../utils.h"
#include "AuditService.h"
#include "EnrollService.h"
#include "UserService.h"

namespace icpproject {
    using namespace std;
    using namespace System;
    using namespace System::Data;
    using namespace System::Collections::Generic;

   public
    value struct TranscriptItem {
        STR cname;
        Grade grade;
        double credits;
        Semester sem;

        TranscriptItem(STR c, Grade g, double cr, Semester s) {
            cname = c;
            grade = g;
            credits = cr;
            sem = s;
        }
    };

   public
    ref class StudentActionService : public UserService {
       public:
        StudentActionService(IUser ^ user) : UserService{user} {}

        ServiceReturn<List<TranscriptItem> ^> GetTranscript(long long uid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    cname,
    grade,
    credits,
    e.sem
FROM
    enrollment e
INNER JOIN course c ON
    e.cid = c.cid
WHERE
    e.uid = {0};
)";
                reader = db::Ins()->execute(String::Format(query, uid));
                auto dt = gcnew List<TranscriptItem>(0);
                if (!reader->HasRows) {
                    return {true, dt};
                }

                while (reader->Read()) {
                    auto cname = reader->GetBodyDefinition("cname");
                    auto grade = parseStrGrade(reader->GetBodyDefinition("grade"));
                    auto credits = Convert::ToDouble(reader->GetBodyDefinition("credits"));
                    auto sem = parseStrSemester(reader->GetBodyDefinition("sem"));
                    dt->Add(TranscriptItem(cname, grade, credits, sem));
                }

                Audit::Ins()->Log("Viewed transcript", user->UID, "Student ID: " + uid);
                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> UpdateProfile(Student student) {
            MySqlDataReader ^ reader = nullptr;
            try {
                db::Ins()->beginTransaction();

                STR query = R"(
UPDATE
    user
SET
    fname = @fname
,
    lname = @lname
WHERE
    uid = @uid
)";
                ParamsH params = gcnew Params(0);
                params->Add("@fname", student.fname);
                params->Add("@lname", student.lname);
                params->Add("@uid", student.uid);

                try {
                    db::Ins()->executeNoRet(query, params);
                } catch (Exception ^ e) {
                    db::Ins()->rollback();
                    errorMsg(e->Message);
                    throw e;
                }
                query = R"(
UPDATE
    student
SET
    major = @major
,
    dob = @dob
,
    picture = @pic
WHERE
    uid = @uid
)";

                params->Clear();
                params->Add("@major", parseMajor(student.major));
                params->Add("@dob", student.dob);
                params->Add("@uid", student.uid);
                params->Add("@pic", student.picture);

                try {
                    db::Ins()->executeNoRet(query, params);
                } catch (Exception ^ e) {
                    db::Ins()->rollback();
                    errorMsg(e->Message);
                    throw e;
                }

                Audit::Ins()->Log("Updated profile", user->UID, "Student ID: " + student.uid);
                db::Ins()->commit();
                return {true, "Profile updated"};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<List<TranscriptItem> ^> GetTranscript() {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    cname,
    grade,
    credits,
    e.sem
FROM
    enrollment e
INNER JOIN course c ON
    e.cid = c.cid
WHERE
    e.uid = {0};
)";
                reader = db::Ins()->execute(String::Format(query, user->UID));
                auto dt = gcnew List<TranscriptItem>(0);
                if (!reader->HasRows) {
                    return {true, dt};
                }

                while (reader->Read()) {
                    auto cname = reader->GetBodyDefinition("cname");
                    auto grade = parseStrGrade(reader->GetBodyDefinition("grade"));
                    auto credits = Convert::ToDouble(reader->GetBodyDefinition("credits"));
                    auto sem = parseStrSemester(reader->GetBodyDefinition("sem"));
                    dt->Add(TranscriptItem(cname, grade, credits, sem));
                }

                Audit::Ins()->Log("Viewed transcript", user->UID);
                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }
    };
}  // namespace icpproject