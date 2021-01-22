#include<iostream>
#include<string>
#include<fstream>
#include <io.h>
#include <fcntl.h>
#include <TCHAR.H>
#include<codecvt>
#include<locale>
#include "atlstr.h"
#include"String_Class.cpp"
using namespace std;
int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	//const locale utf8_locale = locale(locale(), new codecvt_utf8());
	int i;
	wifstream file(L"test.txt");
	file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));
	StringClass s(L"kdjfhsfgoshf"), a(L"На дворе трава на траве дрова не руби дрова на траве двора");
	StringClass textString(file);
	//wcout << textString << endl;
	wcout << s << endl;
	s = L"gdf9d";
	s += L"sDDbkl";
	wcout << s << endl;
	wcout << L"podstroka " << s.findpodstr(L"#d*b") << endl;
	wcout << L"getstatsletter " << endl;
	s.getStatLetters('d');
	vector<wstring> words = a.split(L" t");
	wcout << L"split:" << endl;
	for (i = 0; i < words.size(); i++)
		wcout << i << L"): " << words[i] << endl;
	a.getStatWords(L"траве");
	a.paste(L"Колодец", 6);
	wcout << a << endl <<"count predlogs"<<endl<< a.countPredl() << endl;
	wcout << endl << endl<<L"файловая строка----------------------------------------"<< endl << textString.countPredl() << endl<<textString.findpodstr(L"с*к")<<endl<<L"статистика по словам---------------------------"<<endl;
	textString.getStatWords();

}