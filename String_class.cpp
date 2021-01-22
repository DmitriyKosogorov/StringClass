#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "String_class.h"

using namespace std;

StringClass::StringClass()
{
	len = 0;
	stroka = new wchar_t[0];
}
StringClass::StringClass(const wstring str)
{
	len = str.length();
	stroka = new wchar_t[len];
	for (int i = 0; i < len; i++)
		stroka[i] = str[i];
}
StringClass::StringClass(wifstream& file)
{
	len = 0;
	stroka = new wchar_t[0];
	wchar_t c;
	wstring s;
	while(!file.eof())
	{
		getline(file, s);
		for(int i=0;i<s.length();i++)
			*this += s[i];
	}
}
StringClass::~StringClass()
{
	/*cout << "deleted ";
	for (int i = 0; i < len; i++)
		cout << stroka[i];
	cout <<" "<<this<< endl;*/
	delete[] stroka;
}
wstring StringClass::getstr(int index)
{
	wstring res;
	if(index<0 || index>=len)
		throw StringClassException();
	else
	for (int i = index; i < len; i++)
		res = res + stroka[i];
	return res;
}
wchar_t& StringClass::operator[](int index)
{
	if (index < 0 || index >= len)
		throw StringClassException();
	else
		return stroka[index];
}
wostream& operator<<(wostream& wout, const StringClass& str)
{
	for (int i = 0; i < str.len; i++)
		wout << str.stroka[i];
	return wout;
}
void StringClass::operator=(wstring str)
{
	len = str.length();
	wchar_t* newstroka = new wchar_t[len];
	for (int i = 0; i < len; i++)
		newstroka[i] = str[i];
	delete[] stroka;
	stroka = newstroka;
}

StringClass& StringClass::operator+=(wstring str)
{
	int i,n=len,m=str.length();
	wchar_t* newstroka = new wchar_t[len+m];
	for (i = 0; i < len; i++)
	{
		newstroka[i] = stroka[i];
		//cout << newstroka[i];
	}
	len = len + m;
	for (i = 0; i < m; i++)
	{
		newstroka[n + i] = str[i];
		//cout << newstroka[n+i];
	}
	//wcout << endl;
	delete[] stroka;
	stroka = newstroka;
	return *this;
}

StringClass& StringClass::operator+=(wchar_t symb)
{
	int i, n = len;
	wchar_t* newstroka = new wchar_t[len + 1];
	for (i = 0; i < len; i++)
	{
		newstroka[i] = stroka[i];
	}
	newstroka[len] = symb;
	len = len + 1;

	//wcout << endl;
	delete[] stroka;
	stroka = newstroka;
	return *this;
}

wstring StringClass::findpodstr_special(const wstring str)
{
	int k = 0, i, j;
	wstring rightstr,notrightstr;
	for (i = 0; i < len; i++)
	{
		k = 0;
		for (j = i; j < len; j++)
		{

			if (stroka[j] == str[k] || str[k] == '?')
			{
				rightstr += stroka[j];
				k++;
			}
			else
				if (str[k] == '#')
				{
					switch (stroka[j])
					{
					case '0': k++; rightstr += stroka[j]; break;
					case '1': k++; rightstr += stroka[j]; break;
					case '2': k++; rightstr += stroka[j]; break;
					case '3': k++; rightstr += stroka[j]; break;
					case '4': k++; rightstr += stroka[j]; break;
					case '5': k++; rightstr += stroka[j]; break;
					case '6': k++; rightstr += stroka[j]; break;
					case '7': k++; rightstr += stroka[j]; break;
					case '8': k++; rightstr += stroka[j]; break;
					case '9': k++; rightstr += stroka[j]; break;
					default: break;
					}
				}
				else
					if (str[k] == '*')
					{
						wstring gig = str.substr(k + 1, str.length());
						wstring find = this->getstr(j);
						StringClass gig1(find);
						wstring next = gig1.findpodstr_special(gig);
						if (next != L"" || gig == L"")
						{
							rightstr += next;
							notrightstr += rightstr;
							return notrightstr;
						}
					}
					else
						break;
			if (k == str.length())
			{
				notrightstr += rightstr;
				return notrightstr;
			}


		}

		notrightstr += stroka[i];
	}
	return L"";
}

void StringClass::paste(wstring str, int index)
{
	if (index < 0 || index >= len)
		throw StringClassException();
	else
	{
		int n = len, m = str.length(), i, j;
		len = n + m;
		wchar_t* newstroka = new wchar_t[n + m];
		for (i = 0; i < index; i++)
			newstroka[i] = stroka[i];
		for (i = 0; i < m; i++)
			newstroka[index + i] = str[i];
		for (i = 0; i < n - index; i++)
			newstroka[index + m + i] = stroka[i + index];
		delete[] stroka;
		stroka = newstroka;
	}
}

