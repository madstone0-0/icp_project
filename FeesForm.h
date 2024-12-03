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
    /// Summary for FeesForm
    /// </summary>
   public
    ref class FeesForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       private:
        System::Windows::Forms::SplitContainer ^ splitContainer1;

       private:
        System::Windows::Forms::ListBox ^ payBox;

       private:
        System::Windows::Forms::Button ^ payBtn;

       private:
        System::Windows::Forms::NumericUpDown ^ money;

       private:
       private:
       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::Label ^ paidLab;

       private:
        System::Windows::Forms::Label ^ dueLab;
        PaymentsService ^ service;

       public:
        FeesForm(IChildHost ^ parent) {
            this->parent = parent;
            service = gcnew PaymentsService(parent->user);
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~FeesForm() {
            if (components) {
                delete components;
            }
        }

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
            this->payBox = (gcnew System::Windows::Forms::ListBox());
            this->paidLab = (gcnew System::Windows::Forms::Label());
            this->dueLab = (gcnew System::Windows::Forms::Label());
            this->payBtn = (gcnew System::Windows::Forms::Button());
            this->money = (gcnew System::Windows::Forms::NumericUpDown());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->BeginInit();
            this->splitContainer1->Panel1->SuspendLayout();
            this->splitContainer1->Panel2->SuspendLayout();
            this->splitContainer1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->money))->BeginInit();
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
            this->splitContainer1->Panel1->Controls->Add(this->payBox);
            //
            // splitContainer1.Panel2
            //
            this->splitContainer1->Panel2->Controls->Add(this->paidLab);
            this->splitContainer1->Panel2->Controls->Add(this->dueLab);
            this->splitContainer1->Panel2->Controls->Add(this->payBtn);
            this->splitContainer1->Panel2->Controls->Add(this->money);
            this->splitContainer1->Panel2->Controls->Add(this->label2);
            this->splitContainer1->Panel2->Controls->Add(this->label1);
            this->splitContainer1->Panel2->Paint +=
                gcnew System::Windows::Forms::PaintEventHandler(this, &FeesForm::splitContainer1_Panel2_Paint);
            this->splitContainer1->Size = System::Drawing::Size(641, 256);
            this->splitContainer1->SplitterDistance = 213;
            this->splitContainer1->TabIndex = 0;
            //
            // payBox
            //
            this->payBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
                 System::Windows::Forms::AnchorStyles::Left));
            this->payBox->FormattingEnabled = true;
            this->payBox->Location = System::Drawing::Point(8, 8);
            this->payBox->Name = L"payBox";
            this->payBox->Size = System::Drawing::Size(200, 238);
            this->payBox->TabIndex = 0;
            this->payBox->SelectedIndexChanged +=
                gcnew System::EventHandler(this, &FeesForm::payBox_SelectedIndexChanged);
            //
            // paidLab
            //
            this->paidLab->AutoSize = true;
            this->paidLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->paidLab->Location = System::Drawing::Point(328, 32);
            this->paidLab->Name = L"paidLab";
            this->paidLab->Size = System::Drawing::Size(44, 16);
            this->paidLab->TabIndex = 6;
            this->paidLab->Text = L"label4";
            //
            // dueLab
            //
            this->dueLab->AutoSize = true;
            this->dueLab->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->dueLab->Location = System::Drawing::Point(112, 32);
            this->dueLab->Name = L"dueLab";
            this->dueLab->Size = System::Drawing::Size(44, 16);
            this->dueLab->TabIndex = 5;
            this->dueLab->Text = L"label3";
            //
            // payBtn
            //
            this->payBtn->Location = System::Drawing::Point(152, 200);
            this->payBtn->Name = L"payBtn";
            this->payBtn->Size = System::Drawing::Size(75, 23);
            this->payBtn->TabIndex = 4;
            this->payBtn->Text = L"Pay";
            this->payBtn->UseVisualStyleBackColor = true;
            this->payBtn->Click += gcnew System::EventHandler(this, &FeesForm::payBtn_Click);
            //
            // money
            //
            this->money->Location = System::Drawing::Point(24, 200);
            this->money->Maximum = System::Decimal(gcnew cli::array<System::Int32>(4){1410065407, 2, 0, 0});
            this->money->Name = L"money";
            this->money->Size = System::Drawing::Size(120, 20);
            this->money->TabIndex = 3;
            this->money->ValueChanged += gcnew System::EventHandler(this, &FeesForm::money_ValueChanged);
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(272, 32);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(49, 20);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Paid:";
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(16, 32);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(92, 20);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Total Due:";
            //
            // FeesForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(641, 256);
            this->Controls->Add(this->splitContainer1);
            this->Name = L"FeesForm";
            this->Text = L"FeesForm";
            this->Load += gcnew System::EventHandler(this, &FeesForm::FeesForm_Load);
            this->splitContainer1->Panel1->ResumeLayout(false);
            this->splitContainer1->Panel2->ResumeLayout(false);
            this->splitContainer1->Panel2->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->splitContainer1))->EndInit();
            this->splitContainer1->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->money))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion
       private:
        Payment ^ selectedPayment;
        void updatePayments() {
            try {
                auto res = service->GetOutstandingByUID(parent->user->UID);
                if (!res.status) {
                    MessageBox::Show("Failed to get payments");
                    return;
                }
                payBox->Items->Clear();
                auto payments = res.data;
                for each (auto payment in payments) {
                    auto kvp = gcnew KeyValuePair<long long, STR>(
                        payment.pid, String::Format("{0} - {1}", parseSemester(payment.sem), payment.totalAmount));
                    payBox->Items->Add(kvp);
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

        void updateSelection() {
            try {
                auto selected = payBox->SelectedItem;
                if (selected == nullptr) {
                    return;
                }
                auto kvp = safe_cast<KeyValuePair<long long, STR> ^>(selected);
                auto res = service->GetById(kvp->Key);
                if (!res.status) {
                    MessageBox::Show("Failed to get payment");
                    return;
                }
                auto payment = res.data;
                selectedPayment = payment;
                paidLab->Text = payment->paidAmount.ToString();
                dueLab->Text = payment->totalAmount.ToString();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

        System::Void payBox_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e) { updateSelection(); }

       private:
        System::Void FeesForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                updatePayments();
                updateSelection();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void payBtn_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto selected = payBox->SelectedItem;
                if (selected == nullptr) {
                    MessageBox::Show("Please select a payment");
                    return;
                }
                auto pid = selectedPayment->pid;
                auto total = selectedPayment->totalAmount;
                auto sem = selectedPayment->sem;
                auto paid = selectedPayment->paidAmount;
                auto amount = Convert::ToDouble(money->Value);
                if (amount <= 0) {
                    MessageBox::Show("Please enter a valid amount");
                    return;
                }

                if (amount + paid > total) {
                    MessageBox::Show("Amount exceeds total due");
                    return;
                }
                auto payRes = service->PayBill(parent->user->UID, sem, amount);
                if (!payRes.status) {
                    MessageBox::Show("Failed to pay bill");
                    return;
                }
                MessageBox::Show(payRes.data);
                updatePayments();
                payBox->SelectedIndex = 0;
                updateSelection();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void money_ValueChanged(System::Object ^ sender, System::EventArgs ^ e) {}

       private:
        System::Void splitContainer1_Panel2_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e) {
        }
    };
}  // namespace icpproject
