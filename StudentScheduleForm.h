#pragma once
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
    /// Summary for StudentScheduleForm
    /// </summary>
   public
    ref class StudentScheduleForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       public:
        StudentScheduleForm(IChildHost ^ parent) {
            this->parent = parent;
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~StudentScheduleForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::TreeView ^ schedView;

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
            this->schedView = (gcnew System::Windows::Forms::TreeView());
            this->SuspendLayout();
            //
            // schedView
            //
            this->schedView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->schedView->Location = System::Drawing::Point(8, 8);
            this->schedView->Name = L"schedView";
            this->schedView->Size = System::Drawing::Size(704, 352);
            this->schedView->TabIndex = 0;
            //
            // StudentScheduleForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(718, 367);
            this->Controls->Add(this->schedView);
            this->Name = L"StudentScheduleForm";
            this->Text = L"StudentScheduleForm";
            this->Load += gcnew System::EventHandler(this, &StudentScheduleForm::StudentScheduleForm_Load);
            this->ResumeLayout(false);
        }
#pragma endregion
       private:
        System::Void StudentScheduleForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto service = gcnew ScheduleService(parent->user);
                auto res = service->GenerateStudentSchedule(parent->user->UID);
                if (!res.status) {
                    errorMsg("Failed to retrieve schedule");
                    throw gcnew Exception("Failed to retrieve schedule");
                    return;
                }
                auto stuSched = res.data;
                for each (auto day in stuSched->Keys) {
                    List<ScheduleItem> ^ items = gcnew List<ScheduleItem>(0);
                    stuSched->TryGetValue(day, items);
                    TreeNode ^ dayNode = gcnew TreeNode(day.ToString());
                    items->Sort();
                    for each (auto item in items) {
                        TreeNode ^ itemNode = gcnew TreeNode(String::Format("{0} {1} - {2}", item.cname,
                                                                            item.starttime.ToShortTimeString(),
                                                                            item.endtime.ToShortTimeString()));
                        dayNode->Nodes->Add(itemNode);
                    }
                    schedView->Nodes->Add(dayNode);
                }
                schedView->ExpandAll();
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
