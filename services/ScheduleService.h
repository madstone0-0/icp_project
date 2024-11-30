#pragma once
#include "../db/Database.h"
#include "../utils.h"
#include "AuditService.h"
#include "EnrollService.h"
#include "UserService.h"

namespace icpproject {
    using namespace System::Windows::Forms;

    value struct NewSchedule {
        long long cid;
        DateTime starttime;
        DateTime endtime;
        Day day;

        NewSchedule(long long c, DateTime s, DateTime e, Day d) {
            cid = c;
            starttime = s;
            endtime = e;
            day = d;
        }
    };

    value struct Schedule {
        long long scid;
        long long cid;
        DateTime starttime;
        DateTime endtime;
        Day day;

        Schedule(long long sc, long long c, DateTime s, DateTime e, Day d) {
            scid = sc;
            cid = c;
            starttime = s;
            endtime = e;
            day = d;
        }
    };

    ref class ScheduleService : public UserService {
       private:
        bool doesTimeConflict(DateTime start, DateTime end, Day day) {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    scid
FROM
    schedule
WHERE
    DAY = @d
    AND 
    (
        (
            starttime <= @st
                AND endtime >= @st
        )
        OR 
     (
            starttime <= @et
                AND endtime >= @et
        )
        OR 
     (
            starttime >= @st
                AND endtime <= @et
        )
    )
)";
                ParamsH params = gcnew Params(0);
                params->Add("@d", parseDay(day));
                params->Add("@st", formatDateTimeAsMySQLTime(start));
                params->Add("@et", formatDateTimeAsMySQLTime(end));
                reader = db::Ins()->execute(query, params);

                return reader->HasRows;
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        bool doesScheduleExistId(long long schid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute(String::Format("select * from schedule where scid = {0}", schid));
                return reader->HasRows;
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

       public:
        ScheduleService(IUser ^ user) : UserService{user} {}

        ServiceReturn<DataTable ^> GetAll() {
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute("select * from schedule");
                DataTable ^ dt = gcnew DataTable();
                dt->Load(reader);

                Audit::Ins()->Log("Viewed general schedule", user->UID);
                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> GetAll(ScheduleMap ^ schedule) {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    scid,
    s.cid,
    cname,
    starttime,
    endtime,
    DAY
FROM
    schedule s
INNER JOIN course c ON
    c.cid = s.cid
)";
                reader = db::Ins()->execute(query);
                while (reader->Read()) {
                    auto scid = Convert::ToInt64(reader->GetBodyDefinition("scid"));
                    auto cname = reader->GetBodyDefinition("cname");
                    auto starttime = Convert::ToDateTime(reader->GetBodyDefinition("starttime"));
                    auto endtime = Convert::ToDateTime(reader->GetBodyDefinition("endtime"));
                    auto day = parseStrDay(reader->GetBodyDefinition("day"));
                    if (!schedule->ContainsKey(day)) {
                        schedule->Add(day, gcnew List<ScheduleItem>(0));
                    }
                    List<ScheduleItem> ^ items = gcnew List<ScheduleItem>(0);
                    schedule->TryGetValue(day, items);
                    items->Add(ScheduleItem{scid, cname, starttime, endtime, day});
                }

                Audit::Ins()->Log("Viewed general schedule", user->UID);
                return {true, "Retrieved schedule"};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> Add(NewSchedule sched) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (doesTimeConflict(sched.starttime, sched.endtime, sched.day)) {
                    throw gcnew Exception("Time conflict detected");
                }
                ParamsH params = gcnew Params(0);
                params->Add("@cid", sched.cid);
                params->Add("@st", formatDateTimeAsMySQLTime(sched.starttime));
                params->Add("@et", formatDateTimeAsMySQLTime(sched.endtime));
                params->Add("@d", parseDay(sched.day));
                db::Ins()->executeNoRet(
                    "insert into schedule (cid, starttime, endtime, day) values (@cid, @st, @et, @d)", params);
                auto schid = db::Ins()->getCmd()->LastInsertedId;

                Audit::Ins()->Log("Added schedule", user->UID, String::Format("Schedule Id: {0}", schid));
                return {true, "Schedule added successfully"};

            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> Update(Schedule sched) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesScheduleExistId(sched.scid)) {
                    throw gcnew Exception("Schedule does not exist");
                }
                if (doesTimeConflict(sched.starttime, sched.endtime, sched.day)) {
                    throw gcnew Exception("Time conflict detected");
                }

                ParamsH params = gcnew Params(0);
                params->Add("@cid", sched.cid);
                params->Add("@st", formatDateTimeAsMySQLTime(sched.starttime));
                params->Add("@et", formatDateTimeAsMySQLTime(sched.endtime));
                params->Add("@d", parseDay(sched.day));
                params->Add("@scid", sched.scid);
                db::Ins()->executeNoRet(
                    "update schedule set cid = @cid, starttime = @st, endtime = @et, day = @d where scid = @scid",
                    params);
                Audit::Ins()->Log("Updated schedule", user->UID, String::Format("Schedule Id: {0}", sched.scid));
                return {true, "Schedule updated successfully"};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<STR> Delete(long long schid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                if (!doesScheduleExistId(schid)) {
                    throw gcnew Exception("Schedule does not exist");
                }
                ParamsH params = gcnew Params(0);
                params->Add("@schid", schid);

                db::Ins()->executeNoRet("delete from schedule where scid = @schid", params);
                Audit::Ins()->Log("Deleted schedule", user->UID, String::Format("Schedule Id: {0}", schid));
                return {true, "Schedule deleted successfully"};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<ScheduleMap ^> GenerateStudentSchedule(long long uid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                EnrollService ^ enrollService = gcnew EnrollService(user);
                auto res = enrollService->GetByUId(uid);
                if (!res.status) {
                    return {false, nullptr};
                }

                List<long long> ^ enrolledCourses = gcnew List<long long>(0);
                for each (auto enrollment in res.data) {
                    enrolledCourses->Add(enrollment.cid);
                }
                STR inClause = String::Join(",", enrolledCourses);
                STR query = R"(
SELECT
    scid,
    s.cid,
    cname,
    starttime,
    endtime,
    DAY
FROM
    schedule s
INNER JOIN course c ON
    c.cid = s.cid
WHERE
    s.cid IN (
       {0}
    )
)";
                reader = db::Ins()->execute(String::Format(query, inClause));
                ScheduleMap ^ schedule = gcnew ScheduleMap();
                while (reader->Read()) {
                    auto scid = Convert::ToInt64(reader->GetBodyDefinition("scid"));
                    auto cname = reader->GetBodyDefinition("cname");
                    auto starttime = Convert::ToDateTime(reader->GetBodyDefinition("starttime"));
                    auto endtime = Convert::ToDateTime(reader->GetBodyDefinition("endtime"));
                    auto day = parseStrDay(reader->GetBodyDefinition("day"));
                    if (!schedule->ContainsKey(day)) {
                        schedule->Add(day, gcnew List<ScheduleItem>(0));
                    }
                    List<ScheduleItem> ^ items = gcnew List<ScheduleItem>(0);
                    schedule->TryGetValue(day, items);
                    items->Add(ScheduleItem{scid, cname, starttime, endtime, day});
                }

                return {true, schedule};

            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }
    };

}  // namespace icpproject