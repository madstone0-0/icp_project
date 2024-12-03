#pragma once
#include "services/EnrollService.h"
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
    /// Summary for TranscriptForm
    /// </summary>
   public
    ref class TranscriptForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       public:
        TranscriptForm(IChildHost ^ parent) {
            this->parent = parent;
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~TranscriptForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::Panel ^ panel2;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Label ^ sem2Trans;

       private:
        System::Windows::Forms::Panel ^ panel1;

       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ sem1Trans;

       private:
        System::Windows::Forms::Label ^ label4;

       private:
        System::Windows::Forms::Label ^ cpgaLab;

       private:
        System::Windows::Forms::Label ^ cgpaLab;

       protected:
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
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->sem2Trans = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->sem1Trans = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->cpgaLab = (gcnew System::Windows::Forms::Label());
            this->cgpaLab = (gcnew System::Windows::Forms::Label());
            this->panel2->SuspendLayout();
            this->panel1->SuspendLayout();
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Dock = System::Windows::Forms::DockStyle::Top;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(0, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(146, 31);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Transcript";
            //
            // panel2
            //
            this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->panel2->Controls->Add(this->label3);
            this->panel2->Controls->Add(this->sem2Trans);
            this->panel2->Location = System::Drawing::Point(8, 176);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(672, 148);
            this->panel2->TabIndex = 8;
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
            this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->panel1->Controls->Add(this->label2);
            this->panel1->Controls->Add(this->sem1Trans);
            this->panel1->Location = System::Drawing::Point(8, 40);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(672, 128);
            this->panel1->TabIndex = 7;
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
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(8, 336);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(63, 20);
            this->label4->TabIndex = 9;
            this->label4->Text = L"CGPA:";
            //
            // cpgaLab
            //
            this->cpgaLab->AutoSize = true;
            this->cpgaLab->Location = System::Drawing::Point(80, 344);
            this->cpgaLab->Name = L"cpgaLab";
            this->cpgaLab->Size = System::Drawing::Size(0, 13);
            this->cpgaLab->TabIndex = 10;
            //
            // cgpaLab
            //
            this->cgpaLab->AutoSize = true;
            this->cgpaLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->cgpaLab->Location = System::Drawing::Point(80, 336);
            this->cgpaLab->Name = L"cgpaLab";
            this->cgpaLab->Size = System::Drawing::Size(44, 16);
            this->cgpaLab->TabIndex = 11;
            this->cgpaLab->Text = L"label5";
            //
            // TranscriptForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(686, 379);
            this->Controls->Add(this->cgpaLab);
            this->Controls->Add(this->cpgaLab);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->panel1);
            this->Controls->Add(this->label1);
            this->Name = L"TranscriptForm";
            this->Text = L"TranscriptForm";
            this->Load += gcnew System::EventHandler(this, &TranscriptForm::TranscriptForm_Load);
            this->panel2->ResumeLayout(false);
            this->panel2->PerformLayout();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void TranscriptForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto service = gcnew StudentActionService(parent->user);
                auto res = service->GetTranscript();
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
                sem1Trans->Text = "";
                sem2Trans->Text = "";

                auto sem1List = gcnew List<TranscriptItem>(0);
                auto sem2List = gcnew List<TranscriptItem>(0);
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
    };
}  // namespace icpproject