wstring StringClass::findpodstr(const wstring str)
{
	int k = 0,i,j,rightlen=0;
	wstring rightstr;
	for (i = 0; i < len; i++)
	{
		k = 0;
		for (j = i; j < len; j++)
		{
			
			if (stroka[j] == str[k] || str[k] == '?')
			{
				rightstr += stroka[j];
				k++;
			}
			else
				if (str[k] == '#')
				{
					switch (stroka[j])
					{
					case '0': k++; rightstr += stroka[j]; break;
					case '1': k++; rightstr += stroka[j]; break;
					case '2': k++; rightstr += stroka[j]; break;
					case '3': k++; rightstr += stroka[j]; break;
					case '4': k++; rightstr += stroka[j]; break;
					case '5': k++; rightstr += stroka[j]; break;
					case '6': k++; rightstr += stroka[j]; break;
					case '7': k++; rightstr += stroka[j]; break;
					case '8': k++; rightstr += stroka[j]; break;
					case '9': k++; rightstr += stroka[j]; break;
					default: break;
					}
				}
				else
					if (str[k] == '*')
					{
						wstring gig = str.substr(k + 1, str.length());
						wstring find = this->getstr(j);
						StringClass gig1(find);
						wstring next = gig1.findpodstr_special(gig);
						if (next != L"" || gig == L"")
						{
							rightstr += next;
							return rightstr;
						}
					}
					else break;
			if (k == str.length())
			{
				return rightstr;
			}


		}
	}
	return L"";
}




vector<wstring> StringClass::split(wstring str)
{
	vector<wstring> words;
	wstring word;
	int i,j,k;
	bool b;
	for (i = 0; i < len; i++)
	{
		if (stroka[i] == str[0] && i+str.length()<len)
		{
			k = 0;
			b = true;
			for (j = i; j < i+str.length(); j++)
			{
				if (stroka[j] != str[k])
				{
					b = false;
					break;
				}
				k++;
			}
			if (b == true)
			{
				words.push_back(word);
				word = L"";
				i = i + str.length();
			}
		}
		word += stroka[i];
	}
	words.push_back(word);
	return words;
}

void StringClass::getStatLetters()
{
	bool b;
	vector<wchar_t> letters;
	vector<int> stats;
	for (int i = 0; i < len; i++)
	{
		b = false;
		for (int j = 0; j < letters.size(); j++)
		{
			if (stroka[i] == letters[j])
			{
				stats[j]++;
				b = true;
			}
		}
		if (b == false)
		{
			letters.push_back(stroka[i]);
			stats.push_back(1);
		}
	}
	for (int i = 0; i < letters.size(); i++)
		wcout << letters[i] << L" " << stats[i] << endl;
}

void StringClass::getStatLetters(wchar_t c)
{
	bool b;
	int stats=0, i;
	for (i = 0; i < len; i++)
		if (stroka[i] == c)
			stats++;
	wcout << c << L" " << stats<<endl;
}

void StringClass::getStatWords()
{
	int i;
	bool b;
	vector<wstring> words = this->split(L" ");
	vector<wstring> answer;
	vector<int> stats;
	for (i = 0; i < words.size(); i++)
	{
		b = false;
		for (int j = 0; j < answer.size(); j++)
		{
			if (words[i] == answer[j])
			{
				stats[j]++;
				b = true;
			}
		}
		if (b == false)
		{
			answer.push_back(words[i]);
			stats.push_back(1);
		}
	}
	for (i = 0; i < answer.size(); i++)
		wcout << answer[i] << L" " << stats[i] << endl;
}

void StringClass::getStatWords(wstring str)
{
	int i;
	vector<wstring> words = this->split(L" ");
	int stats = 0;
	for (i = 0; i < words.size(); i++)
	{
		if (words[i] == str)
			stats++;
	}
	wcout << str << L" " << stats<<endl;

}

void StringClass::getStatSentences()
{
	int i;
	bool b;
	vector<wstring> words = this->split(L". ");
	vector<wstring> answer;
	vector<int> stats;
	for (i = 0; i < words.size(); i++)
	{
		b = false;
		for (int j = 0; j < answer.size(); j++)
		{
			if (words[i] == answer[j])
			{
				stats[j]++;
				b = true;
			}
		}
		if (b == false)
		{
			answer.push_back(words[i]);
			stats.push_back(1);
		}
	}
	for (i = 0; i < answer.size(); i++)
		wcout << answer[i] << L" " << stats[i] << endl;
}

void StringClass::getStatSentences(wstring str)
{
	int i;
	vector<wstring> words = this->split(L". ");
	int stats = 0;
	for (i = 0; i < words.size(); i++)
	{
		if (words[i] == str)
			stats++;
	}
	wcout << str << L" " << stats << endl;

}

int StringClass::countPredl()
{
	int stats = 0;
	vector<wstring> predlogs = { L"без", L"безо",L"близ",L"в", L"во", L"вместо",L"вне",L"для", L"до", L"за", L"из", L"изо",
		L"из-за", L"из-под", L"к", L"ко", L"кроме", L"между", L"меж", L"на", L"над", L"о", L"об", L"обо", L"от", L"ото", L"перед",
		L"передо", L"пред", L"по", L"под", L"подо", L"при",L"про",L"ради",L"с",L"со", L"сквозь" , L"среди" , L"у" , L"через" , L"чрез"};
	vector<wstring> words = this->split(L" ");
	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < predlogs.size(); j++)
		{
			if (words[i] == predlogs[j] || words[i] == predlogs[j]+L", " || words[i] == predlogs[j] + L". ")
			{
				//wcout << words[i] << endl;
				stats++;
				break;
			}
		}
	}
	return stats;
}