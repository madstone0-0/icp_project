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
    /// Summary for ViewScheduleForm
    /// </summary>
   public
    ref class ViewScheduleForm : public System::Windows::Forms::Form {
       private:
        IChildHost ^ parent;

       public:
        ViewScheduleForm(IChildHost ^ parent) {
            this->parent = parent;
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ViewScheduleForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::TreeView ^ scheduleView;

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
            this->scheduleView = (gcnew System::Windows::Forms::TreeView());
            this->SuspendLayout();
            //
            // scheduleView
            //
            this->scheduleView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->scheduleView->Location = System::Drawing::Point(16, 48);
            this->scheduleView->Name = L"scheduleView";
            this->scheduleView->Size = System::Drawing::Size(728, 368);
            this->scheduleView->TabIndex = 0;
            //
            // ViewScheduleForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(763, 425);
            this->Controls->Add(this->scheduleView);
            this->Name = L"ViewScheduleForm";
            this->Text = L"ViewScheduleForm";
            this->Load += gcnew System::EventHandler(this, &ViewScheduleForm::ViewScheduleForm_Load);
            this->ResumeLayout(false);
        }
#pragma endregion
       private:
        System::Void ViewScheduleForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                auto service = gcnew ScheduleService(parent->user);
                ScheduleMap ^ masterSchedule = gcnew ScheduleMap();
                auto res = service->GetAll(masterSchedule);
                if (!res.status) {
                    throw gcnew Exception("Failed to fetch schedules");
                }

                scheduleView->BeginUpdate();
                for each (auto day in masterSchedule->Keys) {
                    auto dayNode = gcnew TreeNode(day.ToString());
                    auto itemsList = gcnew List<ScheduleItem>(0);
                    masterSchedule->TryGetValue(day, itemsList);
                    itemsList->Sort();
                    for each (auto sched in itemsList) {
                        auto schedNode =
                            gcnew TreeNode(String::Format("{0} - {1} - {2}", sched.cname, sched.starttime.ToString("t"),
                                                          sched.endtime.ToString("t")));
                        schedNode->Tag = sched.scid;
                        dayNode->Nodes->Add(schedNode);
                    }
                    scheduleView->Nodes->Add(dayNode);
                }
                scheduleView->EndUpdate();
                scheduleView->ExpandAll();

            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject
