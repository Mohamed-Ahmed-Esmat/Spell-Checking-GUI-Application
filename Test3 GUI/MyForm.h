#pragma once
#include <iostream>
#include "TrieHeader.h"
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h> 

namespace Test3GUI {
	const int arraySize = 25000;
	Trie<string> trie;
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			pictureBox1->Visible = false;
			pictureBox2->Visible = false;
			errorEmpty->Visible = false;
			suggest1->Text = msclr::interop::marshal_as<String^>("");
			suggest2->Text = msclr::interop::marshal_as<String^>("");
			suggest3->Text = msclr::interop::marshal_as<String^>("");
			std::ifstream input("D:/Visual Studio 2022 projects/SpellCheckingtest/file.txt");
			string* words = new string[arraySize];
			int i = 0;
			string element;

			while (getline(input, element) && i < arraySize) {
				words[i++] = element;
			}

			// Insert words into the Trie
			for (int j = 0; j < i; j++) {
				trie.insert(words[j]);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ errorEmpty;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ suggest1;
	private: System::Windows::Forms::Label^ suggest2;
	private: System::Windows::Forms::Label^ suggest3;
	private: System::Windows::Forms::Button^ Insert;
	private: System::Windows::Forms::Button^ Delete;
	private: System::Windows::Forms::PictureBox^ updateDictionbutton;






	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->errorEmpty = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->suggest1 = (gcnew System::Windows::Forms::Label());
			this->suggest2 = (gcnew System::Windows::Forms::Label());
			this->suggest3 = (gcnew System::Windows::Forms::Label());
			this->Insert = (gcnew System::Windows::Forms::Button());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->updateDictionbutton = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->updateDictionbutton))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(174, 83);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(165, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(155, 182);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 16);
			this->label1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->AutoSize = true;
			this->button1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(208, 144);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 39);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Check";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(130, 77);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(38, 34);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(345, 77);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(38, 34);
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// errorEmpty
			// 
			this->errorEmpty->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->errorEmpty->AutoSize = true;
			this->errorEmpty->BackColor = System::Drawing::Color::Transparent;
			this->errorEmpty->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->errorEmpty->ForeColor = System::Drawing::Color::DarkRed;
			this->errorEmpty->Location = System::Drawing::Point(187, 29);
			this->errorEmpty->Name = L"errorEmpty";
			this->errorEmpty->Size = System::Drawing::Size(139, 40);
			this->errorEmpty->TabIndex = 5;
			this->errorEmpty->Text = L"Please Enter a Word to Check";
			this->errorEmpty->Click += gcnew System::EventHandler(this, &MyForm::errorEmpty_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				33.33333F)));
			this->tableLayoutPanel1->Controls->Add(this->textBox1, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->errorEmpty, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->pictureBox2, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->button1, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->suggest1, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->suggest2, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->suggest3, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->Insert, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->Delete, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->updateDictionbutton, 0, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(1, 2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.01435F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 23.92344F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 43.26241F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 246)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(515, 456);
			this->tableLayoutPanel1->TabIndex = 6;
			// 
			// suggest1
			// 
			this->suggest1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->suggest1->AutoSize = true;
			this->suggest1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggest1->Location = System::Drawing::Point(36, 209);
			this->suggest1->Name = L"suggest1";
			this->suggest1->Size = System::Drawing::Size(98, 32);
			this->suggest1->TabIndex = 6;
			this->suggest1->Text = L"label2";
			// 
			// suggest2
			// 
			this->suggest2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->suggest2->AutoSize = true;
			this->suggest2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggest2->Location = System::Drawing::Point(207, 209);
			this->suggest2->Name = L"suggest2";
			this->suggest2->Size = System::Drawing::Size(98, 32);
			this->suggest2->TabIndex = 7;
			this->suggest2->Text = L"label3";
			// 
			// suggest3
			// 
			this->suggest3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->suggest3->AutoSize = true;
			this->suggest3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->suggest3->Location = System::Drawing::Point(379, 209);
			this->suggest3->Name = L"suggest3";
			this->suggest3->Size = System::Drawing::Size(98, 32);
			this->suggest3->TabIndex = 8;
			this->suggest3->Text = L"label4";
			// 
			// Insert
			// 
			this->Insert->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Insert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Insert->Location = System::Drawing::Point(37, 144);
			this->Insert->Name = L"Insert";
			this->Insert->Size = System::Drawing::Size(96, 39);
			this->Insert->TabIndex = 9;
			this->Insert->Text = L"Insert";
			this->Insert->UseVisualStyleBackColor = true;
			this->Insert->Click += gcnew System::EventHandler(this, &MyForm::Insert_Click);
			// 
			// Delete
			// 
			this->Delete->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Delete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Delete->ForeColor = System::Drawing::Color::Red;
			this->Delete->Location = System::Drawing::Point(373, 144);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(111, 39);
			this->Delete->TabIndex = 10;
			this->Delete->Text = L"Delete";
			this->Delete->UseVisualStyleBackColor = true;
			this->Delete->Click += gcnew System::EventHandler(this, &MyForm::Delete_Click);
			// 
			// updateDictionbutton
			// 
			this->updateDictionbutton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"updateDictionbutton.Image")));
			this->updateDictionbutton->Location = System::Drawing::Point(3, 3);
			this->updateDictionbutton->Name = L"updateDictionbutton";
			this->updateDictionbutton->Size = System::Drawing::Size(49, 38);
			this->updateDictionbutton->TabIndex = 11;
			this->updateDictionbutton->TabStop = false;
			this->updateDictionbutton->Click += gcnew System::EventHandler(this, &MyForm::updateDictionbutton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HotTrack;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(517, 461);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->MinimumSize = System::Drawing::Size(535, 508);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->updateDictionbutton))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		string suggestions [3];
		System::String^ key = textBox1->Text;
		std::string keyStd = msclr::interop::marshal_as<std::string>(key);
		
		bool result = trie.search(keyStd);
		bool isEmpty = keyStd == "" ? true : false;
		
		if (isEmpty) {
			errorEmpty->Visible = true;
			pictureBox1->Visible = false;
			pictureBox2->Visible = false;
			suggest1->Text = msclr::interop::marshal_as<String^>("");
			suggest2->Text = msclr::interop::marshal_as<String^>("");
			suggest3->Text = msclr::interop::marshal_as<String^>("");
		}
		else if (result) {
			pictureBox1->Visible = true;
			pictureBox2->Visible = false;
			errorEmpty->Visible = false;
			suggest1->Text = msclr::interop::marshal_as<String^>("");
			suggest2->Text = msclr::interop::marshal_as<String^>("");
			suggest3->Text = msclr::interop::marshal_as<String^>("");
		}
		else {
			pictureBox1->Visible = false;
			pictureBox2->Visible = true;
			errorEmpty->Visible = false;
			trie.printSuggestions1(keyStd, suggestions);
			suggest1->Text = msclr::interop::marshal_as<String^>(suggestions[0]);
			//suggest2->Text = msclr::interop::marshal_as<String^>(suggestions[1]);
			//suggest3->Text = msclr::interop::marshal_as<String^>(suggestions[2]);
		}
	}


	
	private: System::Void errorEmpty_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ key = textBox1->Text;
	std::string keyStd = msclr::interop::marshal_as<std::string>(key);
	bool isEmpty = keyStd == "" ? true : false;
	if (!isEmpty) {
		bool deleteSuccess = trie.deleteWord(keyStd);
if (deleteSuccess) {
			pictureBox1->Visible = true;
			pictureBox2->Visible = false;
			errorEmpty->Visible = true;
			errorEmpty->Text = msclr::interop::marshal_as<String^>("Word Deleted Successfully");
		}
		else {
			pictureBox1->Visible = false;
			pictureBox2->Visible = true;
			errorEmpty->Visible = true;
			errorEmpty->Text = msclr::interop::marshal_as<String^>("Word not deleted");
		}
		pictureBox1->Visible = false;
		pictureBox2->Visible = false;
		suggest1->Text = msclr::interop::marshal_as<String^>("");
		suggest2->Text = msclr::interop::marshal_as<String^>("");
		suggest3->Text = msclr::interop::marshal_as<String^>("");
	}
	else {
		errorEmpty->Visible = true;
	}
}
private: System::Void Insert_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ key = textBox1->Text;
	std::string keyStd = msclr::interop::marshal_as<std::string>(key);
	bool isEmpty = keyStd == "" ? true : false;
	if (!isEmpty) {
		bool insertSucces = trie.insert(keyStd);
		if (insertSucces) {
			pictureBox1->Visible = true;
			pictureBox2->Visible = false;
			errorEmpty->Visible = true;
			errorEmpty->Text = msclr::interop::marshal_as<String^>("Word Inserted Successfully");
		}
		else {
			pictureBox1->Visible = false;
			pictureBox2->Visible = true;
			errorEmpty->Visible = true;
			errorEmpty->Text = msclr::interop::marshal_as<String^>("Word not inserted");
		}
		pictureBox1->Visible = false;
		pictureBox2->Visible = false;
		suggest1->Text = msclr::interop::marshal_as<String^>("");
		suggest2->Text = msclr::interop::marshal_as<String^>("");
		suggest3->Text = msclr::interop::marshal_as<String^>("");
	}
	else {
		errorEmpty->Visible = true;
	}
}
private: System::Void updateDictionbutton_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
}
