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
    /// Summary for SignupForm
    /// </summary>
   public
    ref class AdminSignupForm : public System::Windows::Forms::Form {
       public:
        AdminSignupForm(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AdminSignupForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::TextBox ^ fnameInputBox;

       private:
        System::Windows::Forms::TextBox ^ lnameInputBox;

       private:
        System::Windows::Forms::TextBox ^ emailInputBox;

       private:
        System::Windows::Forms::TextBox ^ pswdInputBox;

       private:
        System::Windows::Forms::Button ^ signUpButton;

       protected:
       private:
       private:
       private:
       private:
       private:
       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Label ^ label4;

       private:
        System::Windows::Forms::Label ^ label5;

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
            this->fnameInputBox = (gcnew System::Windows::Forms::TextBox());
            this->lnameInputBox = (gcnew System::Windows::Forms::TextBox());
            this->emailInputBox = (gcnew System::Windows::Forms::TextBox());
            this->pswdInputBox = (gcnew System::Windows::Forms::TextBox());
            this->signUpButton = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(241, 40);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(151, 42);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Sign Up";
            //
            // fnameInputBox
            //
            this->fnameInputBox->Location = System::Drawing::Point(201, 116);
            this->fnameInputBox->Name = L"fnameInputBox";
            this->fnameInputBox->Size = System::Drawing::Size(113, 20);
            this->fnameInputBox->TabIndex = 1;
            //
            // lnameInputBox
            //
            this->lnameInputBox->Location = System::Drawing::Point(315, 116);
            this->lnameInputBox->Name = L"lnameInputBox";
            this->lnameInputBox->Size = System::Drawing::Size(112, 20);
            this->lnameInputBox->TabIndex = 2;
            //
            // emailInputBox
            //
            this->emailInputBox->Location = System::Drawing::Point(201, 165);
            this->emailInputBox->Name = L"emailInputBox";
            this->emailInputBox->Size = System::Drawing::Size(226, 20);
            this->emailInputBox->TabIndex = 3;
            //
            // pswdInputBox
            //
            this->pswdInputBox->Location = System::Drawing::Point(201, 215);
            this->pswdInputBox->Name = L"pswdInputBox";
            this->pswdInputBox->Size = System::Drawing::Size(226, 20);
            this->pswdInputBox->TabIndex = 4;
            //
            // signUpButton
            //
            this->signUpButton->Location = System::Drawing::Point(201, 256);
            this->signUpButton->Name = L"signUpButton";
            this->signUpButton->Size = System::Drawing::Size(226, 23);
            this->signUpButton->TabIndex = 5;
            this->signUpButton->Text = L"Sign Up";
            this->signUpButton->UseVisualStyleBackColor = true;
            this->signUpButton->Click += gcnew System::EventHandler(this, &AdminSignupForm::signUpButton_Click);
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(198, 100);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(57, 13);
            this->label2->TabIndex = 6;
            this->label2->Text = L"First Name";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(369, 100);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(58, 13);
            this->label3->TabIndex = 7;
            this->label3->Text = L"Last Name";
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(198, 149);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(32, 13);
            this->label4->TabIndex = 8;
            this->label4->Text = L"Email";
            //
            // label5
            //
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(198, 199);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(53, 13);
            this->label5->TabIndex = 9;
            this->label5->Text = L"Password";
            //
            // AdminSignupForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(665, 360);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->signUpButton);
            this->Controls->Add(this->pswdInputBox);
            this->Controls->Add(this->emailInputBox);
            this->Controls->Add(this->lnameInputBox);
            this->Controls->Add(this->fnameInputBox);
            this->Controls->Add(this->label1);
            this->Name = L"AdminSignupForm";
            this->Text = L"SignupForm";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        AdminService ^ loginService = gcnew AdminService();
        List<RegularExpressions::Regex ^> ^ emailRegex = gcnew List<RegularExpressions::Regex ^>(1);
        List<RegularExpressions::Regex ^> ^ passwordRegex = gcnew List<RegularExpressions::Regex ^>(1);

        System::Void signUpButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
            auto fname = fnameInputBox->Text->Trim();
            auto lname = lnameInputBox->Text->Trim();
            auto email = emailInputBox->Text->Trim();
            auto password = pswdInputBox->Text->Trim();
            List<STR> ^ fList = gcnew List<STR>(4);
            fList->Add(fname);
            fList->Add(lname);
            fList->Add(email);
            fList->Add(password);

            emailRegex->Add(gcnew Regex{"^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z.]{2,6}$"});
            passwordRegex->Add(gcnew Regex{".{8,}"});
            // passwordRegex->Add(gcnew Regex{"[A-Z]"});
            // passwordRegex->Add(gcnew Regex{"\d{3,}"});
            // passwordRegex->Add(gcnew Regex{"[!@#$%^&*()\-_=+\|{};:/?.>]"});

            for each (STR f in fList) {
                if (String::IsNullOrWhiteSpace(f)) {
                    MessageBox::Show("All fields should be filled");
                    return;
                }
            }

            if (!validateRegexes(email, emailRegex)) {
                MessageBox::Show("Invalid email");
                return;
            }

            if (!validateRegexes(password, passwordRegex)) {
                MessageBox::Show("Invalid password");
                return;
            }

            try {
                SignupUser ^ admin = gcnew SignupUser{fname, lname, email, password};
                auto res = loginService->SignUp(admin);

                if (!res.status) {
                    MessageBox::Show("An error occured");
                    return;
                }

                MessageBox::Show(res.data);
            } catch (Exception ^ e) {
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
