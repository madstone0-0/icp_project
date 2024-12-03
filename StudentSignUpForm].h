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
    /// Summary for StudentSignUpForm
    /// </summary>
   public
    ref class StudentSignUpForm : public System::Windows::Forms::Form {
       private:
        Form ^ parent;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::ComboBox ^ majorBox;

       private:
        StudentService ^ service;

       public:
        StudentSignUpForm(Form ^ other) {
            this->parent = other;
            service = gcnew StudentService();
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
        System::Windows::Forms::PictureBox ^ pictureBox;

       private:
       private:
       private:
       private:
       private:
        System::Windows::Forms::DateTimePicker ^ dobBox;

       private:
       private:
        System::Windows::Forms::Label ^ label7;

       private:
        System::Windows::Forms::Button ^ uploadPictureBtn;

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
            this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
            this->dobBox = (gcnew System::Windows::Forms::DateTimePicker());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->uploadPictureBtn = (gcnew System::Windows::Forms::Button());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->majorBox = (gcnew System::Windows::Forms::ComboBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->pictureBox))->BeginInit();
            this->SuspendLayout();
            //
            // linkLabel2
            //
            this->linkLabel2->AutoSize = true;
            this->linkLabel2->Location = System::Drawing::Point(320, 352);
            this->linkLabel2->Name = L"linkLabel2";
            this->linkLabel2->Size = System::Drawing::Size(48, 13);
            this->linkLabel2->TabIndex = 25;
            this->linkLabel2->TabStop = true;
            this->linkLabel2->Text = L"Go back";
            this->linkLabel2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
            this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(
                this, &StudentSignUpForm::linkLabel2_LinkClicked);
            //
            // linkLabel1
            //
            this->linkLabel1->AutoSize = true;
            this->linkLabel1->Location = System::Drawing::Point(264, 336);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(161, 13);
            this->linkLabel1->TabIndex = 24;
            this->linkLabel1->TabStop = true;
            this->linkLabel1->Text = L"Already have an account\? Login";
            this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(
                this, &StudentSignUpForm::linkLabel1_LinkClicked);
            //
            // label6
            //
            this->label6->AutoSize = true;
            this->label6->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(138, 96);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(72, 16);
            this->label6->TabIndex = 23;
            this->label6->Text = L"First Name";
            //
            // fnTB
            //
            this->fnTB->Location = System::Drawing::Point(141, 112);
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
            this->label5->Location = System::Drawing::Point(141, 183);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(41, 16);
            this->label5->TabIndex = 21;
            this->label5->Text = L"Email";
            this->label5->Click += gcnew System::EventHandler(this, &StudentSignUpForm::label5_Click);
            //
            // emailTB
            //
            this->emailTB->Location = System::Drawing::Point(141, 199);
            this->emailTB->Name = L"emailTB";
            this->emailTB->Size = System::Drawing::Size(260, 20);
            this->emailTB->TabIndex = 20;
            this->emailTB->TextChanged += gcnew System::EventHandler(this, &StudentSignUpForm::emailTB_TextChanged);
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(141, 223);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(67, 16);
            this->label4->TabIndex = 19;
            this->label4->Text = L"Password";
            //
            // passwordTB
            //
            this->passwordTB->Location = System::Drawing::Point(141, 239);
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
            this->label2->Location = System::Drawing::Point(269, 96);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(72, 16);
            this->label2->TabIndex = 17;
            this->label2->Text = L"Last Name";
            //
            // lnTB
            //
            this->lnTB->Location = System::Drawing::Point(272, 112);
            this->lnTB->Name = L"lnTB";
            this->lnTB->Size = System::Drawing::Size(129, 20);
            this->lnTB->TabIndex = 16;
            //
            // signupButton
            //
            this->signupButton->Location = System::Drawing::Point(280, 312);
            this->signupButton->Name = L"signupButton";
            this->signupButton->Size = System::Drawing::Size(136, 23);
            this->signupButton->TabIndex = 15;
            this->signupButton->Text = L"Sign Up";
            this->signupButton->UseVisualStyleBackColor = true;
            this->signupButton->Click += gcnew System::EventHandler(this, &StudentSignUpForm::signupButton_Click);
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(264, 16);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(151, 42);
            this->label1->TabIndex = 14;
            this->label1->Text = L"Sign Up";
            //
            // pictureBox
            //
            this->pictureBox->BackColor = System::Drawing::SystemColors::AppWorkspace;
            this->pictureBox->Location = System::Drawing::Point(448, 112);
            this->pictureBox->Name = L"pictureBox";
            this->pictureBox->Size = System::Drawing::Size(152, 144);
            this->pictureBox->TabIndex = 26;
            this->pictureBox->TabStop = false;
            //
            // dobBox
            //
            this->dobBox->Location = System::Drawing::Point(141, 159);
            this->dobBox->Name = L"dobBox";
            this->dobBox->Size = System::Drawing::Size(259, 20);
            this->dobBox->TabIndex = 30;
            //
            // label7
            //
            this->label7->AutoSize = true;
            this->label7->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(141, 143);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(81, 16);
            this->label7->TabIndex = 31;
            this->label7->Text = L"Date Of Birth";
            //
            // uploadPictureBtn
            //
            this->uploadPictureBtn->Location = System::Drawing::Point(480, 272);
            this->uploadPictureBtn->Name = L"uploadPictureBtn";
            this->uploadPictureBtn->Size = System::Drawing::Size(75, 23);
            this->uploadPictureBtn->TabIndex = 32;
            this->uploadPictureBtn->Text = L"Upload";
            this->uploadPictureBtn->UseVisualStyleBackColor = true;
            this->uploadPictureBtn->Click +=
                gcnew System::EventHandler(this, &StudentSignUpForm::uploadPictureBtn_Click);
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(141, 263);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(41, 16);
            this->label3->TabIndex = 28;
            this->label3->Text = L"Major";
            this->label3->Click += gcnew System::EventHandler(this, &StudentSignUpForm::label3_Click);
            //
            // majorBox
            //
            this->majorBox->FormattingEnabled = true;
            this->majorBox->Location = System::Drawing::Point(144, 280);
            this->majorBox->Name = L"majorBox";
            this->majorBox->Size = System::Drawing::Size(240, 21);
            this->majorBox->TabIndex = 33;
            //
            // StudentSignUpForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(644, 379);
            this->ControlBox = false;
            this->Controls->Add(this->majorBox);
            this->Controls->Add(this->uploadPictureBtn);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->dobBox);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->pictureBox);
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
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"StudentSignUpForm";
            this->Text = L"StudentSignUpForm";
            this->Load += gcnew System::EventHandler(this, &StudentSignUpForm::StudentSignUpForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->pictureBox))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void emailTB_TextChanged(System::Object ^ sender, System::EventArgs ^ e) {}

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
        System::Void label5_Click(System::Object ^ sender, System::EventArgs ^ e) {}

       private:
        System::Void uploadPictureBtn_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
                auto fileDiag = gcnew OpenFileDialog();
                fileDiag->InitialDirectory = "c:\\";
                fileDiag->Filter = "PNG Files (*.png)|*.png|JPG Files (*.jpg)|*.jpg|All Files (*.*)|*.*";
                fileDiag->FilterIndex = 1;
                fileDiag->RestoreDirectory = true;
                if (fileDiag->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                    auto filePath = fileDiag->FileName;
                    pictureBox->ImageLocation = filePath;
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void label3_Click(System::Object ^ sender, System::EventArgs ^ e) {}

       private:
        System::Void signupButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto fname = trim(fnTB->Text);
                auto lname = trim(lnTB->Text);
                auto email = trim(emailTB->Text);
                auto pass = trim(passwordTB->Text);
                auto dob = dobBox->Value;
                auto major = static_cast<Major>(majorBox->SelectedIndex);
                auto picture = pictureBox->Image;
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

                if (picture == nullptr) {
                    MessageBox::Show("Please upload a picture");
                    return;
                }

                auto res = service->SignUp(SignupStudent{fname, lname, email, pass, formatDateTimeAsMySQLDate(dob),
                                                         pictureBox->ImageLocation, major,
                                                         formatDateTimeAsMySQLDate(DateTime::Now)});
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

       private:
        System::Void StudentSignUpForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                passwordTB->UseSystemPasswordChar = true;
                this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
                for (int i{}; i < 8; i++) majorBox->Items->Add(parseMajor(static_cast<Major>(i)));
                majorBox->SelectedIndex = 0;
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void linkLabel2_LinkClicked(System::Object ^ sender,
                                            System::Windows::Forms::LinkLabelLinkClickedEventArgs ^ e) {
            try {
                parent->Show();
                this->Close();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
