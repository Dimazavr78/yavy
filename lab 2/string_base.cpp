#include "string_base.h"
string::string()
{
	size = 0;
	str = new char[1];
	str[0] = '\0';
	std::cout << "Конструктор без параметров" << "\n";
}

string::string(const char temp)
{
	size = 1;
	str = new char[2];
	str[0] = temp;
	str[1] = '\0';
	std::cout << "Конструктор копирования с одним параметром(типа char)" <<"\n";
}
string::string(const char* temp)
{
	size = strlen(temp);
	str = new char[size + 1];
	strcpy(str, temp);
	str[size] = '\0';
	std::cout << "Конструктор с одним параметром (типа char*)" << "\n";
}
string::string(const string& temp)
{
	++copyClassString;
	if (this == &temp)
		return;
	size = temp.size;
	str = new char[size + 1];
	strcpy(str, temp.str);
	str[size] = '\0';
	std::cout << "Конструктор копирования" << "\n";
}
string& string::operator=(const string& temp)
{
	copyClassString++;
	std::cout << "\nОператор=\n";
	if (this == &temp)
		return *this;
	delete[] this->str;
	this->size = temp.size;
	this->str = new char[this->size + 1];
	strcpy(this->str, temp.str);
	this->str[this->size] = '\0';
	return *this;
}
string& string::operator=(const char temp)
{
	copyClassString++;

	string::size = 1;
	delete[] string::str;
	string::str = nullptr;
	string::str = new char[2];
	string::str[0] = temp;
	string::str[1] = '\0';
	return *this;
}
string& string::operator=(const char* temp)
{
	copyClassString++;
	delete[] str;
	str = nullptr;
	size = strlen(temp);
	str = new char[size + 1];
	strcpy(str, temp);
	str[size] = '\0';
	return *this;
}
void string::print(std::ostream& out)
{
	std::cout << "\nОператор>>(base class)\n";
	out << this->str;
}
void string::write(std::istream& in)
{
	std::cout << "\nОператор<<(base class)\n";
	this->str = new char[128];
	in.ignore();
	in.getline(this->str, 128);
	this->size = strlen(this->str);
}
bool string::trans()
{
	std::cout << "У класса string нет операции перевода в unsigned long...\n";
		return 1;
}
bool string::operator>(const string& temp)
{
	std::cout << "\nОператор>\n";
	int i = 0;
	for (i; temp.str[i] != '\0' && str[i] != '\0'; ++i)
	{
		if (str[i] > temp.str[i])
			
			return 1;
	}
	return 0;
}
bool string::operator<(const string& temp)
{
	std::cout << "\nОператор<\n";
	int i = 0;
	for (i; temp.str[i] != '\0' && str[i] != '\0'; ++i)
	{
		if (str[i] < temp.str[i])
			return 1;
	}
	return 0;
}
bool string::operator==(const string& temp)
{
	std::cout << "\nОператор==\n";
	int i = 0;
	for (i; temp.str[i] != '\0' && str[i] != '\0'; ++i)
	{
		if (str[i] != temp.str[i])
			return 0;
	}
	return 1;
}
char string::lastChar()
{
	if (string::size == 0)
		return '0';
	return string::str[string::size - 1];
}
char string::operator[](const int temp)
{
	std::cout << "\nОператор[]\n";
	if (temp >= 0 && temp < size)
		return str[temp];
	return '0';
}
int string::getCopy()
{
	return copyClassString;
}
int string::length()
{
		std::cout << "Метод вычисления длины" << "\n";
	return size;
}
string::~string()
{
	if (size == 0)
		return;
	delete[] str;
	str = nullptr;
	std::cout << "\nСработал деструктор...\n";
}