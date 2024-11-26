#include "MainForm.h"

#include "AdminLoginForm.h"
#include "Tests.h"

using namespace System;
using namespace System::Windows::Forms;

int main(cli::array<System::String ^> ^ args) {
    using namespace icpproject;
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    /*LoginServiceTest();
    CourseServiceTest();*/

    // icpproject::AdminLoginForm form;
    icpproject::MainForm form;
    Application::Run(% form);

    return 0;
}