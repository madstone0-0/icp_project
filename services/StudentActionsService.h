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

    ref class StudentActionService : public UserService {
        StudentActionService(IUser ^ user) : UserService{user} {}

        ServiceReturn<DataTable ^> GetTranscript() {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute(String::Format("select * from enrollment where uid = {0}", user->UID));
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