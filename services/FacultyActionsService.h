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
    ref class FacultyActionService : public UserService {
       public:
        FacultyActionService(IUser ^ user) : UserService{user} {}

        ServiceReturn<DataTable ^> GetAllUnGraded(long long cid, Semester sem) {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    e.uid AS "UID",
    fname AS "First Name",
    lname AS "Last Name",
    sem AS "Semester",
    grade AS "Grade"
FROM
    enrollment e
INNER JOIN USER u ON
    e.uid = u.uid
INNER JOIN student s ON
    s.uid = e.uid
WHERE
    e.cid = @cid
    AND sem = @sem
    AND grade = 'NG'
)";
                ParamsH params = gcnew Params(2);
                params->Add("@cid", cid);
                params->Add("@sem", parseSemester(sem));
                reader = db::Ins()->execute(query, params);
                DataTable ^ dt = gcnew DataTable();
                dt->Load(reader);
                reader->Close();

                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }
    };
}  // namespace icpproject