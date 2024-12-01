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
    /// Summary for PaymentTracker
    /// </summary>
   public
    ref class PaymentTracker : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       public:
        PaymentTracker(IChildHost ^ parent) {
            this->parent = parent;
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~PaymentTracker() {
            if (components) {
                delete components;
            }
        }

       private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container ^ components;

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::DataGridView ^ paymentsGV;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void) {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->paymentsGV = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->paymentsGV))->BeginInit();
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(208, 16);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(309, 31);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Outstanding Payments";
            //
            // paymentsGV
            //
            this->paymentsGV->ColumnHeadersHeightSizeMode =
                System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->paymentsGV->Location = System::Drawing::Point(8, 72);
            this->paymentsGV->Name = L"paymentsGV";
            this->paymentsGV->Size = System::Drawing::Size(696, 304);
            this->paymentsGV->TabIndex = 1;
            //
            // PaymentTracker
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(712, 389);
            this->Controls->Add(this->paymentsGV);
            this->Controls->Add(this->label1);
            this->Name = L"PaymentTracker";
            this->Text = L"PaymentTracker";
            this->Load += gcnew System::EventHandler(this, &PaymentTracker::PaymentTracker_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->paymentsGV))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void PaymentTracker_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto service = gcnew PaymentsService(parent->user);
                auto res = service->GetAllOutstanding();
                auto outstanding = res.data;
                paymentsGV->DataSource = outstanding;
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
