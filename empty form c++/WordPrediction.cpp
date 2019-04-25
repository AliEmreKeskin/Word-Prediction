#include "WordPrediction.h"



WordPrediction::WordPrediction()
{
	this->tried = 0;
	//this->dict = new std::vector<System::String^>;
}

void WordPrediction::LoadDictionary(System::String ^ filename)
{
	const char* filename1 = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(filename);
	std::ifstream stream1(filename1, std::ios::in);
	char str[80];
	int count = 0;
	while (!stream1.eof()) {
		stream1 >> str;
		count++;
	}
	stream1.close();
	this->remainingCount = count;

	System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(filename);
	System::String^ line = gcnew System::String("");
	this->dictionary = gcnew array<System::String^>(count);
	this->remaining = gcnew array<System::String^>(count);
	for (int i = 0; i < count; i++) {
		line = sr->ReadLine();
		this->dictionary[i] = line;
		this->remaining[i] = line;
	}
	sr->Close();
}

void WordPrediction::PrintDictionary(System::Windows::Forms::RichTextBox ^ richTextBox, bool reduced)
{
	if (reduced && this->remainingCount > 1000) {
		richTextBox->AppendText("More than 1000 words\n");
	}
	else {
		for (int i = 0; i < this->dictionary->Length; i++) {
			richTextBox->AppendText(dictionary[i] + "\n");
		}
	}
}

void WordPrediction::PrintRemaining(System::Windows::Forms::RichTextBox ^ richTextBox, bool reduced)
{
	if (reduced && this->remainingCount > 1000) {
		richTextBox->AppendText("More than 1000 words\n");
	}
	else {
		for (int i = 0; i < this->remaining->Length; i++) {
			if (this->remaining[i] != "zzz") {
				richTextBox->AppendText(this->remaining[i] + "\n");
			}
		}
	}	
}

System::String^ WordPrediction::MakeGuess(int pointNormal, int pointCartesian)
{
	if (tried == 0) {
		tried++;
		System::Random^ rand = gcnew System::Random();
		this->guessIndex = rand->Next(remaining->Length);
		this->remaining[guessIndex] = "zzz";
		this->remainingCount--;
		return this->dictionary[this->guessIndex];
	}
	else {
		tried++;
		System::String^ guessWord = this->dictionary[this->guessIndex];
		System::String^ currWord;
		int currPointC;
		int currPointN;
		for (int i = 0; i < this->remaining->Length; i++) {
			currWord = this->remaining[i];
			if (currWord != "zzz") {
				currPointC = CompareCartesian(currWord, guessWord);
				currPointN = CompareNormal(currWord, guessWord);
				if (currPointC != pointCartesian || currPointN != pointNormal) {
					this->remaining[i] = "zzz";
					this->remainingCount--;
				}
			}
		}
		if (this->remainingCount < 1) {
			this->guessIndex = -1;
			return "Word not found";
		}
		else {
			System::Random^ rand = gcnew System::Random;
			do
			{
				this->guessIndex = rand->Next(remaining->Length);
			} while (this->remaining[this->guessIndex] == "zzz");
			this->remaining[guessIndex] = "zzz";
			this->remainingCount--;
			return this->dictionary[this->guessIndex];
		}		
	}
}

void WordPrediction::ExtendDictionary(System::String ^ word)
{
	System::Array::Resize(this->dictionary, this->dictionary->Length + 1);
	this->dictionary[this->dictionary->Length - 1] = word;
	System::Array::Resize(this->remaining, this->remaining->Length + 1);
	this->remaining[this->remaining->Length - 1] = word;
}

void WordPrediction::Restart()
{
	this->tried = 0;
	this->remainingCount = this->dictionary->Length;
	this->dictionary->CopyTo(this->remaining, 0);
}

void WordPrediction::SaveDictionary(System::String ^ filename)
{
	System::IO::StreamWriter^ sr = gcnew System::IO::StreamWriter(filename);
	for (int i = 0; i < this->dictionary->Length; i++) {
		sr->WriteLine(this->dictionary[i]);
	}
	sr->Close();
}
