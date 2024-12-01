#pragma once
#include "services/PaymentsService.h"
#include "utils.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for IssueBillsForm
    /// </summary>
   public
    ref class IssueBillsForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       public:
        IssueBillsForm(IChildHost ^ parent) {
            this->parent = parent;
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~IssueBillsForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::NumericUpDown ^ amountBox;

       private:
        System::Windows::Forms::ComboBox ^ semBox;

       protected:
       private:
       private:
       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Button ^ button1;

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
            this->amountBox = (gcnew System::Windows::Forms::NumericUpDown());
            this->semBox = (gcnew System::Windows::Forms::ComboBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->amountBox))->BeginInit();
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(48, 56);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(88, 24);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Amount:";
            //
            // amountBox
            //
            this->amountBox->Location = System::Drawing::Point(200, 56);
            this->amountBox->Maximum = System::Decimal(gcnew cli::array<System::Int32>(4){999999999, 0, 0, 0});
            this->amountBox->Name = L"amountBox";
            this->amountBox->Size = System::Drawing::Size(120, 20);
            this->amountBox->TabIndex = 1;
            this->amountBox->ValueChanged +=
                gcnew System::EventHandler(this, &IssueBillsForm::numericUpDown1_ValueChanged);
            //
            // semBox
            //
            this->semBox->FormattingEnabled = true;
            this->semBox->Location = System::Drawing::Point(200, 112);
            this->semBox->Name = L"semBox";
            this->semBox->Size = System::Drawing::Size(121, 21);
            this->semBox->TabIndex = 2;
            this->semBox->SelectedIndexChanged +=
                gcnew System::EventHandler(this, &IssueBillsForm::comboBox1_SelectedIndexChanged);
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(48, 112);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(104, 24);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Semester:";
            //
            // button1
            //
            this->button1->Location = System::Drawing::Point(168, 184);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 23);
            this->button1->TabIndex = 4;
            this->button1->Text = L"Issue";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &IssueBillsForm::button1_Click);
            //
            // IssueBillsForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(407, 240);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->semBox);
            this->Controls->Add(this->amountBox);
            this->Controls->Add(this->label1);
            this->Name = L"IssueBillsForm";
            this->Text = L"IssueBillsForm";
            this->Load += gcnew System::EventHandler(this, &IssueBillsForm::IssueBillsForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->amountBox))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void comboBox1_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e) {}

       private:
        System::Void numericUpDown1_ValueChanged(System::Object ^ sender, System::EventArgs ^ e) {}

       private:
        System::Void IssueBillsForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                semBox->Items->Add("S1");
                semBox->Items->Add("S2");
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto due = Convert::ToDouble(amountBox->Value);
                auto semBoxVal = semBox->SelectedItem;

                if (semBoxVal == nullptr) {
                    MessageBox::Show("Please select a semester");
                    return;
                }

                if (due <= 0) {
                    MessageBox::Show("Amount must be greater than 0");
                    return;
                }

                auto sem = parseStrSemester(semBoxVal->ToString());
                auto service = gcnew PaymentsService(parent->user);
                auto issueRes = service->IssueBills(sem, due);
                MessageBox::Show(issueRes.data);
                this->Close();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
