#pragma once
#include <iostream>
#include <string>

#include "../db/Database.h"
#include "../utils.h"

namespace icpproject {
    using namespace std;

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

   public
    ref class AdminService {
       public:
        ServiceReturn<STR> SignUp(SignupUser user) {
            ParamsH params = gcnew Params(1);
            params->Add("@em", user.email);
            MySqlDataReader ^ reader = db::Ins()->execute("select uid from user where email = @em", params);

            if (reader->HasRows) {
                reader->Close();
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
            db::Ins()->executeNoRet("insert into user (fname, lname, email, password) values (@fn, @ln, @em, @pass)",
                                    params);

            auto uid = db::Ins()->getCmd()->LastInsertedId;
            params->Clear();
            params->Add("@u", Convert::ToString(uid));
            db::Ins()->executeNoRet("insert into admin (uid) values (@u)", params);

            return {true, "Admin added successfully"};
        }

        ServiceReturn<Admin ^> Login(LoginUser user) {
            ParamsH params = gcnew Params(1);
            params->Add("@em", user.email);
            MySqlDataReader ^ reader = db::Ins()->execute("select * from user where email = @em", params);

            if (!reader->HasRows) {
                throw gcnew Exception("User not found");
            }
            reader->Read();
            auto passhash = reader->GetBodyDefinition("password");

            if (!verifyHash(user.password, passhash)) {
                reader->Close();
                throw gcnew Exception("Incorrect password");
            }
            // Convert to integer
            auto uid = Convert::ToInt16(reader->GetBodyDefinition("uid"));
            auto fname = reader->GetBodyDefinition("fname");
            auto lname = reader->GetBodyDefinition("lname");
            auto email = reader->GetBodyDefinition("email");
            reader->Close();

            return {true, gcnew Admin{uid, fname, lname, email}};
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

       public:
        ServiceReturn<STR> SignUp(SignupStudent ^ user) {
            ParamsH params = gcnew Params(1);
            params->Add("@em", user->email);
            MySqlDataReader ^ reader = db::Ins()->execute("select uid from user where email = @em", params);

            if (reader->HasRows) {
                reader->Close();
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
            db::Ins()->executeNoRet("insert into user (fname, lname, email, password) values (@fn, @ln, @em, @pass)",
                                    params);

            auto uid = db::Ins()->getCmd()->LastInsertedId;
            cli::array<unsigned char> ^ buff;
            try {
                auto fs = gcnew System::IO::FileStream(picturePath, IO::FileMode::Open, IO::FileAccess::Read);
                auto binReader = gcnew IO::BinaryReader(fs);
                buff = binReader->ReadBytes(fs->Length);
            } catch (Exception ^ e) {
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
        }

        ServiceReturn<Admin ^> Login(LoginUser ^ user) {
            ParamsH params = gcnew Params(1);
            params->Add("@em", user->email);
            MySqlDataReader ^ reader = db::Ins()->execute("select * from user where email = @em", params);

            if (!reader->HasRows) {
                reader->Close();
                throw gcnew Exception("User not found");
            }
            reader->Read();
            auto passhash = reader->GetBodyDefinition("password");

            if (!verifyHash(user->password, passhash)) {
                reader->Close();
                throw gcnew Exception("Invalid password");
            }
            // Convert to integer
            auto uid = Convert::ToInt16(reader->GetBodyDefinition("uid"));
            auto fname = reader->GetBodyDefinition("fname");
            auto lname = reader->GetBodyDefinition("lname");
            auto email = reader->GetBodyDefinition("email");
            reader->Close();

            auto adminRes = gcnew Admin{uid, fname, lname, email};
            return {true, adminRes};
        }
    };
}  // namespace icpproject