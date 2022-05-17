#include "string_idf.h"
indString::indString()
{
	std::cout << "\nКонструктор без параметров\n";
	string::size = 0;
	string::str = new char[1];
	string::str[0] = '\0';
}
indString::indString(const char temp)
{
	std::cout << "\nКонструктор с 1 параметром (char)\n";
	if (check(temp))
	{
		string::size = 1;
		string::str = new char[2];
		string::str[0] = temp;
		string::str[1] = '\0';
	}
	else
	{
		string::size = 1;
		string::str = new char[2];
		string::str[0] = '0';
		string::str[1] = '\0';
	}
}
indString::indString(const char* temp)
{
	std::cout << "\nКонструктор с параметром (char*)\n";
	if (!check(temp))
	{
		string::size = 1;
		string::str = new char[2];
		string::str[0] = '0';
		string::str[1] = '\0';
		return;
		
	}
	string::size = strlen(temp);
	string::str = new char[string::size + 1];
	strcpy(string::str, temp);
	string::str[string::size] = '\0';
}
indString::indString(const indString& temp)
{
	++copyClassIdn;
	if (this == &temp)
		return;
	string::size = temp.size;
	string::str = new char[string::size + 1];
	strcpy(string::str, temp.str);
	string::str[string::size] = '\0';
	std::cout << "Конструктор копирования" << "\n";
}
indString& indString::operator=(const indString& temp)
{
	copyClassIdn++;
	if (this == &temp)
		return *this;
	delete[] string::str;
	string::size = temp.size;
	string::str = new char[string::size + 1];
	strcpy(string::str, temp.str);
	string::str[string::size] = '\0';
	std::cout << "\nОператор=\n";
	return *this;
}
indString& indString::operator=(const char temp)
{
	copyClassIdn++;
	string::size = 1;
	delete[] string::str;
	string::str = nullptr;
	string::str = new char[2];
	if (!check(temp))
	{
		string::str[0] = '0';
		string::str[1] = '\0';
		return *this;
	}
	
		string::str[0] = temp;
	string::str[1] = '\0';
	return *this;
}
indString& indString::operator=(const char* temp)
{
	copyClassIdn++;
	delete[] string::str;
	str = nullptr;
	if (!check(temp))
	{
		string::size = 1;
		string::str = new char[2];
		string::str[0] = '0';
		string::str[1] = '\0';
		return *this;
	}
	string::size = strlen(temp);
	string::str = new char[string::size + 1];
	strcpy(string::str, temp);
	string::str[string::size] = '\0';
	return *this;
}
void indString::print(std::ostream& out)
{
	std::cout << "operator<<(idf lcass)";
	out << this->str;
}
void indString::write(std::istream& in)
{
	std::cout << "operator>>(idf class)\n";
	char* tempChar = new char[128];
	in.ignore();
	in >> tempChar;
	if (!this->check(tempChar))
	{
		delete[] tempChar;
		tempChar = new char[2];
		tempChar[0] = '0';
		tempChar[1] = '\0';
	}
	delete[] this->str;
	this->size = strlen(tempChar);
	this->str = new char[this->size + 1];
	strcpy(this->str, tempChar);
	this->str[this->size] = '\0';
	delete[] tempChar;
}

char indString::lastChar()
{
	if (string::size == 0)
		return '0';
	return string::str[string::size - 1];
}
char indString::operator[](const int temp)
{
	std::cout << "\nОператор[]\n";
	if (temp >= 0 && temp < string::size)
		return string::str[temp];
	return '0';
}
bool indString::check(const char st)
{
	int i = 0;
	if (!((st >= 'А' && st <= 'Я') || (st >= 'а' && st <= 'я') || (st >= '0'
		&& st <= '9') || (st >= 'a' && st <= 'z') || (st >= 'A' && st <= 'Z') || st
		== '_'))
		return 0;
	return 1;
}
bool indString::check(const char* st)
{
	int i = 0, _SIZE = strlen(st);
	for (i; i < _SIZE; ++i)
		if (!((st[i] >= 'А' && st[i] <= 'Я') || (st[i] >= 'а' && st[i] <=
			'я') || (st[i] >= '0' && st[i] <= '9') || (st[i] >= 'a' && st[i] <= 'z') ||
			(st[i] >= 'A' && st[i] <= 'Z') || st[i] == '_'))
			return 0;
	return 1;
}
bool indString::operator>(const indString& temp)
{
	std::cout << "\nОператор>\n";
	int i = 1;
	if (string::size == 0)
		return 0;
	if (temp.str[0] != temp.str[1])
		return 0;
	for (i; temp.str[i] != '\0' && string::str[i] != '\0'; ++i)
	{
		if (string::str[i] > temp.str[i])
			return 1;
	}
	
		return 0;
}
bool indString::operator<(const indString& temp)
{
	std::cout << "\nОператор<\n";
	int i = 1;
	if (string::size == 0)
		return 0;
	if (temp.str[0] != string::str[0])
		return 0;
	for (i; temp.str[i] != '\0' && string::str[i] != '\0'; ++i)
	{
		if (string::str[i] < temp.str[i])
			return 1;
	}
	return 0;
}
bool indString::operator==(const indString& temp)
{
	std::cout << "\nОператор==\n";
	int i = 0;
	if (string::size == 0)
		return 0;
	for (i; temp.str[i] != '\0' && string::str[i] != '\0'; ++i)
	{
		if (string::str[i] != temp.str[i])
			return 0;
	}
	return 1;
}
int indString::getCopy()
{
	return copyClassIdn;
}
indString::~indString()
{
	std::cout << "\nРабота деструктора\n";
	if (string::size != 0)
		delete[] string::str;
	string::str = nullptr;
}