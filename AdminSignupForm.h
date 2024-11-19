#pragma once
#include "services/LoginService.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for AdminSignUpForm
    /// </summary>
   public
    ref class AdminSignUpForm : public System::Windows::Forms::Form {
       public:
        AdminSignUpForm(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

        AdminSignUpForm(Form ^ other) {
            parentForm = other;
            InitializeComponent();
        }

       private:
        Form ^ parentForm;

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AdminSignUpForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::Button ^ signupButton;

       protected:
       private:
       private:
        System::Windows::Forms::TextBox ^ lnTB;

       private:
       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label4;

       private:
        System::Windows::Forms::TextBox ^ passwordTB;

       private:
       private:
        System::Windows::Forms::Label ^ label5;

       private:
        System::Windows::Forms::TextBox ^ emailTB;

       private:
       private:
        System::Windows::Forms::Label ^ label6;

       private:
        System::Windows::Forms::TextBox ^ fnTB;

       private:
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
            this->signupButton = (gcnew System::Windows::Forms::Button());
            this->lnTB = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->passwordTB = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->emailTB = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->fnTB = (gcnew System::Windows::Forms::TextBox());
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(212, 37);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(151, 42);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Sign Up";
            //
            // signupButton
            //
            this->signupButton->Location = System::Drawing::Point(219, 278);
            this->signupButton->Name = L"signupButton";
            this->signupButton->Size = System::Drawing::Size(136, 23);
            this->signupButton->TabIndex = 1;
            this->signupButton->Text = L"Sign Up";
            this->signupButton->UseVisualStyleBackColor = true;
            this->signupButton->Click += gcnew System::EventHandler(this, &AdminSignUpForm::signupButton_Click);
            //
            // lnTB
            //
            this->lnTB->Location = System::Drawing::Point(300, 130);
            this->lnTB->Name = L"lnTB";
            this->lnTB->Size = System::Drawing::Size(129, 20);
            this->lnTB->TabIndex = 2;
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(297, 114);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(72, 16);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Last Name";
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(166, 217);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(74, 16);
            this->label4->TabIndex = 7;
            this->label4->Text = L"Passsword";
            //
            // passwordTB
            //
            this->passwordTB->Location = System::Drawing::Point(169, 233);
            this->passwordTB->Name = L"passwordTB";
            this->passwordTB->Size = System::Drawing::Size(260, 20);
            this->passwordTB->TabIndex = 6;
            //
            // label5
            //
            this->label5->AutoSize = true;
            this->label5->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(166, 161);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(41, 16);
            this->label5->TabIndex = 9;
            this->label5->Text = L"Email";
            //
            // emailTB
            //
            this->emailTB->Location = System::Drawing::Point(169, 177);
            this->emailTB->Name = L"emailTB";
            this->emailTB->Size = System::Drawing::Size(260, 20);
            this->emailTB->TabIndex = 8;
            //
            // label6
            //
            this->label6->AutoSize = true;
            this->label6->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(166, 114);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(72, 16);
            this->label6->TabIndex = 11;
            this->label6->Text = L"First Name";
            //
            // fnTB
            //
            this->fnTB->Location = System::Drawing::Point(169, 130);
            this->fnTB->Name = L"fnTB";
            this->fnTB->Size = System::Drawing::Size(125, 20);
            this->fnTB->TabIndex = 10;
            //
            // linkLabel1
            //
            this->linkLabel1->AutoSize = true;
            this->linkLabel1->Location = System::Drawing::Point(166, 320);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(161, 13);
            this->linkLabel1->TabIndex = 12;
            this->linkLabel1->TabStop = true;
            this->linkLabel1->Text = L"Already have an account\? Login";
            this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(
                this, &AdminSignUpForm::linkLabel1_LinkClicked);
            //
            // AdminSignUpForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(596, 358);
            this->Controls->Add(this->linkLabel1);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->fnTB);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->emailTB);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->passwordTB);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->lnTB);
            this->Controls->Add(this->signupButton);
            this->Controls->Add(this->label1);
            this->Name = L"AdminSignUpForm";
            this->Text = L"AdminSignUpForm";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void linkLabel1_LinkClicked(System::Object ^ sender,
                                            System::Windows::Forms::LinkLabelLinkClickedEventArgs ^ e) {
            parentForm->Show();
            this->Close();
        }

       private:
        System::Void signupButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto adminService = gcnew AdminService();
                auto em = emailTB->Text->Trim();
                auto pass = passwordTB->Text->Trim();
                auto fname = fnTB->Text->Trim();
                auto lname = lnTB->Text->Trim();
                bool isValid = true;

                if (String::IsNullOrWhiteSpace(em)) {
                    MessageBox::Show("Email cannot be empty");
                    isValid = false;
                }

                if (String::IsNullOrWhiteSpace(pass)) {
                    MessageBox::Show("Password cannot be empty");
                    isValid = false;
                }

                if (String::IsNullOrWhiteSpace(fname)) {
                    MessageBox::Show("First name cannot be empty");
                    isValid = false;
                }

                if (String::IsNullOrWhiteSpace(lname)) {
                    MessageBox::Show("Last name cannot be empty");
                    isValid = false;
                }

                if (isValid) {
                    auto res = adminService->SignUp(SignupUser{fname, lname, em, pass});
                    System::Console::WriteLine(String::Format(
                        "First Name: {0}\nLast Name: {1}\nEmail: {2}\nPassword: {3}", fname, lname, em, pass));
                    if (res.status) {
                        MessageBox::Show(res.data);
                        parentForm->Show();
                        this->Close();
                    } else {
                        MessageBox::Show("Signed up failed");
                    }
                }

            } catch (Exception ^ e) {
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
