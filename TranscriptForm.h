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

       protected:
       private:
        System::Windows::Forms::Label ^ transcriptText;

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
            this->transcriptText = (gcnew System::Windows::Forms::Label());
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
            // transcriptText
            //
            this->transcriptText->AutoSize = true;
            this->transcriptText->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->transcriptText->Location = System::Drawing::Point(24, 72);
            this->transcriptText->Name = L"transcriptText";
            this->transcriptText->Size = System::Drawing::Size(51, 20);
            this->transcriptText->TabIndex = 1;
            this->transcriptText->Text = L"label2";
            //
            // TranscriptForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(686, 352);
            this->Controls->Add(this->transcriptText);
            this->Controls->Add(this->label1);
            this->Name = L"TranscriptForm";
            this->Text = L"TranscriptForm";
            this->Load += gcnew System::EventHandler(this, &TranscriptForm::TranscriptForm_Load);
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

                transcriptText->Text = "";
                for each (auto item in res.data) {
                    transcriptText->Text += String::Format("{0} - {1}\n", item.cname, parseGrade(item.grade, true));
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
