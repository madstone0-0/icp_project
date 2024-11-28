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

    ref class FacultyActionService : public UserService {
        FacultyActionService(IUser ^ user) : UserService{user} {}

        ServiceReturn<DataTable ^> GetAllUnGraded(long long cid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute(
                    String::Format("select * from enrollment where grade is null and cid = {0}", cid));
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