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

       private:
        System::Windows::Forms::MenuStrip ^ menuStrip1;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ fileToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ exitToolStripMenuItem;

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
            System::ComponentModel::ComponentResourceManager ^ resources =
                (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
            this->usersGrid = (gcnew System::Windows::Forms::DataGridView());
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->usersGrid))->BeginInit();
            this->menuStrip1->SuspendLayout();
            this->SuspendLayout();
            //
            // usersGrid
            //
            this->usersGrid->AllowUserToAddRows = false;
            this->usersGrid->AllowUserToDeleteRows = false;
            this->usersGrid->ColumnHeadersHeightSizeMode =
                System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->usersGrid->Location = System::Drawing::Point(29, 71);
            this->usersGrid->Name = L"usersGrid";
            this->usersGrid->ReadOnly = true;
            this->usersGrid->Size = System::Drawing::Size(707, 286);
            this->usersGrid->TabIndex = 0;
            //
            // menuStrip1
            //
            this->menuStrip1->Items->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(1){this->fileToolStripMenuItem});
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(1011, 24);
            this->menuStrip1->TabIndex = 2;
            this->menuStrip1->Text = L"menuStrip1";
            //
            // fileToolStripMenuItem
            //
            this->fileToolStripMenuItem->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(1){this->exitToolStripMenuItem});
            this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
            this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
            this->fileToolStripMenuItem->Text = L"File";
            //
            // exitToolStripMenuItem
            //
            this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
            this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
            this->exitToolStripMenuItem->Text = L"Exit";
            this->exitToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
            //
            // MainForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1011, 435);
            this->Controls->Add(this->usersGrid);
            this->Controls->Add(this->menuStrip1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon ^>(resources->GetObject(L"$this.Icon")));
            this->IsMdiContainer = true;
            this->MainMenuStrip = this->menuStrip1;
            this->MaximizeBox = false;
            this->Name = L"MainForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"MainForm";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->usersGrid))->EndInit();
            this->menuStrip1->ResumeLayout(false);
            this->menuStrip1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();
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

       private:
        System::Void exitToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            Application::Exit();
        }
    };
}  // namespace icpproject
