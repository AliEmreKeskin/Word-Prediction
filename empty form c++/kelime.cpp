#include "kelime.h"

//int loadDictionary(const char * filename, std::string *dictionary, int %dictSize)
//{
//	FILE* dictionarFile;
//	if (dictionarFile = fopen(filename, "r")) {
//		int count = 0;
//		std::string tempStr;
//
//		//start reading
//		while (!feof(dictionarFile)) {
//			count++;
//			std::string* tempArr = new std::string[count];
//
//			//first reading
//			if (count == 1) {
//				fscanf(dictionarFile, "%s", tempStr);
//				tempArr[count - 1] = tempStr;
//				dictionary = tempArr;
//			}
//
//			//additional readings
//			else {
//				for (int i = 0; i < count-1; i++) {
//					tempArr[i] = dictionary[i];
//				}
//				delete[]dictionary;
//				fscanf(dictionarFile, "%s", tempStr);
//				tempArr[count - 1] = tempStr;
//				dictionary = tempArr;
//			}
//		}
//		dictSize = count;
//	}
//	fclose(dictionarFile);
//	return 0;
//}

//int loadDictionary(const char * filename, char ** dictionary, int % dictSize)
//{
//	FILE* dictionaryFile = fopen(filename, "r");
//	dictSize = 0;
//	char* str;
//	while (!feof(dictionaryFile)) {
//		fscanf(dictionaryFile, "%s", str);
//		dictSize++;
//	}
//	dictionary = new char*[dictSize];
//	rewind(dictionaryFile);
//	for (int i = 0; i < dictSize; i++) {
//		fscanf(dictionaryFile, "%s", dictionary[i]);
//	}
//
//	return 1;
//}

int loadDictionary(const char * filename, char **dictionary, int % dictSize)
{
	dictSize = 0;
	std::ifstream stream1(filename,std::ios::in);
	char str[80];
	while (!stream1.eof()) {
		stream1 >> str;
		dictSize++;
	}
	stream1.close();

	dictionary = new char*[dictSize];
	stream1.open(filename, std::ios::in);
	for (int i = 0; i < dictSize; i++) {
		std::string text;
		std::getline(stream1, text);
		dictionary[i] = new char[text.length() + 1];
		strcpy(dictionary[i], text.c_str());
	}
	stream1.close();

	return 0;
}

int MakeGuess(array<System::String^>^ dictionary, int size, int guess, int point)
{
	System::String^ guessWord = dictionary[guess];
	int guessSize = guessWord->Length;
	System::String^ currWord;
	int currSize;
	int currPoint;
	for (int i = 0; i < size; i++) {
		currPoint = 0;
		currWord = dictionary[i];
		currSize = currWord->Length;
		for (int j = 0; j < currSize; j++) {
			for (int k = 0; k < guessSize; k++) {
				if (currWord[j] == guessWord[k]) {
					currPoint += (j+1)*(k+1);
				}
			}
		}
		if (currPoint != point) {
			dictionary[i] = "zzz";
		}
	}
	System::Random^ rand = gcnew System::Random;
	int newGuess;
	do
	{
	newGuess = rand->Next(size);
	} while (dictionary[newGuess]=="zzz");

	return newGuess;
}

int CalculatePoint(System::String ^ str1, System::String ^ str2)
{
	int point = 0;
	for (int i = 0; i < str1->Length; i++) {
		for (int j = 0; j < str2->Length; j++)
		{
			if (str1[i] == str2[j]) {
				point += (i + 1)*(j + 1);
			}
		}
	}
	return point;
}

System::String^ CompressString(System::String ^ str)
{
	System::String^ temp = "";
	for (int i = 0; i < str->Length; i++) {
		if (!temp->Contains(str[i].ToString())) {
			temp = temp + str[i];
		}
	}
	return temp;
}

int CompareCartesian(System::String ^ str1, System::String ^ str2)
{
	int point = 0;
	for (int i = 0; i < str1->Length; i++) {
		for (int j = 0; j < str2->Length; j++)
		{
			if (str1[i] == str2[j]) {
				point++;
			}
		}
	}
	return point;
}

int CompareNormal(System::String ^ str1, System::String ^ str2)
{
	int point = 0;
	for (int i = 0; i < str1->Length; i++) {
		for (int j = 0; j < str2->Length; j++)
		{
			if (str1[i] == str2[j]) {
				point++;
				break;
			}
		}
	}
	return point;
}

int MakeGuessNormal(array<System::String^>^ dictionary, int size, int guess, int point)
{
	System::String^ guessWord = dictionary[guess];
	System::String^ currWord;
	int currPoint;
	for (int i = 0; i < size; i++) {
		currWord = dictionary[i];
		currPoint = CompareNormal(currWord, guessWord);
		if (currPoint != point) {
			dictionary[i] = "zzz";
		}
	}
	System::Random^ rand = gcnew System::Random;
	int newGuess;
	do
	{
		newGuess = rand->Next(size);
	} while (dictionary[newGuess] == "zzz");

	return newGuess;
}

int MakeGuessCartesian(array<System::String^>^ dictionary, int size, int guess, int point)
{
	System::String^ guessWord = dictionary[guess];
	System::String^ currWord;
	int currPoint;
	for (int i = 0; i < size; i++) {
		currWord = dictionary[i];
		currPoint = CompareCartesian(currWord, guessWord);
		if (currPoint != point) {
			dictionary[i] = "zzz";
		}
	}
	System::Random^ rand = gcnew System::Random;
	int newGuess;
	do
	{
		newGuess = rand->Next(size);
	} while (dictionary[newGuess] == "zzz");

	return newGuess;
}

int MakeGuessNormalCartesian(array<System::String^>^ dictionary, int size, int guess, int pointC, int pointN)
{
	System::String^ guessWord = dictionary[guess];
	System::String^ currWord;
	int currPointC;
	int currPointN;
	for (int i = 0; i < size; i++) {
		currWord = dictionary[i];
		currPointC = CompareCartesian(currWord, guessWord);
		currPointN = CompareNormal(currWord, guessWord);
		if (currPointC != pointC || currPointN != pointN) {
			dictionary[i] = "zzz";
		}
	}
	System::Random^ rand = gcnew System::Random;
	int newGuess;
	do
	{
		newGuess = rand->Next(size);
	} while (dictionary[newGuess] == "zzz");

	return newGuess;
}
