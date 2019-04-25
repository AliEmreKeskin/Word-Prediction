#pragma once
#include "kelime.h"
#include <chrono>
#include "WordPrediction.h"

namespace emptyformc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected:
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadDictionaryToolStripMenuItem;
	private: System::Windows::Forms::Label^  remainingTexBox;



	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::TextBox^  tahmin;
	private: System::Windows::Forms::TextBox^  puan;


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::TextBox^  TB_pointN;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ToolStripMenuItem^  addWordToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveDictionaryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  restartToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  reducedPrintingToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;


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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadDictionaryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addWordToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveDictionaryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restartToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reducedPrintingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->remainingTexBox = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->tahmin = (gcnew System::Windows::Forms::TextBox());
			this->puan = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->TB_pointN = (gcnew System::Windows::Forms::TextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(11, 40);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(100, 151);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuToolStripMenuItem,
					this->settingsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(468, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->loadDictionaryToolStripMenuItem,
					this->addWordToolStripMenuItem, this->saveDictionaryToolStripMenuItem, this->restartToolStripMenuItem
			});
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->menuToolStripMenuItem->Text = L"Menu";
			// 
			// loadDictionaryToolStripMenuItem
			// 
			this->loadDictionaryToolStripMenuItem->Name = L"loadDictionaryToolStripMenuItem";
			this->loadDictionaryToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->loadDictionaryToolStripMenuItem->Text = L"Load Dictionary";
			this->loadDictionaryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadDictionaryToolStripMenuItem_Click);
			// 
			// addWordToolStripMenuItem
			// 
			this->addWordToolStripMenuItem->Name = L"addWordToolStripMenuItem";
			this->addWordToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->addWordToolStripMenuItem->Text = L"Add Word";
			this->addWordToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::addWordToolStripMenuItem_Click);
			// 
			// saveDictionaryToolStripMenuItem
			// 
			this->saveDictionaryToolStripMenuItem->Name = L"saveDictionaryToolStripMenuItem";
			this->saveDictionaryToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->saveDictionaryToolStripMenuItem->Text = L"Save Dictionary";
			this->saveDictionaryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveDictionaryToolStripMenuItem_Click);
			// 
			// restartToolStripMenuItem
			// 
			this->restartToolStripMenuItem->Name = L"restartToolStripMenuItem";
			this->restartToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->restartToolStripMenuItem->Text = L"Restart";
			this->restartToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::restartToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->reducedPrintingToolStripMenuItem });
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// reducedPrintingToolStripMenuItem
			// 
			this->reducedPrintingToolStripMenuItem->Checked = true;
			this->reducedPrintingToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->reducedPrintingToolStripMenuItem->Name = L"reducedPrintingToolStripMenuItem";
			this->reducedPrintingToolStripMenuItem->Size = System::Drawing::Size(165, 22);
			this->reducedPrintingToolStripMenuItem->Text = L"Reduced Printing";
			this->reducedPrintingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::reducedPrintingToolStripMenuItem_Click);
			// 
			// remainingTexBox
			// 
			this->remainingTexBox->AutoSize = true;
			this->remainingTexBox->Location = System::Drawing::Point(12, 194);
			this->remainingTexBox->Name = L"remainingTexBox";
			this->remainingTexBox->Size = System::Drawing::Size(60, 13);
			this->remainingTexBox->TabIndex = 2;
			this->remainingTexBox->Text = L"Remaining:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(118, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Normal";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(227, 40);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(228, 151);
			this->richTextBox2->TabIndex = 5;
			this->richTextBox2->Text = L"";
			// 
			// tahmin
			// 
			this->tahmin->Location = System::Drawing::Point(121, 69);
			this->tahmin->Name = L"tahmin";
			this->tahmin->Size = System::Drawing::Size(100, 20);
			this->tahmin->TabIndex = 6;
			// 
			// puan
			// 
			this->puan->Location = System::Drawing::Point(177, 116);
			this->puan->Name = L"puan";
			this->puan->Size = System::Drawing::Size(44, 20);
			this->puan->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(120, 142);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Calculate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(226, 194);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Tried: 0 times";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(120, 40);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Guess";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(120, 171);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 11;
			this->textBox1->Text = L"Your Pick Here";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(226, 211);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Total Time: 0 s";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(174, 100);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Cartesian";
			// 
			// TB_pointN
			// 
			this->TB_pointN->Location = System::Drawing::Point(121, 116);
			this->TB_pointN->Name = L"TB_pointN";
			this->TB_pointN->Size = System::Drawing::Size(44, 20);
			this->TB_pointN->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 24);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Dictionary";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(226, 24);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Outputs";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 231);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->TB_pointN);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->puan);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tahmin);
			this->Controls->Add(this->remainingTexBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Word Prediction";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		array<System::String^>^dictionary;
		System::String^ guessWord;
		int count;
		int remaining;
		int tried;
		int guess;
		int point;
		int pointC;
		int pointN;
		double totalTime;
		WordPrediction game1;

	private: System::Void loadDictionaryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			game1.LoadDictionary(openFileDialog1->FileName);
			richTextBox2->AppendText("Dictionary loaded\n");
			game1.PrintDictionary(richTextBox1,reducedPrintingToolStripMenuItem->Checked);
			remainingTexBox->Text = "Remaining: " + game1.remainingCount.ToString();
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (game1.tried == 0) {
			pointC = 0;
			pointN = 0;
		}
		else {
			pointC = System::Convert::ToInt32(puan->Text);
			pointN = System::Convert::ToInt32(TB_pointN->Text);
		}
		auto start = std::chrono::high_resolution_clock::now();
		guessWord = game1.MakeGuess(pointN, pointC);
		auto finish = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> elapsed = finish - start;

		if (guessWord == "Word not found") {
			MessageBox::Show(guessWord);
		}
		tahmin->Text = guessWord;
		label4->Text = "Tried: " + game1.tried.ToString() + " times";
		richTextBox2->AppendText(game1.tried.ToString() + ".iteration\n" +"Guess: "+guessWord+ "\nElapsed in: " + elapsed.count().ToString() + "\n");
		totalTime += elapsed.count();
		label1->Text = "Total Time: " + totalTime.ToString() + " s";
		remainingTexBox->Text = "Remaining: " + game1.remainingCount.ToString();
		richTextBox1->Clear();
		game1.PrintRemaining(richTextBox1, reducedPrintingToolStripMenuItem->Checked);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int tempPoint = CompareCartesian(textBox1->Text, tahmin->Text);
		puan->Text = tempPoint.ToString();
		int tempPointN = CompareNormal(textBox1->Text, tahmin->Text);
		TB_pointN->Text = tempPointN.ToString();
	}

