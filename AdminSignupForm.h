#pragma once

namespace icpproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminSignUpForm
	/// </summary>
	public ref class AdminSignUpForm : public System::Windows::Forms::Form
	{
	public:
		AdminSignUpForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminSignUpForm()
		{
			if (components)
			{
				delete components;
			}
		}

               private:
                System::Windows::Forms::Label ^ label1;

               protected:
               private:
                System::Windows::Forms::Button ^ button1;

               private:
                System::Windows::Forms::TextBox ^ textBox1;

               private:
                System::Windows::Forms::Label ^ label2;

               private:
                System::Windows::Forms::Label ^ label4;

               private:
                System::Windows::Forms::TextBox ^ textBox3;

               private:
                System::Windows::Forms::Label ^ label5;

               private:
                System::Windows::Forms::TextBox ^ textBox4;

               private:
                System::Windows::Forms::Label ^ label6;

               private:
                System::Windows::Forms::TextBox ^ textBox5;

               private:
                System::Windows::Forms::LinkLabel ^ linkLabel1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
                    this->label1 = (gcnew System::Windows::Forms::Label());
                    this->button1 = (gcnew System::Windows::Forms::Button());
                    this->textBox1 = (gcnew System::Windows::Forms::TextBox());
                    this->label2 = (gcnew System::Windows::Forms::Label());
                    this->label4 = (gcnew System::Windows::Forms::Label());
                    this->textBox3 = (gcnew System::Windows::Forms::TextBox());
                    this->label5 = (gcnew System::Windows::Forms::Label());
                    this->textBox4 = (gcnew System::Windows::Forms::TextBox());
                    this->label6 = (gcnew System::Windows::Forms::Label());
                    this->textBox5 = (gcnew System::Windows::Forms::TextBox());
                    this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
                    this->SuspendLayout();
                    //
                    // label1
                    //
                    this->label1->AutoSize = true;
                    this->label1->Font = (gcnew System::Drawing::Font(
                        L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
                        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
                    this->label1->Location = System::Drawing::Point(212, 37);
                    this->label1->Name = L"label1";
                    this->label1->Size = System::Drawing::Size(151, 42);
                    this->label1->TabIndex = 0;
                    this->label1->Text = L"Sign Up";
                    //
                    // button1
                    //
                    this->button1->Location = System::Drawing::Point(219, 278);
                    this->button1->Name = L"button1";
                    this->button1->Size = System::Drawing::Size(136, 23);
                    this->button1->TabIndex = 1;
                    this->button1->Text = L"Sign Up";
                    this->button1->UseVisualStyleBackColor = true;
                    //
                    // textBox1
                    //
                    this->textBox1->Location = System::Drawing::Point(300, 130);
                    this->textBox1->Name = L"textBox1";
                    this->textBox1->Size = System::Drawing::Size(129, 20);
                    this->textBox1->TabIndex = 2;
                    //
                    // label2
                    //
                    this->label2->AutoSize = true;
                    this->label2->Font = (gcnew System::Drawing::Font(
                        L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
                    this->label2->Location = System::Drawing::Point(297, 114);
                    this->label2->Name = L"label2";
                    this->label2->Size = System::Drawing::Size(72, 16);
                    this->label2->TabIndex = 3;
                    this->label2->Text = L"Last Name";
                    //
                    // label4
                    //
                    this->label4->AutoSize = true;
                    this->label4->Font = (gcnew System::Drawing::Font(
                        L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
                    this->label4->Location = System::Drawing::Point(166, 217);
                    this->label4->Name = L"label4";
                    this->label4->Size = System::Drawing::Size(74, 16);
                    this->label4->TabIndex = 7;
                    this->label4->Text = L"Passsword";
                    //
                    // textBox3
                    //
                    this->textBox3->Location = System::Drawing::Point(169, 233);
                    this->textBox3->Name = L"textBox3";
                    this->textBox3->Size = System::Drawing::Size(260, 20);
                    this->textBox3->TabIndex = 6;
                    //
                    // label5
                    //
                    this->label5->AutoSize = true;
                    this->label5->Font = (gcnew System::Drawing::Font(
                        L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
                    this->label5->Location = System::Drawing::Point(166, 161);
                    this->label5->Name = L"label5";
                    this->label5->Size = System::Drawing::Size(41, 16);
                    this->label5->TabIndex = 9;
                    this->label5->Text = L"Email";
                    //
                    // textBox4
                    //
                    this->textBox4->Location = System::Drawing::Point(169, 177);
                    this->textBox4->Name = L"textBox4";
                    this->textBox4->Size = System::Drawing::Size(260, 20);
                    this->textBox4->TabIndex = 8;
                    //
                    // label6
                    //
                    this->label6->AutoSize = true;
                    this->label6->Font = (gcnew System::Drawing::Font(
                        L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
                        System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
                    this->label6->Location = System::Drawing::Point(166, 114);
                    this->label6->Name = L"label6";
                    this->label6->Size = System::Drawing::Size(72, 16);
                    this->label6->TabIndex = 11;
                    this->label6->Text = L"First Name";
                    //
                    // textBox5
                    //
                    this->textBox5->Location = System::Drawing::Point(169, 130);
                    this->textBox5->Name = L"textBox5";
                    this->textBox5->Size = System::Drawing::Size(125, 20);
                    this->textBox5->TabIndex = 10;
                    //
                    // linkLabel1
                    //
                    this->linkLabel1->AutoSize = true;
                    this->linkLabel1->Location = System::Drawing::Point(166, 320);
                    this->linkLabel1->Name = L"linkLabel1";
                    this->linkLabel1->Size = System::Drawing::Size(161, 13);
                    this->linkLabel1->TabIndex = 12;
                    this->linkLabel1->TabStop = true;
                    this->linkLabel1->Text = L"Already have an account\? Login";
                    //
                    // AdminSignUpForm
                    //
                    this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
                    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
                    this->ClientSize = System::Drawing::Size(596, 358);
                    this->Controls->Add(this->linkLabel1);
                    this->Controls->Add(this->label6);
                    this->Controls->Add(this->textBox5);
                    this->Controls->Add(this->label5);
                    this->Controls->Add(this->textBox4);
                    this->Controls->Add(this->label4);
                    this->Controls->Add(this->textBox3);
                    this->Controls->Add(this->label2);
                    this->Controls->Add(this->textBox1);
                    this->Controls->Add(this->button1);
                    this->Controls->Add(this->label1);
                    this->Name = L"AdminSignUpForm";
                    this->Text = L"AdminSignUpForm";
                    this->ResumeLayout(false);
                    this->PerformLayout();
                }
#pragma endregion
	};
}
