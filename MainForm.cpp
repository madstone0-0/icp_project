#include "MainForm.h"

#include "./AdminSignupForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<System::String ^> ^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    icpproject::AdminSignupForm form;
    Application::Run(% form);

    return 0;
}