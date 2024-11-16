#pragma once
#include <msclr/marshal_cppstd.h>

#include <string>

namespace icpproject {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Security::Cryptography;
    using namespace System::Text;
    using namespace System::Text::RegularExpressions;
    using STR = String ^ ;

    STR toNETString(const std::string& str) { return gcnew String(str.c_str()); }

    std::string fromNETString(STR str) { return msclr::interop::marshal_as<std::string>(str); }

    bool validateRegexes(STR str, List<RegularExpressions::Regex ^> ^ regexes) {
        for each (Regex ^ re in regexes) {
            if (!re->IsMatch(str)) return false;
        }
        return true;
    }

    STR getHash(STR password) {
        RIPEMD160 ^ ripemd = RIPEMD160::Create();
        cli::array<unsigned char> ^ bytes = Encoding::UTF8->GetBytes(password);
        cli::array<unsigned char> ^ hashed = ripemd->ComputeHash(bytes);
        StringBuilder ^ sb = gcnew StringBuilder("");

        for (int i = 0; i < hashed->Length; i++) sb->Append(hashed[i]);
        return sb->ToString();
    }

    bool verifyHash(STR password, STR hash) { return getHash(password)->Equals(hash); }
}  // namespace icpproject