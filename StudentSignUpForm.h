#pragma once
#include "./utils.h"
#include "services/UserService.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for StudentSignUpForm
    /// </summary>
   public
    ref class StudentSignUpForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       public:
        StudentSignUpForm(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

        StudentSignUpForm(IChildHost ^ parent) {
            this->parent = parent;
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~StudentSignUpForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Button ^ button1;
        System::Windows::Forms::Button ^ signUpButton;
        System::Windows::Forms::Label ^ label1;
        System::Windows::Forms::Label ^ label2;
        System::Windows::Forms::Label ^ label3;
        System::Windows::Forms::Label ^ label4;
        System::Windows::Forms::Label ^ label5;
        System::Windows::Forms::TextBox ^ firstNameTB;
        System::Windows::Forms::TextBox ^ lastNameTB;
        System::Windows::Forms::TextBox ^ emailTB;
        System::Windows::Forms::TextBox ^ passwordTB;
        System::Windows::Forms::TextBox ^ confirmPasswordTB;
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
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->signUpButton = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->firstNameTB = (gcnew System::Windows::Forms::TextBox());
            this->lastNameTB = (gcnew System::Windows::Forms::TextBox());
            this->emailTB = (gcnew System::Windows::Forms::TextBox());
            this->passwordTB = (gcnew System::Windows::Forms::TextBox());
            this->confirmPasswordTB = (gcnew System::Windows::Forms::TextBox());
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->SuspendLayout();

            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(282, 309);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(94, 23);
            this->button1->TabIndex = 15;
            this->button1->Text = L"Cancel";
            this->button1->UseVisualStyleBackColor = true;
            
            // 
            // signUpButton
            // 
            this->signUpButton->Location = System::Drawing::Point(183, 309);
            this->signUpButton->Name = L"signUpButton";
            this->signUpButton->Size = System::Drawing::Size(93, 23);
            this->signUpButton->TabIndex = 14;
            this->signUpButton->Text = L"Sign Up";
            this->signUpButton->UseVisualStyleBackColor = true;
            this->signUpButton->Click += gcnew System::EventHandler(this, &StudentSignUpForm::signUpButton_Click);

            // 
            // label1 (First Name)
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(180, 57);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(60, 13);
            this->label1->TabIndex = 8;
            this->label1->Text = L"First Name";
            
            // 
            // label2 (Last Name)
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(180, 97);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(61, 13);
            this->label2->TabIndex = 9;
            this->label2->Text = L"Last Name";

            // 
            // label3 (Email)
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(180, 137);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(35, 13);
            this->label3->TabIndex = 10;
            this->label3->Text = L"Email";
            
            // 
            // label4 (Password)
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(180, 177);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(53, 13);
            this->label4->TabIndex = 11;
            this->label4->Text = L"Password";
            
            // 
            // label5 (Confirm Password)
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(180, 217);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(89, 13);
            this->label5->TabIndex = 12;
            this->label5->Text = L"Confirm Password";

            // 
            // firstNameTB
            // 
            this->firstNameTB->Location = System::Drawing::Point(183, 73);
            this->firstNameTB->Name = L"firstNameTB";
            this->firstNameTB->Size = System::Drawing::Size(193, 20);
            this->firstNameTB->TabIndex = 13;

            // 
            // lastNameTB
            // 
            this->lastNameTB->Location = System::Drawing::Point(183, 113);
            this->lastNameTB->Name = L"lastNameTB";
            this->lastNameTB->Size = System::Drawing::Size(193, 20);
            this->lastNameTB->TabIndex = 14;

            // 
            // emailTB
            // 
            this->emailTB->Location = System::Drawing::Point(183, 153);
            this->emailTB->Name = L"emailTB";
            this->emailTB->Size = System::Drawing::Size(193, 20);
            this->emailTB->TabIndex = 15;

            // 
            // passwordTB
            // 
            this->passwordTB->Location = System::Drawing::Point(183, 193);
            this->passwordTB->Name = L"passwordTB";
            this->passwordTB->Size = System::Drawing::Size(193, 20);
            this->passwordTB->TabIndex = 16;

            // 
            // confirmPasswordTB
            // 
            this->confirmPasswordTB->Location = System::Drawing::Point(183, 233);
            this->confirmPasswordTB->Name = L"confirmPasswordTB";
            this->confirmPasswordTB->Size = System::Drawing::Size(193, 20);
            this->confirmPasswordTB->TabIndex = 17;

            // 
            // linkLabel1
            // 
            this->linkLabel1->AutoSize = true;
            this->linkLabel1->Location = System::Drawing::Point(184, 267);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(156, 13);
            this->linkLabel1->TabIndex = 18;
            this->linkLabel1->TabStop = true;
            this->linkLabel1->Text = L"Already have an account? Login";
            
            // 
            // StudentSignUpForm
            // 
            this->ClientSize = System::Drawing::Size(478, 358);
            this->Controls->Add(this->linkLabel1);
            this->Controls->Add(this->confirmPasswordTB);
            this->Controls->Add(this->passwordTB);
            this->Controls->Add(this->emailTB);
            this->Controls->Add(this->lastNameTB);
            this->Controls->Add(this->firstNameTB);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->signUpButton);
            this->Controls->Add(this->button1);
            this->Name = L"StudentSignUpForm";
            this->Text = L"Student Sign Up";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

       private:
        // Event handler for signUpButton click
        void signUpButton_Click(System::Object^ sender, System::EventArgs^ e) {
            // Handle sign-up logic here, including validation and calling registration services
            String^ firstName = firstNameTB->Text;
            String^ lastName = lastNameTB->Text;
            String^ email = emailTB->Text;
            String^ password = passwordTB->Text;
            String^ confirmPassword = confirmPasswordTB->Text;

            // You can now implement registration logic or call RegistrationService here
        }
    };
}
