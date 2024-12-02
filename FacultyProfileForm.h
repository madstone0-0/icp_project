#pragma once
#include "services/CourseService.h"
#include "utils.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for FacultyProfileForm
    /// </summary>
   public
    ref class FacultyProfileForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       public:
        FacultyProfileForm(IChildHost ^ parent) {
            this->parent = parent;
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~FacultyProfileForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Label ^ label1;

       protected:
       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Label ^ label4;

       private:
        System::Windows::Forms::Label ^ label5;

       private:
        System::Windows::Forms::Label ^ nameLab;

       private:
        System::Windows::Forms::Label ^ emailLab;

       private:
        System::Windows::Forms::Label ^ appLab;

       private:
        System::Windows::Forms::Label ^ deptLab;

       private:
        System::Windows::Forms::Label ^ classesLab;

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
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->nameLab = (gcnew System::Windows::Forms::Label());
            this->emailLab = (gcnew System::Windows::Forms::Label());
            this->appLab = (gcnew System::Windows::Forms::Label());
            this->deptLab = (gcnew System::Windows::Forms::Label());
            this->classesLab = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(8, 40);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(71, 24);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Name:";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(8, 128);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(68, 24);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Email:";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(432, 128);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(181, 24);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Assigned Classes:";
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(8, 208);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(182, 24);
            this->label4->TabIndex = 3;
            this->label4->Text = L"Appointment Date:";
            //
            // label5
            //
            this->label5->AutoSize = true;
            this->label5->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(432, 40);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(123, 24);
            this->label5->TabIndex = 4;
            this->label5->Text = L"Department:";
            //
            // nameLab
            //
            this->nameLab->AutoSize = true;
            this->nameLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->nameLab->Location = System::Drawing::Point(88, 48);
            this->nameLab->Name = L"nameLab";
            this->nameLab->Size = System::Drawing::Size(44, 16);
            this->nameLab->TabIndex = 5;
            this->nameLab->Text = L"label6";
            //
            // emailLab
            //
            this->emailLab->AutoSize = true;
            this->emailLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->emailLab->Location = System::Drawing::Point(80, 136);
            this->emailLab->Name = L"emailLab";
            this->emailLab->Size = System::Drawing::Size(44, 16);
            this->emailLab->TabIndex = 6;
            this->emailLab->Text = L"label7";
            //
            // appLab
            //
            this->appLab->AutoSize = true;
            this->appLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->appLab->Location = System::Drawing::Point(192, 216);
            this->appLab->Name = L"appLab";
            this->appLab->Size = System::Drawing::Size(44, 16);
            this->appLab->TabIndex = 7;
            this->appLab->Text = L"label8";
            //
            // deptLab
            //
            this->deptLab->AutoSize = true;
            this->deptLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->deptLab->Location = System::Drawing::Point(568, 48);
            this->deptLab->Name = L"deptLab";
            this->deptLab->Size = System::Drawing::Size(44, 16);
            this->deptLab->TabIndex = 8;
            this->deptLab->Text = L"label9";
            //
            // classesLab
            //
            this->classesLab->AutoSize = true;
            this->classesLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->classesLab->Location = System::Drawing::Point(616, 136);
            this->classesLab->Name = L"classesLab";
            this->classesLab->Size = System::Drawing::Size(51, 16);
            this->classesLab->TabIndex = 9;
            this->classesLab->Text = L"label10";
            //
            // FacultyProfileForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(698, 265);
            this->Controls->Add(this->classesLab);
            this->Controls->Add(this->deptLab);
            this->Controls->Add(this->appLab);
            this->Controls->Add(this->emailLab);
            this->Controls->Add(this->nameLab);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"FacultyProfileForm";
            this->Text = L"FacultyProfileForm";
            this->Load += gcnew System::EventHandler(this, &FacultyProfileForm::FacultyProfileForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void FacultyProfileForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto service = gcnew CourseService(parent->user);
                auto faculty = dynamic_cast<Faculty ^>(parent->user);
                nameLab->Text = String::Format("{0} {1}", faculty->fname, faculty->lname);
                emailLab->Text = faculty->email;
                appLab->Text = Convert::ToDateTime(faculty->appDate).ToShortDateString();
                deptLab->Text = parseDept(faculty->dept, true);
                auto res = service->GetByFaculty(faculty->uid);
                if (!res.status) {
                    throw gcnew Exception("Could not get courses");
                }
                auto courses = res.data;
                classesLab->Text = courses->Count.ToString();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
