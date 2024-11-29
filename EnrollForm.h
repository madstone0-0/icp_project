#pragma once
#include "services/CourseService.h"
#include "services/EnrollService.h"
#include "utils.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for EnrollForm
    /// </summary>
   public
    ref class EnrollForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;
        CourseService ^ courseService;

       private:
        System::Windows::Forms::ListBox ^ prereqsView;
        EnrollService ^ enrollService;

       public:
        EnrollForm(IChildHost ^ parent) {
            this->parent = parent;
            courseService = gcnew CourseService(parent->user);
            enrollService = gcnew EnrollService(parent->user);
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~EnrollForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::SplitContainer ^ splitContainer1;

       private:
        System::Windows::Forms::ListBox ^ courseBox;

       protected:
       private:
       private:
        System::Windows::Forms::Label ^ slotsLab;

       private:
        System::Windows::Forms::Label ^ credLab;

       private:
        System::Windows::Forms::Label ^ lecLab;

       private:
        System::Windows::Forms::Label ^ nameLab;

       private:
        System::Windows::Forms::Label ^ label4;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::Button ^ button1;

       private:
        System::Windows::Forms::GroupBox ^ groupBox1;

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
            this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
            this->courseBox = (gcnew System::Windows::Forms::ListBox());
            this->slotsLab = (gcnew System::Windows::Forms::Label());
            this->credLab = (gcnew System::Windows::Forms::Label());
            this->lecLab = (gcnew System::Windows::Forms::Label());
            this->nameLab = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->prereqsView = (gcnew System::Windows::Forms::ListBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->BeginInit();
            this->splitContainer1->Panel1->SuspendLayout();
            this->splitContainer1->Panel2->SuspendLayout();
            this->splitContainer1->SuspendLayout();
            this->groupBox1->SuspendLayout();
            this->SuspendLayout();
            //
            // splitContainer1
            //
            this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->splitContainer1->Location = System::Drawing::Point(0, 0);
            this->splitContainer1->Name = L"splitContainer1";
            //
            // splitContainer1.Panel1
            //
            this->splitContainer1->Panel1->Controls->Add(this->courseBox);
            //
            // splitContainer1.Panel2
            //
            this->splitContainer1->Panel2->Controls->Add(this->slotsLab);
            this->splitContainer1->Panel2->Controls->Add(this->credLab);
            this->splitContainer1->Panel2->Controls->Add(this->lecLab);
            this->splitContainer1->Panel2->Controls->Add(this->nameLab);
            this->splitContainer1->Panel2->Controls->Add(this->label4);
            this->splitContainer1->Panel2->Controls->Add(this->label3);
            this->splitContainer1->Panel2->Controls->Add(this->label2);
            this->splitContainer1->Panel2->Controls->Add(this->label1);
            this->splitContainer1->Panel2->Controls->Add(this->button1);
            this->splitContainer1->Panel2->Controls->Add(this->groupBox1);
            this->splitContainer1->Size = System::Drawing::Size(736, 382);
            this->splitContainer1->SplitterDistance = 245;
            this->splitContainer1->TabIndex = 0;
            //
            // courseBox
            //
            this->courseBox->FormattingEnabled = true;
            this->courseBox->Location = System::Drawing::Point(8, 8);
            this->courseBox->Name = L"courseBox";
            this->courseBox->Size = System::Drawing::Size(232, 368);
            this->courseBox->TabIndex = 0;
            this->courseBox->SelectedIndexChanged +=
                gcnew System::EventHandler(this, &EnrollForm::courseBox_SelectedIndexChanged);
            //
            // slotsLab
            //
            this->slotsLab->AutoSize = true;
            this->slotsLab->Location = System::Drawing::Point(168, 128);
            this->slotsLab->Name = L"slotsLab";
            this->slotsLab->Size = System::Drawing::Size(35, 13);
            this->slotsLab->TabIndex = 9;
            this->slotsLab->Text = L"label8";
            //
            // credLab
            //
            this->credLab->AutoSize = true;
            this->credLab->Location = System::Drawing::Point(336, 128);
            this->credLab->Name = L"credLab";
            this->credLab->Size = System::Drawing::Size(35, 13);
            this->credLab->TabIndex = 8;
            this->credLab->Text = L"label7";
            //
            // lecLab
            //
            this->lecLab->AutoSize = true;
            this->lecLab->Location = System::Drawing::Point(344, 40);
            this->lecLab->Name = L"lecLab";
            this->lecLab->Size = System::Drawing::Size(35, 13);
            this->lecLab->TabIndex = 7;
            this->lecLab->Text = L"label6";
            //
            // nameLab
            //
            this->nameLab->AutoSize = true;
            this->nameLab->Location = System::Drawing::Point(88, 40);
            this->nameLab->Name = L"nameLab";
            this->nameLab->Size = System::Drawing::Size(35, 13);
            this->nameLab->TabIndex = 6;
            this->nameLab->Text = L"label5";
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(232, 120);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(81, 24);
            this->label4->TabIndex = 5;
            this->label4->Text = L"Credits:";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(8, 120);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(152, 24);
            this->label3->TabIndex = 4;
            this->label3->Text = L"Available Slots:";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(232, 32);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(93, 24);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Lecturer:";
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(8, 32);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(71, 24);
            this->label1->TabIndex = 2;
            this->label1->Text = L"Name:";
            //
            // button1
            //
            this->button1->Location = System::Drawing::Point(208, 344);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Enroll";
            this->button1->UseVisualStyleBackColor = true;
            //
            // groupBox1
            //
            this->groupBox1->Controls->Add(this->prereqsView);
            this->groupBox1->Location = System::Drawing::Point(16, 168);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(456, 168);
            this->groupBox1->TabIndex = 0;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Prerequisites";
            //
            // prereqsView
            //
            this->prereqsView->FormattingEnabled = true;
            this->prereqsView->Location = System::Drawing::Point(8, 24);
            this->prereqsView->Name = L"prereqsView";
            this->prereqsView->Size = System::Drawing::Size(440, 134);
            this->prereqsView->TabIndex = 0;
            //
            // EnrollForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(736, 382);
            this->Controls->Add(this->splitContainer1);
            this->Name = L"EnrollForm";
            this->Text = L"EnrollForm";
            this->Load += gcnew System::EventHandler(this, &EnrollForm::EnrollForm_Load);
            this->splitContainer1->Panel1->ResumeLayout(false);
            this->splitContainer1->Panel2->ResumeLayout(false);
            this->splitContainer1->Panel2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->EndInit();
            this->splitContainer1->ResumeLayout(false);
            this->groupBox1->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion
       private:
        void updateSelection() {
            try {
                auto kvp = (KeyValuePair<long long, STR> ^) courseBox->SelectedItem;
                auto res = courseService->GetById(kvp->Key);
                auto course = res.data;
                auto preqRes = courseService->GetPrereqCourses(course->cid);
                auto prereqs = preqRes.data;
                auto facRes = courseService->GetTeachingFaculty(course->cid);
                auto faculty = facRes.data;
                auto capRes = courseService->GetRemainingCapacity(course->cid);
                auto remaining = capRes.data;

                nameLab->Text = course->cname;
                credLab->Text = Convert::ToString(course->credits);
                lecLab->Text = faculty->fname + " " + faculty->lname;
                slotsLab->Text = Convert::ToString(remaining);

                prereqsView->BeginUpdate();
                prereqsView->Items->Clear();
                for each (auto preq in prereqs) {
                    prereqsView->Items->Add(preq.cname);
                }
                prereqsView->EndUpdate();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

        System::Void EnrollForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto allCourses = gcnew List<Course>(0);
                auto allCoursesRes = courseService->GetAll(allCourses);
                if (!allCoursesRes.status) {
                    throw gcnew Exception("Could not fetch courses");
                }

                courseBox->BeginUpdate();
                for each (auto course in allCourses) {
                    KeyValuePair<long long, STR> ^ itm = gcnew KeyValuePair<long long, STR>(course.cid, course.cname);
                    courseBox->Items->Add(itm);
                }
                courseBox->SelectedIndex = 0;
                courseBox->EndUpdate();

                prereqsView->SelectionMode = SelectionMode::None;
                updateSelection();

            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void courseBox_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e) {
            updateSelection();
        }
    };
}  // namespace icpproject
