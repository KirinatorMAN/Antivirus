#pragma once

#include <windows.h>
#include "IPC.h"
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include "PipeNamesBuffsizesPaths.h"
//msclr::interop::marshal_as<std::string>(mPathBox->Text);
//msclr::interop::marshal_as<String^>(el));

HANDLE pipeForSend = NULL;
HANDLE pipeForRead = NULL;

namespace Client {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	public ref class ClientForm : public System::Windows::Forms::Form
	{
	public:
		ClientForm(void)
		{
			InitializeComponent();
			Control::CheckForIllegalCrossThreadCalls = false;
		}

	protected:
		~ClientForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog;
	private: System::Windows::Forms::OpenFileDialog^ openFD;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ProgressBar^ progressBar2;
	private: System::Windows::Forms::RichTextBox^ txtScheduleScanRes;
	private: System::Windows::Forms::TextBox^ txtSchedulePath;
	private: System::Windows::Forms::Button^ btnStopSchedule;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker;
	private: System::Windows::Forms::ListBox^ scheduleListBox;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnScheduleScan;
	private: System::Windows::Forms::Button^ btnBrowse3;

	private: System::Windows::Forms::Button^ btnDelMonitoring;
	private: System::Windows::Forms::Button^ btnSetMonitoring;
	private: System::Windows::Forms::ListBox^ monitoringListBox;
	private: System::Windows::Forms::TextBox^ txtMonitoringPath;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnBrowse2;

	private: System::Windows::Forms::Button^ btnBrowseFile;
	private: System::Windows::Forms::Button^ btnStopScan;
	private: System::Windows::Forms::ProgressBar^ progressBar1;




	private: System::Windows::Forms::TextBox^ txtScanPath;
	private: System::Windows::Forms::RichTextBox^ txtScanRes;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnStartScan;
	private: System::Windows::Forms::Button^ btnBrowseFolder;



	private: System::Windows::Forms::ListBox^ reportListBox;

	private: System::Windows::Forms::ListBox^ QuarantineListBox;

	private: System::Windows::Forms::Button^ btnDeleteFromQuarantine;
	private: System::Windows::Forms::Button^ btnMoveToQuarantine;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::ProgressBar^ progressBar3;
	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::RichTextBox^ txtMonitorRes;

