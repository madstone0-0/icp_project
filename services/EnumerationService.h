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

        ServiceReturn<STR> GetAllStudents(List<Student> ^ students) {
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
                while (reader->Read()) {
                    auto uid = Convert::ToInt64(reader->GetUInt64("UID"));
                    auto fname = reader->GetBodyDefinition("First_Name");
                    auto lname = reader->GetBodyDefinition("Last_Name");
                    auto email = reader->GetBodyDefinition("Email");
                    auto dob = reader->GetBodyDefinition("Date_Of_Birth");
                    PictureH picture;
                    try {
                        int ordinal = reader->GetOrdinal("picture");
                        if (reader->IsDBNull(ordinal)) {
                            picture = gcnew Picture(0);
                        } else {
                            auto pictureLen = reader->GetBytes(reader->GetOrdinal("picture"), 0, nullptr, 0, 0);
                            picture = gcnew Picture(pictureLen);
                            reader->GetBytes(reader->GetOrdinal("picture"), 0, picture, 0, pictureLen);
                        }
                    } catch (Exception ^ e) {
                        errorMsg(e->Message);
                        // MessageBox::Show(e->Message);
                        picture = gcnew Picture(0);
                    }
                    auto major = parseStrMajor(reader->GetBodyDefinition("Major"));
                    auto enrollDate = reader->GetBodyDefinition("Enroll_Date");
                    students->Add(Student(uid, fname, lname, email, dob, picture, major, enrollDate));
                }

                return {true, "Retrieved all students"};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

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

        ServiceReturn<STR> GetAllFaculty(List<Faculty> ^ faculty) {
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
                while (reader->Read()) {
                    auto uid = Convert::ToInt64(reader->GetUInt64("UID"));
                    auto fname = reader->GetBodyDefinition("First_Name");
                    auto lname = reader->GetBodyDefinition("Last_Name");
                    auto email = reader->GetBodyDefinition("Email");
                    auto appDate = reader->GetBodyDefinition("Appointment_Date");
                    auto dept = parseStrDept(reader->GetBodyDefinition("Department"));
                    faculty->Add(Faculty(uid, fname, lname, email, appDate, dept));
                }

                return {true, "Retrieved all faculty"};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<Faculty ^> GetFacultyById(long long uid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    u.uid,
    fname AS "First Name",
    lname AS "Last Name",
    email AS "Email",
    dept AS "Department"
FROM
    faculty f
INNER JOIN USER u ON
    f.uid = u.uid
WHERE
    u.uid = {0}
)";
                reader = db::Ins()->execute(String::Format(query, uid));
                if (!reader->HasRows) throw gcnew Exception("Faculty does not exist");

                reader->Read();
                auto fname = reader->GetBodyDefinition("First Name");
                auto lname = reader->GetBodyDefinition("Last Name");
                auto email = reader->GetBodyDefinition("Email");
                auto dept = parseStrDept(reader->GetBodyDefinition("Department"));
                return {true, gcnew Faculty(uid, fname, lname, email, "N/A", dept)};
            } finally {
                if (reader != nullptr) {
                    reader->Close();
                }
            }
        }

        ServiceReturn<Student ^> GetStudentById(long long uid) {
            MySqlDataReader ^ reader = nullptr;
            try {
                STR query = R"(
SELECT
    u.uid,
    fname AS "First Name",
    lname AS "Last Name",
    email AS "Email",
    dob AS "Date Of Birth",
    picture AS "Picture",
    major AS "Major",
    enrolldate AS "Enroll Date"
FROM
    student s
INNER JOIN USER u ON
    s.uid = u.uid
WHERE
    u.uid = {0}
)";
                reader = db::Ins()->execute(String::Format(query, uid));
                if (!reader->HasRows) throw gcnew Exception("Student does not exist");
                reader->Read();
                auto fname = reader->GetBodyDefinition("First Name");
                auto lname = reader->GetBodyDefinition("Last Name");
                auto email = reader->GetBodyDefinition("Email");
                auto dob = reader->GetBodyDefinition("Date Of Birth");
                PictureH picture;
                try {
                    int ordinal = reader->GetOrdinal("picture");
                    if (reader->IsDBNull(ordinal)) {
                        picture = gcnew Picture(0);
                    } else {
                        auto pictureLen = reader->GetBytes(reader->GetOrdinal("picture"), 0, nullptr, 0, 0);
                        picture = gcnew Picture(pictureLen);
                        reader->GetBytes(reader->GetOrdinal("picture"), 0, picture, 0, pictureLen);
                    }
                } catch (Exception ^ e) {
                    errorMsg(e->Message);
                    // MessageBox::Show(e->Message);
                    picture = gcnew Picture(0);
                }
                auto major = parseStrMajor(reader->GetBodyDefinition("Major"));
                auto enrollDate = reader->GetBodyDefinition("Enroll Date");
                return {true, gcnew Student(uid, fname, lname, email, dob, picture, major, enrollDate)};
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