private: System::Void addWordToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	game1.ExtendDictionary(textBox1->Text);
	richTextBox2->AppendText("The word \"" + textBox1->Text + "\" added to dictionary\n");
	richTextBox1->Clear();
	game1.PrintDictionary(richTextBox1, reducedPrintingToolStripMenuItem->Checked);
}
private: System::Void restartToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	game1.Restart();
	totalTime = 0;
	richTextBox2->Clear();
	richTextBox2->AppendText("Restarted\n");
	richTextBox1->Clear();
	TB_pointN->Clear();
	tahmin->Clear();
	textBox1->Text = "Your Pick Here";
	puan->Clear();
	label4->Text = "Tried: 0 times";
	label1->Text = "Total Time: 0 s";
	remainingTexBox->Text = "Remaining: " + game1.remainingCount.ToString();
	game1.PrintRemaining(richTextBox1, reducedPrintingToolStripMenuItem->Checked);
}
private: System::Void reducedPrintingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (reducedPrintingToolStripMenuItem->Checked == true) {
		reducedPrintingToolStripMenuItem->Checked = false;
	}
	else
	{
		reducedPrintingToolStripMenuItem->Checked = true;
	}
}
private: System::Void saveDictionaryToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	saveFileDialog1->Filter = "New Dictionary|*.txt";
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		game1.SaveDictionary(saveFileDialog1->FileName);
	}
}

};
}
