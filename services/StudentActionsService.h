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
        Semester seml;

        TranscriptItem(STR c, Grade g, double cr, Semester s) {
            cname = c;
            grade = g;
            credits = cr;
            seml = s;
        }
    };

   public
    ref class StudentActionService : public UserService {
       public:
        StudentActionService(IUser ^ user) : UserService{user} {}

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