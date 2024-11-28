#pragma once
#include "UserService.h"
#include "db/Database.h"
#include "utils.h"

namespace icpproject {
    using namespace std;
    using namespace System;
    using namespace System::Data;
    using namespace System::Collections::Generic;

   public
    ref class EnumerationService : public UserService {
       public:
        EnumerationService(IUser ^ user) : UserService{user} {}

        ServiceReturn<DataTable ^> GetAllStudents() {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    student.uid AS UID,
    fname AS First_Name,
    lname AS Last_Name,
    email AS Email,
    dob AS 
Date_Of_Birth,
    picture AS Picture,
    major AS Major,
    enrolldate AS Enroll_Date
FROM
    student
INNER 
JOIN USER 
ON
    user.uid = student.uid
)";
                reader = db::Ins()->execute(query);
                DataTable ^ dt = gcnew DataTable();
                dt->Load(reader);
                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<DataTable ^> GetAllFaculty() {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    faculty.uid AS UID,
    fname AS First_Name,
    lname AS Last_Name,
    email AS Email,
    appDate AS 
Appointment_Date,
    dept AS Department
FROM
    faculty
INNER JOIN USER ON
    user.uid = faculty.uid
)";
                reader = db::Ins()->execute(query);
                DataTable ^ dt = gcnew DataTable();
                dt->Load(reader);
                return {true, dt};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }
    };
}  // namespace icpproject
