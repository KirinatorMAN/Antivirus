#include "DatabaseEditorLogic.h"
#include <string>

#pragma once
namespace DatabaseEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SQLite;
	using namespace System::Text;
	using namespace System::Threading;
	using namespace System::IO;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			Control::CheckForIllegalCrossThreadCalls = false;
		}
	private: System::Windows::Forms::Button^ btnRemove;
	private: System::Windows::Forms::OpenFileDialog^ openFD;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btnViewDatabase;
	private: System::Windows::Forms::Button^ btnCreateDatabase;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ txtDatabaseFilePath;
	private: System::Windows::Forms::TextBox^ txtNewDBName;
	private: System::Windows::Forms::TextBox^ txtOffsetEnd;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::TextBox^ txtSignature;
	private: System::Windows::Forms::TextBox^ txtOffsetBegin;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	public:
		SQLiteConnection^ database;
	protected:

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			database->Close();
		}

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->openFD = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btnViewDatabase = (gcnew System::Windows::Forms::Button());
			this->btnRemove = (gcnew System::Windows::Forms::Button());
			this->btnCreateDatabase = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtNewDBName = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtDatabaseFilePath = (gcnew System::Windows::Forms::TextBox());
			this->txtOffsetEnd = (gcnew System::Windows::Forms::TextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->txtSignature = (gcnew System::Windows::Forms::TextBox());
			this->txtOffsetBegin = (gcnew System::Windows::Forms::TextBox());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFD
			// 
			this->openFD->FileName = L"AntimalwareDatabase.db";
			this->openFD->Filter = L"Файлы БД (*.db)|*.db";
			this->openFD->InitialDirectory = L"C:\\Users\\lk191\\Desktop\\ЗИ от ВПО\\";
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::Black;
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::Blue;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::Blue;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::Blue;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->GridColor = System::Drawing::Color::Gainsboro;
			this->dataGridView1->Location = System::Drawing::Point(503, 10);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::Silver;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::Blue;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->RowHeadersWidth = 15;
			this->dataGridView1->RowTemplate->DefaultCellStyle->BackColor = System::Drawing::Color::White;
			this->dataGridView1->RowTemplate->DefaultCellStyle->ForeColor = System::Drawing::Color::Black;
			this->dataGridView1->RowTemplate->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::Blue;
			this->dataGridView1->RowTemplate->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(922, 331);
			this->dataGridView1->TabIndex = 4;
			// 
			// btnViewDatabase
			// 
			this->btnViewDatabase->BackColor = System::Drawing::Color::Silver;
			this->btnViewDatabase->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnViewDatabase->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnViewDatabase->ForeColor = System::Drawing::Color::Black;
			this->btnViewDatabase->Location = System::Drawing::Point(4, 17);
			this->btnViewDatabase->Margin = System::Windows::Forms::Padding(2);
			this->btnViewDatabase->Name = L"btnViewDatabase";
			this->btnViewDatabase->Size = System::Drawing::Size(158, 29);
			this->btnViewDatabase->TabIndex = 1;
			this->btnViewDatabase->Text = L"Открыть файл базы";
			this->btnViewDatabase->UseVisualStyleBackColor = false;
			this->btnViewDatabase->Click += gcnew System::EventHandler(this, &MyForm::btnViewDatabase_Click);
			// 
			// btnRemove
			// 
			this->btnRemove->AutoSize = true;
			this->btnRemove->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnRemove->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnRemove->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnRemove->Location = System::Drawing::Point(9, 286);
			this->btnRemove->Margin = System::Windows::Forms::Padding(2);
			this->btnRemove->Name = L"btnRemove";
			this->btnRemove->Size = System::Drawing::Size(146, 51);
			this->btnRemove->TabIndex = 10;
			this->btnRemove->Text = L"Удалить выбранную \r\nзапись";
			this->btnRemove->UseVisualStyleBackColor = false;
			this->btnRemove->Click += gcnew System::EventHandler(this, &MyForm::btnRemove_Click);
			// 
			// btnCreateDatabase
			// 
			this->btnCreateDatabase->BackColor = System::Drawing::Color::Gray;
			this->btnCreateDatabase->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnCreateDatabase->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnCreateDatabase->ForeColor = System::Drawing::Color::Black;
			this->btnCreateDatabase->Location = System::Drawing::Point(4, 22);
			this->btnCreateDatabase->Margin = System::Windows::Forms::Padding(2);
			this->btnCreateDatabase->Name = L"btnCreateDatabase";
			this->btnCreateDatabase->Size = System::Drawing::Size(158, 24);
			this->btnCreateDatabase->TabIndex = 4;
			this->btnCreateDatabase->Text = L"Создать базу";
			this->btnCreateDatabase->UseVisualStyleBackColor = false;
			this->btnCreateDatabase->Click += gcnew System::EventHandler(this, &MyForm::btnCreateDatabase_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->btnCreateDatabase);
			this->groupBox1->Controls->Add(this->txtNewDBName);
			this->groupBox1->ForeColor = System::Drawing::Color::Black;
			this->groupBox1->Location = System::Drawing::Point(9, 67);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(284, 53);
			this->groupBox1->TabIndex = 13;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Создание базы";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(164, 9);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(94, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Имя новой базы:";
			// 
			// txtNewDBName
			// 
			this->txtNewDBName->BackColor = System::Drawing::Color::White;
			this->txtNewDBName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtNewDBName->ForeColor = System::Drawing::Color::Black;
			this->txtNewDBName->Location = System::Drawing::Point(166, 23);
			this->txtNewDBName->Margin = System::Windows::Forms::Padding(2);
			this->txtNewDBName->Name = L"txtNewDBName";
			this->txtNewDBName->Size = System::Drawing::Size(113, 21);
			this->txtNewDBName->TabIndex = 3;
			this->txtNewDBName->Text = L"ABOBA";
			this->txtNewDBName->DoubleClick += gcnew System::EventHandler(this, &MyForm::txtNewDBName_DoubleClick);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->txtDatabaseFilePath);
			this->groupBox2->Controls->Add(this->btnViewDatabase);
			this->groupBox2->ForeColor = System::Drawing::Color::Black;
			this->groupBox2->Location = System::Drawing::Point(9, 10);
			this->groupBox2->Margin = System::Windows::Forms::Padding(2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(2);
			this->groupBox2->Size = System::Drawing::Size(490, 53);
			this->groupBox2->TabIndex = 14;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Открытие базы";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(164, 9);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Открытая база:";
			// 
			// txtDatabaseFilePath
			// 
			this->txtDatabaseFilePath->BackColor = System::Drawing::Color::White;
			this->txtDatabaseFilePath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtDatabaseFilePath->ForeColor = System::Drawing::Color::Black;
			this->txtDatabaseFilePath->Location = System::Drawing::Point(166, 23);
			this->txtDatabaseFilePath->Margin = System::Windows::Forms::Padding(2);
			this->txtDatabaseFilePath->Name = L"txtDatabaseFilePath";
			this->txtDatabaseFilePath->ReadOnly = true;
			this->txtDatabaseFilePath->Size = System::Drawing::Size(319, 21);
			this->txtDatabaseFilePath->TabIndex = 2;
			// 
			// txtOffsetEnd
			// 
			this->txtOffsetEnd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->txtOffsetEnd->BackColor = System::Drawing::Color::White;
			this->txtOffsetEnd->ForeColor = System::Drawing::Color::Black;
			this->txtOffsetEnd->Location = System::Drawing::Point(258, 126);
			this->txtOffsetEnd->Margin = System::Windows::Forms::Padding(2);
			this->txtOffsetEnd->Multiline = true;
			this->txtOffsetEnd->Name = L"txtOffsetEnd";
			this->txtOffsetEnd->Size = System::Drawing::Size(83, 20);
			this->txtOffsetEnd->TabIndex = 8;
			// 
			// btnAdd
			// 
			this->btnAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnAdd->BackColor = System::Drawing::Color::Silver;
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnAdd->Location = System::Drawing::Point(5, 35);
			this->btnAdd->Margin = System::Windows::Forms::Padding(2);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(138, 93);
			this->btnAdd->TabIndex = 9;
			this->btnAdd->Text = L"Добавить запись";
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
			// 
			// txtSignature
			// 
			this->txtSignature->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->txtSignature->BackColor = System::Drawing::Color::White;
			this->txtSignature->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtSignature->ForeColor = System::Drawing::Color::Black;
			this->txtSignature->Location = System::Drawing::Point(258, 52);
			this->txtSignature->Margin = System::Windows::Forms::Padding(2);
			this->txtSignature->Multiline = true;
			this->txtSignature->Name = L"txtSignature";
			this->txtSignature->Size = System::Drawing::Size(165, 20);
			this->txtSignature->TabIndex = 6;
			// 
			// txtOffsetBegin
			// 
			this->txtOffsetBegin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->txtOffsetBegin->BackColor = System::Drawing::Color::White;
			this->txtOffsetBegin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtOffsetBegin->ForeColor = System::Drawing::Color::Black;
			this->txtOffsetBegin->Location = System::Drawing::Point(258, 89);
			this->txtOffsetBegin->Margin = System::Windows::Forms::Padding(2);
			this->txtOffsetBegin->Multiline = true;
			this->txtOffsetBegin->Name = L"txtOffsetBegin";
			this->txtOffsetBegin->Size = System::Drawing::Size(94, 20);
			this->txtOffsetBegin->TabIndex = 7;
			// 
			// txtName
			// 
			this->txtName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->txtName->BackColor = System::Drawing::Color::White;
			this->txtName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtName->ForeColor = System::Drawing::Color::Black;
			this->txtName->Location = System::Drawing::Point(258, 15);
			this->txtName->Margin = System::Windows::Forms::Padding(2);
			this->txtName->Multiline = true;
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(92, 20);
			this->txtName->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(157, 91);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(97, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Отступ от начала:";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(168, 128);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Отступ с конца:";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(192, 54);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Сигнатура:";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(165, 17);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Имя вредоноса:";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->txtSignature);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->txtOffsetEnd);
			this->groupBox3->Controls->Add(this->btnAdd);
			this->groupBox3->Controls->Add(this->txtOffsetBegin);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->txtName);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Location = System::Drawing::Point(9, 125);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(427, 156);
			this->groupBox3->TabIndex = 15;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Добавление записи";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1436, 352);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->btnRemove);
			this->ForeColor = System::Drawing::Color::Black;
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(814, 251);
			this->Name = L"MyForm";
			this->Text = L"DatabaseEditor";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void clearInputTextboxes()
	{
		txtName->Clear();
		txtSignature->Clear();
		txtOffsetBegin->Clear();
		txtOffsetEnd->Clear();
	}

	private: void openDatabase()
	{		
		dataGridView1->DataSource = DatabaseEditorLogic::fillDataTable(database);
		setColumnsWidth();
	}

	private: void openDatabaseOnFormLoad()
	{
		database = gcnew SQLiteConnection();
		DatabaseEditorLogic::openDatabase(database);
		txtDatabaseFilePath->Text = database->FileName;
		dataGridView1->DataSource = DatabaseEditorLogic::fillDataTable(database);
		setColumnsWidth();
	}

	private: System::Void btnViewDatabase_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFD->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			txtDatabaseFilePath->Text = openFD->FileName;
			database = gcnew SQLiteConnection();
			DatabaseEditorLogic::openDatabase(database, openFD->FileName);			
			Thread^ thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::openDatabase));
			thread->IsBackground = true;
			thread->Start();
		}
	}

	private: System::Void btnCreateDatabase_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ fileName = "C:\\Users\\lk191\\Desktop\\ЗИ от ВПО\\ABOBADatabase\\" + txtNewDBName->Text + ".db";
		if (File::Exists(fileName))
		{
			MessageBox::Show("Файл " + fileName + " уже Существует", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		txtDatabaseFilePath->Clear();
		database->Close();
		database = gcnew SQLiteConnection();
		try
		{
			DatabaseEditorLogic::createDatabase(database, fileName);
			dataGridView1->DataSource = DatabaseEditorLogic::fillDataTable(database);
			setColumnsWidth();
			txtDatabaseFilePath->Text = database->FileName;
			MessageBox::Show("База \"" + database->FileName + "\" успешно создана!", "Создание базы", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Error Working SQL: " + e->ToString(), "Exception ...");
		}
	}

	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (txtName->Text == "" || txtSignature->Text == "" || txtOffsetBegin->Text == "" || txtOffsetEnd->Text == "") {
			MessageBox::Show("Для добавления записи, заполните поля", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		try
		{
			DatabaseEditorLogic::addRecord(database, txtName->Text, txtSignature->Text, txtOffsetBegin->Text, txtOffsetEnd->Text);
			dataGridView1->DataSource = DatabaseEditorLogic::fillDataTable(database);
			setColumnsWidth();
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception ...");
		}
		clearInputTextboxes();
	}

	private: System::Void btnRemove_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int index = dataGridView1->CurrentCell->RowIndex; // Номер выделенной строки
		String^ malwareName = dataGridView1->Rows[index]->Cells["MW_NAME"]->Value->ToString(); //Определим _id в выделенной строке
		try
		{
			DatabaseEditorLogic::deleteRecord(database, malwareName);
			dataGridView1->DataSource = DatabaseEditorLogic::fillDataTable(database);
			setColumnsWidth();
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Error Executing SQL: " + e->ToString(), "Exception ...");
		}
	}

	private: System::Void txtNewDBName_DoubleClick(System::Object^ sender, System::EventArgs^ e)
	{
		txtNewDBName->SelectAll();
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		Thread^ thread = gcnew Thread(gcnew ThreadStart(this, &MyForm::openDatabaseOnFormLoad));
		thread->IsBackground = true;
		thread->Start();
	}

	private: void setColumnsWidth()
	{
		dataGridView1->Columns[4]->MinimumWidth = 300;
		dataGridView1->Columns[4]->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		dataGridView1->Columns[0]->Width = 70;
		dataGridView1->Columns[0]->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		dataGridView1->Columns[2]->Width = 140;
		dataGridView1->Columns[2]->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		dataGridView1->Columns[3]->Width = 130;
		dataGridView1->Columns[3]->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		dataGridView1->Columns[5]->Width = 145;
		dataGridView1->Columns[5]->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		dataGridView1->Columns[6]->Width = 125;
		dataGridView1->Columns[6]->Resizable = System::Windows::Forms::DataGridViewTriState::False;

		dataGridView1->EnableHeadersVisualStyles = false;
	}
};
}
