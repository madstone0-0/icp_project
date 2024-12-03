#pragma once
#include "services/EnumerationService.h"
#include "services/StudentActionsService.h"
#include "utils.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for GenerateTranscriptForm
    /// </summary>
   public
    ref class GenerateTranscriptForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;
        EnumerationService ^ enumService;
        StudentActionService ^ studentService;
        STR searchText = "";

       public:
        GenerateTranscriptForm(IChildHost ^ parent) {
            this->parent = parent;
            studentService = gcnew StudentActionService(parent->user);
            enumService = gcnew EnumerationService(parent->user);
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~GenerateTranscriptForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::SplitContainer ^ splitContainer1;

       protected:
       private:
        System::Windows::Forms::TextBox ^ searchBox;

       private:
        System::Windows::Forms::ListBox ^ studentBox;

       private:
        System::Windows::Forms::Panel ^ panel2;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Label ^ sem2Trans;

       private:
        System::Windows::Forms::Panel ^ panel1;

       private:
       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ sem1Trans;

       private:
        System::Windows::Forms::Label ^ studentNameYear;

       private:
        System::Windows::Forms::Label ^ cgpaLab;

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
            this->searchBox = (gcnew System::Windows::Forms::TextBox());
            this->studentBox = (gcnew System::Windows::Forms::ListBox());
            this->cgpaLab = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->sem2Trans = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->sem1Trans = (gcnew System::Windows::Forms::Label());
            this->studentNameYear = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->BeginInit();
            this->splitContainer1->Panel1->SuspendLayout();
            this->splitContainer1->Panel2->SuspendLayout();
            this->splitContainer1->SuspendLayout();
            this->panel2->SuspendLayout();
            this->panel1->SuspendLayout();
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
            this->splitContainer1->Panel1->Controls->Add(this->searchBox);
            this->splitContainer1->Panel1->Controls->Add(this->studentBox);
            //
            // splitContainer1.Panel2
            //
            this->splitContainer1->Panel2->Controls->Add(this->cgpaLab);
            this->splitContainer1->Panel2->Controls->Add(this->label1);
            this->splitContainer1->Panel2->Controls->Add(this->panel2);
            this->splitContainer1->Panel2->Controls->Add(this->panel1);
            this->splitContainer1->Panel2->Controls->Add(this->studentNameYear);
            this->splitContainer1->Size = System::Drawing::Size(807, 421);
            this->splitContainer1->SplitterDistance = 269;
            this->splitContainer1->TabIndex = 0;
            //
            // searchBox
            //
            this->searchBox->Location = System::Drawing::Point(16, 16);
            this->searchBox->Name = L"searchBox";
            this->searchBox->Size = System::Drawing::Size(240, 20);
            this->searchBox->TabIndex = 1;
            this->searchBox->TextChanged +=
                gcnew System::EventHandler(this, &GenerateTranscriptForm::searchBox_TextChanged);
            //
            // studentBox
            //
            this->studentBox->FormattingEnabled = true;
            this->studentBox->Location = System::Drawing::Point(8, 56);
            this->studentBox->Name = L"studentBox";
            this->studentBox->Size = System::Drawing::Size(256, 355);
            this->studentBox->TabIndex = 0;
            this->studentBox->SelectedIndexChanged +=
                gcnew System::EventHandler(this, &GenerateTranscriptForm::studentBox_SelectedIndexChanged);
            //
            // cgpaLab
            //
            this->cgpaLab->AutoSize = true;
            this->cgpaLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->cgpaLab->Location = System::Drawing::Point(400, 24);
            this->cgpaLab->Name = L"cgpaLab";
            this->cgpaLab->Size = System::Drawing::Size(44, 16);
            this->cgpaLab->TabIndex = 8;
            this->cgpaLab->Text = L"label4";
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(304, 16);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(82, 25);
            this->label1->TabIndex = 7;
            this->label1->Text = L"CGPA:";
            //
            // panel2
            //
            this->panel2->Controls->Add(this->label3);
            this->panel2->Controls->Add(this->sem2Trans);
            this->panel2->Location = System::Drawing::Point(16, 232);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(504, 176);
            this->panel2->TabIndex = 6;
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(0, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(115, 24);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Semester 2";
            //
            // sem2Trans
            //
            this->sem2Trans->AutoSize = true;
            this->sem2Trans->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->sem2Trans->Location = System::Drawing::Point(8, 32);
            this->sem2Trans->Name = L"sem2Trans";
            this->sem2Trans->Size = System::Drawing::Size(44, 16);
            this->sem2Trans->TabIndex = 4;
            this->sem2Trans->Text = L"label5";
            //
            // panel1
            //
            this->panel1->Controls->Add(this->label2);
            this->panel1->Controls->Add(this->sem1Trans);
            this->panel1->Location = System::Drawing::Point(16, 64);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(504, 160);
            this->panel1->TabIndex = 5;
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(0, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(115, 24);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Semester 1";
            //
            // sem1Trans
            //
            this->sem1Trans->AutoSize = true;
            this->sem1Trans->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->sem1Trans->Location = System::Drawing::Point(8, 32);
            this->sem1Trans->Name = L"sem1Trans";
            this->sem1Trans->Size = System::Drawing::Size(44, 16);
            this->sem1Trans->TabIndex = 3;
            this->sem1Trans->Text = L"label4";
            //
            // studentNameYear
            //
            this->studentNameYear->AutoSize = true;
            this->studentNameYear->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->studentNameYear->Location = System::Drawing::Point(16, 16);
            this->studentNameYear->Name = L"studentNameYear";
            this->studentNameYear->Size = System::Drawing::Size(76, 25);
            this->studentNameYear->TabIndex = 0;
            this->studentNameYear->Text = L"label1";
            //
            // GenerateTranscriptForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(807, 421);
            this->Controls->Add(this->splitContainer1);
            this->Name = L"GenerateTranscriptForm";
            this->Text = L"GenerateTranscriptForm";
            this->Load += gcnew System::EventHandler(this, &GenerateTranscriptForm::GenerateTranscriptForm_Load);
            this->splitContainer1->Panel1->ResumeLayout(false);
            this->splitContainer1->Panel1->PerformLayout();
            this->splitContainer1->Panel2->ResumeLayout(false);
            this->splitContainer1->Panel2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->EndInit();
            this->splitContainer1->ResumeLayout(false);
            this->panel2->ResumeLayout(false);
            this->panel2->PerformLayout();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion
       private:
        System::Void studentBox_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e) {
            updateTranscript();
        }

       private:
        void updateTranscript() {
            try {
                auto kvp = (KeyValuePair<long long, STR> ^) studentBox->SelectedItem;
                if (kvp == nullptr) {
                    return;
                }

                auto res = studentService->GetTranscript(kvp->Key);
                if (!res.status) {
                    throw gcnew Exception("Could not fetch transcript");
                }
                auto transcript = res.data;
                auto semMap = gcnew Dictionary<STR, List<TranscriptItem> ^>(0);
                double cGPA = 0;
                auto count = transcript->Count;
                for each (auto item in transcript) {
                    if (!semMap->ContainsKey(parseSemester(item.sem))) {
                        semMap->Add(parseSemester(item.sem), gcnew List<TranscriptItem>(0));
                    }
                    if (item.grade == Grade::NG) count--;
                    auto semList = gcnew List<TranscriptItem>(0);
                    semMap->TryGetValue(parseSemester(item.sem), semList);
                    semList->Add(item);
                    cGPA += gradeToCredits(item.grade) * item.credits;
                }
                if (count == 0 || cGPA == 0) {
                    cGPA = 0;
                } else {
                    cGPA /= count;
                }
                cgpaLab->Text = Convert::ToString(Math::Round(cGPA, 2, MidpointRounding::AwayFromZero));
                studentNameYear->Text = kvp->Value;
                sem1Trans->Text = "";
                sem2Trans->Text = "";

                auto sem1List = gcnew List<TranscriptItem>(1);
                auto sem2List = gcnew List<TranscriptItem>(1);
                semMap->TryGetValue(parseSemester(Semester::S1), sem1List);
                semMap->TryGetValue(parseSemester(Semester::S2), sem2List);

                if (sem1List != nullptr && sem1List->Count != 0)
                    for each (auto item in sem1List) {
                        sem1Trans->Text +=
                            String::Format("{0} - {1} - {2}\n", item.cname, parseGrade(item.grade, true), item.credits);
                    }

                if (sem2List != nullptr && sem2List->Count != 0)
                    for each (auto item in sem2List) {
                        sem2Trans->Text +=
                            String::Format("{0} - {1} - {2}\n", item.cname, parseGrade(item.grade, true), item.credits);
                    }

            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

        List<Student> ^
            filterStudents(List<Student> ^ students) {
                if (isEmpty(searchText)) {
                    return students;
                }

                auto res = gcnew List<Student>(0);
                for each (auto student in students) {
                    auto lowerText = searchText->ToLower()->Replace(" ", "");
                    auto name = student.FirstName->ToLower() + student.LastName->ToLower();
                    if (name->Contains(lowerText)) {
                        res->Add(student);
                    }
                }
                return res;
            }

            void updateStudents() {
            auto students = gcnew List<Student>(0);
            auto getRes = enumService->GetAllStudents(students);
            auto filtered = filterStudents(students);
            studentBox->BeginUpdate();
            studentBox->Items->Clear();
            for each (auto student in filtered) {
                auto kvp = gcnew KeyValuePair<long long, STR>(student.UID, student.FirstName + " " + student.LastName);
                studentBox->Items->Add(kvp);
            }
            studentBox->EndUpdate();
        }

        System::Void GenerateTranscriptForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                updateStudents();
                studentBox->SelectedIndex = 0;
                updateTranscript();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void searchBox_TextChanged(System::Object ^ sender, System::EventArgs ^ e) {
            searchText = trim(searchBox->Text);
            updateStudents();
        }
    };
}  // namespace icpproject
