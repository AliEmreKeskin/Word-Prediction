#pragma once
#include <cstdio>
#include <fstream>
#include <string>
int loadDictionary(const char * filename, char **dictionary, int %dictSize);
int MakeGuess(array<System::String^>^ dictionary, int size, int guess, int point);
int CalculatePoint(System::String^ str1, System::String^ str2);
System::String^ CompressString(System::String^ str);
int CompareCartesian(System::String^ str1, System::String^ str2);
int CompareNormal(System::String^ hidden, System::String^ guess);
int MakeGuessNormal(array<System::String^>^ dictionary, int size, int guess, int point);
int MakeGuessCartesian(array<System::String^>^ dictionary, int size, int guess, int point);
int MakeGuessNormalCartesian(array<System::String^>^ dictionary, int size, int guess, int pointC, int pointN);