	private: System::Windows::Forms::Button^ btnStopService;
	private: System::Windows::Forms::Button^ btnStartService;
	private: System::Windows::Forms::Panel^ panelFastCheck;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panelPlanCheck;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panelFolderMonitoring;



	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label12;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Panel^ panelDetectedThreats;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panelMenu;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label19;

	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;








	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->folderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openFD = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->txtScheduleScanRes = (gcnew System::Windows::Forms::RichTextBox());
			this->txtSchedulePath = (gcnew System::Windows::Forms::TextBox());
			this->btnStopSchedule = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->scheduleListBox = (gcnew System::Windows::Forms::ListBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnScheduleScan = (gcnew System::Windows::Forms::Button());
			this->btnBrowse3 = (gcnew System::Windows::Forms::Button());
			this->progressBar3 = (gcnew System::Windows::Forms::ProgressBar());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtMonitorRes = (gcnew System::Windows::Forms::RichTextBox());
			this->btnDelMonitoring = (gcnew System::Windows::Forms::Button());
			this->btnSetMonitoring = (gcnew System::Windows::Forms::Button());
			this->monitoringListBox = (gcnew System::Windows::Forms::ListBox());
			this->txtMonitoringPath = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnBrowse2 = (gcnew System::Windows::Forms::Button());
			this->btnBrowseFile = (gcnew System::Windows::Forms::Button());
			this->btnStopScan = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->txtScanPath = (gcnew System::Windows::Forms::TextBox());
			this->txtScanRes = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnStartScan = (gcnew System::Windows::Forms::Button());
			this->btnBrowseFolder = (gcnew System::Windows::Forms::Button());
			this->btnStopService = (gcnew System::Windows::Forms::Button());
			this->btnStartService = (gcnew System::Windows::Forms::Button());
			this->reportListBox = (gcnew System::Windows::Forms::ListBox());
			this->btnDeleteFromQuarantine = (gcnew System::Windows::Forms::Button());
			this->QuarantineListBox = (gcnew System::Windows::Forms::ListBox());
			this->btnMoveToQuarantine = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->panelFastCheck = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panelPlanCheck = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panelFolderMonitoring = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panelDetectedThreats = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->panelMenu = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->panelFastCheck->SuspendLayout();
			this->panelPlanCheck->SuspendLayout();
			this->panelFolderMonitoring->SuspendLayout();
			this->panelDetectedThreats->SuspendLayout();
			this->panelMenu->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::White;
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(288, 53);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(162, 13);
			this->label7->TabIndex = 24;
			this->label7->Text = L"Процесс последней проверки:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::White;
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(2, 165);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(154, 13);
			this->label6->TabIndex = 23;
			this->label6->Text = L"Запланированные проверки:";
			// 
			// progressBar2
			// 
			this->progressBar2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar2->Location = System::Drawing::Point(6, 407);
			this->progressBar2->Margin = System::Windows::Forms::Padding(2);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(806, 23);
			this->progressBar2->TabIndex = 21;
			// 
			// txtScheduleScanRes
			// 
			this->txtScheduleScanRes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtScheduleScanRes->BackColor = System::Drawing::Color::White;
			this->txtScheduleScanRes->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtScheduleScanRes->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtScheduleScanRes->ForeColor = System::Drawing::Color::Black;
			this->txtScheduleScanRes->HideSelection = false;
			this->txtScheduleScanRes->Location = System::Drawing::Point(291, 68);
			this->txtScheduleScanRes->Margin = System::Windows::Forms::Padding(2);
			this->txtScheduleScanRes->Name = L"txtScheduleScanRes";
			this->txtScheduleScanRes->ReadOnly = true;
			this->txtScheduleScanRes->Size = System::Drawing::Size(521, 335);
			this->txtScheduleScanRes->TabIndex = 22;
			this->txtScheduleScanRes->Text = L"";
			// 
			// txtSchedulePath
			// 
			this->txtSchedulePath->BackColor = System::Drawing::Color::White;
			this->txtSchedulePath->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtSchedulePath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtSchedulePath->ForeColor = System::Drawing::Color::Black;
			this->txtSchedulePath->Location = System::Drawing::Point(6, 68);
			this->txtSchedulePath->Margin = System::Windows::Forms::Padding(2);
			this->txtSchedulePath->Name = L"txtSchedulePath";
			this->txtSchedulePath->ReadOnly = true;
			this->txtSchedulePath->Size = System::Drawing::Size(208, 23);
			this->txtSchedulePath->TabIndex = 14;
			// 
			// btnStopSchedule
			// 
			this->btnStopSchedule->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnStopSchedule->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnStopSchedule->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnStopSchedule->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStopSchedule->Location = System::Drawing::Point(675, 435);
			this->btnStopSchedule->Margin = System::Windows::Forms::Padding(2);
			this->btnStopSchedule->Name = L"btnStopSchedule";
			this->btnStopSchedule->Size = System::Drawing::Size(137, 61);
			this->btnStopSchedule->TabIndex = 20;
			this->btnStopSchedule->Text = L"Отменить";
			this->btnStopSchedule->UseVisualStyleBackColor = false;
			this->btnStopSchedule->Click += gcnew System::EventHandler(this, &ClientForm::btnStopSchedule_Click);
			// 
			// dateTimePicker
			// 
			this->dateTimePicker->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->dateTimePicker->CalendarForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dateTimePicker->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->dateTimePicker->CalendarTitleBackColor = System::Drawing::SystemColors::ButtonShadow;
			this->dateTimePicker->CustomFormat = L"HH:mm";
			this->dateTimePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 33.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dateTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker->Location = System::Drawing::Point(154, 95);
			this->dateTimePicker->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker->Name = L"dateTimePicker";
			this->dateTimePicker->ShowUpDown = true;
			this->dateTimePicker->Size = System::Drawing::Size(133, 58);
			this->dateTimePicker->TabIndex = 19;
			// 
			// scheduleListBox
			// 
			this->scheduleListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->scheduleListBox->BackColor = System::Drawing::Color::White;
			this->scheduleListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->scheduleListBox->ForeColor = System::Drawing::Color::Black;
			this->scheduleListBox->FormattingEnabled = true;
			this->scheduleListBox->Location = System::Drawing::Point(6, 180);
			this->scheduleListBox->Margin = System::Windows::Forms::Padding(2);
			this->scheduleListBox->Name = L"scheduleListBox";
			this->scheduleListBox->Size = System::Drawing::Size(281, 223);
			this->scheduleListBox->Sorted = true;
			this->scheduleListBox->TabIndex = 17;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::White;
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(3, 53);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(147, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L"Директория сканирования:";
			// 
			// btnScheduleScan
			// 
			this->btnScheduleScan->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnScheduleScan->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnScheduleScan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnScheduleScan->Location = System::Drawing::Point(6, 95);
			this->btnScheduleScan->Margin = System::Windows::Forms::Padding(2);
			this->btnScheduleScan->Name = L"btnScheduleScan";
			this->btnScheduleScan->Size = System::Drawing::Size(133, 59);
			this->btnScheduleScan->TabIndex = 13;
			this->btnScheduleScan->Text = L"Запланировать";
			this->btnScheduleScan->UseVisualStyleBackColor = false;
			this->btnScheduleScan->Click += gcnew System::EventHandler(this, &ClientForm::btnScheduleScan_Click);
			// 
			// btnBrowse3
			// 
			this->btnBrowse3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnBrowse3->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnBrowse3->Location = System::Drawing::Point(218, 68);
			this->btnBrowse3->Margin = System::Windows::Forms::Padding(2);
			this->btnBrowse3->Name = L"btnBrowse3";
			this->btnBrowse3->Size = System::Drawing::Size(69, 23);
			this->btnBrowse3->TabIndex = 16;
			this->btnBrowse3->Text = L"Обзор";
			this->btnBrowse3->UseVisualStyleBackColor = false;
			this->btnBrowse3->Click += gcnew System::EventHandler(this, &ClientForm::btnBrowse3_Click);
			// 
			// progressBar3
			// 
			this->progressBar3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar3->Location = System::Drawing::Point(6, 407);
			this->progressBar3->Margin = System::Windows::Forms::Padding(2);
			this->progressBar3->Name = L"progressBar3";
			this->progressBar3->Size = System::Drawing::Size(806, 23);
			this->progressBar3->TabIndex = 35;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::White;
			this->label9->ForeColor = System::Drawing::Color::Black;
			this->label9->Location = System::Drawing::Point(2, 165);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(170, 13);
			this->label9->TabIndex = 34;
			this->label9->Text = L"Список папок для мониторинга:";
			// 
			// txtMonitorRes
			// 
			this->txtMonitorRes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtMonitorRes->BackColor = System::Drawing::Color::White;
			this->txtMonitorRes->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtMonitorRes->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtMonitorRes->ForeColor = System::Drawing::Color::Black;
			this->txtMonitorRes->HideSelection = false;
			this->txtMonitorRes->Location = System::Drawing::Point(291, 68);
			this->txtMonitorRes->Margin = System::Windows::Forms::Padding(2);
			this->txtMonitorRes->Name = L"txtMonitorRes";
			this->txtMonitorRes->ReadOnly = true;
			this->txtMonitorRes->Size = System::Drawing::Size(521, 335);
			this->txtMonitorRes->TabIndex = 32;
			this->txtMonitorRes->Text = L"";
			// 
			// btnDelMonitoring
			// 
			this->btnDelMonitoring->BackColor = System::Drawing::Color::White;
			this->btnDelMonitoring->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnDelMonitoring->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnDelMonitoring->Location = System::Drawing::Point(154, 95);
			this->btnDelMonitoring->Margin = System::Windows::Forms::Padding(2);
			this->btnDelMonitoring->Name = L"btnDelMonitoring";
			this->btnDelMonitoring->Size = System::Drawing::Size(133, 59);
			this->btnDelMonitoring->TabIndex = 31;
			this->btnDelMonitoring->Text = L"Отменить мониторинг";
			this->btnDelMonitoring->UseVisualStyleBackColor = false;
			this->btnDelMonitoring->Click += gcnew System::EventHandler(this, &ClientForm::btnDelMonitoring_Click);
			// 
			// btnSetMonitoring
			// 
			this->btnSetMonitoring->BackColor = System::Drawing::Color::White;
			this->btnSetMonitoring->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnSetMonitoring->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnSetMonitoring->Location = System::Drawing::Point(6, 95);
			this->btnSetMonitoring->Margin = System::Windows::Forms::Padding(2);
			this->btnSetMonitoring->Name = L"btnSetMonitoring";
			this->btnSetMonitoring->Size = System::Drawing::Size(133, 59);
			this->btnSetMonitoring->TabIndex = 30;
			this->btnSetMonitoring->Text = L"Установить мониторинг";
			this->btnSetMonitoring->UseVisualStyleBackColor = false;
			this->btnSetMonitoring->Click += gcnew System::EventHandler(this, &ClientForm::btnSetMonitoring_Click_1);
			// 
			// monitoringListBox
			// 
			this->monitoringListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->monitoringListBox->BackColor = System::Drawing::Color::White;
			this->monitoringListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->monitoringListBox->ForeColor = System::Drawing::Color::Black;
			this->monitoringListBox->FormattingEnabled = true;
			this->monitoringListBox->Location = System::Drawing::Point(6, 180);
			this->monitoringListBox->Margin = System::Windows::Forms::Padding(2);
			this->monitoringListBox->Name = L"monitoringListBox";
			this->monitoringListBox->Size = System::Drawing::Size(281, 223);
			this->monitoringListBox->TabIndex = 29;
			// 
			// txtMonitoringPath
			// 
			this->txtMonitoringPath->BackColor = System::Drawing::Color::White;
			this->txtMonitoringPath->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtMonitoringPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->txtMonitoringPath->ForeColor = System::Drawing::Color::Black;
			this->txtMonitoringPath->Location = System::Drawing::Point(6, 68);
			this->txtMonitoringPath->Margin = System::Windows::Forms::Padding(2);
			this->txtMonitoringPath->Name = L"txtMonitoringPath";
			this->txtMonitoringPath->ReadOnly = true;
			this->txtMonitoringPath->Size = System::Drawing::Size(208, 23);
			this->txtMonitoringPath->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::White;
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(3, 53);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(141, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Директория мониторинга:";
			// 
			// btnBrowse2
			// 
			this->btnBrowse2->BackColor = System::Drawing::Color::White;
			this->btnBrowse2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnBrowse2->Location = System::Drawing::Point(218, 68);
			this->btnBrowse2->Margin = System::Windows::Forms::Padding(2);
			this->btnBrowse2->Name = L"btnBrowse2";
			this->btnBrowse2->Size = System::Drawing::Size(69, 23);
			this->btnBrowse2->TabIndex = 9;
			this->btnBrowse2->Text = L"Обзор";
			this->btnBrowse2->UseVisualStyleBackColor = false;
			this->btnBrowse2->Click += gcnew System::EventHandler(this, &ClientForm::btnBrowse2_Click);
			// 
			// btnBrowseFile
			// 
			this->btnBrowseFile->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnBrowseFile->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnBrowseFile->Location = System::Drawing::Point(6, 56);
			this->btnBrowseFile->Margin = System::Windows::Forms::Padding(2);
			this->btnBrowseFile->Name = L"btnBrowseFile";
			this->btnBrowseFile->Size = System::Drawing::Size(88, 41);
			this->btnBrowseFile->TabIndex = 16;
			this->btnBrowseFile->Text = L"Выбрать файл";
			this->btnBrowseFile->UseVisualStyleBackColor = false;
			this->btnBrowseFile->Click += gcnew System::EventHandler(this, &ClientForm::btnBrowseFile_Click);
			// 
			// btnStopScan
			// 
			this->btnStopScan->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnStopScan->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnStopScan->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnStopScan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStopScan->Location = System::Drawing::Point(675, 435);
			this->btnStopScan->Margin = System::Windows::Forms::Padding(2);
			this->btnStopScan->Name = L"btnStopScan";
			this->btnStopScan->Size = System::Drawing::Size(137, 61);
			this->btnStopScan->TabIndex = 14;
			this->btnStopScan->Text = L"Остановить сканирование";
			this->btnStopScan->UseVisualStyleBackColor = false;
			this->btnStopScan->Click += gcnew System::EventHandler(this, &ClientForm::btnStopScan_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->progressBar1->Location = System::Drawing::Point(6, 101);
			this->progressBar1->Margin = System::Windows::Forms::Padding(2);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(806, 23);
			this->progressBar1->TabIndex = 13;
			// 
			// txtScanPath
			// 
			this->txtScanPath->BackColor = System::Drawing::Color::White;
			this->txtScanPath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtScanPath->ForeColor = System::Drawing::Color::Black;
			this->txtScanPath->Location = System::Drawing::Point(190, 73);
			this->txtScanPath->Margin = System::Windows::Forms::Padding(2);
			this->txtScanPath->Name = L"txtScanPath";
			this->txtScanPath->ReadOnly = true;
			this->txtScanPath->Size = System::Drawing::Size(302, 23);
			this->txtScanPath->TabIndex = 2;
			// 
			// txtScanRes
			// 
			this->txtScanRes->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtScanRes->BackColor = System::Drawing::Color::White;
			this->txtScanRes->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtScanRes->ForeColor = System::Drawing::Color::Black;
			this->txtScanRes->HideSelection = false;
			this->txtScanRes->Location = System::Drawing::Point(6, 128);
			this->txtScanRes->Margin = System::Windows::Forms::Padding(2);
			this->txtScanRes->Name = L"txtScanRes";
			this->txtScanRes->ReadOnly = true;
			this->txtScanRes->Size = System::Drawing::Size(806, 303);
			this->txtScanRes->TabIndex = 15;
			this->txtScanRes->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(191, 56);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Путь сканирования:";
			// 
			// btnStartScan
			// 
			this->btnStartScan->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnStartScan->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnStartScan->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnStartScan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStartScan->Location = System::Drawing::Point(534, 435);
			this->btnStartScan->Margin = System::Windows::Forms::Padding(2);
			this->btnStartScan->Name = L"btnStartScan";
			this->btnStartScan->Size = System::Drawing::Size(137, 61);
			this->btnStartScan->TabIndex = 0;
			this->btnStartScan->Text = L"Начать сканирование";
			this->btnStartScan->UseVisualStyleBackColor = false;
			this->btnStartScan->Click += gcnew System::EventHandler(this, &ClientForm::btnStartScan_Click);
			// 
			// btnBrowseFolder
			// 
			this->btnBrowseFolder->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnBrowseFolder->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnBrowseFolder->Location = System::Drawing::Point(98, 56);
			this->btnBrowseFolder->Margin = System::Windows::Forms::Padding(2);
			this->btnBrowseFolder->Name = L"btnBrowseFolder";
			this->btnBrowseFolder->Size = System::Drawing::Size(88, 41);
			this->btnBrowseFolder->TabIndex = 5;
			this->btnBrowseFolder->Text = L"Выбрать папку";
			this->btnBrowseFolder->UseVisualStyleBackColor = false;
			this->btnBrowseFolder->Click += gcnew System::EventHandler(this, &ClientForm::btnBrowse_Click);
			// 
			// btnStopService
			// 
			this->btnStopService->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnStopService->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnStopService->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnStopService->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStopService->Location = System::Drawing::Point(14, 112);
			this->btnStopService->Margin = System::Windows::Forms::Padding(2);
			this->btnStopService->Name = L"btnStopService";
			this->btnStopService->Size = System::Drawing::Size(185, 72);
			this->btnStopService->TabIndex = 1;
			this->btnStopService->Text = L"Остановить сервис";
			this->btnStopService->UseVisualStyleBackColor = false;
			this->btnStopService->Click += gcnew System::EventHandler(this, &ClientForm::btnStopService_Click);
			// 
			// btnStartService
			// 
			this->btnStartService->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnStartService->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnStartService->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnStartService->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnStartService->Location = System::Drawing::Point(14, 23);
			this->btnStartService->Margin = System::Windows::Forms::Padding(2);
			this->btnStartService->Name = L"btnStartService";
			this->btnStartService->Size = System::Drawing::Size(185, 86);
			this->btnStartService->TabIndex = 0;
			this->btnStartService->Text = L"Запустить сервис";
			this->btnStartService->UseVisualStyleBackColor = false;
			this->btnStartService->Click += gcnew System::EventHandler(this, &ClientForm::btnStartService_Click);
			// 
			// reportListBox
			// 
			this->reportListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->reportListBox->BackColor = System::Drawing::Color::White;
			this->reportListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->reportListBox->ForeColor = System::Drawing::Color::Black;
			this->reportListBox->FormattingEnabled = true;
			this->reportListBox->Location = System::Drawing::Point(6, 68);
			this->reportListBox->Margin = System::Windows::Forms::Padding(2);
			this->reportListBox->Name = L"reportListBox";
			this->reportListBox->Size = System::Drawing::Size(310, 418);
			this->reportListBox->TabIndex = 12;
			// 
			// btnDeleteFromQuarantine
			// 
			this->btnDeleteFromQuarantine->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnDeleteFromQuarantine->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnDeleteFromQuarantine->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnDeleteFromQuarantine->Location = System::Drawing::Point(320, 68);
			this->btnDeleteFromQuarantine->Margin = System::Windows::Forms::Padding(2);
			this->btnDeleteFromQuarantine->Name = L"btnDeleteFromQuarantine";
			this->btnDeleteFromQuarantine->Size = System::Drawing::Size(178, 90);
			this->btnDeleteFromQuarantine->TabIndex = 23;
			this->btnDeleteFromQuarantine->Text = L"Вернуть из карантина\r\n<----------------------";
			this->btnDeleteFromQuarantine->UseVisualStyleBackColor = false;
			this->btnDeleteFromQuarantine->Click += gcnew System::EventHandler(this, &ClientForm::btnDeleteFromQuarantine_Click_1);
			// 
			// QuarantineListBox
			// 
			this->QuarantineListBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->QuarantineListBox->BackColor = System::Drawing::Color::White;
			this->QuarantineListBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->QuarantineListBox->ForeColor = System::Drawing::Color::Black;
			this->QuarantineListBox->FormattingEnabled = true;
			this->QuarantineListBox->Location = System::Drawing::Point(502, 68);
			this->QuarantineListBox->Margin = System::Windows::Forms::Padding(2);
			this->QuarantineListBox->Name = L"QuarantineListBox";
			this->QuarantineListBox->Size = System::Drawing::Size(310, 418);
			this->QuarantineListBox->TabIndex = 17;
			// 
			// btnMoveToQuarantine
			// 
			this->btnMoveToQuarantine->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnMoveToQuarantine->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnMoveToQuarantine->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnMoveToQuarantine->Location = System::Drawing::Point(321, 162);
			this->btnMoveToQuarantine->Margin = System::Windows::Forms::Padding(2);
			this->btnMoveToQuarantine->Name = L"btnMoveToQuarantine";
			this->btnMoveToQuarantine->Size = System::Drawing::Size(178, 90);
			this->btnMoveToQuarantine->TabIndex = 22;
			this->btnMoveToQuarantine->Text = L"Поместить в карантин\r\n----------------------->\r\n";
			this->btnMoveToQuarantine->UseVisualStyleBackColor = false;
			this->btnMoveToQuarantine->Click += gcnew System::EventHandler(this, &ClientForm::btnMoveToQuarantine_Click_1);
			// 
			// btnDelete
			// 
			this->btnDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnDelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnDelete->Location = System::Drawing::Point(321, 256);
			this->btnDelete->Margin = System::Windows::Forms::Padding(2);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(178, 90);
			this->btnDelete->TabIndex = 21;
			this->btnDelete->Text = L"Удалить";
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &ClientForm::btnDelete_Click_1);
			// 
			// panelFastCheck
			// 
			this->panelFastCheck->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelFastCheck->Controls->Add(this->label10);
			this->panelFastCheck->Controls->Add(this->button1);
			this->panelFastCheck->Controls->Add(this->progressBar1);
			this->panelFastCheck->Controls->Add(this->btnBrowseFile);
			this->panelFastCheck->Controls->Add(this->btnStopScan);
			this->panelFastCheck->Controls->Add(this->btnBrowseFolder);
			this->panelFastCheck->Controls->Add(this->btnStartScan);
			this->panelFastCheck->Controls->Add(this->txtScanPath);
			this->panelFastCheck->Controls->Add(this->label2);
			this->panelFastCheck->Controls->Add(this->txtScanRes);
			this->panelFastCheck->Location = System::Drawing::Point(0, 0);
			this->panelFastCheck->Name = L"panelFastCheck";
			this->panelFastCheck->Size = System::Drawing::Size(827, 504);
			this->panelFastCheck->TabIndex = 9;
			this->panelFastCheck->Visible = false;
			// 
			// label10
			// 
			this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label10->BackColor = System::Drawing::Color::Silver;
			this->label10->Font = (gcnew System::Drawing::Font(L"Calibri", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(0, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(827, 48);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Быстрая проверка";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Location = System::Drawing::Point(6, 435);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 61);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Вернуться на главный экран";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ClientForm::button1_Click);
			// 
			// panelPlanCheck
			// 
			this->panelPlanCheck->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelPlanCheck->Controls->Add(this->txtScheduleScanRes);
			this->panelPlanCheck->Controls->Add(this->button2);
			this->panelPlanCheck->Controls->Add(this->label7);
			this->panelPlanCheck->Controls->Add(this->progressBar2);
			this->panelPlanCheck->Controls->Add(this->label11);
			this->panelPlanCheck->Controls->Add(this->scheduleListBox);
			this->panelPlanCheck->Controls->Add(this->label4);
			this->panelPlanCheck->Controls->Add(this->btnScheduleScan);
			this->panelPlanCheck->Controls->Add(this->btnStopSchedule);
			this->panelPlanCheck->Controls->Add(this->btnBrowse3);
			this->panelPlanCheck->Controls->Add(this->dateTimePicker);
			this->panelPlanCheck->Controls->Add(this->txtSchedulePath);
			this->panelPlanCheck->Controls->Add(this->label6);
			this->panelPlanCheck->Location = System::Drawing::Point(0, 0);
			this->panelPlanCheck->Name = L"panelPlanCheck";
			this->panelPlanCheck->Size = System::Drawing::Size(827, 504);
			this->panelPlanCheck->TabIndex = 10;
			this->panelPlanCheck->Visible = false;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Location = System::Drawing::Point(6, 435);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(133, 61);
			this->button2->TabIndex = 25;
			this->button2->Text = L"Вернуться на главный экран";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ClientForm::button1_Click);
			// 
			// label11
			// 
			this->label11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label11->BackColor = System::Drawing::Color::Silver;
			this->label11->Font = (gcnew System::Drawing::Font(L"Calibri", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(0, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(827, 48);
			this->label11->TabIndex = 18;
			this->label11->Text = L"Запланированная проверка";
			// 
			// panelFolderMonitoring
			// 
			this->panelFolderMonitoring->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelFolderMonitoring->Controls->Add(this->progressBar3);
			this->panelFolderMonitoring->Controls->Add(this->button3);
			this->panelFolderMonitoring->Controls->Add(this->label9);
			this->panelFolderMonitoring->Controls->Add(this->btnDelMonitoring);
			this->panelFolderMonitoring->Controls->Add(this->label12);
			this->panelFolderMonitoring->Controls->Add(this->btnSetMonitoring);
			this->panelFolderMonitoring->Controls->Add(this->txtMonitorRes);
			this->panelFolderMonitoring->Controls->Add(this->label13);
			this->panelFolderMonitoring->Controls->Add(this->monitoringListBox);
			this->panelFolderMonitoring->Controls->Add(this->btnBrowse2);
			this->panelFolderMonitoring->Controls->Add(this->txtMonitoringPath);
			this->panelFolderMonitoring->Controls->Add(this->label3);
			this->panelFolderMonitoring->Location = System::Drawing::Point(0, 0);
			this->panelFolderMonitoring->Name = L"panelFolderMonitoring";
			this->panelFolderMonitoring->Size = System::Drawing::Size(827, 504);
			this->panelFolderMonitoring->TabIndex = 11;
			this->panelFolderMonitoring->Visible = false;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button3->Location = System::Drawing::Point(6, 435);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(133, 61);
			this->button3->TabIndex = 25;
			this->button3->Text = L"Вернуться на главный экран";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ClientForm::button1_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::White;
			this->label12->ForeColor = System::Drawing::Color::Black;
			this->label12->Location = System::Drawing::Point(288, 53);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(162, 13);
			this->label12->TabIndex = 24;
			this->label12->Text = L"Процесс последней проверки:";
			// 
			// label13
			// 
			this->label13->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label13->BackColor = System::Drawing::Color::Silver;
			this->label13->Font = (gcnew System::Drawing::Font(L"Calibri", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->ForeColor = System::Drawing::Color::Black;
			this->label13->Location = System::Drawing::Point(0, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(827, 48);
			this->label13->TabIndex = 18;
			this->label13->Text = L"Мониторинг папки";
			// 
			// panelDetectedThreats
			// 
			this->panelDetectedThreats->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelDetectedThreats->Controls->Add(this->button4);
			this->panelDetectedThreats->Controls->Add(this->btnDeleteFromQuarantine);
			this->panelDetectedThreats->Controls->Add(this->label16);
			this->panelDetectedThreats->Controls->Add(this->btnMoveToQuarantine);
			this->panelDetectedThreats->Controls->Add(this->QuarantineListBox);
			this->panelDetectedThreats->Controls->Add(this->label15);
			this->panelDetectedThreats->Controls->Add(this->btnDelete);
			this->panelDetectedThreats->Controls->Add(this->reportListBox);
			this->panelDetectedThreats->Controls->Add(this->label14);
			this->panelDetectedThreats->Location = System::Drawing::Point(0, 0);
			this->panelDetectedThreats->Name = L"panelDetectedThreats";
			this->panelDetectedThreats->Size = System::Drawing::Size(827, 504);
			this->panelDetectedThreats->TabIndex = 12;
			this->panelDetectedThreats->Visible = false;
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button4->Location = System::Drawing::Point(321, 445);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(176, 41);
			this->button4->TabIndex = 24;
			this->button4->Text = L"Вернуться на главный экран";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &ClientForm::button1_Click);
			// 
			// label16
			// 
			this->label16->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label16->AutoSize = true;
			this->label16->ForeColor = System::Drawing::Color::Black;
			this->label16->Location = System::Drawing::Point(499, 53);
			this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(73, 13);
			this->label16->TabIndex = 20;
			this->label16->Text = L"В карантине:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->ForeColor = System::Drawing::Color::Black;
			this->label15->Location = System::Drawing::Point(3, 53);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(126, 13);
			this->label15->TabIndex = 19;
			this->label15->Text = L"Обнаруженные угрозы:";
			// 
			// label14
			// 
			this->label14->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label14->BackColor = System::Drawing::Color::Silver;
			this->label14->Font = (gcnew System::Drawing::Font(L"Calibri", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->ForeColor = System::Drawing::Color::Black;
			this->label14->Location = System::Drawing::Point(0, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(827, 48);
			this->label14->TabIndex = 18;
			this->label14->Text = L"Обнаруженные угрозы";
			// 
			// panelMenu
			// 
			this->panelMenu->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelMenu->Controls->Add(this->groupBox2);
			this->panelMenu->Controls->Add(this->groupBox1);
			this->panelMenu->Controls->Add(this->label19);
			this->panelMenu->Location = System::Drawing::Point(0, 0);
			this->panelMenu->Name = L"panelMenu";
			this->panelMenu->Size = System::Drawing::Size(827, 504);
			this->panelMenu->TabIndex = 13;
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->groupBox2->Controls->Add(this->btnStopService);
			this->groupBox2->Controls->Add(this->btnStartService);
			this->groupBox2->Location = System::Drawing::Point(421, 88);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(214, 202);
			this->groupBox2->TabIndex = 23;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Управление сервисом";
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Location = System::Drawing::Point(202, 88);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(179, 202);
			this->groupBox1->TabIndex = 22;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Функционал антивируса:";
			// 
			// button7
			// 
			this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button7->Location = System::Drawing::Point(20, 108);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(133, 38);
			this->button7->TabIndex = 20;
			this->button7->Text = L"Мониторинг папки";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &ClientForm::button7_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button5->Location = System::Drawing::Point(20, 64);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(133, 38);
			this->button5->TabIndex = 20;
			this->button5->Text = L"Запланированная проверка";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &ClientForm::button5_Click);
			// 
			// button8
			// 
			this->button8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button8->Location = System::Drawing::Point(20, 152);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(133, 38);
			this->button8->TabIndex = 20;
			this->button8->Text = L"Обнаруженные угрозы и\r\nкарантин";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &ClientForm::button8_Click);
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button6->Location = System::Drawing::Point(20, 20);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(133, 38);
			this->button6->TabIndex = 20;
			this->button6->Text = L"Быстрая проверка";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &ClientForm::button6_Click);
			// 
			// label19
			// 
			this->label19->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label19->BackColor = System::Drawing::Color::Silver;
			this->label19->Font = (gcnew System::Drawing::Font(L"Calibri", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->ForeColor = System::Drawing::Color::Black;
			this->label19->Location = System::Drawing::Point(0, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(827, 48);
			this->label19->TabIndex = 18;
			this->label19->Text = L"Главное меню";
			this->label19->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ClientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(827, 504);
			this->Controls->Add(this->panelMenu);
			this->Controls->Add(this->panelFastCheck);
			this->Controls->Add(this->panelPlanCheck);
			this->Controls->Add(this->panelFolderMonitoring);
			this->Controls->Add(this->panelDetectedThreats);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(792, 251);
			this->Name = L"ClientForm";
			this->Text = L"Антивирус";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &ClientForm::ClientForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &ClientForm::ClientForm_Load);
			this->panelFastCheck->ResumeLayout(false);
			this->panelFastCheck->PerformLayout();
			this->panelPlanCheck->ResumeLayout(false);
			this->panelPlanCheck->PerformLayout();
			this->panelFolderMonitoring->ResumeLayout(false);
			this->panelFolderMonitoring->PerformLayout();
			this->panelDetectedThreats->ResumeLayout(false);
			this->panelDetectedThreats->PerformLayout();
			this->panelMenu->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void ClientForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		Thread^ thread = gcnew Thread(gcnew ThreadStart(this, &ClientForm::createPipeAndListening));
		thread->IsBackground = true;
		thread->Start();
	}

	private: bool createPipeForRead()
	{
		pipeForRead = CreateNamedPipe(
			PIPE_SERVICE_TO_CLIENT_NAME,             // имя канала 
			PIPE_ACCESS_DUPLEX,       // чтение/запись доступ 
			PIPE_TYPE_MESSAGE |       // тип сообщения каналу 
			PIPE_READMODE_MESSAGE |   // режим чтения сообщений 
			PIPE_WAIT,                // режим блокирования
			PIPE_UNLIMITED_INSTANCES, // максимальное количество экземпляров 
			PIPE_BUFSIZE,                  // размер буфера на выход 
			PIPE_BUFSIZE,                  // размер буфера на вход 
			0,                        // клиент время 
			NULL);                    // атрибут безопасности по умолчанию 

		if (pipeForRead == INVALID_HANDLE_VALUE)
		{
			//MessageBox::Show("Нет соединения с сервером\r\nКод ошибки: " + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			FlushFileBuffers(pipeForRead);
			DisconnectNamedPipe(pipeForRead);
			CloseHandle(pipeForRead);
			//createPipeForSend();
			return false;
		}
		return true;
	}

	private: bool createPipeForSend()
	{
		pipeForSend = NULL;
		CloseHandle(pipeForSend);

		if (pipeForSend == NULL)
			pipeForSend = CreateFile(
				PIPE_CLIENT_TO_SERVICE_NAME,   // pipe name 
				GENERIC_READ |  // read and write access 
				GENERIC_WRITE,
				0,              // no sharing 
				NULL,           // default security attributes
				OPEN_EXISTING,  // opens existing pipe 
				0,              // default attributes 
				NULL);          // no template file 

		  // Break if the pipe handle is valid.
		if (pipeForSend == INVALID_HANDLE_VALUE)
		{
			CloseHandle(pipeForSend);
			//MessageBox::Show("Нет соединения с сервером\r\n" + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			pipeForSend = NULL;
			return false;
		}

		// Exit if an error other than ERROR_PIPE_BUSY occurs.
		if (GetLastError() == ERROR_PIPE_BUSY)
		{
			CloseHandle(pipeForSend);
			//MessageBox::Show("Нет соединения с сервером\r\n" + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			pipeForSend = NULL;
			return false;
		}

		// Exit if an error other than ERROR_PIPE_BUSY occurs.
		if (GetLastError() == ERROR_BROKEN_PIPE)
		{
			CloseHandle(pipeForSend);
			//MessageBox::Show("Нет соединения с сервером\r\n" + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			pipeForSend = NULL;
			return false;
		}

		if (GetLastError() == ERROR_FILE_NOT_FOUND)
		{
			CloseHandle(pipeForSend);
			//MessageBox::Show("Нет соединения с сервером\r\n" + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			pipeForSend = NULL;
			return false;
		}
		if (!GetLastError())
			return true;
	}

	void createPipeAndListening()
	{
		bool fConnected2 = false, fConnected3 = false;
		while (!fConnected2)
		{
			fConnected2 = createPipeForSend();

		}
		while (!fConnected3)
		{
			fConnected3 = createPipeForRead();

		}

		// Подождите, пока клиент подключится; если это удастся,
		// функция возвращает ненулевое значение. Если функция
		// возвращает ноль, GetLastError возвращает ERROR_PIPE_CONNECTED.
		BOOL fConnected = ConnectNamedPipe(pipeForRead, NULL) ?
			TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
		message messagefromService;
		while (fConnected)
		{
			messagefromService = Messenger::readMessage(pipeForRead, PIPE_BUFSIZE);
			if (messagefromService.cmd == COMMAND::UNKNOWN)
			{				
				MessageBox::Show("Сервис был остановлен", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
				progressBar1->Value = 0;
				progressBar2->Value = 0;
				progressBar3->Value = 0;
				txtScanRes->Clear();
				txtScheduleScanRes->Clear();
				txtMonitorRes->Clear();
				bool fConnected2 = false, fConnected3 = false;
				while (!fConnected2)
				{
					fConnected2 = createPipeForSend();

				}
				while (!fConnected3)
				{
					fConnected3 = createPipeForRead();

				}
				fConnected = ConnectNamedPipe(pipeForRead, NULL) ?
					TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
				if (!fConnected)
				{
					//MessageBox::Show("Нет соединения с сервером\r\n" + GetLastError().ToString(), "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					FlushFileBuffers(pipeForRead);
					DisconnectNamedPipe(pipeForRead);
					CloseHandle(pipeForRead);
				}
			}
			messageProcessing(messagefromService);
		}
		
		//progressBar1->Value = 0;

		//CloseHandle(pipeForRead);
		//createPipeForSend();
		//Thread^ thread = gcnew Thread(gcnew ThreadStart(this, &ClientForm::createPipeAndListening));
		//thread->IsBackground = true;
		//thread->Start();
		//createPipeAndListening();
	}		

	void messageProcessing(message msg)
	{
		switch (msg.cmd)
		{
			case COMMAND::INFO: {
				if (msg.nArr.at(0) == 0) {
					reportListBox->Items->Clear();
					for (size_t i = 0; i < msg.sArr.size(); i += 2)
					{
						if (!reportListBox->Items->Contains(msclr::interop::marshal_as<String^>(msg.sArr.at(i + 1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(i))))
							reportListBox->Items->Add(msclr::interop::marshal_as<String^>(msg.sArr.at(i + 1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(i)));
					}
				}
				if (msg.nArr.at(0) == 1) {
					QuarantineListBox->Items->Clear();
					for (size_t i = 0; i < msg.sArr.size(); i += 2)
					{
						if (!QuarantineListBox->Items->Contains(msclr::interop::marshal_as<String^>(msg.sArr.at(i + 1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(i))))
							QuarantineListBox->Items->Add(msclr::interop::marshal_as<String^>(msg.sArr.at(i + 1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(i)));
					}
				}
				break;
			}
		   case COMMAND::START: {
			   if (!msg.nArr.empty())
			   {
				   progressBar1->Maximum = msg.nArr.at(0);
			   }
			   else
			   {
				   txtScanRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   txtScanRes->AppendText("\t\t\t");
				   txtScanRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(1)));
				   txtScanRes->AppendText("\r\n");
				   progressBar1->Increment(1);
				   if (msclr::interop::marshal_as<String^>(msg.sArr.at(1))->Contains("вредонос"))
				   {
					   if (!reportListBox->Items->Contains(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0))))
						   reportListBox->Items->Add(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   }
	
			   }
			   break;
		   }
		   case COMMAND::SCHEDULE_START: {
			   if (!msg.nArr.empty())
			   {
				   progressBar2->Maximum = msg.nArr.at(0);
				   if (scheduleListBox->Items->Count > 0)
					   scheduleListBox->Items->RemoveAt(0);
			   }
			   else
			   {
				   txtScheduleScanRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   txtScheduleScanRes->AppendText("\t\t\t");
				   txtScheduleScanRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(1)));
				   txtScheduleScanRes->AppendText("\r\n");
				   progressBar2->Increment(1);
				   if (msclr::interop::marshal_as<String^>(msg.sArr.at(1))->Contains("вредонос"))
				   {
					   if (!reportListBox->Items->Contains(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0))))
						   reportListBox->Items->Add(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   }
	
			   }
			   break;
		   }

		   case COMMAND::SET_MONITORING: {
			   if (!msg.nArr.empty())
			   {
				   progressBar3->Value = 0;
				   txtMonitorRes->Clear();
				   progressBar3->Maximum = msg.nArr.at(0);
			   }
			   else
			   {
				   txtMonitorRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   txtMonitorRes->AppendText("\t\t\t");
				   txtMonitorRes->AppendText(msclr::interop::marshal_as<String^>(msg.sArr.at(1)));
				   txtMonitorRes->AppendText("\r\n");
				   progressBar3->Increment(1);
				   if (msclr::interop::marshal_as<String^>(msg.sArr.at(1))->Contains("вредонос"))
				   {
					   if (!reportListBox->Items->Contains(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0))))
						   reportListBox->Items->Add(msclr::interop::marshal_as<String^>(msg.sArr.at(1)) + "\t" + msclr::interop::marshal_as<String^>(msg.sArr.at(0)));
				   }

			   }
			   break;
		   }
		   case COMMAND::STOP: {
			   btnBrowseFile->Enabled = true;
			   btnBrowseFolder->Enabled = true;
			   btnStartScan->Enabled = true;
			   progressBar1->Value = 0;
			   txtScanRes->Clear();
			   MessageBox::Show("Сканирование остановлено\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1), "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   break;
		   }
		   case COMMAND::SCAN_RESULT: {
			   btnBrowseFile->Enabled = true;
			   btnBrowseFolder->Enabled = true;
			   btnStartScan->Enabled = true;
			   //progressBar1->Value = 0;
			   txtScanRes->AppendText("\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1) + "\r\n");
			   MessageBox::Show("Сканирование успешно завершилось!\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1), "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   break;
		   }
		   case COMMAND::SCHEDULE_SCAN_RESULT: {
			   //progressBar2->Value = 0;
			   txtScheduleScanRes->AppendText("\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1) + "\r\n");
			   MessageBox::Show("Запланированное сканирование успешно завершилось!\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1), "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   break;
		   }
		   case COMMAND::MONITORING_RESULT: {
			   //progressBar3->Value = 0;
			   txtMonitorRes->AppendText("\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1) + "\r\n");
			   MessageBox::Show("Содержимое папки было изменено, папка успешно просканирована\r\nКоличество просканированных файлов: " + msg.nArr.at(0) + "\r\nУгроз: " + msg.nArr.at(1), "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   break;
		   }
		   case COMMAND::RESET_SCHEDULE: {
			   MessageBox::Show("Запланированная проверка отменена", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
			   if (scheduleListBox->Items->Count > 0)
				   scheduleListBox->Items->Clear();
			   progressBar2->Value = 0;
			   txtScheduleScanRes->Clear();
			   break;
		   }
		}
	}

	private: System::Void btnStartScan_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (String::IsNullOrWhiteSpace(txtScanPath->Text))
		{
			MessageBox::Show("Выберите файл или папку для сканирования", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		btnBrowseFile->Enabled = false;
		btnBrowseFolder->Enabled = false;
		btnStartScan->Enabled = false;
		txtScanRes->Clear();
		progressBar1->Value = 0;
		message startScanMsg;
		std::string path = msclr::interop::marshal_as<std::string>(txtScanPath->Text);
		startScanMsg.cmd = COMMAND::START;
		startScanMsg.sArr.push_back(path);
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, startScanMsg);	
		txtScanPath->Clear();
	}

	private: System::Void btnBrowseFile_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openFD->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			txtScanPath->Text = openFD->FileName;
		}
	}

	private: System::Void btnStopScan_Click(System::Object^ sender, System::EventArgs^ e)
	{
		message startScanMsg;
		startScanMsg.cmd = COMMAND::STOP;
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, startScanMsg);
	}
	private: System::Void btnStopSchedule_Click(System::Object^ sender, System::EventArgs^ e)
	{
		message stopSchedule;
		stopSchedule.cmd = COMMAND::RESET_SCHEDULE;
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, stopSchedule);
		MessageBox::Show("Запланированная проверка будет отменена в течении 30 секунд", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void btnDelete_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		if (reportListBox->SelectedItems->Count == 0)
		{
			MessageBox::Show("Выберите файл для удаления", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		message delMsg;
		delMsg.cmd = COMMAND::DEL;
		String^ threatText = reportListBox->SelectedItem->ToString();
		array<String^>^ threatTextArr = threatText->Split('\t');
		String^ nameMessage = threatTextArr->GetValue(0)->ToString();
		String^ pathMessage = threatTextArr->GetValue(1)->ToString();
		delMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(pathMessage));
		delMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(nameMessage));
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, delMsg);
		reportListBox->Items->Remove(reportListBox->SelectedItem);
	}

	private: System::Void btnMoveToQuarantine_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		if (reportListBox->SelectedItems->Count == 0)
		{
			MessageBox::Show("Выберите файл для помещения в карантин", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		message quarMsg;
		quarMsg.cmd = COMMAND::MOVE_TO_QUARANTINE;
		String^ threatText = reportListBox->SelectedItem->ToString();
		array<String^>^ threatTextArr = threatText->Split('\t');
		String^ nameMessage = threatTextArr->GetValue(0)->ToString();
		String^ pathMessage = threatTextArr->GetValue(1)->ToString();
		quarMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(pathMessage));
		quarMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(nameMessage));
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, quarMsg);
		QuarantineListBox->Items->Add(reportListBox->SelectedItem);
		reportListBox->Items->Remove(reportListBox->SelectedItem);
	}

	private: System::Void btnDeleteFromQuarantine_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		if (QuarantineListBox->SelectedItems->Count == 0)
		{
			MessageBox::Show("Выберите файл для возврата из карантина", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		message delFromQuarMsg;
		delFromQuarMsg.cmd = COMMAND::DELETE_FROM_QUARANTINE;
		String^ threatText = QuarantineListBox->SelectedItem->ToString();
		array<String^>^ threatTextArr = threatText->Split('\t');
		String^ nameMessage = threatTextArr->GetValue(0)->ToString();
		String^ pathMessage = threatTextArr->GetValue(1)->ToString();
		delFromQuarMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(pathMessage));
		delFromQuarMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(nameMessage));
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, delFromQuarMsg);
		reportListBox->Items->Add(QuarantineListBox->SelectedItem);
		QuarantineListBox->Items->Remove(QuarantineListBox->SelectedItem);
	}

	private: System::Void btnSetMonitoring_Click_1(System::Object^ sender, System::EventArgs^ e)
	{
		monitoringListBox->Items->Add(txtMonitoringPath->Text);
		message monitoringMessage;
		monitoringMessage.sArr.push_back(msclr::interop::marshal_as<std::string>(txtMonitoringPath->Text));
		monitoringMessage.cmd = COMMAND::SET_MONITORING;
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, monitoringMessage);
		txtMonitoringPath->Clear();
	}

	private: System::Void btnDelMonitoring_Click(System::Object^ sender, System::EventArgs^ e)
	{
		txtMonitoringPath->Clear();
		message monitoringMessage;
		monitoringMessage.cmd = COMMAND::STOP_MONITORING;
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, monitoringMessage);
		monitoringListBox->Items->Clear();
		MessageBox::Show("Мониторинг отменён", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	
	private: System::Void btnBrowse_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			txtScanPath->Text = folderBrowserDialog->SelectedPath;
		}
	}

	private: System::Void btnBrowse2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			txtMonitoringPath->Text = folderBrowserDialog->SelectedPath;
		}
	}

	private: System::Void btnBrowse3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (folderBrowserDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

			txtSchedulePath->Text = folderBrowserDialog->SelectedPath;
			dateTimePicker->Value = dateTimePicker->Value.AddMinutes(1);
		}
	}

	private: System::Void btnScheduleScan_Click(System::Object^ sender, System::EventArgs^ e)
	{
		txtScheduleScanRes->Clear();
		if (String::IsNullOrEmpty(txtSchedulePath->Text))
		{
			MessageBox::Show("Выберите файл или папку для сканирования", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		scheduleListBox->Items->Add(dateTimePicker->Value.ToShortTimeString() + "\t" + txtSchedulePath->Text);
		message scheduleMsg;
		scheduleMsg.cmd = COMMAND::SET_SCHEDULE;
		scheduleMsg.sArr.push_back(msclr::interop::marshal_as<std::string>(txtSchedulePath->Text));
		scheduleMsg.nArr.push_back(dateTimePicker->Value.Hour);
		scheduleMsg.nArr.push_back(dateTimePicker->Value.Minute);
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, scheduleMsg);
		txtSchedulePath->Clear();
		progressBar2->Value = 0;
		monitoringListBox->Items->Clear();
	}

	private: System::Void btnStartService_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SC_HANDLE schSCManager = OpenSCManager(
			NULL,                    // local computer
			NULL,                    // ServicesActive database 
			SC_MANAGER_CONNECT);

		if (NULL == schSCManager)
		{
			HRESULT error = GetLastError();
			printf("OpenSCManager failed (%d)\n", error);
			return;
		}

		SC_HANDLE schService = OpenService(
			schSCManager,         // SCM database 
			L"PajiloyService2",            // name of service 
			SERVICE_START |
			SERVICE_QUERY_STATUS |
			SERVICE_ENUMERATE_DEPENDENTS);

		if (schService == NULL)
		{
			printf("OpenService failed (%d)\n", GetLastError());
			CloseServiceHandle(schSCManager);
			return;
		}

		StartService(schService, NULL, NULL);

		MessageBox::Show("Сервис запущен", "Информация", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void btnStopService_Click(System::Object^ sender, System::EventArgs^ e)
	{
		message doStopMsg;
		doStopMsg.cmd = COMMAND::STOP_SERVICE;
		Messenger::sendMessage(pipeForSend, PIPE_BUFSIZE, doStopMsg);
	}

	private: System::Void ClientForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
	{
		FlushFileBuffers(pipeForSend);
		DisconnectNamedPipe(pipeForSend);
		//CloseHandle(pipeForSend);
	}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	panelFastCheck->Visible = true;
	panelMenu->Visible = false;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	panelPlanCheck->Visible = true;
	panelMenu->Visible = false;
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	panelFolderMonitoring->Visible = true;
	panelMenu->Visible = false;
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	panelDetectedThreats->Visible = true;
	panelMenu->Visible = false;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	panelDetectedThreats->Visible = false;
	panelFastCheck->Visible = false;
	panelFolderMonitoring->Visible = false;
	panelPlanCheck->Visible = false;
	panelMenu->Visible = true;

}
};
}
