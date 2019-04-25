#pragma once
#include <fstream>
#include "kelime.h"
#include <vector>
ref class WordPrediction
{
public:
	array<System::String^>^ dictionary;
	array<System::String^>^ remaining;
	int remainingCount;
	int tried;
	int guessIndex;

	WordPrediction();
	void LoadDictionary(System::String^ filename);
	void PrintDictionary(System::Windows::Forms::RichTextBox^ richTextBox, bool reduced);
	void PrintRemaining(System::Windows::Forms::RichTextBox^ richTextBox, bool reduced);
	System::String^ MakeGuess(int pointNormal, int pointCartesian);
	void ExtendDictionary(System::String^ word);
	void Restart();
	void SaveDictionary(System::String^ filename);
};

