#pragma once
#include "AdminSignUpForm.h"
#include "services/LoginService.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for AdminLoginForm
    /// </summary>
   public
    ref class AdminLoginForm : public System::Windows::Forms::Form {
       public:
        AdminLoginForm(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AdminLoginForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::TextBox ^ emailTB;

       private:
        System::Windows::Forms::TextBox ^ passwordTB;

       private:
        System::Windows::Forms::Button ^ loginButton;

       protected:
       private:
       private:
       private:
       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::LinkLabel ^ linkLabel1;

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
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->emailTB = (gcnew System::Windows::Forms::TextBox());
            this->passwordTB = (gcnew System::Windows::Forms::TextBox());
            this->loginButton = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(230, 61);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(110, 42);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Login";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            //
            // emailTB
            //
            this->emailTB->Location = System::Drawing::Point(176, 146);
            this->emailTB->Name = L"emailTB";
            this->emailTB->Size = System::Drawing::Size(193, 20);
            this->emailTB->TabIndex = 1;
            //
            // passwordTB
            //
            this->passwordTB->Location = System::Drawing::Point(176, 201);
            this->passwordTB->Name = L"passwordTB";
            this->passwordTB->Size = System::Drawing::Size(193, 20);
            this->passwordTB->TabIndex = 2;
            //
            // loginButton
            //
            this->loginButton->Location = System::Drawing::Point(207, 241);
            this->loginButton->Name = L"loginButton";
            this->loginButton->Size = System::Drawing::Size(133, 23);
            this->loginButton->TabIndex = 3;
            this->loginButton->Text = L"Login";
            this->loginButton->UseVisualStyleBackColor = true;
            this->loginButton->Click += gcnew System::EventHandler(this, &AdminLoginForm::loginButton_Click);
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(173, 127);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(41, 16);
            this->label2->TabIndex = 4;
            this->label2->Text = L"Email";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(173, 182);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(67, 16);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Password";
            //
            // linkLabel1
            //
            this->linkLabel1->AutoSize = true;
            this->linkLabel1->Location = System::Drawing::Point(177, 313);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(163, 13);
            this->linkLabel1->TabIndex = 6;
            this->linkLabel1->TabStop = true;
            this->linkLabel1->Text = L"Don\'t have an account\? Sign Up";
            this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(
                this, &AdminLoginForm::linkLabel1_LinkClicked);
            //
            // AdminLoginForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(557, 378);
            this->Controls->Add(this->linkLabel1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->loginButton);
            this->Controls->Add(this->passwordTB);
            this->Controls->Add(this->emailTB);
            this->Controls->Add(this->label1);
            this->Name = L"AdminLoginForm";
            this->Text = L"AdminLoginForm";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
       private:
        System::Void linkLabel1_LinkClicked(System::Object ^ sender,
                                            System::Windows::Forms::LinkLabelLinkClickedEventArgs ^ e) {
            Form ^ signUp = gcnew AdminSignUpForm(this);
            signUp->Show();
            this->Hide();
        }

       private:
        System::Void loginButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto adminService = gcnew AdminService();
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
                    auto res = adminService->Login(LoginUser{em, pass});
                    infoMsg("Logging in as admin");
                    debugMsg(String::Format("Email: {0}\tPassword: {1}", em, pass));
                    if (res.status) {
                        MessageBox::Show("Logged in successfully");
                        auto user = res.data;
                    } else {
                        MessageBox::Show("Log in failed");
                    }
                }

            } catch (Exception ^ e) {
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
