#include "MainForm.h"

#include "AdminLoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<System::String ^> ^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    icpproject::AdminLoginForm form;
    // icpproject::MainForm form;
    Application::Run(% form);

    return 0;
}