#pragma once
#include "./utils.h"

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for StudentProfileForm
    /// </summary>
   public
    ref class StudentProfileForm : public System::Windows::Forms::Form {
       private:
        STR stuFName;
        STR stuLName;
        Major stuMajor;
        STR stuDOB;
        STR stuEnrollDate;

       private:
        System::Windows::Forms::Label ^ label1;

       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::Label ^ label4;
        PictureH stuPicture;

        STR parseMajorName(Major m) {
            switch (m) {
                case Major::CS:
                    return "Computer Science";
                    break;
                case Major::BA:
                    return "Business Administration";
                    break;
                case Major::MA:
                    return "Mechatronic Engineering";
                    break;
                case Major::CE:
                    return "Computer Engineering";
                    break;
                case Major::EE:
                    return "Electrical Engineering";
                    break;
                case Major::EN:
                    return "Engineering?";
                    break;
                case Major::ME:
                    return "Mechanical Engineering";
                    break;
            }
        }

       public:
        property STR FirstName {
            STR get() { return stuFName; }
            void set(STR value) { stuFName = value; }
        }

        property STR LastName {
            STR get() { return stuLName; }
            void set(STR value) { stuLName = value; }
        }

        property Major MJ {
            Major get() { return stuMajor; }
            void set(Major value) { stuMajor = value; }
        }

        property STR DOB {
            STR get() { return stuDOB; }
            void set(STR value) { stuDOB = value; }
        }

        property STR EnrollDate {
            STR get() { return stuEnrollDate; }
            void set(STR value) { stuEnrollDate = value; }
        }

        property PictureH PictureBytes {
            PictureH get() { return stuPicture; }
            void set(PictureH value) { stuPicture = value; }
        }

        StudentProfileForm(STR fn, STR ln, Major m, STR d, STR e, PictureH p) {
            stuFName = fn;
            stuLName = ln;
            stuMajor = m;
            stuDOB = d;
            stuEnrollDate = e;
            stuPicture = p;
            InitializeComponent();
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~StudentProfileForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Label ^ stuNameLabel;

       private:
        System::Windows::Forms::Label ^ stuMajorLabel;

       private:
        System::Windows::Forms::Label ^ stuDOBLabel;

       private:
        System::Windows::Forms::Label ^ stuEnrollLabel;

       private:
       private:
       private:
       protected:
       private:
       protected:
       private:
       private:
       private:
       private:
        System::Windows::Forms::PictureBox ^ pictureBox1;

       private:
        System::Windows::Forms::Label ^ label5;

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
            this->stuNameLabel = (gcnew System::Windows::Forms::Label());
            this->stuMajorLabel = (gcnew System::Windows::Forms::Label());
            this->stuDOBLabel = (gcnew System::Windows::Forms::Label());
            this->stuEnrollLabel = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            //
            // stuNameLabel
            //
            this->stuNameLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->stuNameLabel->AutoSize = true;
            this->stuNameLabel->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->stuNameLabel->Location = System::Drawing::Point(144, 80);
            this->stuNameLabel->Name = L"stuNameLabel";
            this->stuNameLabel->Size = System::Drawing::Size(60, 24);
            this->stuNameLabel->TabIndex = 0;
            this->stuNameLabel->Text = L"label1";
            //
            // stuMajorLabel
            //
            this->stuMajorLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->stuMajorLabel->AutoSize = true;
            this->stuMajorLabel->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->stuMajorLabel->Location = System::Drawing::Point(144, 128);
            this->stuMajorLabel->Name = L"stuMajorLabel";
            this->stuMajorLabel->Size = System::Drawing::Size(60, 24);
            this->stuMajorLabel->TabIndex = 1;
            this->stuMajorLabel->Text = L"label2";
            //
            // stuDOBLabel
            //
            this->stuDOBLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->stuDOBLabel->AutoSize = true;
            this->stuDOBLabel->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->stuDOBLabel->Location = System::Drawing::Point(144, 184);
            this->stuDOBLabel->Name = L"stuDOBLabel";
            this->stuDOBLabel->Size = System::Drawing::Size(60, 24);
            this->stuDOBLabel->TabIndex = 2;
            this->stuDOBLabel->Text = L"label3";
            //
            // stuEnrollLabel
            //
            this->stuEnrollLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->stuEnrollLabel->AutoSize = true;
            this->stuEnrollLabel->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->stuEnrollLabel->Location = System::Drawing::Point(144, 240);
            this->stuEnrollLabel->Name = L"stuEnrollLabel";
            this->stuEnrollLabel->Size = System::Drawing::Size(60, 24);
            this->stuEnrollLabel->TabIndex = 3;
            this->stuEnrollLabel->Text = L"label4";
            //
            // pictureBox1
            //
            this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                (System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->pictureBox1->Location = System::Drawing::Point(480, 64);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(240, 232);
            this->pictureBox1->TabIndex = 4;
            this->pictureBox1->TabStop = false;
            //
            // label5
            //
            this->label5->AutoSize = true;
            this->label5->Dock = System::Windows::Forms::DockStyle::Top;
            this->label5->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(0, 0);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(123, 42);
            this->label5->TabIndex = 5;
            this->label5->Text = L"Profile";
            //
            // label1
            //
            this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(8, 80);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(71, 24);
            this->label1->TabIndex = 6;
            this->label1->Text = L"Name:";
            //
            // label2
            //
            this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(8, 128);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(68, 24);
            this->label2->TabIndex = 7;
            this->label2->Text = L"Major:";
            //
            // label3
            //
            this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(8, 184);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(129, 24);
            this->label3->TabIndex = 8;
            this->label3->Text = L"Date of Birth:";
            //
            // label4
            //
            this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
                ((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) |
                 System::Windows::Forms::AnchorStyles::Right));
            this->label4->AutoSize = true;
            this->label4->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(8, 240);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(119, 24);
            this->label4->TabIndex = 9;
            this->label4->Text = L"Enroll Date:";
            //
            // StudentProfileForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(748, 458);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->stuEnrollLabel);
            this->Controls->Add(this->stuDOBLabel);
            this->Controls->Add(this->stuMajorLabel);
            this->Controls->Add(this->stuNameLabel);
            this->Name = L"StudentProfileForm";
            this->Text = L"StudentProfileForm";
            this->Load += gcnew System::EventHandler(this, &StudentProfileForm::StudentProfileForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize ^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
        System::Void StudentProfileForm_Load(System::Object ^ sender, System::EventArgs ^ e) {
            try {
                pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
                stuNameLabel->Text = stuFName + " " + stuLName;
                stuMajorLabel->Text = parseMajorName(stuMajor);
                stuDOBLabel->Text = stuDOB;
                stuEnrollLabel->Text = stuEnrollDate;
                pictureBox1->Image = Image::FromStream(gcnew IO::MemoryStream(stuPicture));
            } catch (Exception ^ e) {
                errorMsg(e->Message);
                MessageBox::Show(e->Message);
            }
        }
    };
}  // namespace icpproject