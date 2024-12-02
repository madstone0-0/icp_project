#pragma once
#include "services/CourseService.h"
#include "services/EnumerationService.h"
#include "utils.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for ViewAssignmentsForm
    /// </summary>
   public
    ref class ViewAssignmentsForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;
        CourseService ^ courseService;
        EnumerationService ^ enumService;

       public:
        ViewAssignmentsForm(IChildHost ^ parent) {
            this->parent = parent;
            courseService = gcnew CourseService(this->parent->user);
            enumService = gcnew EnumerationService(this->parent->user);
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ViewAssignmentsForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::SplitContainer ^ splitContainer1;

       protected:
       private:
        System::Windows::Forms::ListBox ^ facBox;

       private:
        System::Windows::Forms::Button ^ saveButton;

       private:
       private:
        System::Windows::Forms::GroupBox ^ group;

       private:
        System::Windows::Forms::ListBox ^ courseBox;

       private:
        System::Windows::Forms::Label ^ deptLab;

       private:
        System::Windows::Forms::Label ^ emailLab;

       private:
        System::Windows::Forms::Label ^ nameLab;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label1;

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
            this->facBox = (gcnew System::Windows::Forms::ListBox());
            this->deptLab = (gcnew System::Windows::Forms::Label());
            this->emailLab = (gcnew System::Windows::Forms::Label());
            this->nameLab = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->saveButton = (gcnew System::Windows::Forms::Button());
            this->group = (gcnew System::Windows::Forms::GroupBox());
            this->courseBox = (gcnew System::Windows::Forms::ListBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->BeginInit();
            this->splitContainer1->Panel1->SuspendLayout();
            this->splitContainer1->Panel2->SuspendLayout();
            this->splitContainer1->SuspendLayout();
            this->group->SuspendLayout();
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
            this->splitContainer1->Panel1->Controls->Add(this->facBox);
            //
            // splitContainer1.Panel2
            //
            this->splitContainer1->Panel2->Controls->Add(this->deptLab);
            this->splitContainer1->Panel2->Controls->Add(this->emailLab);
            this->splitContainer1->Panel2->Controls->Add(this->nameLab);
            this->splitContainer1->Panel2->Controls->Add(this->label3);
            this->splitContainer1->Panel2->Controls->Add(this->label2);
            this->splitContainer1->Panel2->Controls->Add(this->label1);
            this->splitContainer1->Panel2->Controls->Add(this->saveButton);
            this->splitContainer1->Panel2->Controls->Add(this->group);
            this->splitContainer1->Size = System::Drawing::Size(740, 389);
            this->splitContainer1->SplitterDistance = 246;
            this->splitContainer1->TabIndex = 0;
            //
            // facBox
            //
            this->facBox->FormattingEnabled = true;
            this->facBox->Location = System::Drawing::Point(8, 8);
            this->facBox->Name = L"facBox";
            this->facBox->Size = System::Drawing::Size(232, 381);
            this->facBox->TabIndex = 0;
            this->facBox->SelectedIndexChanged +=
                gcnew System::EventHandler(this, &ViewAssignmentsForm::facBox_SelectedIndexChanged);
            //
            // deptLab
            //
            this->deptLab->AutoSize = true;
            this->deptLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->deptLab->Location = System::Drawing::Point(152, 136);
            this->deptLab->Name = L"deptLab";
            this->deptLab->Size = System::Drawing::Size(44, 16);
            this->deptLab->TabIndex = 8;
            this->deptLab->Text = L"label6";
            //
            // emailLab
            //
            this->emailLab->AutoSize = true;
            this->emailLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->emailLab->Location = System::Drawing::Point(360, 24);
            this->emailLab->Name = L"emailLab";
            this->emailLab->Size = System::Drawing::Size(44, 16);
            this->emailLab->TabIndex = 7;
            this->emailLab->Text = L"label5";
            //
            // nameLab
            //
            this->nameLab->AutoSize = true;
            this->nameLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->nameLab->Location = System::Drawing::Point(96, 24);
            this->nameLab->Name = L"nameLab";
            this->nameLab->Size = System::Drawing::Size(44, 16);
            this->nameLab->TabIndex = 6;
            this->nameLab->Text = L"label4";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(280, 16);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(68, 24);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Email:";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(16, 128);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(123, 24);
            this->label2->TabIndex = 4;
            this->label2->Text = L"Department:";
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(8, 16);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(71, 24);
            this->label1->TabIndex = 3;
            this->label1->Text = L"Name:";
            //
            // saveButton
            //
            this->saveButton->Location = System::Drawing::Point(216, 360);
            this->saveButton->Name = L"saveButton";
            this->saveButton->Size = System::Drawing::Size(75, 23);
            this->saveButton->TabIndex = 2;
            this->saveButton->Text = L"Save";
            this->saveButton->UseVisualStyleBackColor = true;
            this->saveButton->Click += gcnew System::EventHandler(this, &ViewAssignmentsForm::button1_Click);
            //
            // group
            //
            this->group->Controls->Add(this->courseBox);
            this->group->Location = System::Drawing::Point(8, 184);
            this->group->Name = L"group";
            this->group->Size = System::Drawing::Size(472, 168);
            this->group->TabIndex = 1;
            this->group->TabStop = false;
            this->group->Text = L"Assigned Courses";
            //
            // courseBox
            //
            this->courseBox->FormattingEnabled = true;
            this->courseBox->Location = System::Drawing::Point(8, 16);
            this->courseBox->Name = L"courseBox";
            this->courseBox->Size = System::Drawing::Size(464, 160);
            this->courseBox->TabIndex = 0;
            //
            // ViewAssignmentsForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(740, 389);
            this->Controls->Add(this->splitContainer1);
            this->Name = L"ViewAssignmentsForm";
            this->Text = L"ViewAssignmentsForm";
            this->Load += gcnew System::EventHandler(this, &ViewAssignmentsForm::ViewAssignmentsForm_Load);
            this->splitContainer1->Panel1->ResumeLayout(false);
            this->splitContainer1->Panel2->ResumeLayout(false);
            this->splitContainer1->Panel2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->EndInit();
            this->splitContainer1->ResumeLayout(false);
            this->group->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion
       private:
        void updateFaculty() {
            try {
                auto allFac = gcnew List<Faculty>(0);
                auto res = enumService->GetAllFaculty(allFac);
                if (!res.status) {
                    throw gcnew Exception("Could not fetch faculty");
                }
                facBox->Items->Clear();
                for each (auto fac in allFac) {
                    auto kvp = gcnew KeyValuePair<long long, STR>(fac.uid, fac.fname + " " + fac.lname);
                    facBox->Items->Add(kvp);
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

        void updateSelection() {
            try {
                auto selected = facBox->SelectedItem;
                if (selected == nullptr) {
                    return;
                }
                auto kvp = (KeyValuePair<long long, STR> ^) selected;
                auto faculty = enumService->GetFacultyById(kvp->Key).data;
                auto res = courseService->GetByFaculty(kvp->Key);
                auto facCourses = res.data;
                auto courses = gcnew List<Course>(0);
                auto courseRes = courseService->GetAll(courses);
                if (!courseRes.status) {
                    throw gcnew Exception("Could not fetch courses");
                }
                auto allCoursesMap = gcnew SortedDictionary<long long, STR>();
                auto facCoursesMap = gcnew SortedDictionary<long long, STR>();
                for each (auto c in courses) {
                    allCoursesMap->Add(c.cid, c.cname);
                }
                for each (auto c in facCourses) {
                    facCoursesMap->Add(c.cid, c.cname);
                }
                courseBox->Items->Clear();
                nameLab->Text = faculty->fname + " " + faculty->lname;
                emailLab->Text = faculty->email;
                deptLab->Text = parseDept(faculty->dept, true);

                courseBox->BeginUpdate();
                int i = 0;
                for each (auto c in allCoursesMap->Keys) {
                    auto kvp = gcnew KeyValuePair<long long, STR>(c, allCoursesMap[c]);
                    courseBox->Items->Add(kvp);
                    if (facCoursesMap->ContainsKey(c)) {
                        courseBox->SetSelected(i, true);
                    }
                    i++;
                }
                courseBox->EndUpdate();

            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

        System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto selected = facBox->SelectedItem;
                if (selected == nullptr) {
                    return;
                }
                auto kvp = (KeyValuePair<long long, STR> ^) selected;
                auto fid = kvp->Key;
                auto clearRes = courseService->ClearAssignments(fid);
                for each (auto item in courseBox->SelectedItems) {
                    auto cid = ((KeyValuePair<long long, STR> ^) item)->Key;
                    auto res = courseService->UpdateFacultyAssignment(fid, cid);
                    if (!res.status) {
                        throw gcnew Exception("Could not update faculty assignment");
                    }
                }
                MessageBox::Show("Faculty assignments updated successfully");
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void ViewAssignmentsForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                courseBox->SelectionMode = SelectionMode::MultiSimple;
                updateFaculty();
                facBox->SelectedIndex = 0;
                updateSelection();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void facBox_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e) { updateSelection(); }
    };
}  // namespace icpproject
