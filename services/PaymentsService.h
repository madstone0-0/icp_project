#pragma once
#include "../db/Database.h"
#include "../utils.h"
#include "AuditService.h"
#include "EnumerationService.h"
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
       private:
        bool doesPaymentExist(long long uid, Semester sem) {
            return doesExist(String::Format("select uid, pid from payments where uid = {0} and sem = '{1}'", uid,
                                            parseSemester(sem)));
        }

       public:
        PaymentsService(IUser ^ user) : UserService{user} {};

        ServiceReturn<DataTable ^> GetAllOutstanding() {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    p.uid,
    fname AS "First Name",
    lname AS "Last Name",
    total_amount AS "Total Amount",
    paid_amount AS "Paid Amount"
FROM
    payments p
INNER JOIN `user` u ON
    u.uid = p.uid
WHERE
    paid_amount <> total_amount;
)";
                reader = db::Ins()->execute(query);
                DataTable ^ dt = gcnew DataTable();
                dt->Load(reader);

                Audit::Ins()->Log("Viewed all outstanding payments", user->UID);
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

        ServiceReturn<STR> IssueBills(Semester sem, double due) {
            MySqlDataReader ^ reader = nullptr;
            try {
                auto enumService = gcnew EnumerationService(user);
                auto students = gcnew List<Student>(0);
                auto getRes = enumService->GetAllStudents(students);
                if (!getRes.status) {
                    throw gcnew Exception("Could not fetch students");
                }
                db::Ins()->beginTransaction();
                try {
                    ParamsH params = gcnew Params(0);
                    int i = 0;
                    for each (auto s in students) {
                        if (doesPaymentExist(s.uid, sem)) {
                            continue;
                        }

                        params->Add("@id", s.uid);
                        params->Add("@sem", parseSemester(sem));
                        params->Add("@tot", due);
                        db::Ins()->executeNoRet(
                            "insert into payments (uid, sem, total_amount, paid_amount) values (@id, @sem, @tot, 0)",
                            params);
                        i++;
                    }

                    Audit::Ins()->Log("Issued payments", user->UID,
                                      String::Format("Issued payments to {0} students", i));
                    db::Ins()->commit();
                    return {true, String::Format("Issued payments to {0} students", i)};
                } catch (Exception ^ e) {
                    db::Ins()->rollback();
                    throw;
                }

            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> PayBill(long long uid, Semester sem, double amount) {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
UPDATE
    payments
SET
    paid_amount = paid_amount + @amt
WHERE
    uid = @uid and sem = @sem
)";
                ParamsH params = gcnew Params(0);
                params->Add("@uid", uid);
                params->Add("@sem", parseSemester(sem));
                params->Add("@amt", amount);
                db::Ins()->executeNoRet(query, params);
                Audit::Ins()->Log(
                    "Paid bill", user->UID,
                    String::Format("User ID: {0}, Semester: {1}, Amount: {2}", uid, parseSemester(sem), amount));
                return {true, "Bill paid successfully"};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }
    };
}  // namespace icpproject