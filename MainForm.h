#pragma once
#include <iostream>

#include "db/Database.h"
#include "services/LoginService.h"

namespace icpproject {
    using namespace std;
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Collections::Generic;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for MainForm
    /// </summary>
   public
    ref class MainForm : public System::Windows::Forms::Form {
        DataTable ^ dt = gcnew DataTable();

       public:
        MainForm(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MainForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::DataGridView ^ usersGrid;

       protected:
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
            this->usersGrid = (gcnew System::Windows::Forms::DataGridView());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->usersGrid))->BeginInit();
            this->SuspendLayout();
            //
            // usersGrid
            //
            this->usersGrid->AllowUserToAddRows = false;
            this->usersGrid->AllowUserToDeleteRows = false;
            this->usersGrid->ColumnHeadersHeightSizeMode =
                System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->usersGrid->Location = System::Drawing::Point(28, 32);
            this->usersGrid->Name = L"usersGrid";
            this->usersGrid->ReadOnly = true;
            this->usersGrid->Size = System::Drawing::Size(707, 286);
            this->usersGrid->TabIndex = 0;
            //
            // MainForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(770, 360);
            this->Controls->Add(this->usersGrid);
            this->Name = L"MainForm";
            this->Text = L"MainForm";
            this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->usersGrid))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

       private:
        System::Void MainForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto res = db::Ins()->execute("select * from user");
                dt->Load(res);
                res->Close();
                usersGrid->DataSource = dt;
            } catch (Exception ^ e) {
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
