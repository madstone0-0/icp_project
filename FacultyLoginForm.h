#pragma once
#include "./utils.h"
#include "services/LoginService.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for FacultyLoginForm
    /// </summary>
   public
    ref class FacultyLoginForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       public:
        FacultyLoginForm(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

        FacultyLoginForm(IChildHost ^ parent) {
            this->parent = parent;
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~FacultyLoginForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Button ^ button1;

       protected:
       private:
        System::Windows::Forms::LinkLabel ^ linkLabel1;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Button ^ loginButton;

       private:
        System::Windows::Forms::TextBox ^ passwordTB;

       private:
        System::Windows::Forms::TextBox ^ emailTB;

       private:
        System::Windows::Forms::Label ^ label1;

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
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->loginButton = (gcnew System::Windows::Forms::Button());
            this->passwordTB = (gcnew System::Windows::Forms::TextBox());
            this->emailTB = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            //
            // button1
            //
            this->button1->Location = System::Drawing::Point(282, 237);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(94, 23);
            this->button1->TabIndex = 15;
            this->button1->Text = L"Cancel";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &FacultyLoginForm::button1_Click);
            //
            // linkLabel1
            //
            this->linkLabel1->AutoSize = true;
            this->linkLabel1->Location = System::Drawing::Point(184, 309);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(163, 13);
            this->linkLabel1->TabIndex = 14;
            this->linkLabel1->TabStop = true;
            this->linkLabel1->Text = L"Don\'t have an account\? Sign Up";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(180, 178);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(67, 16);
            this->label3->TabIndex = 13;
            this->label3->Text = L"Password";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(180, 123);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(41, 16);
            this->label2->TabIndex = 12;
            this->label2->Text = L"Email";
            //
            // loginButton
            //
            this->loginButton->Location = System::Drawing::Point(183, 237);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(93, 23);
            this->loginButton->TabIndex = 11;
            this->loginButton->Text = L"Login";
            this->loginButton->UseVisualStyleBackColor = true;
            this->loginButton->Click += gcnew System::EventHandler(this, &FacultyLoginForm::loginButton_Click);
            //
            // passwordTB
            //
            this->passwordTB->Location = System::Drawing::Point(183, 197);
            this->passwordTB->Name = L"passwordTB";
            this->passwordTB->Size = System::Drawing::Size(193, 20);
            this->passwordTB->TabIndex = 10;
            //
            // emailTB
            //
            this->emailTB->Location = System::Drawing::Point(183, 142);
            this->emailTB->Name = L"emailTB";
            this->emailTB->Size = System::Drawing::Size(193, 20);
            this->emailTB->TabIndex = 9;
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(237, 57);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(110, 42);
            this->label1->TabIndex = 8;
            this->label1->Text = L"Login";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            //
            // FacultyLoginForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(557, 378);
            this->ControlBox = false;
            this->Controls->Add(this->button1);
            this->Controls->Add(this->linkLabel1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->loginButton);
            this->Controls->Add(this->passwordTB);
            this->Controls->Add(this->emailTB);
            this->Controls->Add(this->label1);
            this->Name = L"FacultyLoginForm";
            this->Text = L"FacultyLoginForm";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void loginButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto facultyService = gcnew FacultyService();
                auto em = emailTB->Text->Trim();
                auto pass = passwordTB->Text->Trim();
                bool isValid = true;

                if (String::IsNullOrWhiteSpace(em)) {
                    MessageBox::Show("Email cannot be empty");
                    isValid = false;
                }

                if (String::IsNullOrWhiteSpace(pass)) {
                    MessageBox::Show("Password cannot be empty");
                    isValid = false;
                }

                if (isValid) {
                    auto res = facultyService->Login(LoginUser{em, pass});
                    infoMsg("Logging in as admin");
                    debugMsg(String::Format("Email: {0}\tPassword: {1}", em, pass));
                    if (res.status) {
                        MessageBox::Show("Logged in successfully");
                        auto user = res.data;
                        parent->user = user;
                        this->Close();
                    } else {
                        MessageBox::Show("Log in failed");
                    }
                }

            } catch (Exception ^ e) {
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e) {
            this->Close();
            parent->showChooseForm();
        }
    };
}  // namespace icpproject
