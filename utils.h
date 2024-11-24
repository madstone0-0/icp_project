#pragma once
#include <msclr/marshal_cppstd.h>

#include <string>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Security::Cryptography;
using namespace System::Text;
using namespace System::Text::RegularExpressions;
using STR = String ^ ;

namespace icpproject {
    using STR = String ^ ;
}

template <typename T>
public value struct ServiceReturn {
    bool status;
    T data;
};

enum class Major { CS, BA, EN, ME, EE, CE, MA };

enum class Department { CS, HM, EN, BA };

enum class Semester { S1, S2 };

inline STR parseDept(const Department& dept) {
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

inline Department parseStrDept(STR dept) {
    if (dept == "CS") return Department::CS;
    if (dept == "HM") return Department::HM;
    if (dept == "EN") return Department::EN;
    if (dept == "BA") return Department::BA;
}

inline STR parseMajor(const Major& major) {
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

inline Major parseStrMajor(STR major) {
    if (major == "CS") return Major::CS;
    if (major == "BA") return Major::BA;
    if (major == "MA") return Major::MA;
    if (major == "CA") return Major::CE;
    if (major == "EE") return Major::EE;
    if (major == "EN") return Major::EN;
}

inline STR parseSemester(const Semester& sem) {
    switch (sem) {
        case Semester::S1:
            return "S1";
            break;
        case Semester::S2:
            return "S2";
            break;
    }
}

inline Semester parseStrSemester(STR sem) {
    if (sem == "S1") return Semester::S1;
    if (sem == "S2") return Semester::S2;
}

public
interface class IUser {
    property int UID {
        int get();
        void set(int value);
    }
    property STR FirstName {
        STR get();
        void set(STR value);
    }
    property STR LastName {
        STR get();
        void set(STR value);
    }
    property STR Email {
        STR get();
        void set(STR value);
    }
};

public
value struct User : public IUser {
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

    User(int u, STR f, STR l, STR e) {
        uid = u;
        fname = f;
        lname = l;
        email = e;
    }
};

inline STR toNETString(const std::string& str) { return gcnew String(str.c_str()); }

inline std::string fromNETString(STR str) { return msclr::interop::marshal_as<std::string>(str); }

inline bool validateRegexes(STR str, List<RegularExpressions::Regex ^> ^ regexes) {
    for each (Regex ^ re in regexes) {
        if (!re->IsMatch(str)) return false;
    }
    return true;
}

inline STR getHash(STR password) {
    RIPEMD160 ^ ripemd = RIPEMD160::Create();
    cli::array<unsigned char> ^ bytes = Encoding::UTF8->GetBytes(password);
    cli::array<unsigned char> ^ hashed = ripemd->ComputeHash(bytes);
    StringBuilder ^ sb = gcnew StringBuilder("");

    for (int i = 0; i < hashed->Length; i++) sb->Append(hashed[i]);
    return sb->ToString();
}

inline bool verifyHash(STR password, STR hash) { return getHash(password)->Equals(hash); }

inline void errorMsg(STR msg, STR id = "None") {
    System::Diagnostics::Debug::WriteLine(String::Format("ID: {0} = Error: {1}", id, msg));
}

inline void infoMsg(STR msg, STR id = "None") {
    System::Diagnostics::Debug::WriteLine(String::Format("ID: {0} = Info: {1}", id, msg));
}

inline void debugMsg(STR msg, STR id = "None") {
    System::Diagnostics::Debug::WriteLine(String::Format("ID: {0} = Debug: {1}", id, msg));
}