#pragma once
#include "../db/Database.h"
#include "../utils.h"
#include "AuditService.h"
#include "UserService.h"

namespace icpproject {

    enum class PaymentStatus { Pending, Partial, Paid };

    inline STR parsePaymentStatus(PaymentStatus status) {
        switch (status) {
            case PaymentStatus::Pending:
                return "pending";
                break;
            case PaymentStatus::Partial:
                return "partial";
                break;
            case PaymentStatus::Paid:
                return "paid";
                break;
        }
    }

    inline PaymentStatus parseStrPaymentStatus(STR status) {
        if (status == "pending") return PaymentStatus::Pending;
        if (status == "partial") return PaymentStatus::Partial;
        if (status == "paid") return PaymentStatus::Paid;
    }

    value struct Payment {
        long long pid;
        long long uid;
        Semester sem;
        double totalAmount;
        double paidAmount;
        PaymentStatus paymentStatus;

        Payment(long long p, long long u, Semester s, double t, double pa, PaymentStatus ps) {
            pid = p;
            uid = u;
            sem = s;
            totalAmount = t;
            paidAmount = pa;
            paymentStatus = ps;
        }
    };

    value struct NewPayment {
        long long uid;
        Semester sem;
        double totalAmount;
        double paidAmount;
        PaymentStatus paymentStatus;
        NewPayment(long long u, Semester s, double t, double pa, PaymentStatus ps) {
            uid = u;
            sem = s;
            totalAmount = t;
            paidAmount = pa;
            paymentStatus = ps;
        }
    };

   public
    ref class PaymentsService : public UserService {
       public:
        PaymentsService(IUser ^ user) : UserService{user} {};

        ServiceReturn<DataTable ^> GetAll() {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute("select * from payments");
                DataTable ^ dt = gcnew DataTable();
                dt->Load(reader);

                Audit::Ins()->Log("Viewed all payments", user->UID);
                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<DataTable ^> GetByUId(long long uid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute(String::Format("select * from payments where uid = {0}", uid));
                DataTable ^ dt = gcnew DataTable();
                dt->Load(reader);

                Audit::Ins()->Log("Viewed payments by user", user->UID, "User ID: " + uid);
                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<DataTable ^> GetBySemester(Semester sem) {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader =
                    db::Ins()->execute(String::Format("select * from payments where sem = {0}", parseSemester(sem)));
                DataTable ^ dt = gcnew DataTable();
                dt->Load(reader);

                Audit::Ins()->Log("Viewed payments by semester", user->UID, "Semester: " + parseSemester(sem));
                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<Payment ^> GetById(long long pid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesExist(String::Format("select * from payments where pid = {0}", pid))) {
                    throw gcnew Exception("Payment does not exist");
                }

                reader = db::Ins()->execute(String::Format("select * from payments where pid = {0}", pid));
                reader->Read();
                auto uid = Convert::ToInt64(reader->GetBodyDefinition("uid"));
                auto sem = parseStrSemester(reader->GetBodyDefinition("sem"));
                auto totalAmount = Convert::ToDouble(reader->GetBodyDefinition("total_amount"));
                auto paidAmount = Convert::ToDouble(reader->GetBodyDefinition("paid_amount"));
                auto paymentStatus = parseStrPaymentStatus(reader->GetBodyDefinition("paymentStatus"));
                auto payment = gcnew Payment(pid, uid, sem, totalAmount, paidAmount, paymentStatus);

                Audit::Ins()->Log("Viewed payment", user->UID, "Payment ID: " + pid);
                return {true, payment};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> IssueBills(Semester sem) {}

        ServiceReturn<STR> PayBill(long long uid, Semester sem, double amount) {}
    };
}  // namespace icpproject