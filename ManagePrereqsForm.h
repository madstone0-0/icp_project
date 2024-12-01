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
    /// Summary for ManagePrereqsForm
    /// </summary>
   public
    ref class UpdateCourseForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       private:
        System::Windows::Forms::ListBox ^ courseBox;

       private:
        System::Windows::Forms::Button ^ deleteButton;

       private:
        CourseService ^ courseService;

       public:
        UpdateCourseForm(IChildHost ^ parent) {
            this->parent = parent;
            courseService = gcnew CourseService(this->parent->user);
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~UpdateCourseForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::SplitContainer ^ splitContainer1;

       private:
       private:
       private:
       private:
        System::Windows::Forms::Label ^ label4;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::GroupBox ^ smth;

       private:
        System::Windows::Forms::ListBox ^ prereqBox;

       private:
        System::Windows::Forms::TextBox ^ cnameBox;

       private:
        System::Windows::Forms::ComboBox ^ semBox;

       private:
       private:
        System::Windows::Forms::ComboBox ^ creditsBox;

       private:
        System::Windows::Forms::NumericUpDown ^ capIn;

       private:
        System::Windows::Forms::Button ^ updateButton;

       private:
       private:
       private:
       protected:
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
            this->updateButton = (gcnew System::Windows::Forms::Button());
            this->semBox = (gcnew System::Windows::Forms::ComboBox());
            this->creditsBox = (gcnew System::Windows::Forms::ComboBox());
            this->capIn = (gcnew System::Windows::Forms::NumericUpDown());
            this->cnameBox = (gcnew System::Windows::Forms::TextBox());
            this->smth = (gcnew System::Windows::Forms::GroupBox());
            this->prereqBox = (gcnew System::Windows::Forms::ListBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->deleteButton = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->BeginInit();
            this->splitContainer1->Panel1->SuspendLayout();
            this->splitContainer1->Panel2->SuspendLayout();
            this->splitContainer1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->capIn))->BeginInit();
            this->smth->SuspendLayout();
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
            this->splitContainer1->Panel2->Controls->Add(this->deleteButton);
            this->splitContainer1->Panel2->Controls->Add(this->updateButton);
            this->splitContainer1->Panel2->Controls->Add(this->semBox);
            this->splitContainer1->Panel2->Controls->Add(this->creditsBox);
            this->splitContainer1->Panel2->Controls->Add(this->capIn);
            this->splitContainer1->Panel2->Controls->Add(this->cnameBox);
            this->splitContainer1->Panel2->Controls->Add(this->smth);
            this->splitContainer1->Panel2->Controls->Add(this->label4);
            this->splitContainer1->Panel2->Controls->Add(this->label3);
            this->splitContainer1->Panel2->Controls->Add(this->label2);
            this->splitContainer1->Panel2->Controls->Add(this->label1);
            this->splitContainer1->Size = System::Drawing::Size(709, 396);
            this->splitContainer1->SplitterDistance = 235;
            this->splitContainer1->TabIndex = 0;
            //
            // courseBox
            //
            this->courseBox->FormattingEnabled = true;
            this->courseBox->Location = System::Drawing::Point(8, 8);
            this->courseBox->Name = L"courseBox";
            this->courseBox->Size = System::Drawing::Size(224, 381);
            this->courseBox->TabIndex = 0;
            this->courseBox->SelectedIndexChanged +=
                gcnew System::EventHandler(this, &UpdateCourseForm::courseBox_SelectedIndexChanged);
            //
            // updateButton
            //
            this->updateButton->Location = System::Drawing::Point(56, 360);
            this->updateButton->Name = L"updateButton";
            this->updateButton->Size = System::Drawing::Size(75, 23);
            this->updateButton->TabIndex = 10;
            this->updateButton->Text = L"Update";
            this->updateButton->UseVisualStyleBackColor = true;
            this->updateButton->Click += gcnew System::EventHandler(this, &UpdateCourseForm::updateButton_Click);
            //
            // semBox
            //
            this->semBox->FormattingEnabled = true;
            this->semBox->Location = System::Drawing::Point(336, 40);
            this->semBox->Name = L"semBox";
            this->semBox->Size = System::Drawing::Size(112, 21);
            this->semBox->TabIndex = 9;
            //
            // creditsBox
            //
            this->creditsBox->FormattingEnabled = true;
            this->creditsBox->Location = System::Drawing::Point(96, 88);
            this->creditsBox->Name = L"creditsBox";
            this->creditsBox->Size = System::Drawing::Size(104, 21);
            this->creditsBox->TabIndex = 8;
            //
            // capIn
            //
            this->capIn->Location = System::Drawing::Point(320, 96);
            this->capIn->Name = L"capIn";
            this->capIn->Size = System::Drawing::Size(120, 20);
            this->capIn->TabIndex = 7;
            //
            // cnameBox
            //
            this->cnameBox->Location = System::Drawing::Point(88, 32);
            this->cnameBox->Name = L"cnameBox";
            this->cnameBox->Size = System::Drawing::Size(100, 20);
            this->cnameBox->TabIndex = 6;
            //
            // smth
            //
            this->smth->Controls->Add(this->prereqBox);
            this->smth->Location = System::Drawing::Point(8, 144);
            this->smth->Name = L"smth";
            this->smth->Size = System::Drawing::Size(456, 208);
            this->smth->TabIndex = 5;
            this->smth->TabStop = false;
            this->smth->Text = L"Prerequisites";
            //
            // prereqBox
            //
            this->prereqBox->FormattingEnabled = true;
            this->prereqBox->Location = System::Drawing::Point(8, 24);
            this->prereqBox->Name = L"prereqBox";
            this->prereqBox->Size = System::Drawing::Size(440, 173);
            this->prereqBox->TabIndex = 0;
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(216, 88);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(95, 24);
            this->label4->TabIndex = 3;
            this->label4->Text = L"Capacity:";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(224, 32);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(104, 24);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Semester:";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(16, 88);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(81, 24);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Credits:";
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(16, 32);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(71, 24);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Name:";
            //
            // deleteButton
            //
            this->deleteButton->Location = System::Drawing::Point(312, 360);
            this->deleteButton->Name = L"deleteButton";
            this->deleteButton->Size = System::Drawing::Size(75, 23);
            this->deleteButton->TabIndex = 11;
            this->deleteButton->Text = L"Delete";
            this->deleteButton->UseVisualStyleBackColor = true;
            //
            // UpdateCourseForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(709, 396);
            this->Controls->Add(this->splitContainer1);
            this->Name = L"UpdateCourseForm";
            this->Text = L"ManagePrereqsForm";
            this->Load += gcnew System::EventHandler(this, &UpdateCourseForm::UpdateCourseForm_Load);
            this->splitContainer1->Panel1->ResumeLayout(false);
            this->splitContainer1->Panel2->ResumeLayout(false);
            this->splitContainer1->Panel2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->EndInit();
            this->splitContainer1->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->capIn))->EndInit();
            this->smth->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion
       private:
        Course ^ selectedCourse {};
        void updateSelection() {
            try {
                auto kvp = (KeyValuePair<long long, STR> ^) courseBox->SelectedItem;
                auto res = courseService->GetById(kvp->Key);
                selectedCourse = res.data;
                auto course = res.data;

                auto allCourses = gcnew List<Course>(0);
                auto allCoursesRes = courseService->GetAll(allCourses);
                if (!allCoursesRes.status) {
                    throw gcnew Exception("Could not fetch courses");
                }
                auto preqRes = courseService->GetPrereqCourses(course->cid);
                auto prereqs = preqRes.data;
                auto allCoursesMap = gcnew SortedDictionary<long long, STR>();
                auto prereqMap = gcnew SortedDictionary<long long, STR>();
                for each (auto c in allCourses) {
                    if (c.cid == course->cid) {
                        continue;
                    }
                    allCoursesMap->Add(c.cid, c.cname);
                }
                for each (auto c in prereqs) {
                    prereqMap->Add(c.cid, c.cname);
                }

                cnameBox->Text = course->cname;
                creditsBox->SelectedItem = course->credits;
                semBox->SelectedItem = parseSemester(course->sem);
                capIn->Value = course->capacity;

                prereqBox->BeginUpdate();
                prereqBox->Items->Clear();
                int i = 0;
                for each (auto c in allCoursesMap->Keys) {
                    auto kvp = gcnew KeyValuePair<long long, STR>(c, allCoursesMap[c]);
                    prereqBox->Items->Add(kvp);
                    if (prereqMap->ContainsKey(c)) {
                        prereqBox->SetSelected(i, true);
                    }
                    i++;
                }
                prereqBox->EndUpdate();

            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

        void updateCourses() {
            auto allCourses = gcnew List<Course>(0);
            auto allCoursesRes = courseService->GetAll(allCourses);
            if (!allCoursesRes.status) {
                throw gcnew Exception("Could not fetch courses");
            }

            courseBox->Items->Clear();
            courseBox->BeginUpdate();
            for each (auto course in allCourses) {
                KeyValuePair<long long, STR> ^ itm = gcnew KeyValuePair<long long, STR>(course.cid, course.cname);
                courseBox->Items->Add(itm);
            }
            courseBox->SelectedIndex = 0;
            courseBox->EndUpdate();
        }

        System::Void UpdateCourseForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                List<double> ^ credits = gcnew List<double>(0);
                credits->Add(1.0);
                credits->Add(0.5);
                List<STR> ^ sems = gcnew List<STR>(0);
                sems->Add("S1");
                sems->Add("S2");
                creditsBox->DataSource = credits;
                semBox->DataSource = sems;

                updateCourses();

                prereqBox->SelectionMode = SelectionMode::MultiSimple;
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

       private:
        System::Void updateButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto kvp = (KeyValuePair<long long, STR> ^) courseBox->SelectedItem;
                auto prereqs = gcnew PreReqList(0);
                for each (auto item in prereqBox->SelectedItems) {
                    auto kvp = (KeyValuePair<long long, STR> ^) item;
                    prereqs->Add(kvp->Key);
                }
                auto cname = trim(cnameBox->Text);
                auto credits = Convert::ToDouble(creditsBox->SelectedItem);
                auto sem = parseStrSemester((STR)semBox->SelectedItem);
                auto capacity = Convert::ToInt32(capIn->Value);

                if (isEmpty(cname)) {
                    MessageBox::Show("Course name cannot be empty");
                    return;
                }

                if (capacity <= 0) {
                    MessageBox::Show("Capacity must be greater than 0");
                    return;
                }
                auto course = Course(kvp->Key, cname, credits, sem, capacity, prereqs);
                auto updateRes = courseService->Update(course);
                if (!updateRes.status) {
                    MessageBox::Show("Failed to update course");
                    return;
                }

                MessageBox::Show(updateRes.data);
                updateCourses();
                updateSelection();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
