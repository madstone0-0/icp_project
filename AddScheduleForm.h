#pragma once
#include "services/CourseService.h"
#include "services/ScheduleService.h"
#include "utils.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for AddScheduleForm
    /// </summary>
   public
    ref class AddScheduleForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;
        ScheduleService ^ scheduleService;

       public:
        AddScheduleForm(IChildHost ^ parent) {
            this->parent = parent;
            scheduleService = gcnew ScheduleService(parent->user);
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AddScheduleForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::ListBox ^ courseBox;

       protected:
       private:
       private:
        System::Windows::Forms::DateTimePicker ^ endTimeBox;

       private:
       private:
       private:
        System::Windows::Forms::ComboBox ^ dayCombo;

       private:
       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Button ^ addButton;

       private:
        System::Windows::Forms::DateTimePicker ^ startTimeBox;

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
            this->courseBox = (gcnew System::Windows::Forms::ListBox());
            this->startTimeBox = (gcnew System::Windows::Forms::DateTimePicker());
            this->endTimeBox = (gcnew System::Windows::Forms::DateTimePicker());
            this->dayCombo = (gcnew System::Windows::Forms::ComboBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->addButton = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            //
            // courseBox
            //
            this->courseBox->FormattingEnabled = true;
            this->courseBox->Location = System::Drawing::Point(8, 8);
            this->courseBox->Name = L"courseBox";
            this->courseBox->Size = System::Drawing::Size(664, 173);
            this->courseBox->TabIndex = 0;
            //
            // startTimeBox
            //
            this->startTimeBox->Location = System::Drawing::Point(120, 208);
            this->startTimeBox->Name = L"startTimeBox";
            this->startTimeBox->Size = System::Drawing::Size(200, 20);
            this->startTimeBox->TabIndex = 1;
            //
            // endTimeBox
            //
            this->endTimeBox->Location = System::Drawing::Point(456, 208);
            this->endTimeBox->Name = L"endTimeBox";
            this->endTimeBox->Size = System::Drawing::Size(200, 20);
            this->endTimeBox->TabIndex = 2;
            //
            // dayCombo
            //
            this->dayCombo->FormattingEnabled = true;
            this->dayCombo->Location = System::Drawing::Point(120, 264);
            this->dayCombo->Name = L"dayCombo";
            this->dayCombo->Size = System::Drawing::Size(121, 21);
            this->dayCombo->TabIndex = 3;
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(8, 208);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(110, 24);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Start Time:";
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(16, 256);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(51, 24);
            this->label2->TabIndex = 5;
            this->label2->Text = L"Day:";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(344, 208);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(107, 24);
            this->label3->TabIndex = 6;
            this->label3->Text = L"End Time:";
            this->label3->Click += gcnew System::EventHandler(this, &AddScheduleForm::label3_Click);
            //
            // addButton
            //
            this->addButton->Location = System::Drawing::Point(304, 304);
            this->addButton->Name = L"addButton";
            this->addButton->Size = System::Drawing::Size(75, 23);
            this->addButton->TabIndex = 7;
            this->addButton->Text = L"Add";
            this->addButton->UseVisualStyleBackColor = true;
            this->addButton->Click += gcnew System::EventHandler(this, &AddScheduleForm::addButton_Click);
            //
            // AddScheduleForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(680, 343);
            this->Controls->Add(this->addButton);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->dayCombo);
            this->Controls->Add(this->endTimeBox);
            this->Controls->Add(this->startTimeBox);
            this->Controls->Add(this->courseBox);
            this->Name = L"AddScheduleForm";
            this->Text = L"AddScheduleForm";
            this->Load += gcnew System::EventHandler(this, &AddScheduleForm::AddScheduleForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void label3_Click(System::Object ^ sender, System::EventArgs ^ e) {}

       private:
        System::Void AddScheduleForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                STR fmt = "hh:mm tt";
                startTimeBox->CustomFormat = fmt;
                startTimeBox->Format = DateTimePickerFormat::Custom;
                startTimeBox->ShowUpDown = true;
                endTimeBox->CustomFormat = fmt;
                endTimeBox->Format = DateTimePickerFormat::Custom;
                endTimeBox->ShowUpDown = true;
                for (int i = 0; i < 5; i++) {
                    dayCombo->Items->Add(parseDay(static_cast<Day>(i)));
                }
                dayCombo->SelectedIndex = 0;

                auto courseService = gcnew CourseService(parent->user);
                auto courses = gcnew List<Course>(0);
                auto res = courseService->GetAll(courses);
                if (!res.status) {
                    throw gcnew Exception("Failed to fetch courses");
                }

                courseBox->SelectionMode = SelectionMode::One;
                courseBox->BeginUpdate();
                for each (auto course in courses) {
                    auto kvp = gcnew KeyValuePair<long long, STR>(course.cid, course.cname);
                    courseBox->Items->Add(kvp);
                }
                courseBox->EndUpdate();
                courseBox->SelectedIndex = 0;

            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }

       private:
        System::Void addButton_Click(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto startTime = startTimeBox->Value;
                auto endTime = endTimeBox->Value;
                auto day = static_cast<Day>(dayCombo->SelectedIndex);
                auto kvp = (KeyValuePair<long long, STR> ^) courseBox->SelectedItem;

                if (kvp == nullptr) {
                    throw gcnew Exception("Please select a course");
                }

                auto cid = kvp->Key;
                auto addRes = scheduleService->Add(NewSchedule(cid, startTime, endTime, day));
                if (!addRes.status) {
                    throw gcnew Exception(addRes.data);
                }

                MessageBox::Show(addRes.data);
                startTimeBox->Value = DateTime::Now;
                endTimeBox->Value = DateTime::Now;
                dayCombo->SelectedIndex = 0;
                courseBox->SelectedIndex = -1;

            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
