#pragma once
#include "utils.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for EnumerationForm
    /// </summary>
   public
    ref class EnumerationForm : public System::Windows::Forms::Form {
       private:
        STR title;
        DataTable ^ dt;

       public:
        EnumerationForm(STR t, DataTable ^ data) {
            title = t;
            dt = data;
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~EnumerationForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Label ^ label1;

       protected:
       private:
        System::Windows::Forms::DataGridView ^ GV;

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
            this->GV = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->GV))->BeginInit();
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(355, 28);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(110, 42);
            this->label1->TabIndex = 3;
            this->label1->Text = L"Label";
            //
            // GV
            //
            this->GV->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                (((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) |
                  System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->GV->ColumnHeadersHeightSizeMode =
                System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->GV->Location = System::Drawing::Point(59, 100);
            this->GV->Name = L"GV";
            this->GV->ReadOnly = true;
            this->GV->Size = System::Drawing::Size(792, 336);
            this->GV->TabIndex = 2;
            //
            // EnumerationForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(910, 464);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->GV);
            this->Name = L"EnumerationForm";
            this->Text = L"EnumerationForm";
            this->Load += gcnew System::EventHandler(this, &EnumerationForm::EnumerationForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->GV))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void EnumerationForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            label1->Text = title;
            GV->DataSource = dt;
        }
    };
}  // namespace icpproject
