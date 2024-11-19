#pragma once
#include <msclr/marshal_cppstd.h>

#include <string>

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Security::Cryptography;
using namespace System::Text;
using namespace System::Text::RegularExpressions;
using STR = String ^ ;

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