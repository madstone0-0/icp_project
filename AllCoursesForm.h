#pragma once
#include "services/CourseService.h"
#include "utils.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for AllCoursesForm
    /// </summary>
   public
    ref class AllCoursesForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       public:
        AllCoursesForm(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

        AllCoursesForm(IChildHost ^ parent) {
            this->parent = parent;
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AllCoursesForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::DataGridView ^ courseGV;

       protected:
       private:
       protected:
       private:
        System::Windows::Forms::Label ^ label1;

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
            this->courseGV = (gcnew System::Windows::Forms::DataGridView());
            this->label1 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->courseGV))->BeginInit();
            this->SuspendLayout();
            //
            // courseGV
            //
            this->courseGV->ColumnHeadersHeightSizeMode =
                System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->courseGV->Location = System::Drawing::Point(40, 88);
            this->courseGV->Name = L"courseGV";
            this->courseGV->Size = System::Drawing::Size(792, 336);
            this->courseGV->TabIndex = 0;
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(336, 16);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(209, 42);
            this->label1->TabIndex = 1;
            this->label1->Text = L"All Courses";
            //
            // AllCoursesForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(858, 464);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->courseGV);
            this->Name = L"AllCoursesForm";
            this->Text = L"AllCoursesForm";
            this->Load += gcnew System::EventHandler(this, &AllCoursesForm::AllCoursesForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->courseGV))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void AllCoursesForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                CourseService ^ service = gcnew CourseService(parent->user);
                auto res = service->GetAll();
                if (res.status) {
                    courseGV->DataSource = res.data;
                }
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
