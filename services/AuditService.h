#pragma once
#include "../db/Database.h"
#include "../utils.h"

namespace icpproject {
    template <typename T>
    concept Number = requires {
        std::is_integral_v<T> || std::is_floating_point_v<T>;
        std::is_convertible_v<T, std::string>;
    };

    using namespace std;
    using namespace System;

   public
    ref class AuditService {
       public:
        static AuditService ^ instance;
        static AuditService ^
            Ins() {
                if (instance == nullptr) {
                    instance = gcnew AuditService();
                }
                return instance;
            }

            template <typename T>
            void log(STR action, T uid) {
            ParamsH params = gcnew Params(1);
            params->Add("@action", action);
            params->Add("@uid", uid);
            db::Ins()->executeNoRet("insert into audit_log (action, user_id) values (@action, @uid)", params);
        }

        template <typename T>
        void log(STR action, T uid, STR details) {
            ParamsH params = gcnew Params(1);
            params->Add("@action", action);
            params->Add("@uid", uid);
            params->Add("@details", details);
            db::Ins()->executeNoRet("insert into audit_log (action, user_id, details) values (@action, @uid, @details)",
                                    params);
        }

        ~AuditService() { delete instance; }

       private:
        AuditService() {}
    };

    using Audit = AuditService;
}  // namespace icpproject