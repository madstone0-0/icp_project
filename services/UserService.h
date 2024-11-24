#pragma once
#include "../utils.h"

namespace icpproject {
    using namespace System;
    using namespace System::Data;
    using namespace System::Collections::Generic;

    /*interface class IUserService {

    };*/

    ref class UserService {
       public:
        UserService(IUser ^ u) { user = u; }

       protected:
        IUser ^ user;
    };
}  // namespace icpproject