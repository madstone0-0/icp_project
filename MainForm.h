#pragma once
#include <iostream>

#include "AddCourseForm.h"
#include "AddScheduleForm.h"
#include "ChooseLoginForm.h"
#include "EnrollForm.h"
#include "EnumerationForm.h"
#include "FacultyCoursesForm.h"
#include "FacultyProfileForm.h"
#include "FeesForm.h"
#include "GenerateTranscriptForm.h"
#include "IssueBillsForm.h"
#include "ManagePrereqsForm.h"
#include "PaymentTracker.h"
#include "StudentProfileForm.h"
#include "StudentScheduleForm.h"
#include "TranscriptForm.h"
#include "ViewAssignmentsForm.h"
#include "ViewScheduleForm.h"
#include "db/Database.h"
#include "services/AuditService.h"
#include "services/CourseService.h"
#include "services/EnrollService.h"
#include "services/EnumerationService.h"
#include "services/LoginService.h"
#include "services/PaymentsService.h"
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
       private:
        System::Windows::Forms::ToolStripMenuItem ^ adminToolStripMenuItem;

       private:
       private:
        System::Windows::Forms::ToolStripMenuItem ^ studentToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ facultyToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ logoutToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ coursesToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ allCoursesToolStripMenuItem1;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ enumerateToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ studentsToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ facultyToolStripMenuItem1;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ auditLogToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ addCourseToolStripMenuItem;

       private:
       private:
       private:
        System::Windows::Forms::ToolStripMenuItem ^ enrollmentsToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ paymentsToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ scheduleToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ viewScheduleToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ addScheduleToolStripMenuItem;

       private:
       private:
        System::Windows::Forms::ToolStripMenuItem ^ managePrerequistesToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ facultyToolStripMenuItem2;

       private:
       private:
        System::Windows::Forms::ToolStripMenuItem ^ viewCourseAssignmentsToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ studentToolStripMenuItem1;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ generateTranscriptToolStripMenuItem1;

       private:
        System::Windows::Forms::BindingSource ^ bindingSource1;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ profileToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ transcriptToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ courseToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ viewEnrolledCoursesToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ enrollInCourseToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ feesToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ viewScheduleToolStripMenuItem1;

       private:
        IUser ^ _user;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ profileToolStripMenuItem1;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ coursesToolStripMenuItem1;

       private:
       private:
       private:
        System::Windows::Forms::ToolStripMenuItem ^ issuePaymentsToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ issueBillsToolStripMenuItem;

       private:
        System::Windows::Forms::ToolStripMenuItem ^ trackPaymentsToolStripMenuItem;
        EnumerationService ^ enumService;

       public:
        virtual property IUser ^
            user {
                IUser ^ get() { return this->_user; } void set(IUser ^ value) { this->_user = value; }
            }

            MainForm(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

        MainForm(IUser ^ user) {
            this->user = user;
            enumService = gcnew EnumerationService(this->_user);
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
        System::ComponentModel::IContainer ^ components;

       private:
       private:
       protected:
       private:
       protected:
       private:
        /// <summary>
        /// Required designer variable.
        /// </summary>

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void) {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager ^ resources =
                (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
            this->adminToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->coursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->allCoursesToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->addCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->managePrerequistesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->facultyToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->viewCourseAssignmentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->studentToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->generateTranscriptToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->enumerateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->studentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->facultyToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->enrollmentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->paymentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->issuePaymentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->issueBillsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->trackPaymentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->scheduleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->viewScheduleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->addScheduleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->auditLogToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->studentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->profileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->transcriptToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->courseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->viewEnrolledCoursesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->enrollInCourseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->viewScheduleToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->feesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->facultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->profileToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->coursesToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->logoutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
            this->menuStrip1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->bindingSource1))->BeginInit();
            this->SuspendLayout();
            //
            // menuStrip1
            //
            this->menuStrip1->Items->AddRange(gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(4){
                this->adminToolStripMenuItem, this->studentToolStripMenuItem, this->facultyToolStripMenuItem,
                this->logoutToolStripMenuItem});
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(1011, 24);
            this->menuStrip1->TabIndex = 2;
            this->menuStrip1->Text = L"menuStrip1";
            //
            // adminToolStripMenuItem
            //
            this->adminToolStripMenuItem->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(5){
                    this->coursesToolStripMenuItem, this->enumerateToolStripMenuItem,
                    this->issuePaymentsToolStripMenuItem, this->scheduleToolStripMenuItem,
                    this->auditLogToolStripMenuItem});
            this->adminToolStripMenuItem->Name = L"adminToolStripMenuItem";
            this->adminToolStripMenuItem->Size = System::Drawing::Size(55, 20);
            this->adminToolStripMenuItem->Text = L"Admin";
            //
            // coursesToolStripMenuItem
            //
            this->coursesToolStripMenuItem->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(5){
                    this->allCoursesToolStripMenuItem1, this->addCourseToolStripMenuItem,
                    this->managePrerequistesToolStripMenuItem, this->facultyToolStripMenuItem2,
                    this->studentToolStripMenuItem1});
            this->coursesToolStripMenuItem->Name = L"coursesToolStripMenuItem";
            this->coursesToolStripMenuItem->Size = System::Drawing::Size(131, 22);
            this->coursesToolStripMenuItem->Text = L"Courses";
            //
            // allCoursesToolStripMenuItem1
            //
            this->allCoursesToolStripMenuItem1->Name = L"allCoursesToolStripMenuItem1";
            this->allCoursesToolStripMenuItem1->Size = System::Drawing::Size(162, 22);
            this->allCoursesToolStripMenuItem1->Text = L"All Courses";
            this->allCoursesToolStripMenuItem1->Click +=
                gcnew System::EventHandler(this, &MainForm::allCoursesToolStripMenuItem1_Click);
            //
            // addCourseToolStripMenuItem
            //
            this->addCourseToolStripMenuItem->Name = L"addCourseToolStripMenuItem";
            this->addCourseToolStripMenuItem->Size = System::Drawing::Size(162, 22);
            this->addCourseToolStripMenuItem->Text = L"Add Course";
            this->addCourseToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::addCourseToolStripMenuItem_Click);
            //
            // managePrerequistesToolStripMenuItem
            //
            this->managePrerequistesToolStripMenuItem->Name = L"managePrerequistesToolStripMenuItem";
            this->managePrerequistesToolStripMenuItem->Size = System::Drawing::Size(162, 22);
            this->managePrerequistesToolStripMenuItem->Text = L"Manage Courses";
            this->managePrerequistesToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::managePrerequistesToolStripMenuItem_Click);
            //
            // facultyToolStripMenuItem2
            //
            this->facultyToolStripMenuItem2->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(1){
                    this->viewCourseAssignmentsToolStripMenuItem});
            this->facultyToolStripMenuItem2->Name = L"facultyToolStripMenuItem2";
            this->facultyToolStripMenuItem2->Size = System::Drawing::Size(162, 22);
            this->facultyToolStripMenuItem2->Text = L"Faculty";
            //
            // viewCourseAssignmentsToolStripMenuItem
            //
            this->viewCourseAssignmentsToolStripMenuItem->Name = L"viewCourseAssignmentsToolStripMenuItem";
            this->viewCourseAssignmentsToolStripMenuItem->Size = System::Drawing::Size(228, 22);
            this->viewCourseAssignmentsToolStripMenuItem->Text = L"Manage Course Assignments";
            this->viewCourseAssignmentsToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::viewCourseAssignmentsToolStripMenuItem_Click);
            //
            // studentToolStripMenuItem1
            //
            this->studentToolStripMenuItem1->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(1){
                    this->generateTranscriptToolStripMenuItem1});
            this->studentToolStripMenuItem1->Name = L"studentToolStripMenuItem1";
            this->studentToolStripMenuItem1->Size = System::Drawing::Size(162, 22);
            this->studentToolStripMenuItem1->Text = L"Student";
            //
            // generateTranscriptToolStripMenuItem1
            //
            this->generateTranscriptToolStripMenuItem1->Name = L"generateTranscriptToolStripMenuItem1";
            this->generateTranscriptToolStripMenuItem1->Size = System::Drawing::Size(176, 22);
            this->generateTranscriptToolStripMenuItem1->Text = L"Generate Transcript";
            this->generateTranscriptToolStripMenuItem1->Click +=
                gcnew System::EventHandler(this, &MainForm::generateTranscriptToolStripMenuItem1_Click);
            //
            // enumerateToolStripMenuItem
            //
            this->enumerateToolStripMenuItem->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(4){
                    this->studentsToolStripMenuItem, this->facultyToolStripMenuItem1,
                    this->enrollmentsToolStripMenuItem, this->paymentsToolStripMenuItem});
            this->enumerateToolStripMenuItem->Name = L"enumerateToolStripMenuItem";
            this->enumerateToolStripMenuItem->Size = System::Drawing::Size(131, 22);
            this->enumerateToolStripMenuItem->Text = L"Enumerate";
            //
            // studentsToolStripMenuItem
            //
            this->studentsToolStripMenuItem->Name = L"studentsToolStripMenuItem";
            this->studentsToolStripMenuItem->Size = System::Drawing::Size(137, 22);
            this->studentsToolStripMenuItem->Text = L"Students";
            this->studentsToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::studentsToolStripMenuItem_Click);
            //
            // facultyToolStripMenuItem1
            //
            this->facultyToolStripMenuItem1->Name = L"facultyToolStripMenuItem1";
            this->facultyToolStripMenuItem1->Size = System::Drawing::Size(137, 22);
            this->facultyToolStripMenuItem1->Text = L"Faculty";
            this->facultyToolStripMenuItem1->Click +=
                gcnew System::EventHandler(this, &MainForm::facultyToolStripMenuItem1_Click);
            //
            // enrollmentsToolStripMenuItem
            //
            this->enrollmentsToolStripMenuItem->Name = L"enrollmentsToolStripMenuItem";
            this->enrollmentsToolStripMenuItem->Size = System::Drawing::Size(137, 22);
            this->enrollmentsToolStripMenuItem->Text = L"Enrollments";
            this->enrollmentsToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::enrollmentsToolStripMenuItem_Click);
            //
            // paymentsToolStripMenuItem
            //
            this->paymentsToolStripMenuItem->Name = L"paymentsToolStripMenuItem";
            this->paymentsToolStripMenuItem->Size = System::Drawing::Size(137, 22);
            this->paymentsToolStripMenuItem->Text = L"Payments";
            this->paymentsToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::paymentsToolStripMenuItem_Click);
            //
            // issuePaymentsToolStripMenuItem
            //
            this->issuePaymentsToolStripMenuItem->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(2){this->issueBillsToolStripMenuItem,
                                                                             this->trackPaymentsToolStripMenuItem});
            this->issuePaymentsToolStripMenuItem->Name = L"issuePaymentsToolStripMenuItem";
            this->issuePaymentsToolStripMenuItem->Size = System::Drawing::Size(131, 22);
            this->issuePaymentsToolStripMenuItem->Text = L"Payments";
            //
            // issueBillsToolStripMenuItem
            //
            this->issueBillsToolStripMenuItem->Name = L"issueBillsToolStripMenuItem";
            this->issueBillsToolStripMenuItem->Size = System::Drawing::Size(157, 22);
            this->issueBillsToolStripMenuItem->Text = L"Issue Bills";
            this->issueBillsToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::issueBillsToolStripMenuItem_Click);
            //
            // trackPaymentsToolStripMenuItem
            //
            this->trackPaymentsToolStripMenuItem->Name = L"trackPaymentsToolStripMenuItem";
            this->trackPaymentsToolStripMenuItem->Size = System::Drawing::Size(157, 22);
            this->trackPaymentsToolStripMenuItem->Text = L"Track Payments";
            this->trackPaymentsToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::trackPaymentsToolStripMenuItem_Click);
            //
            // scheduleToolStripMenuItem
            //
            this->scheduleToolStripMenuItem->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(2){this->viewScheduleToolStripMenuItem,
                                                                             this->addScheduleToolStripMenuItem});
            this->scheduleToolStripMenuItem->Name = L"scheduleToolStripMenuItem";
            this->scheduleToolStripMenuItem->Size = System::Drawing::Size(131, 22);
            this->scheduleToolStripMenuItem->Text = L"Schedule";
            //
            // viewScheduleToolStripMenuItem
            //
            this->viewScheduleToolStripMenuItem->Name = L"viewScheduleToolStripMenuItem";
            this->viewScheduleToolStripMenuItem->Size = System::Drawing::Size(150, 22);
            this->viewScheduleToolStripMenuItem->Text = L"View Schedule";
            this->viewScheduleToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::viewScheduleToolStripMenuItem_Click);
            //
            // addScheduleToolStripMenuItem
            //
            this->addScheduleToolStripMenuItem->Name = L"addScheduleToolStripMenuItem";
            this->addScheduleToolStripMenuItem->Size = System::Drawing::Size(150, 22);
            this->addScheduleToolStripMenuItem->Text = L"Add Schedule";
            this->addScheduleToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::addScheduleToolStripMenuItem_Click);
            //
            // auditLogToolStripMenuItem
            //
            this->auditLogToolStripMenuItem->Name = L"auditLogToolStripMenuItem";
            this->auditLogToolStripMenuItem->Size = System::Drawing::Size(131, 22);
            this->auditLogToolStripMenuItem->Text = L"Audit Log";
            this->auditLogToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::auditLogToolStripMenuItem_Click);
            //
            // studentToolStripMenuItem
            //
            this->studentToolStripMenuItem->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(4){
                    this->profileToolStripMenuItem, this->transcriptToolStripMenuItem, this->courseToolStripMenuItem,
                    this->feesToolStripMenuItem});
            this->studentToolStripMenuItem->Name = L"studentToolStripMenuItem";
            this->studentToolStripMenuItem->Size = System::Drawing::Size(60, 20);
            this->studentToolStripMenuItem->Text = L"Student";
            //
            // profileToolStripMenuItem
            //
            this->profileToolStripMenuItem->Name = L"profileToolStripMenuItem";
            this->profileToolStripMenuItem->Size = System::Drawing::Size(180, 22);
            this->profileToolStripMenuItem->Text = L"Profile";
            this->profileToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::profileToolStripMenuItem_Click);
            //
            // transcriptToolStripMenuItem
            //
            this->transcriptToolStripMenuItem->Name = L"transcriptToolStripMenuItem";
            this->transcriptToolStripMenuItem->Size = System::Drawing::Size(180, 22);
            this->transcriptToolStripMenuItem->Text = L"Transcript";
            this->transcriptToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::transcriptToolStripMenuItem_Click);
            //
            // courseToolStripMenuItem
            //
            this->courseToolStripMenuItem->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(3){this->viewEnrolledCoursesToolStripMenuItem,
                                                                             this->enrollInCourseToolStripMenuItem,
                                                                             this->viewScheduleToolStripMenuItem1});
            this->courseToolStripMenuItem->Name = L"courseToolStripMenuItem";
            this->courseToolStripMenuItem->Size = System::Drawing::Size(180, 22);
            this->courseToolStripMenuItem->Text = L"Course";
            //
            // viewEnrolledCoursesToolStripMenuItem
            //
            this->viewEnrolledCoursesToolStripMenuItem->Name = L"viewEnrolledCoursesToolStripMenuItem";
            this->viewEnrolledCoursesToolStripMenuItem->Size = System::Drawing::Size(190, 22);
            this->viewEnrolledCoursesToolStripMenuItem->Text = L"View Enrolled Courses";
            this->viewEnrolledCoursesToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::viewEnrolledCoursesToolStripMenuItem_Click);
            //
            // enrollInCourseToolStripMenuItem
            //
            this->enrollInCourseToolStripMenuItem->Name = L"enrollInCourseToolStripMenuItem";
            this->enrollInCourseToolStripMenuItem->Size = System::Drawing::Size(190, 22);
            this->enrollInCourseToolStripMenuItem->Text = L"Enroll In Course";
            this->enrollInCourseToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::enrollInCourseToolStripMenuItem_Click);
            //
            // viewScheduleToolStripMenuItem1
            //
            this->viewScheduleToolStripMenuItem1->Name = L"viewScheduleToolStripMenuItem1";
            this->viewScheduleToolStripMenuItem1->Size = System::Drawing::Size(190, 22);
            this->viewScheduleToolStripMenuItem1->Text = L"View Schedule";
            this->viewScheduleToolStripMenuItem1->Click +=
                gcnew System::EventHandler(this, &MainForm::viewScheduleToolStripMenuItem1_Click);
            //
            // feesToolStripMenuItem
            //
            this->feesToolStripMenuItem->Name = L"feesToolStripMenuItem";
            this->feesToolStripMenuItem->Size = System::Drawing::Size(180, 22);
            this->feesToolStripMenuItem->Text = L"Fees";
            this->feesToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::feesToolStripMenuItem_Click);
            //
            // facultyToolStripMenuItem
            //
            this->facultyToolStripMenuItem->DropDownItems->AddRange(
                gcnew cli::array<System::Windows::Forms::ToolStripItem ^>(2){this->profileToolStripMenuItem1,
                                                                             this->coursesToolStripMenuItem1});
            this->facultyToolStripMenuItem->Name = L"facultyToolStripMenuItem";
            this->facultyToolStripMenuItem->Size = System::Drawing::Size(57, 20);
            this->facultyToolStripMenuItem->Text = L"Faculty";
            //
            // profileToolStripMenuItem1
            //
            this->profileToolStripMenuItem1->Name = L"profileToolStripMenuItem1";
            this->profileToolStripMenuItem1->Size = System::Drawing::Size(162, 22);
            this->profileToolStripMenuItem1->Text = L"Profile";
            this->profileToolStripMenuItem1->Click +=
                gcnew System::EventHandler(this, &MainForm::profileToolStripMenuItem1_Click);
            //
            // coursesToolStripMenuItem1
            //
            this->coursesToolStripMenuItem1->Name = L"coursesToolStripMenuItem1";
            this->coursesToolStripMenuItem1->Size = System::Drawing::Size(162, 22);
            this->coursesToolStripMenuItem1->Text = L"Manage Courses";
            this->coursesToolStripMenuItem1->Click +=
                gcnew System::EventHandler(this, &MainForm::coursesToolStripMenuItem1_Click);
            //
            // logoutToolStripMenuItem
            //
            this->logoutToolStripMenuItem->Name = L"logoutToolStripMenuItem";
            this->logoutToolStripMenuItem->Size = System::Drawing::Size(57, 20);
            this->logoutToolStripMenuItem->Text = L"Logout";
            this->logoutToolStripMenuItem->Click +=
                gcnew System::EventHandler(this, &MainForm::logoutToolStripMenuItem_Click);
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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->bindingSource1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

       private:
        System::Void MainForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            adminToolStripMenuItem->Visible = false;
            studentToolStripMenuItem->Visible = false;
            facultyToolStripMenuItem->Visible = false;
            logoutToolStripMenuItem->Visible = false;
            try {
                ChooseLoginForm ^ loginForm = gcnew ChooseLoginForm(this);
                loginForm->MdiParent = this;
                loginForm->Show();
                loginForm->StartPosition = FormStartPosition::CenterParent;
                loginForm->WindowState = FormWindowState::Normal;
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
                    logoutToolStripMenuItem->Visible = true;
                } else if (_user->GetType() == Student::typeid) {
                    // Student
                    // Add Student Menu
                    infoMsg("Student logged in", "MainForm");
                    studentToolStripMenuItem->Visible = true;
                    logoutToolStripMenuItem->Visible = true;
                } else if (_user->GetType() == Faculty::typeid) {
                    // Faculty
                    // Add Faculty Menu
                    infoMsg("Faculty logged in", "MainForm");
                    facultyToolStripMenuItem->Visible = true;
                    logoutToolStripMenuItem->Visible = true;
                }
            }
        }

       private:
        System::Void exitToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            Application::Exit();
        }

       public:
        virtual void showChooseForm() {
            user = nullptr;
            for each (Form ^ form in MdiChildren) {
                form->Close();
            }
            adminToolStripMenuItem->Visible = false;
            studentToolStripMenuItem->Visible = false;
            facultyToolStripMenuItem->Visible = false;
            logoutToolStripMenuItem->Visible = false;
            try {
                ChooseLoginForm ^ loginForm = gcnew ChooseLoginForm(this);
                loginForm->MdiParent = this;
                loginForm->Show();
                loginForm->StartPosition = FormStartPosition::CenterParent;
                loginForm->WindowState = FormWindowState::Normal;
                loginForm->BringToFront();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void logoutToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) { showChooseForm(); }

       private:
        System::Void allCoursesToolStripMenuItem1_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                CourseService ^ service = gcnew CourseService(user);
                auto res = service->GetAll();
                if (res.status) {
                    EnumerationForm ^ enumForm = gcnew EnumerationForm("All Courses", res.data);
                    enumForm->MdiParent = this;
                    enumForm->StartPosition = FormStartPosition::CenterScreen;
                    enumForm->Show();
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void studentsToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto res = enumService->GetAllStudents();
                Audit::Ins()->Log("Get all students", user->UID);
                if (res.status) {
                    EnumerationForm ^ enumForm = gcnew EnumerationForm("All Students", res.data);
                    enumForm->MdiParent = this;
                    enumForm->StartPosition = FormStartPosition::CenterScreen;
                    enumForm->Show();
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void facultyToolStripMenuItem1_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto res = enumService->GetAllFaculty();
                Audit::Ins()->Log("Get all faculty", user->UID);
                if (res.status) {
                    EnumerationForm ^ enumForm = gcnew EnumerationForm("All Faculty", res.data);
                    enumForm->MdiParent = this;
                    enumForm->StartPosition = FormStartPosition::CenterScreen;
                    enumForm->Show();
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void auditLogToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto res = Audit::Ins()->GetAll();
                if (res.status) {
                    EnumerationForm ^ enumForm = gcnew EnumerationForm("Audit Log", res.data);
                    enumForm->MdiParent = this;
                    enumForm->StartPosition = FormStartPosition::CenterScreen;
                    enumForm->Show();
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void managePrerequistesToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto updateCourse = gcnew UpdateCourseForm(this);
                updateCourse->MdiParent = this;
                updateCourse->StartPosition = FormStartPosition::CenterScreen;
                updateCourse->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
       private:
        System::Void profileToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                Student ^ student = dynamic_cast<Student ^>(user);
                if (student == nullptr) {
                    throw gcnew Exception("User is not a student");
                }
                StudentProfileForm ^ profileForm = gcnew StudentProfileForm(this);
                profileForm->MdiParent = this;
                profileForm->StartPosition = FormStartPosition::CenterScreen;
                profileForm->Show();

            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void addCourseToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                AddCourseForm ^ courseForm = gcnew AddCourseForm(this);
                courseForm->MdiParent = this;
                courseForm->StartPosition = FormStartPosition::CenterScreen;
                courseForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void enrollmentsToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                EnrollService ^ service = gcnew EnrollService(user);
                auto res = service->GetAll();
                if (res.status) {
                    EnumerationForm ^ enumForm = gcnew EnumerationForm("Enrollments", res.data, true,
                                                                       "delete from enrollment where eid = @id", "eid");
                    enumForm->MdiParent = this;
                    enumForm->StartPosition = FormStartPosition::CenterScreen;
                    enumForm->Show();
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void viewEnrolledCoursesToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                EnrollService ^ service = gcnew EnrollService(user);
                auto res = service->GetByUId(user->UID);
                if (res.status) {
                    DataTable ^ dt = gcnew DataTable();
                    dt->Columns->Add("Course Name");
                    dt->Columns->Add("Grade");
                    dt->Columns->Add("Semester");
                    dt->Columns->Add("Credits");
                    for each (auto item in res.data) {
                        dt->Rows->Add(item.cname, parseGrade(item.grade, true), parseSemester(item.sem),
                                      Convert::ToString(item.credits));
                    }
                    EnumerationForm ^ enumForm = gcnew EnumerationForm("Enrolled Courses", dt);
                    enumForm->MdiParent = this;
                    enumForm->StartPosition = FormStartPosition::CenterScreen;
                    enumForm->Show();
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void enrollInCourseToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                EnrollForm ^ enrollForm = gcnew EnrollForm(this);
                enrollForm->MdiParent = this;
                enrollForm->StartPosition = FormStartPosition::CenterScreen;
                enrollForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void transcriptToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto transcriptForm = gcnew TranscriptForm(this);
                transcriptForm->MdiParent = this;
                transcriptForm->StartPosition = FormStartPosition::CenterScreen;
                transcriptForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void viewScheduleToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto viewScheduleForm = gcnew ViewScheduleForm(this);
                viewScheduleForm->MdiParent = this;
                viewScheduleForm->StartPosition = FormStartPosition::CenterScreen;
                viewScheduleForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void viewScheduleToolStripMenuItem1_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto viewForm = gcnew StudentScheduleForm(this);
                viewForm->MdiParent = this;
                viewForm->StartPosition = FormStartPosition::CenterScreen;
                viewForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void assignCourseToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {}

       private:
        System::Void generateTranscriptToolStripMenuItem1_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto generateTranscriptForm = gcnew GenerateTranscriptForm(this);
                generateTranscriptForm->MdiParent = this;
                generateTranscriptForm->StartPosition = FormStartPosition::CenterScreen;
                generateTranscriptForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void addScheduleToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto addScheduleForm = gcnew AddScheduleForm(this);
                addScheduleForm->MdiParent = this;
                addScheduleForm->StartPosition = FormStartPosition::CenterScreen;
                addScheduleForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void manageCoursesToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto manageCoursesForm = gcnew FacultyCoursesForm(this);
                manageCoursesForm->MdiParent = this;
                manageCoursesForm->StartPosition = FormStartPosition::CenterScreen;
                manageCoursesForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void paymentsToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto paymentsService = gcnew PaymentsService(user);
                auto payRes = paymentsService->GetAll();
                auto payments = payRes.data;
                auto enumForm = gcnew EnumerationForm("Payments", payments);
                enumForm->MdiParent = this;
                enumForm->StartPosition = FormStartPosition::CenterScreen;
                enumForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
       private:
        System::Void issueBillsToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto issueBillsForm = gcnew IssueBillsForm(this);
                issueBillsForm->MdiParent = this;
                issueBillsForm->StartPosition = FormStartPosition::CenterScreen;
                issueBillsForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void trackPaymentsToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto trackingForm = gcnew PaymentTracker(this);
                trackingForm->MdiParent = this;
                trackingForm->StartPosition = FormStartPosition::CenterScreen;
                trackingForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void viewCourseAssignmentsToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto viewForm = gcnew ViewAssignmentsForm(this);
                viewForm->MdiParent = this;
                viewForm->StartPosition = FormStartPosition::CenterScreen;
                viewForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void profileToolStripMenuItem1_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto facProfileForm = gcnew FacultyProfileForm(this);
                facProfileForm->MdiParent = this;
                facProfileForm->StartPosition = FormStartPosition::CenterScreen;
                facProfileForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void coursesToolStripMenuItem1_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto manageCoursesForm = gcnew FacultyCoursesForm(this);
                manageCoursesForm->MdiParent = this;
                manageCoursesForm->StartPosition = FormStartPosition::CenterScreen;
                manageCoursesForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void feesToolStripMenuItem_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto feesForm = gcnew FeesForm(this);
                feesForm->MdiParent = this;
                feesForm->StartPosition = FormStartPosition::CenterScreen;
                feesForm->Show();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
