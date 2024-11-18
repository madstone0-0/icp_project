#pragma once

namespace icpproject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for AdminLoginForm
    /// </summary>
   public
    ref class AdminLoginForm : public System::Windows::Forms::Form {
       public:
        AdminLoginForm(void) {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

       protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AdminLoginForm() {
            if (components) {
                delete components;
            }
        }

       private:
        System::Windows::Forms::Label ^ label1;

       protected:
       private:
        System::Windows::Forms::TextBox ^ textBox1;

       private:
        System::Windows::Forms::TextBox ^ textBox2;

       private:
        System::Windows::Forms::Button ^ button1;

       private:
        System::Windows::Forms::Label ^ label2;

       private:
        System::Windows::Forms::Label ^ label3;

       private:
        System::Windows::Forms::LinkLabel ^ linkLabel1;

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
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->SuspendLayout();
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(230, 61);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(110, 42);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Login";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            //
            // textBox1
            //
            this->textBox1->Location = System::Drawing::Point(176, 146);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(193, 20);
            this->textBox1->TabIndex = 1;
            //
            // textBox2
            //
            this->textBox2->Location = System::Drawing::Point(176, 201);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(193, 20);
            this->textBox2->TabIndex = 2;
            //
            // button1
            //
            this->button1->Location = System::Drawing::Point(207, 241);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(133, 23);
            this->button1->TabIndex = 3;
            this->button1->Text = L"Login";
            this->button1->UseVisualStyleBackColor = true;
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(173, 127);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(41, 16);
            this->label2->TabIndex = 4;
            this->label2->Text = L"Email";
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Font =
                (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                                             System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(173, 182);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(67, 16);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Password";
            //
            // linkLabel1
            //
            this->linkLabel1->AutoSize = true;
            this->linkLabel1->Location = System::Drawing::Point(173, 309);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(163, 13);
            this->linkLabel1->TabIndex = 6;
            this->linkLabel1->TabStop = true;
            this->linkLabel1->Text = L"Don\'t have an account\? Sign Up";
            //
            // AdminLoginForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(598, 378);
            this->Controls->Add(this->linkLabel1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label1);
            this->Name = L"AdminLoginForm";
            this->Text = L"AdminLoginForm";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
       private:
    };
}  // namespace icpproject
