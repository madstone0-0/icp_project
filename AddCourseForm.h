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
    using namespace System::Collections::Generic;

    /// <summary>
    /// Summary for AddCourseForm
    /// </summary>
   public
    ref class AddCourseForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       private:
        System::Windows::Forms::Label ^ label5;

       private:
        System::Windows::Forms::ComboBox ^ facBox;
        CourseService ^ service;

       public:
        AddCourseForm(IChildHost ^ parent) {
            this->parent = parent;
            service = gcnew CourseService(parent->user);
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AddCourseForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Label ^ label1;

       protected:
       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Label ^ label4;

       private:
        System::Windows::Forms::TextBox ^ cnameInput;

       private:
        System::Windows::Forms::ComboBox ^ semCombo;

       private:
        System::Windows::Forms::ComboBox ^ creditsCombo;

       private:
        System::Windows::Forms::NumericUpDown ^ capacityInput;

       private:
        System::Windows::Forms::ListBox ^ prereqBox;

       private:
        System::Windows::Forms::Button ^ addButton;

       private:
       private:
       private:
       private:
       private:
       private:
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
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->cnameInput = (gcnew System::Windows::Forms::TextBox());
            this->semCombo = (gcnew System::Windows::Forms::ComboBox());
            this->creditsCombo = (gcnew System::Windows::Forms::ComboBox());
            this->capacityInput = (gcnew System::Windows::Forms::NumericUpDown());
            this->prereqBox = (gcnew System::Windows::Forms::ListBox());
            this->addButton = (gcnew System::Windows::Forms::Button());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->facBox = (gcnew System::Windows::Forms::ComboBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->capacityInput))->BeginInit();
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(16, 24);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(71, 24);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Name:";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(344, 32);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(81, 24);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Credits:";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(352, 88);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(104, 24);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Semester:";
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(16, 88);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(95, 24);
            this->label4->TabIndex = 3;
            this->label4->Text = L"Capacity:";
            //
            // cnameInput
            //
            this->cnameInput->Location = System::Drawing::Point(120, 24);
            this->cnameInput->Name = L"cnameInput";
            this->cnameInput->Size = System::Drawing::Size(124, 20);
            this->cnameInput->TabIndex = 4;
            this->cnameInput->TextChanged += gcnew System::EventHandler(this, &AddCourseForm::cnameInput_TextChanged);
            //
            // semCombo
            //
            this->semCombo->FormattingEnabled = true;
            this->semCombo->Location = System::Drawing::Point(464, 88);
            this->semCombo->Name = L"semCombo";
            this->semCombo->Size = System::Drawing::Size(121, 21);
            this->semCombo->TabIndex = 8;
            //
            // creditsCombo
            //
            this->creditsCombo->FormattingEnabled = true;
            this->creditsCombo->Location = System::Drawing::Point(456, 32);
            this->creditsCombo->Name = L"creditsCombo";
            this->creditsCombo->Size = System::Drawing::Size(121, 21);
            this->creditsCombo->TabIndex = 9;
            //
            // capacityInput
            //
            this->capacityInput->Location = System::Drawing::Point(128, 88);
            this->capacityInput->Name = L"capacityInput";
            this->capacityInput->Size = System::Drawing::Size(120, 20);
            this->capacityInput->TabIndex = 10;
            //
            // prereqBox
            //
            this->prereqBox->FormattingEnabled = true;
            this->prereqBox->Location = System::Drawing::Point(24, 192);
            this->prereqBox->Name = L"prereqBox";
            this->prereqBox->Size = System::Drawing::Size(576, 95);
            this->prereqBox->TabIndex = 11;
            //
            // addButton
            //
            this->addButton->Location = System::Drawing::Point(264, 296);
            this->addButton->Name = L"addButton";
            this->addButton->Size = System::Drawing::Size(75, 23);
            this->addButton->TabIndex = 12;
            this->addButton->Text = L"Add";
            this->addButton->UseVisualStyleBackColor = true;
            this->addButton->Click += gcnew System::EventHandler(this, &AddCourseForm::addButton_Click);
            //
            // label5
            //
            this->label5->AutoSize = true;
            this->label5->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(16, 144);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(83, 24);
            this->label5->TabIndex = 13;
            this->label5->Text = L"Faculty:";
            //
            // facBox
            //
            this->facBox->FormattingEnabled = true;
            this->facBox->Location = System::Drawing::Point(120, 144);
            this->facBox->Name = L"facBox";
            this->facBox->Size = System::Drawing::Size(121, 21);
            this->facBox->TabIndex = 14;
            //
            // AddCourseForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(653, 324);
            this->Controls->Add(this->facBox);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->addButton);
            this->Controls->Add(this->prereqBox);
            this->Controls->Add(this->capacityInput);
            this->Controls->Add(this->creditsCombo);
            this->Controls->Add(this->semCombo);
            this->Controls->Add(this->cnameInput);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Name = L"AddCourseForm";
            this->Text = L"AddCourseForm";
            this->Load += gcnew System::EventHandler(this, &AddCourseForm::AddCourseForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->capacityInput))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

       private:
        System::Void addButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto cname = trim(cnameInput->Text);
                auto credits = Convert::ToDouble(creditsCombo->SelectedItem);
                auto sem = parseStrSemester(Convert::ToString(semCombo->SelectedItem));
                auto capacity = Convert::ToInt32(capacityInput->Value);
                PreReqList ^ prereqs = gcnew PreReqList(0);

                if (isEmpty(cname)) {
                    throw gcnew Exception("Course name cannot be empty");
                }

                if (capacity <= 0) {
                    throw gcnew Exception("Credits must be greater than 0");
                }

                infoMsg("Course name: " + cname);
                infoMsg("Credits: " + credits);
                infoMsg("Semester: " + parseSemester(sem));
                infoMsg("Capacity: " + capacity);

                for each (auto p in prereqBox->SelectedItems) {
                    auto kvp = (KeyValuePair<long long, STR> ^) p;
                    prereqs->Add(kvp->Key);
                    infoMsg(kvp->Value);
                }

                auto res = service->Add(NewCourse(cname, credits, sem, capacity, prereqs));
                if (res.status) {
                    MessageBox::Show(res.data);
                } else {
                    auto lastId = db::Ins()->getCmd()->LastInsertedId;
                    service->Delete(lastId);
                    MessageBox::Show("Failed to add course");
                    return;
                }

                cnameInput->Text = "";
                creditsCombo->SelectedIndex = 0;
                semCombo->SelectedIndex = 0;
                capacityInput->Value = 0;
                prereqBox->ClearSelected();

            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void AddCourseForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                List<double> ^ credits = gcnew List<double>(0);
                credits->Add(1.0);
                credits->Add(0.5);
                List<STR> ^ sems = gcnew List<STR>(0);
                sems->Add("S1");
                sems->Add("S2");
                creditsCombo->DataSource = credits;
                semCombo->DataSource = sems;
                List<Course> ^ courses = gcnew List<Course>(0);
                auto res = service->GetAll(courses);
                prereqBox->SelectionMode = SelectionMode::MultiSimple;
                prereqBox->BeginUpdate();
                for each (auto c in courses) {
                    KeyValuePair<long long, STR> ^ kvp = gcnew KeyValuePair<long long, STR>(c.cid, c.cname);
                    prereqBox->Items->Add(kvp);
                }
                prereqBox->EndUpdate();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void cnameInput_TextChanged(System::Object ^ sender, System::EventArgs ^ e) {}
    };
}  // namespace icpproject