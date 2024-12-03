#pragma once
#include "services/LoginService.h"
#include "utils.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for FacultySignUpForm
    /// </summary>
   public
    ref class FacultySignUpForm : public System::Windows::Forms::Form {
       private:
        Form ^ parent;
        FacultyService ^ service;

       public:
        FacultySignUpForm(Form ^ parent) {
            this->parent = parent;
            service = gcnew FacultyService();
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~FacultySignUpForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::LinkLabel ^ linkLabel2;

       protected:
       private:
        System::Windows::Forms::LinkLabel ^ linkLabel1;

       private:
        System::Windows::Forms::Label ^ label6;

       private:
        System::Windows::Forms::TextBox ^ fnTB;

       private:
        System::Windows::Forms::Label ^ label5;

       private:
        System::Windows::Forms::TextBox ^ emailTB;

       private:
        System::Windows::Forms::Label ^ label4;

       private:
        System::Windows::Forms::TextBox ^ passwordTB;

       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::TextBox ^ lnTB;

       private:
        System::Windows::Forms::Button ^ signupButton;

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::ComboBox ^ deptBox;

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
            this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->fnTB = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->emailTB = (gcnew System::Windows::Forms::TextBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->passwordTB = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->lnTB = (gcnew System::Windows::Forms::TextBox());
            this->signupButton = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->deptBox = (gcnew System::Windows::Forms::ComboBox());
            this->SuspendLayout();
            //
            // linkLabel2
            //
            this->linkLabel2->AutoSize = true;
            this->linkLabel2->Location = System::Drawing::Point(171, 338);
            this->linkLabel2->Name = L"linkLabel2";
            this->linkLabel2->Size = System::Drawing::Size(48, 13);
            this->linkLabel2->TabIndex = 25;
            this->linkLabel2->TabStop = true;
            this->linkLabel2->Text = L"Go back";
            this->linkLabel2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            //
            // linkLabel1
            //
            this->linkLabel1->AutoSize = true;
            this->linkLabel1->Location = System::Drawing::Point(171, 316);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(161, 13);
            this->linkLabel1->TabIndex = 24;
            this->linkLabel1->TabStop = true;
            this->linkLabel1->Text = L"Already have an account\? Login";
            this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(
                this, &FacultySignUpForm::linkLabel1_LinkClicked);
            //
            // label6
            //
            this->label6->AutoSize = true;
            this->label6->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(173, 81);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(72, 16);
            this->label6->TabIndex = 23;
            this->label6->Text = L"First Name";
            //
            // fnTB
            //
            this->fnTB->Location = System::Drawing::Point(176, 97);
            this->fnTB->Name = L"fnTB";
            this->fnTB->Size = System::Drawing::Size(125, 20);
            this->fnTB->TabIndex = 22;
            //
            // label5
            //
            this->label5->AutoSize = true;
            this->label5->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(173, 128);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(41, 16);
            this->label5->TabIndex = 21;
            this->label5->Text = L"Email";
            //
            // emailTB
            //
            this->emailTB->Location = System::Drawing::Point(176, 144);
            this->emailTB->Name = L"emailTB";
            this->emailTB->Size = System::Drawing::Size(260, 20);
            this->emailTB->TabIndex = 20;
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(173, 184);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(74, 16);
            this->label4->TabIndex = 19;
            this->label4->Text = L"Passsword";
            //
            // passwordTB
            //
            this->passwordTB->Location = System::Drawing::Point(176, 200);
            this->passwordTB->Name = L"passwordTB";
            this->passwordTB->Size = System::Drawing::Size(260, 20);
            this->passwordTB->TabIndex = 18;
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(304, 81);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(72, 16);
            this->label2->TabIndex = 17;
            this->label2->Text = L"Last Name";
            //
            // lnTB
            //
            this->lnTB->Location = System::Drawing::Point(307, 97);
            this->lnTB->Name = L"lnTB";
            this->lnTB->Size = System::Drawing::Size(129, 20);
            this->lnTB->TabIndex = 16;
            //
            // signupButton
            //
            this->signupButton->Location = System::Drawing::Point(224, 280);
            this->signupButton->Name = L"signupButton";
            this->signupButton->Size = System::Drawing::Size(136, 23);
            this->signupButton->TabIndex = 15;
            this->signupButton->Text = L"Sign Up";
            this->signupButton->UseVisualStyleBackColor = true;
            this->signupButton->Click += gcnew System::EventHandler(this, &FacultySignUpForm::signupButton_Click);
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(222, 23);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(151, 42);
            this->label1->TabIndex = 14;
            this->label1->Text = L"Sign Up";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(176, 232);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(77, 16);
            this->label3->TabIndex = 26;
            this->label3->Text = L"Department";
            this->label3->Click += gcnew System::EventHandler(this, &FacultySignUpForm::label3_Click);
            //
            // deptBox
            //
            this->deptBox->FormattingEnabled = true;
            this->deptBox->Location = System::Drawing::Point(176, 248);
            this->deptBox->Name = L"deptBox";
            this->deptBox->Size = System::Drawing::Size(256, 21);
            this->deptBox->TabIndex = 27;
            //
            // FacultySignUpForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(614, 359);
            this->ControlBox = false;
            this->Controls->Add(this->deptBox);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->linkLabel2);
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
            this->Name = L"FacultySignUpForm";
            this->Text = L"FacultySignUpForm";
            this->Load += gcnew System::EventHandler(this, &FacultySignUpForm::FacultySignUpForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void label3_Click(System::Object ^ sender, System::EventArgs ^ e) {}

       private:
        System::Void FacultySignUpForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
                passwordTB->UseSystemPasswordChar = true;
                for (int i{}; i < 4; i++) deptBox->Items->Add(parseDept(static_cast<Department>(i), true));
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void linkLabel1_LinkClicked(System::Object ^ sender,
                                            System::Windows::Forms::LinkLabelLinkClickedEventArgs ^ e) {
            try {
                parent->Show();
                this->Close();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void signupButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto fname = trim(fnTB->Text);
                auto email = trim(emailTB->Text);
                auto pass = trim(passwordTB->Text);
                auto lname = trim(lnTB->Text);
                auto dept = static_cast<Department>(deptBox->SelectedIndex);
                auto checked = gcnew List<STR>(0);
                checked->Add(fname);
                checked->Add(lname);
                checked->Add(email);
                checked->Add(pass);
                if (isAnyEmpty(checked)) {
                    MessageBox::Show("All fields are required");
                    return;
                }

                if (!validateEmail(email)) {
                    MessageBox::Show("Invalid email");
                    return;
                }

                if (!validatePassword(pass)) {
                    MessageBox::Show(
                        "Password must be at least 8 characters long, including one uppercase letter, one lowercase "
                        "letter, one digit, and one special character.");
                    return;
                }

                auto res = service->SignUp(
                    SignupFaculty{fname, lname, email, pass, formatDateTimeAsMySQLDate(DateTime::Now), dept});

                if (!res.status) {
                    MessageBox::Show("Sign up failed");
                    return;
                }
                MessageBox::Show("Sign up successful");
                parent->Show();
                this->Close();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
