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

using PreReqList = List<System::Int64>;

namespace icpproject {
    using STR = String ^ ;
}

template <typename T>
public value struct ServiceReturn {
    bool status;
    T data;
};

enum class Major { CS, BA, EN, ME, EE, CE, MA, MI };

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

inline STR parseDept(Department dept, bool pretty = false) {
    switch (dept) {
        case Department::CS:
            if (pretty) return "Computer Science";
            return "CS";
            break;
        case Department::HM:
            if (pretty) return "Humanities";
            return "HM";
            break;
        case Department::EN:
            if (pretty) return "Engineering";
            return "EN";
            break;
        case Department::BA:
            if (pretty) return "Business Administration";
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

inline STR parseMajor(Major major, bool pretty = false) {
    switch (major) {
        case Major::CS:
            if (pretty) return "Computer Science";
            return "CS";
            break;
        case Major::BA:
            if (pretty) return "Business Administration";
            return "BA";
            break;
        case Major::MA:
            if (pretty) return "Mechatronic Engineering";
            return "MA";
            break;
        case Major::CE:
            if (pretty) return "Computer Engineering";
            return "CE";
            break;
        case Major::ME:
            if (pretty) return "Mechanical Engineering";
            return "ME";
            break;
        case Major::EE:
            if (pretty) return "Electrical Engineering";
            return "EE";
            break;
        case Major::EN:
            if (pretty) return "Economics";
            return "EN";
            break;
        case Major::MI:
            if (pretty) return "Management Information Systems";
            return "MI";
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
    if (major == "ME") return Major::ME;
    if (major == "MI") return Major::MI;
}

inline STR parseSemester(Semester sem) {
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

inline double gradeToCredits(Grade grade) {
    switch (grade) {
        case Grade::A_plus:
            return 4.0;
            break;
        case Grade::A:
            return 4.0;
            break;
        case Grade::B:
            return 3.0;
            break;
        case Grade::B_plus:
            return 3.5;
            break;
        case Grade::C:
            return 2.0;
            break;
        case Grade::C_plus:
            return 2.5;
            break;
        case Grade::D:
            return 1.0;
            break;
        case Grade::D_plus:
            return 1.5;
            break;
        case Grade::E:
            return 0.0;
            break;
        case Grade::E_plus:
            return 0.0;
            break;
        case Grade::F_plus:
            return 0.0;
            break;
        case Grade::F:
            return 0.0;
            break;
        case Grade::NG:
            return 0.0;
            break;
    }
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
    property IUser ^
        user {
            IUser ^ get();
            void set(IUser ^ value);
        }

        void
        showChooseForm();
};

value struct ScheduleItem : public IComparable<ScheduleItem> {
    long long scid;
    STR cname;
    DateTime starttime;
    DateTime endtime;
    Day day;

    virtual int CompareTo(ScheduleItem other) { return starttime.CompareTo(other.starttime); }

    ScheduleItem(long long s, STR c, DateTime st, DateTime et, Day d) {
        scid = s;
        cname = c;
        starttime = st;
        endtime = et;
        day = d;
    }
};

// using ScheduleMap = Dictionary<Day, List<ScheduleItem> ^>;
using ScheduleMap = SortedDictionary<Day, List<ScheduleItem> ^>;

template <typename Data, typename Extra>
value struct DataWithExtra {
    Data data;
    Extra extra;

    DataWithExtra(Data d, Extra e) {
        data = d;
        extra = e;
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

public
value struct Student : public IUser {
    int uid;
    STR fname;
    STR lname;
    STR email;
    STR dob;
    PictureH picture;
    Major major;
    STR enrollDate;

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

value struct NewCourse {
    STR cname;
    double credits;
    Semester sem;
    int capacity;
    PreReqList ^ prereqs;

    NewCourse(STR c, double cr, Semester s, int cap, PreReqList ^ p) {
        cname = c;
        credits = cr;
        sem = s;
        capacity = cap;
        prereqs = p;
    }

    NewCourse(STR c, double cr, Semester s, int cap) {
        cname = c;
        credits = cr;
        sem = s;
        capacity = cap;
        prereqs = gcnew PreReqList(0);
    }

    NewCourse(STR c, double cr, Semester s) {
        cname = c;
        credits = cr;
        sem = s;
        capacity = 40;
        prereqs = gcnew PreReqList(0);
    }
};

value struct Course {
    int cid;
    STR cname;
    double credits;
    Semester sem;
    int capacity;
    PreReqList ^ prereqs;

    operator STR() { return cname; }

    Course(int c, STR cn, double cr, Semester s, int cap, PreReqList ^ p) {
        cid = c;
        cname = cn;
        credits = cr;
        sem = s;
        capacity = cap;
        prereqs = p;
    }

    Course(int c, STR cn, double cr, Semester s, int cap) {
        cid = c;
        cname = cn;
        credits = cr;
        sem = s;
        capacity = cap;
        prereqs = gcnew PreReqList(0);
    }
};

inline STR formatDateTimeAsMySQLDate(DateTime dt) { return dt.ToString("yyyy-MM-dd"); }

inline STR formatDateTimeAsMySQLTime(DateTime dt) { return dt.ToString("HH:mm:ss"); }

inline STR toNETString(const std::string& str) { return gcnew String(str.c_str()); }

inline std::string fromNETString(STR str) { return msclr::interop::marshal_as<std::string>(str); }

inline bool validateRegexes(STR str, List<RegularExpressions::Regex ^> ^ regexes) {
    for each (Regex ^ re in regexes) {
        if (!re->IsMatch(str)) return false;
    }
    return true;
}

inline bool validateEmail(STR email) {
    List<Regex ^> ^ regexes = gcnew List<Regex ^>(0);
    regexes->Add(gcnew Regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$"));
    return validateRegexes(email, regexes);
}

inline bool validatePassword(STR password) {
    List<Regex ^> ^ regexes = gcnew List<Regex ^>(0);
    regexes->Add(gcnew Regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[^\\da-zA-Z]).{8,}$"));
    return validateRegexes(password, regexes);
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