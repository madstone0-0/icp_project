#pragma once
#include <iostream>

#include "ChooseLoginForm.h"
#include "db/Database.h"
#include "services/CourseService.h"
#include "services/EnrollService.h"
#include "services/LoginService.h"
#include "utils.h"

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
    ref class MainForm : public System::Windows::Forms::Form, IChildHost {
        DataTable ^ dt = gcnew DataTable();

       private:
        System::Windows::Forms::ToolStripMenuItem ^ adminToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ allCoursesToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ studentToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ facultyToolStripMenuItem;
        IUser ^ _user;

       public:
        virtual property IUser ^
            user {
                IUser ^ get() { return this->_user; } void set(IUser ^ value) {
                    infoMsg("User logged in: " + value->FirstName + " " + value->LastName, "MainForm");
                    this->_user = value;
                }
            }

            MainForm(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

        MainForm(IUser ^ user) {
            this->user = user;
            InitializeComponent();
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
       private:
        System::Windows::Forms::MenuStrip ^ menuStrip1;

       private:
       private:
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
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->adminToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->studentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->allCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->menuStrip1->SuspendLayout();
            this->SuspendLayout();
            //
            // menuStrip1
            //
            this->menuStrip1->Items->AddRange(gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(3){
                this->adminToolStripMenuItem, this->studentToolStripMenuItem, this->facultyToolStripMenuItem});
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(1011, 24);
            this->menuStrip1->TabIndex = 2;
            this->menuStrip1->Text = L"menuStrip1";
            //
            // adminToolStripMenuItem
            //
            this->adminToolStripMenuItem->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(1){this->allCoursesToolStripMenuItem});
            this->adminToolStripMenuItem->Name = L"adminToolStripMenuItem";
            this->adminToolStripMenuItem->Size = System::Drawing::Size(55, 20);
            this->adminToolStripMenuItem->Text = L"Admin";
            //
            // studentToolStripMenuItem
            //
            this->studentToolStripMenuItem->Name = L"studentToolStripMenuItem";
            this->studentToolStripMenuItem->Size = System::Drawing::Size(60, 20);
            this->studentToolStripMenuItem->Text = L"Student";
            //
            // facultyToolStripMenuItem
            //
            this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
            this->facultyToolStripMenuItem->Size = System::Drawing::Size(57, 20);
            this->facultyToolStripMenuItem->Text = L"Faculty";
            //
            // allCoursesToolStripMenuItem
            //
            this->allCoursesToolStripMenuItem->Name = L"allCoursesToolStripMenuItem";
            this->allCoursesToolStripMenuItem->Size = System::Drawing::Size(180, 22);
            this->allCoursesToolStripMenuItem->Text = L"All Courses";
            //
            // MainForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1011, 435);
            this->Controls->Add(this->menuStrip1);
            this->Icon = (cli::safe_cast<System::Drawing::Icon ^>(resources->GetObject(L"$this.Icon")));
            this->IsMdiContainer = true;
            this->MainMenuStrip = this->menuStrip1;
            this->Name = L"MainForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"MainForm";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
            this->MdiChildActivate += gcnew System::EventHandler(this, &MainForm::Mainform_ChildUpdate);
            this->menuStrip1->ResumeLayout(false);
            this->menuStrip1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

       private:
        System::Void MainForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            adminToolStripMenuItem->Visible = false;
            studentToolStripMenuItem->Visible = false;
            facultyToolStripMenuItem->Visible = false;
            try {
                ChooseLoginForm ^ loginForm = gcnew ChooseLoginForm(this);
                loginForm->MdiParent = this;
                loginForm->Show();
                loginForm->StartPosition = FormStartPosition::CenterParent;
                loginForm->BringToFront();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void Mainform_ChildUpdate(System::Object ^ sender, System::EventArgs ^ e) {
            if (_user != nullptr) {
                infoMsg("User logged in: " + _user->FirstName + " " + _user->LastName, "MainForm");
                if (_user->GetType() == Admin::typeid) {
                    // Admin
                    // Add Admin Menu
                    infoMsg("Admin logged in", "MainForm");
                    adminToolStripMenuItem->Visible = true;
                } else if (_user->GetType() == Student::typeid) {
                    // Student
                    // Add Student Menu
                    infoMsg("Student logged in", "MainForm");
                    studentToolStripMenuItem->Visible = true;
                } else if (_user->GetType() == Faculty::typeid) {
                    // Faculty
                    // Add Faculty Menu
                    infoMsg("Faculty logged in", "MainForm");
                    facultyToolStripMenuItem->Visible = true;
                }
            }
        }

       private:
        System::Void exitToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            Application::Exit();
        }
    };
}  // namespace icpproject
