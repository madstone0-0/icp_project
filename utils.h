#pragma once
#include <msclr/marshal_cppstd.h>

#include <string>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Security::Cryptography;
using namespace System::Text;
using namespace System::Text::RegularExpressions;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;

using STR = String ^ ;

using Picture = cli::array<Byte>;
using PictureH = Picture ^ ;

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

enum class Grade { A_plus, A, B, B_plus, C, C_plus, D, D_plus, E, E_plus, F_plus, F, NG };

inline STR trim(STR str) { return str->Trim(); }
inline bool isEmpty(STR str) { return String::IsNullOrWhiteSpace(str); }

inline bool isAnyEmpty(List<STR> ^ strs) {
    for each (STR str in strs) {
        if (isEmpty(str)) return true;
    }
    return false;
}

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

inline STR parseGrade(const Grade& grade, bool pretty = false) {
    switch (grade) {
        case Grade::A_plus:
            return "A+";
            break;
        case Grade::A:
            return "A";
            break;
        case Grade::B:
            return "B";
            break;
        case Grade::B_plus:
            return "B+";
            break;
        case Grade::C:
            return "C";
            break;
        case Grade::C_plus:
            return "C+";
            break;
        case Grade::D:
            return "D";
            break;
        case Grade::D_plus:
            return "D+";
            break;
        case Grade::E:
            return "E";
            break;
        case Grade::E_plus:
            return "E+";
            break;
        case Grade::F_plus:
            return "F+";
            break;
        case Grade::F:
            return "F";
            break;
        case Grade::NG:
            if (pretty) return "Not Graded";
            return "NG";
            break;
    }
}

inline Grade parseStrGrade(STR grade) {
    if (grade == "A+") return Grade::A_plus;
    if (grade == "A") return Grade::A;
    if (grade == "B") return Grade::B;
    if (grade == "B+") return Grade::B_plus;
    if (grade == "C") return Grade::C;
    if (grade == "C+") return Grade::C_plus;
    if (grade == "D") return Grade::D;
    if (grade == "D+") return Grade::D_plus;
    if (grade == "E") return Grade::E;
    if (grade == "E+") return Grade::E_plus;
    if (grade == "F+") return Grade::F_plus;
    if (grade == "F") return Grade::F;
    if (grade == "NG" || grade == "Not Graded") return Grade::NG;
}

inline STR parseDay(Day day) {
    switch (day) {
        case Day::Monday:
            return "Monday";
            break;
        case Day::Tuesday:
            return "Tuesday";
            break;
        case Day::Wednesday:
            return "Wednesday";
            break;
        case Day::Thursday:
            return "Thursday";
            break;
        case Day::Friday:
            return "Friday";
            break;
    }
}

inline System::Windows::Forms::Day parseStrDay(STR day) {
    if (day == "Monday") return Day::Monday;
    if (day == "Tuesday") return Day::Tuesday;
    if (day == "Wednesday") return Day::Wednesday;
    if (day == "Thursday") return Day::Thursday;
    if (day == "Friday") return Day::Friday;
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
interface class IChildHost {
    property IUser ^ user {
        IUser ^ get();
        void set(IUser ^ value);
    }
};

public
value struct Faculty : public IUser {
    long long uid;
    STR fname;
    STR lname;
    STR email;
    STR appDate;
    Department dept;

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

inline STR formatDateTimeAsMySQLTime(DateTime dt) { return dt.ToString("HH:mm:ss"); }

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