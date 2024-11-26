#pragma once
#include "AdminLoginForm.h"
#include "FacultyLoginForm.h"
#include "StudentLoginForm.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for ChooseLoginForm
    /// </summary>
   public
    ref class ChooseLoginForm : public System::Windows::Forms::Form {
       public:
        IChildHost ^ parent;
        ChooseLoginForm(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

        ChooseLoginForm(IChildHost ^ parent) {
            this->parent = parent;
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ChooseLoginForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Button ^ adminLogin;

       private:
        System::Windows::Forms::Button ^ studentLogin;

       private:
        System::Windows::Forms::Button ^ facultyLogin;

       protected:
       private:
       protected:
       private:
       private:
       private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void) {
            this->adminLogin = (gcnew System::Windows::Forms::Button());
            this->studentLogin = (gcnew System::Windows::Forms::Button());
            this->facultyLogin = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            //
            // adminLogin
            //
            this->adminLogin->Location = System::Drawing::Point(192, 104);
            this->adminLogin->Name = L"adminLogin";
            this->adminLogin->Size = System::Drawing::Size(75, 23);
            this->adminLogin->TabIndex = 0;
            this->adminLogin->Text = L"Admin";
            this->adminLogin->UseVisualStyleBackColor = true;
            this->adminLogin->Click += gcnew System::EventHandler(this, &ChooseLoginForm::adminLogin_Click);
            //
            // studentLogin
            //
            this->studentLogin->Location = System::Drawing::Point(192, 144);
            this->studentLogin->Name = L"studentLogin";
            this->studentLogin->Size = System::Drawing::Size(75, 23);
            this->studentLogin->TabIndex = 1;
            this->studentLogin->Text = L"Student";
            this->studentLogin->UseVisualStyleBackColor = true;
            this->studentLogin->Click += gcnew System::EventHandler(this, &ChooseLoginForm::studentLogin_Click);
            //
            // facultyLogin
            //
            this->facultyLogin->Location = System::Drawing::Point(192, 184);
            this->facultyLogin->Name = L"facultyLogin";
            this->facultyLogin->Size = System::Drawing::Size(75, 23);
            this->facultyLogin->TabIndex = 2;
            this->facultyLogin->Text = L"Faculty";
            this->facultyLogin->UseVisualStyleBackColor = true;
            this->facultyLogin->Click += gcnew System::EventHandler(this, &ChooseLoginForm::facultyLogin_Click);
            //
            // ChooseLoginForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(470, 321);
            this->ControlBox = false;
            this->Controls->Add(this->facultyLogin);
            this->Controls->Add(this->studentLogin);
            this->Controls->Add(this->adminLogin);
            this->MaximizeBox = false;
            this->Name = L"ChooseLoginForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"ChooseLoginForm";
            this->ResumeLayout(false);
        }
#pragma endregion
       private:
        System::Void adminLogin_Click(System::Object ^ sender, System::EventArgs ^ e) {
            AdminLoginForm ^ adminLoginForm = gcnew AdminLoginForm(parent);
            adminLoginForm->MdiParent = this->MdiParent;
            adminLoginForm->StartPosition = FormStartPosition::CenterScreen;
            adminLoginForm->Show();
            this->Hide();
        }

       private:
        System::Void studentLogin_Click(System::Object ^ sender, System::EventArgs ^ e) {
            StudentLoginForm ^ studentLoginForm = gcnew StudentLoginForm(parent);
            studentLoginForm->MdiParent = this->MdiParent;
            studentLoginForm->StartPosition = FormStartPosition::CenterScreen;
            studentLoginForm->Show();
            this->Hide();
        }

       private:
        System::Void facultyLogin_Click(System::Object ^ sender, System::EventArgs ^ e) {
            FacultyLoginForm ^ facultyLoginForm = gcnew FacultyLoginForm(parent);
            facultyLoginForm->MdiParent = this->MdiParent;
            facultyLoginForm->StartPosition = FormStartPosition::CenterScreen;
            facultyLoginForm->Show();
            this->Hide();
        }
    };
}  // namespace icpproject
