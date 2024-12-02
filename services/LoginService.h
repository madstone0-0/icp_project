#pragma once
#include <iostream>
#include <string>

#include "../db/Database.h"
#include "../utils.h"
#include "AuditService.h"

namespace icpproject {
    using namespace std;
    using System::Diagnostics::Debug;

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

   public
    value struct Admin : public IUser {
        int uid;
        STR fname;
        STR lname;
        STR email;

        virtual property int UID {
            int get() { return uid; }
            void set(int value) { uid = value; }
        }

        virtual property STR FirstName {
            STR get() { return fname; }
            void set(STR value) { fname = value; }
        }

        virtual property STR LastName {
            STR get() { return lname; }
            void set(STR value) { lname = value; }
        }

        virtual property STR Email {
            STR get() { return email; }
            void set(STR value) { email = value; }
        }

        Admin(int u, STR f, STR l, STR e) {
            uid = u;
            fname = f;
            lname = l;
            email = e;
        }
    };

    // Attempt at abstraction
    // public
    // interface class IUserService {
    //     ServiceReturn<STR> SignUp(SignupUser user);
    //     ServiceReturn<STR> Login(LoginUser user);
    // };

    // public
    //  ref class BaseUserService : IUserService {
    //     private:
    //      STR userTableName = "user";
    //      STR serviceTableName;

    //    protected:
    //     generic<typename TEnum> static TEnum parseStrEnum(String ^ value, Dictionary<String ^, TEnum> ^ mapping) {
    //         if (mapping->ContainsKey(value)) {
    //             TEnum val;
    //             mapping->TryGetValue(value, val);
    //             return val;
    //         }
    //         throw gcnew Exception("Invalid enum value");
    //     }

    //    public:
    // };

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

                db::Ins()->beginTransaction();
                try {
                    db::Ins()->executeNoRet(
                        "insert into user (fname, lname, email, password) values (@fn, @ln, @em, @pass)", params);

                    auto uid = db::Ins()->getCmd()->LastInsertedId;
                    params->Clear();
                    params->Add("@u", Convert::ToString(uid));
                    db::Ins()->executeNoRet("insert into admin (uid) values (@u)", params);
                    Audit::Ins()->Log("AdminSignUp", uid);

                    return {true, "Admin added successfully"};
                } catch (Exception ^ e) {
                    reader->Close();
                    db::Ins()->rollback();
                    throw e;
                } finally {
                    db::Ins()->commit();
                }

            } finally {
                if (reader != nullptr) reader->Close();
            }
        }

        ServiceReturn<IUser ^> Login(LoginUser user) {
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

                Audit::Ins()->Log("AdminLogin", uid);
                return {true, gcnew Admin{uid, fname, lname, email}};
            } finally {
                if (reader != nullptr) reader->Close();
            }
        }
    };

   public
    ref class StudentService {
       private:
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
                db::Ins()->beginTransaction();
                try {
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
                        "insert into student (uid, dob, picture, major, enrollDate) values (@u, @d, @p, @m, @e)",
                        params);

                    Audit::Ins()->Log("StudentSignUp", uid);
                    return {true, "Student added successfully"};
                } catch (Exception ^ e) {
                    reader->Close();
                    db::Ins()->rollback();
                    throw e;
                } finally {
                    db::Ins()->commit();
                }
            } finally {
                if (reader != nullptr) reader->Close();
            }
        }

        ServiceReturn<IUser ^> Login(LoginUser ^ user) {
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

                if (!isUserType(uid, "student")) {
                    throw gcnew Exception("User is not a student");
                }

                db::Ins()->beginTransaction();
                try {
                    reader = db::Ins()->execute("select * from student where uid = " + Convert::ToString(uid));
                    reader->Read();
                    auto dob = reader->GetBodyDefinition("dob");
                    PictureH picture = gcnew Picture(0);
                    try {
                        auto pictureLen = reader->GetBytes(reader->GetOrdinal("picture"), 0, nullptr, 0, 0);
                        picture = gcnew Picture(pictureLen);
                        reader->GetBytes(reader->GetOrdinal("picture"), 0, picture, 0, pictureLen);
                    } catch (Exception ^ e) {
                        errorMsg(e->Message, "StudentLogin");
                        picture = gcnew Picture(0);
                    }
                    auto major = parseStrMajor(reader->GetBodyDefinition("major"));
                    auto enrollDate = reader->GetBodyDefinition("enrollDate");
                    reader->Close();

                    auto studentRes = gcnew Student{uid, fname, lname, email, dob, picture, major, enrollDate};
                    Audit::Ins()->Log("StudentLogin", uid);
                    return {true, studentRes};
                } catch (Exception ^ e) {
                    reader->Close();
                    db::Ins()->rollback();
                    errorMsg(e->Message, "StudentLogin");
                    Audit::Ins()->Log("StudentLogin", uid, e->Message);
                    return {false, nullptr};
                } finally {
                    db::Ins()->commit();
                }
            } finally {
                if (reader != nullptr) reader->Close();
            }
        }
    };

   public
    ref class FacultyService {
       private:
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
                db::Ins()->beginTransaction();
                try {
                    db::Ins()->executeNoRet(
                        "insert into user (fname, lname, email, password) values (@fn, @ln, @em, @pass)", params);

                    auto uid = db::Ins()->getCmd()->LastInsertedId;
                    params->Clear();
                    params->Add("@uid", uid);
                    params->Add("@app", appDate);
                    params->Add("@dept", parseDept(dept));
                    db::Ins()->executeNoRet("insert into faculty (uid, appDate, dept) values (@uid, @app, @dept)",
                                            params);

                    Audit::Ins()->Log("FacultySignUp", uid);
                    return {true, "Faculty added successfully"};
                } catch (Exception ^ e) {
                    reader->Close();
                    db::Ins()->rollback();
                    throw e;
                } finally {
                    db::Ins()->commit();
                }
            } finally {
                if (reader != nullptr) reader->Close();
            }
        }

        ServiceReturn<IUser ^> Login(LoginUser user) {
            ParamsH params = gcnew Params(1);
            params->Add("@em", user.email);
            MySqlDataReader ^ reader = nullptr;

            try {
                reader = db::Ins()->execute(
                    "select user.uid as uid, fname, lname, email, appDate, password, dept from user inner join faculty "
                    "on user.uid = faculty.uid where email = @em ",
                    params);
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

                Audit::Ins()->Log("FacultyLogin", uid);
                return {true, gcnew Faculty{uid, fname, lname, email, appD, dept}};
            } finally {
                if (reader != nullptr) reader->Close();
            }
        }
    };
}  // namespace icpproject