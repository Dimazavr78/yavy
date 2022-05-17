#include "string_dec.h"
decString::decString()
{
	std::cout << "\nКонструктор без параметров\n";
	string::size = 0;
	string::str = new char[1];
	string::str[0] = '\0';
}
decString::decString(const char temp)
{
	std::cout << "\nКонструктор с 1 параметром (char)\n";
	if (check(temp))
	{
		if (temp == '+' || temp == '-')
		{
			string::size = 1;
			string::str = new char[2];
			string::str[0] = temp;
			string::str[1] = '\0';
		}
		else
		{
			string::size = 2;
			string::str = new char[3];
			string::str[0] = '+';
			string::str[1] = temp;
			string::str[2] = '\0';
		}
	}
	else
	{
		string::size = 1;
		string::str = new char[1];
		string::str[0] = '\0';
	}
}
decString::decString(const char* temp)
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
	string::str = new char[string::size + 2];
	
		if (strlen(temp) > 0)
		{
			if (temp[0] == '-' || temp[0] == '+')
			{
				strcpy(string::str, temp);
				string::str[string::size] = '\0';
			}
			else if (temp[0] != '+')
			{
				string::size++;
				string::str[0] = '+';
				strcpy(string::str, temp);
				string::str[string::size + 1] = '\0';
			}
		}
		else
		{
			string::size = 1;
			string::str[0] = '0';
			string::str[1] = '\0';
		}
}
decString::decString(const decString& temp)
{
	++copyClassDec;
	if (this == &temp)
		return;
	string::size = temp.size;
	string::str = new char[string::size + 1];
	strcpy(string::str, temp.str);
	string::str[string::size] = '\0';
	std::cout << "Конструктор копирования" << "\n";
}
decString& decString::operator=(const decString& temp)
{
	copyClassDec++;
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
decString& decString::operator=(const char temp)
{
	copyClassDec++;
	string::size = 1;
	delete[] string::str;
	string::str = nullptr;
	string::str = new char[3];
	if (!check(temp))
	{
		string::str[0] = '0';
		string::str[1] = '\0';
	}
	else if (temp == '+' || temp == '-')
	{
		string::str[0] = temp;
		string::str[1] = '\0';
	}
	else
	{
		string::size++;
		string::str[0] = '+';
		string::str[1] = temp;
		string::str[2] = '\0';
	}
	return *this;
}
decString& decString::operator=(const char* temp)
{
	copyClassDec++;
	delete[]string::str;
	string::str = nullptr;
	if (!check(temp))
	{
		string::size = 1;
		string::str = new char[2];
		string::str[0] = '0';
		string::str[1] = '\0';
		return *this;
	}
	string::size = strlen(temp);
	string::str = new char[string::size + 2];
	if (temp[0] != '-' && temp[0] != '+')
	{
		string::size++;
		string::str[0] = '+';
		string::str[1] = '\0';
		strcat(string::str, temp);
		
			return *this;
	}
	strcpy(string::str, temp);
	string::str[string::size] = '\0';
	return *this;
}
void decString::print(std::ostream& out)
{
	std::cout << "operator<<(dec class)\n";
	out << this->str;
}
void decString::write(std::istream& in)
{
	std::cout << "operator>>(dec class)\n" << "\n";
	in.ignore();
	delete[] string::str;
	string::str = nullptr;
	char* tempChar = new char[128];
	int i = 0;
	in >> tempChar;
	string::size = strlen(tempChar);
	string::str = new char[strlen(tempChar) + 2];
	if (string::size > 0)
	{
		if (tempChar[0] == '-' || tempChar[0] == '+')
		{
			strcpy(string::str, tempChar);
			string::str[string::size] = '\0';
		}
		else if (tempChar[0] != '+')
		{
			string::size++;
			string::str[0] = '+';
			for (i; i < strlen(tempChar); ++i)
				string::str[i + 1] = tempChar[i];
			string::str[i + 1] = '\0';
		}
	}
	else
	{
		string::size = 1;
		string::str[0] = '0';
		string::str[1] = '\0';
	}
	delete[] tempChar;
}
char decString::operator[](const int temp)
{
	std::cout << "\nОператор[]\n";
	
		if (temp >= 0 && temp < string::size)
			return str[temp];
	return '0';
}
bool decString::check(const char temp)
{
	if ((temp >= '0' && temp <= '9') || temp == '+' || temp == '-')
		return 1;
	return 0;
}
bool decString::check(const char* temp)
{
	size_t i = 0;
	for (i; i < strlen(temp); ++i)
	{
		if (!((temp[i] >= '0' && temp[i] <= '9') || (i == 0 && (temp[i] ==
			'-' || temp[i] == '+'))))
			return 0;
	}
	return 1;
}
bool decString::operator>(const decString& temp)
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
bool decString::operator<(const decString& temp)
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
bool decString::operator==(const decString& temp)
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
int decString::_atoi()
{
	if (string::size == 0)
		return 0;
	return atoi(string::str);
}
int decString::getCopy()
{
	return copyClassDec;
}
bool decString::trans()
{
	unsigned long temp = strtoul(string::str, NULL, 0);
	return (temp >= 0 && temp <= ULLONG_MAX) ? 1 : 0;
}
decString::~decString()
{
	std::cout << "\nСработал деструктор\n";
	if (string::size == 0)
		return;
	delete[] string::str;
	string::str = nullptr;
}