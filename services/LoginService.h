#pragma once
#include <iostream>
#include <string>

#include "../db/Database.h"
#include "../utils.h"

namespace icpproject {
    using namespace std;
    using System::Diagnostics::Debug;

    template <typename T>
    public value struct ServiceReturn {
        bool status;
        T data;
    };

   public
    value struct SignupUser {
        STR fname;
        STR lname;
        STR email;
        STR password;

        SignupUser(STR f, STR l, STR e, STR p) {
            fname = f;
            lname = l;
            email = e;
            password = p;
        }
    };

    enum class Major { CS, BA, EN, ME, EE, CE, MA };

    enum class Department { CS, HM, EN, BA };

   public
    value struct SignupStudent {
        STR fname;
        STR lname;
        STR email;
        STR password;
        STR dob;
        STR picturePath;
        Major major;
        STR enrollDate;
    };

   public
    value struct SignupFaculty {
        STR fname;
        STR lname;
        STR email;
        STR password;
        STR appDate;
        Department dept;
    };

   public
    value struct LoginUser {
        STR email;
        STR password;
    };

   public
    value struct Admin {
        int uid;
        STR fname;
        STR lname;
        STR email;

        Admin(int u, STR f, STR l, STR e) {
            uid = u;
            fname = f;
            lname = l;
            email = e;
        }
    };

    inline bool isUserType(int uid, STR tableName) {
        MySqlDataReader ^ reader = nullptr;
        try {
            reader = db::Ins()->execute(String::Format("select uid from {0} where uid = {1} ", tableName, uid));
            return reader->HasRows;
        } finally {
            if (reader != nullptr) {
                reader->Close();
            }
        }
    }

    using PictureH = cli::array<unsigned char> ^ ;
    using Picture = cli::array<unsigned char>;
   public
    value struct Student {
        int uid;
        STR fname;
        STR lname;
        STR email;
        STR dob;
        PictureH picture;
        Major major;
        STR enrollDate;
        Student(int u, STR f, STR l, STR e, STR d, PictureH p, Major m, STR en) {
            uid = u;
            fname = f;
            lname = l;
            email = e;
            dob = d;
            picture = p;
            major = m;
            enrollDate = en;
        };
    };

   public
    value struct Faculty {
        int uid;
        STR fname;
        STR lname;
        STR email;
        STR appDate;
        Department dept;
        Faculty(int u, STR f, STR l, STR e, STR a, Department d) {
            uid = u;
            fname = f;
            lname = l;
            email = e;
            appDate = a;
            dept = d;
        };
    };

   public
    ref class AdminService {
       public:
        ServiceReturn<STR> SignUp(SignupUser user) {
            ParamsH params = gcnew Params(1);
            params->Add("@em", user.email);
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute("select uid from user where email = @em", params);

                if (reader->HasRows) {
                    throw gcnew Exception("User already exists");
                }
                reader->Close();

                auto fname = user.fname;
                auto lname = user.lname;
                auto email = user.email;
                auto password = user.password;
                auto passhash = getHash(password);

                params->Clear();
                params->Add("@fn", fname);
                params->Add("@ln", lname);
                params->Add("@em", email);
                params->Add("@pass", passhash);
                db::Ins()->executeNoRet(
                    "insert into user (fname, lname, email, password) values (@fn, @ln, @em, @pass)", params);

                auto uid = db::Ins()->getCmd()->LastInsertedId;
                params->Clear();
                params->Add("@u", Convert::ToString(uid));
                db::Ins()->executeNoRet("insert into admin (uid) values (@u)", params);

                return {true, "Admin added successfully"};
            } finally {
                if (reader != nullptr) reader->Close();
            }
        }

