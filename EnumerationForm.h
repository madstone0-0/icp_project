#pragma once

#include "db/Database.h"
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
        STR deleteCommand;
        STR idColname;

       private:
        System::Windows::Forms::Button ^ button1;
        Object ^ dataSource;
        BindingSource ^ bs;

       private:
        System::Windows::Forms::Button ^ button2;
        bool enableSync = false;

       public:
        EnumerationForm(STR t, Object ^ data) {
            title = t;
            dataSource = data;
            bs = gcnew BindingSource(dataSource, "");
            InitializeComponent();
        }

        EnumerationForm(STR t, Object ^ data, bool enableSync, STR deleteCommand, STR idColname) {
            title = t;
            dataSource = data;
            bs = gcnew BindingSource(dataSource, "");
            this->deleteCommand = deleteCommand;
            this->idColname = idColname;
            this->enableSync = enableSync;
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
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
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
            this->label1->Location = System::Drawing::Point(408, 8);
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
            this->GV->Location = System::Drawing::Point(64, 72);
            this->GV->Name = L"GV";
            this->GV->ReadOnly = true;
            this->GV->Size = System::Drawing::Size(792, 336);
            this->GV->TabIndex = 2;
            //
            // button1
            //
            this->button1->Location = System::Drawing::Point(328, 424);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(112, 23);
            this->button1->TabIndex = 4;
            this->button1->Text = L"Sync Changes";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &EnumerationForm::button1_Click);
            //
            // button2
            //
            this->button2->Location = System::Drawing::Point(472, 424);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(112, 23);
            this->button2->TabIndex = 5;
            this->button2->Text = L"Discard Changes";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &EnumerationForm::button2_Click);
            //
            // EnumerationForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(910, 464);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
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
            bs->DataSource = dataSource;
            GV->DataSource = bs;
            if (!enableSync) {
                button1->Enabled = false;
                button2->Enabled = false;
                GV->EditMode = DataGridViewEditMode::EditProgrammatically;
            }
        }

       private:
        System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto diagRes = MessageBox::Show("Do you want to sync changes?", "Sync Changes",
                                                MessageBoxButtons::YesNo, MessageBoxIcon::Question);
                if (diagRes == System::Windows::Forms::DialogResult::No) return;
                GV->EndEdit();
                db::Ins()->getCmd()->CommandText = deleteCommand;
                db::Ins()->getCmd()->Parameters->Clear();
                db::Ins()->getCmd()->Parameters->Add("@id", MySqlDbType::Int32, 4, idColname);
                db::Ins()->getDta()->DeleteCommand = db::Ins()->getCmd();
                db::Ins()->getDta()->Update((DataTable ^) dataSource);
                db::Ins()->getDta()->DeleteCommand = nullptr;
                MessageBox::Show("Synced");
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void button2_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto diagRes = MessageBox::Show("Do you want to discard changes?", "Discard Changes",
                                                MessageBoxButtons::YesNo, MessageBoxIcon::Question);
                if (diagRes == System::Windows::Forms::DialogResult::No) return;
                bs->DataSource = dataSource;
                GV->Refresh();
                MessageBox::Show("Discarded");
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
