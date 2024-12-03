#pragma once
#include "services/AuditService.h"
#include "services/CourseService.h"
#include "services/EnrollService.h"
#include "services/FacultyActionsService.h"
#include "utils.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for FacultyCoursesForm
    /// </summary>
   public
    ref class FacultyCoursesForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       private:
        System::Windows::Forms::Label ^ label4;

       private:
        System::Windows::Forms::ComboBox ^ semBox;

       private:
        CourseService ^ service;

       private:
        System::Windows::Forms::CheckBox ^ ungradedToggle;
        EnrollService ^ enrollService;

       private:
        System::Windows::Forms::Button ^ saveButton;
        FacultyActionService ^ facultyService;

       public:
        FacultyCoursesForm(IChildHost ^ parent) {
            this->parent = parent;
            service = gcnew CourseService(parent->user);
            enrollService = gcnew EnrollService(parent->user);
            facultyService = gcnew FacultyActionService(parent->user);
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~FacultyCoursesForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::SplitContainer ^ splitContainer1;

       private:
        System::Windows::Forms::ListBox ^ coursesBox;

       protected:
       private:
       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::DataGridView ^ rosterGV;

       private:
       private:
        System::Windows::Forms::GroupBox ^ groupBox1;

       private:
        System::Windows::Forms::Label ^ nameLab;

       private:
        System::Windows::Forms::Label ^ creditsLab;

       private:
       private:
        System::Windows::Forms::Label ^ enrolledLab;

       private:
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
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->semBox = (gcnew System::Windows::Forms::ComboBox());
            this->coursesBox = (gcnew System::Windows::Forms::ListBox());
            this->saveButton = (gcnew System::Windows::Forms::Button());
            this->ungradedToggle = (gcnew System::Windows::Forms::CheckBox());
            this->creditsLab = (gcnew System::Windows::Forms::Label());
            this->enrolledLab = (gcnew System::Windows::Forms::Label());
            this->nameLab = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->rosterGV = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->BeginInit();
            this->splitContainer1->Panel1->SuspendLayout();
            this->splitContainer1->Panel2->SuspendLayout();
            this->splitContainer1->SuspendLayout();
            this->groupBox1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->rosterGV))->BeginInit();
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
            this->splitContainer1->Panel1->Controls->Add(this->label4);
            this->splitContainer1->Panel1->Controls->Add(this->semBox);
            this->splitContainer1->Panel1->Controls->Add(this->coursesBox);
            //
            // splitContainer1.Panel2
            //
            this->splitContainer1->Panel2->Controls->Add(this->saveButton);
            this->splitContainer1->Panel2->Controls->Add(this->ungradedToggle);
            this->splitContainer1->Panel2->Controls->Add(this->creditsLab);
            this->splitContainer1->Panel2->Controls->Add(this->enrolledLab);
            this->splitContainer1->Panel2->Controls->Add(this->nameLab);
            this->splitContainer1->Panel2->Controls->Add(this->label3);
            this->splitContainer1->Panel2->Controls->Add(this->label2);
            this->splitContainer1->Panel2->Controls->Add(this->label1);
            this->splitContainer1->Panel2->Controls->Add(this->groupBox1);
            this->splitContainer1->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                this, &FacultyCoursesForm::splitContainer1_Panel2_Paint);
            this->splitContainer1->Size = System::Drawing::Size(833, 362);
            this->splitContainer1->SplitterDistance = 277;
            this->splitContainer1->TabIndex = 0;
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(40, 16);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(91, 20);
            this->label4->TabIndex = 2;
            this->label4->Text = L"Semester:";
            //
            // semBox
            //
            this->semBox->FormattingEnabled = true;
            this->semBox->Location = System::Drawing::Point(144, 16);
            this->semBox->Name = L"semBox";
            this->semBox->Size = System::Drawing::Size(97, 21);
            this->semBox->TabIndex = 1;
            this->semBox->SelectedIndexChanged +=
                gcnew System::EventHandler(this, &FacultyCoursesForm::semBox_SelectedIndexChanged);
            //
            // coursesBox
            //
            this->coursesBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
                 System::Windows::Forms::AnchorStyles::Left));
            this->coursesBox->FormattingEnabled = true;
            this->coursesBox->Location = System::Drawing::Point(8, 56);
            this->coursesBox->Name = L"coursesBox";
            this->coursesBox->Size = System::Drawing::Size(256, 290);
            this->coursesBox->TabIndex = 0;
            this->coursesBox->SelectedIndexChanged +=
                gcnew System::EventHandler(this, &FacultyCoursesForm::corusesBox_SelectedIndexChanged);
            //
            // saveButton
            //
            this->saveButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->saveButton->Location = System::Drawing::Point(240, 328);
            this->saveButton->Name = L"saveButton";
            this->saveButton->Size = System::Drawing::Size(75, 23);
            this->saveButton->TabIndex = 9;
            this->saveButton->Text = L"Save";
            this->saveButton->UseVisualStyleBackColor = true;
            this->saveButton->Click += gcnew System::EventHandler(this, &FacultyCoursesForm::saveButton_Click);
            //
            // ungradedToggle
            //
            this->ungradedToggle->AutoSize = true;
            this->ungradedToggle->Location = System::Drawing::Point(248, 56);
            this->ungradedToggle->Name = L"ungradedToggle";
            this->ungradedToggle->Size = System::Drawing::Size(127, 17);
            this->ungradedToggle->TabIndex = 8;
            this->ungradedToggle->Text = L"Show Only Ungraded";
            this->ungradedToggle->UseVisualStyleBackColor = true;
            this->ungradedToggle->CheckedChanged +=
                gcnew System::EventHandler(this, &FacultyCoursesForm::ungradedToggle_CheckedChanged);
            //
            // creditsLab
            //
            this->creditsLab->AutoSize = true;
            this->creditsLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->creditsLab->Location = System::Drawing::Point(328, 16);
            this->creditsLab->Name = L"creditsLab";
            this->creditsLab->Size = System::Drawing::Size(44, 16);
            this->creditsLab->TabIndex = 7;
            this->creditsLab->Text = L"label6";
            //
            // enrolledLab
            //
            this->enrolledLab->AutoSize = true;
            this->enrolledLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->enrolledLab->Location = System::Drawing::Point(112, 56);
            this->enrolledLab->Name = L"enrolledLab";
            this->enrolledLab->Size = System::Drawing::Size(44, 16);
            this->enrolledLab->TabIndex = 6;
            this->enrolledLab->Text = L"label5";
            //
            // nameLab
            //
            this->nameLab->AutoSize = true;
            this->nameLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->nameLab->Location = System::Drawing::Point(88, 16);
            this->nameLab->Name = L"nameLab";
            this->nameLab->Size = System::Drawing::Size(44, 16);
            this->nameLab->TabIndex = 5;
            this->nameLab->Text = L"label4";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(8, 48);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(95, 24);
            this->label3->TabIndex = 3;
            this->label3->Text = L"Enrolled:";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(240, 8);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(81, 24);
            this->label2->TabIndex = 2;
            this->label2->Text = L"Credits:";
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(8, 8);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(71, 24);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Name:";
            //
            // groupBox1
            //
            this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->groupBox1->Controls->Add(this->rosterGV);
            this->groupBox1->Location = System::Drawing::Point(8, 88);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(536, 240);
            this->groupBox1->TabIndex = 4;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Roster";
            //
            // rosterGV
            //
            this->rosterGV->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->rosterGV->ColumnHeadersHeightSizeMode =
                System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->rosterGV->Location = System::Drawing::Point(8, 16);
            this->rosterGV->Name = L"rosterGV";
            this->rosterGV->Size = System::Drawing::Size(520, 216);
            this->rosterGV->TabIndex = 0;
            //
            // FacultyCoursesForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(833, 362);
            this->Controls->Add(this->splitContainer1);
            this->Name = L"FacultyCoursesForm";
            this->Text = L"FacultyCoursesForm";
            this->Load += gcnew System::EventHandler(this, &FacultyCoursesForm::FacultyCoursesForm_Load);
            this->splitContainer1->Panel1->ResumeLayout(false);
            this->splitContainer1->Panel1->PerformLayout();
            this->splitContainer1->Panel2->ResumeLayout(false);
            this->splitContainer1->Panel2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->EndInit();
            this->splitContainer1->ResumeLayout(false);
            this->groupBox1->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->rosterGV))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion
       private:
        Semester chosenSem = Semester::S1;
        DataTable ^ students = nullptr;
        bool onlyUngraded = false;
        void updateSelection() {
            try {
                rosterGV->DataSource = nullptr;
                auto kvp = (KeyValuePair<long long, STR> ^) coursesBox->SelectedItem;
                if (kvp == nullptr) {
                    return;
                }
                auto cid = kvp->Key;
                auto course = service->GetById(cid).data;

                BindingSource ^ bs = gcnew BindingSource(students, "");
                if (onlyUngraded) {
                    auto getRes = facultyService->GetAllUnGraded(cid, chosenSem);
                    students = getRes.data;
                } else {
                    auto getRes = enrollService->GetAllEnrolledIn(cid, chosenSem);
                    students = getRes.data;
                }
                bs->DataSource = students;
                rosterGV->DataSource = bs;

                nameLab->Text = course->cname;
                creditsLab->Text = course->credits.ToString();
                enrolledLab->Text = Convert::ToString(students->Rows->Count);

                // Create a ComboBox column for grades
                DataGridViewComboBoxColumn ^ gradeColumn = gcnew DataGridViewComboBoxColumn();
                gradeColumn->ReadOnly = false;
                DataGridViewColumn ^ oldGradeColumn = nullptr;
                gradeColumn->Name = "Grade";
                gradeColumn->HeaderText = "Grade";
                for each (DataGridViewColumn ^ c in rosterGV->Columns) {
                    c->ReadOnly = true;
                    if (trim(c->Name)->CompareTo("Grade") == 0) {
                        c->ReadOnly = false;
                        oldGradeColumn = c;
                    }
                }
                gradeColumn->Items->Clear();
                for (int i{}; i < 13; i++) gradeColumn->Items->Add(parseGrade(static_cast<Grade>(i)));
                gradeColumn->DataPropertyName = oldGradeColumn->DataPropertyName;
                rosterGV->Columns->Remove(oldGradeColumn);
                rosterGV->Columns->Add(gradeColumn);

                gradeColumn->DisplayStyle = DataGridViewComboBoxDisplayStyle::ComboBox;
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

        void updateCourses() {
            try {
                coursesBox->Items->Clear();
                auto getRes = service->GetByFaculty(parent->user->UID);
                auto courses = getRes.data;
                for each (auto c in courses) {
                    if (c.sem != chosenSem) continue;
                    auto kvp = gcnew KeyValuePair<long long, String ^>(c.cid, c.cname);
                    coursesBox->Items->Add(kvp);
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void corusesBox_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e) {
            updateSelection();
        }

       private:
        System::Void FacultyCoursesForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                semBox->Items->Add("S1");
                semBox->Items->Add("S2");
                rosterGV->ReadOnly = false;
                updateCourses();
                semBox->SelectedIndex = 0;
                updateSelection();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void semBox_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                chosenSem = parseStrSemester(semBox->SelectedItem->ToString());
                updateCourses();
                updateSelection();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void splitContainer1_Panel2_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e) {
        }

       private:
        System::Void ungradedToggle_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                onlyUngraded = ungradedToggle->Checked;
                updateSelection();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void saveButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto kvp = (KeyValuePair<long long, STR> ^) coursesBox->SelectedItem;
                if (kvp == nullptr) {
                    return;
                }
                auto cid = kvp->Key;
                auto diagRes = MessageBox::Show("Do you want to sync changes?", "Sync Changes",
                                                MessageBoxButtons::YesNo, MessageBoxIcon::Question);
                if (diagRes == System::Windows::Forms::DialogResult::No) return;
                db::Ins()->getCmd()->CommandText =
                    "UPDATE enrollment SET grade = @grade WHERE uid = @uid AND cid = @cid";
                db::Ins()->getCmd()->Parameters->Clear();
                db::Ins()->getCmd()->Parameters->Add("@grade", MySqlDbType::String, 4, "Grade");
                db::Ins()->getCmd()->Parameters->Add("@uid", MySqlDbType::Int64, 8, "UID");
                db::Ins()->getCmd()->Parameters->AddWithValue("@cid", cid);

                db::Ins()->getDta()->UpdateCommand = db::Ins()->getCmd();
                db::Ins()->getDta()->Update((DataTable ^) students);

                Audit::Ins()->Log("Synced grades", parent->user->UID, "Course ID: " + cid);
                MessageBox::Show("Synced");
                rosterGV->Refresh();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