        ServiceReturn<Admin ^> Login(LoginUser user) {
            ParamsH params = gcnew Params(1);
            params->Add("@em", user.email);
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute("select * from user where email = @em", params);

                if (!reader->HasRows) {
                    reader->Close();
                    throw gcnew Exception("User not found");
                }

                reader->Read();
                auto uid = Convert::ToInt16(reader->GetBodyDefinition("uid"));
                auto fname = reader->GetBodyDefinition("fname");
                auto lname = reader->GetBodyDefinition("lname");
                auto email = reader->GetBodyDefinition("email");
                auto passhash = reader->GetBodyDefinition("password");
                reader->Close();
                if (!verifyHash(user.password, passhash)) {
                    throw gcnew Exception("Incorrect password");
                }

                // Convert to integer
                if (!isUserType(uid, "admin")) {
                    throw gcnew Exception("User is not an admin");
                }

                return {true, gcnew Admin{uid, fname, lname, email}};
            } finally {
                if (reader != nullptr) reader->Close();
            }
        }
    };

   public
    ref class StudentService {
       private:
        STR parseMajor(const Major& major) {
            switch (major) {
                case Major::CS:
                    return "CS";
                    break;
                case Major::BA:
                    return "BA";
                    break;
                case Major::MA:
                    return "MA";
                    break;
                case Major::CE:
                    return "CA";
                    break;
                case Major::EE:
                    return "EE";
                    break;
                case Major::EN:
                    return "EN";
                    break;
            }
        }

        Major parseStrMajor(STR major) {
            if (major == "CS") return Major::CS;
            if (major == "BA") return Major::BA;
            if (major == "MA") return Major::MA;
            if (major == "CA") return Major::CE;
            if (major == "EE") return Major::EE;
            if (major == "EN") return Major::EN;
        }

       public:
        ServiceReturn<STR> SignUp(SignupStudent ^ user) {
            ParamsH params = gcnew Params(1);
            params->Add("@em", user->email);
            MySqlDataReader ^ reader = nullptr;
            try {
                reader = db::Ins()->execute("select uid from user where email = @em", params);
                if (reader->HasRows) {
                    throw gcnew Exception("User already exists");
                }
                reader->Close();

                auto fname = user->fname;
                auto lname = user->lname;
                auto email = user->email;
                auto password = user->password;
                auto dob = user->dob;
                auto picturePath = user->picturePath;
                auto major = user->major;
                auto enrollDate = user->enrollDate;

                auto passhash = getHash(password);
                params->Clear();
                params->Add("@fn", fname);
                params->Add("@ln", lname);
                params->Add("@em", email);
                params->Add("@pass", passhash);
                db::Ins()->executeNoRet(
                    "insert into user (fname, lname, email, password) values (@fn, @ln, @em, @pass)", params);

                auto uid = db::Ins()->getCmd()->LastInsertedId;
                cli::array<unsigned char> ^ buff;
                try {
                    auto fs = gcnew System::IO::FileStream(picturePath, IO::FileMode::Open, IO::FileAccess::Read);
                    auto binReader = gcnew IO::BinaryReader(fs);
                    buff = binReader->ReadBytes(fs->Length);
                } catch (Exception ^ e) {
                    errorMsg(e->Message, "StudentSignUp");
                    throw e;
                }
                params->Clear();
                params->Add("@u", Convert::ToString(uid));
                params->Add("@d", dob);
                params->Add("@p", buff);
                params->Add("@m", parseMajor(major));
                params->Add("@e", enrollDate);
                db::Ins()->executeNoRet(
                    "insert into student (uid, dob, picture, major, enrollDate) values (@u, @d, @p, @m, @e)", params);
                return {true, "Student added successfully"};
            } finally {
                if (reader != nullptr) reader->Close();
            }
        }

        ServiceReturn<Student ^> Login(LoginUser ^ user) {
            ParamsH params = gcnew Params(1);
            params->Add("@em", user->email);
            MySqlDataReader ^ reader = nullptr;

            try {
                reader = db::Ins()->execute("select * from user where email = @em", params);
                if (!reader->HasRows) {
                    throw gcnew Exception("User not found");
                }
                reader->Read();
                auto uid = Convert::ToInt16(reader->GetBodyDefinition("uid"));
                auto passhash = reader->GetBodyDefinition("password");
                auto fname = reader->GetBodyDefinition("fname");
                auto lname = reader->GetBodyDefinition("lname");
                auto email = reader->GetBodyDefinition("email");
                reader->Close();

                if (!verifyHash(user->password, passhash)) {
                    throw gcnew Exception("Invalid password");
                }
                // Convert to integer

                if (!isUserType(uid, "student")) {
                    throw gcnew Exception("User is not a student");
                }

                try {
                    reader = db::Ins()->execute("select * from student where uid = " + Convert::ToString(uid));
                    auto dob = reader->GetBodyDefinition("dob");
                    auto pictureStr = reader->GetBodyDefinition("picture");
                    PictureH picture = gcnew Picture(pictureStr->Length);
                    picture = Encoding::UTF8->GetBytes(pictureStr);
                    auto major = parseStrMajor(reader->GetBodyDefinition("major"));
                    auto enrollDate = reader->GetBodyDefinition("enrollDate");

                    auto studentRes = gcnew Student{uid, fname, lname, email, dob, picture, major, enrollDate};
                    return {true, studentRes};
                } catch (Exception ^ e) {
                    reader->Close();
                    errorMsg(e->Message, "StudentLogin");
                    return {false, nullptr};
                }
            } finally {
                if (reader != nullptr) reader->Close();
            }
        }
    };

   public
    ref class FacultyService {
       private:
        STR parseDept(const Department& dept) {
            switch (dept) {
                case Department::CS:
                    return "CS";
                    break;
                case Department::HM:
                    return "HM";
                    break;
                case Department::EN:
                    return "EN";
                    break;
                case Department::BA:
                    return "BA";
                    break;
            }
        }

        Department parseStrDept(STR dept) {
            if (dept == "CS") return Department::CS;
            if (dept == "HM") return Department::HM;
            if (dept == "EN") return Department::EN;
            if (dept == "BA") return Department::BA;
        }

       public:
        ServiceReturn<STR> SignUp(SignupFaculty faculty) {
            ParamsH params = gcnew Params(1);
            params->Add("@em", faculty.email);
            MySqlDataReader ^ reader = nullptr;

            try {
                reader = db::Ins()->execute("select uid from user where email = @em", params);
                if (reader->HasRows) {
                    throw gcnew Exception("User already exists");
                }
                reader->Close();

                auto fname = faculty.fname;
                auto lname = faculty.lname;
                auto email = faculty.email;
                auto password = faculty.password;
                auto appDate = faculty.appDate;
                auto dept = faculty.dept;

                auto passhash = getHash(password);
                params->Clear();
                params->Add("@fn", fname);
                params->Add("@ln", lname);
                params->Add("@em", email);
                params->Add("@pass", passhash);
                db::Ins()->executeNoRet(
                    "insert into user (fname, lname, email, password) values (@fn, @ln, @em, @pass)", params);

                auto uid = db::Ins()->getCmd()->LastInsertedId;
                params->Clear();
                params->Add("@app", appDate);
                params->Add("@dept", parseDept(dept));
                db::Ins()->executeNoRet("insert into faculty (uid, appDate, dept) values (@app, @dept)", params);

                return {true, "Faculty added successfully"};
            } finally {
                if (reader != nullptr) reader->Close();
            }
        }

        ServiceReturn<Faculty ^> Login(LoginUser user) {
            ParamsH params = gcnew Params(1);
            params->Add("@em", user.email);
            MySqlDataReader ^ reader = nullptr;

            try {
                reader = db::Ins()->execute("select * from user where email = @em", params);
                if (!reader->HasRows) {
                    reader->Close();
                    throw gcnew Exception("User not found");
                }

                reader->Read();
                auto fname = reader->GetBodyDefinition("fname");
                auto lname = reader->GetBodyDefinition("lname");
                auto email = reader->GetBodyDefinition("email");
                auto appD = reader->GetBodyDefinition("appDate");
                auto passhash = reader->GetBodyDefinition("password");
                auto uid = Convert::ToInt16(reader->GetBodyDefinition("uid"));
                auto dept = parseStrDept(reader->GetBodyDefinition("dept"));
                reader->Close();

                if (!verifyHash(user.password, passhash)) {
                    throw gcnew Exception("Incorrect password");
                }

                if (!isUserType(uid, "faculty")) {
                    throw gcnew Exception("User is not a faculty");
                }

                return {true, gcnew Faculty{uid, fname, lname, email, appD, dept}};
            } finally {
                if (reader != nullptr) reader->Close();
            }
        }
    };
}  // namespace icpproject