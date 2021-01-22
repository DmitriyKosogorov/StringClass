#pragma once
#ifndef STRING_CLASS
#define STRING_CLASS
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class StringClassException {};


class StringClass
{
private:
	wchar_t* stroka;
	int len;
	wstring findpodstr_special(const wstring str);
public:
	StringClass();
	StringClass(const wstring str);
	StringClass(wifstream& file);
	~StringClass();
	wstring getstr(int index);
	wchar_t& operator[](int index);
	void operator=(wstring str);
	StringClass& operator+=(wstring str);
	StringClass& operator+=(wchar_t symb);
	wstring findpodstr(const wstring str);
	void paste(wstring str, int index);
	friend wostream& operator<<(wostream& wout, const StringClass& str);
	vector<wstring> split(wstring str);
	int countPredl();
	void getStatLetters();
	void getStatLetters(wchar_t c);
	void getStatWords();
	void getStatWords(wstring str);
	void getStatSentences();
	void getStatSentences(wstring str);
};

#endif

