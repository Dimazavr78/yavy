#include <iostream>
#include "string_idf.h"
#include "string_dec.h"
#include "string_base.h"
#include <vector>
#include <Windows.h>
#include <typeinfo>
#define pause system("pause")
#define cls system("cls")
static int strString = 0, strDec = 0, strIndif = 0;
std::vector<string*> initialization(std::vector<string*>);
std::vector<string*> test(std::vector<string*>);
int fullArr(const std::vector<bool>, const int);
void showFullArr(const std::vector<bool>, const int);

void showTypeId(const std::vector<string*>, const int);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	static int okMenu = 0;
	char menu = 0;
	std::vector <string*> str;
	do
	{
		cls;
		std::cout << " |-------------|\n";
		std::cout << " | Меню |\n";
		std::cout << " |-------------|\n\n";
		std::cout << "1. Инициализация\n2. Тестирование\n3.Выход\n\nВвод: ";
		std::cin >> menu;
		switch (menu)
		{
		case '1':
		{
			if (okMenu)
			{
				std::cout << "\nОбъекты были инициализированы ранее...\n";
				pause;
				break;
			}
			str = initialization(str);
			okMenu = 1;
		}break;
		case'2':
		{
			str = test(str);
		}break;
		case'3': break;
		default: break;
		}
	} while (menu != '3');
	return 0;
}
std::vector<string*> initialization(std::vector<string*> str)
{
	static bool okIn = 0;
	char menu = 0, secondMenu = 0, * startNum = new char[128];
	int numElem = 0, index = 0, numStr = -1;
	std::vector<bool> tempArr;
	do
	{
		cls;

		std::cout << " |----------------------|\n";
		std::cout << " | Инициализация |\n";
		std::cout << " |----------------------|\n\n";
		std::cout << "1. Число элементов\n2. Начальное значение\n3.Выход\n\nВвод: ";
		std::cin >> menu;
		switch (menu)
		{
		case '1':
		{
			cls;
			if (okIn)
			{
				std::cout << "Вы уже ввели число элементов!\n";
				pause;
				break;
			}
			else
			{
				do
				{
					cls;
					std::cout << "Ввод числа элементов: ";
					std::cin >> numElem;
				} while (numElem < 1);
				for (int i = 0; i < numElem; ++i)
				{
					str.push_back(new string);
					tempArr.push_back(0);
				}
			}
			okIn = 1;
		}break;
		case '2':
		{
			if (!okIn)
			{
				cls;
				std::cout << "Перед тем, как ввести начальное значение, введите число элементов!\n";
				pause;
			}
			else
			{
				do
				{
					index = -1;
					do
					{
						cls;
						std::cout << "Введено элементов " <<

							fullArr(tempArr, numElem) << " из " << numElem;
						if (fullArr(tempArr, numElem) > 0)
						{
							showFullArr(tempArr, numElem);
						}
						std::cout << "\nВведите индекс вмассиве от 0 до " << ((numElem != 0) ? numElem - 1 : 0) << ": ";
						std::cin >> index;
					} while (index<0 || index>numElem - 1);
					do
					{
						cls;
						std::cout << " |---------------- - | \n";
						std::cout << " | Выбор типа| \n";
						std::cout << " |---------------- - | \n\n";
						std::cout << "1. Строкаидентификатор\n2. Десятичная строка\n3. Базовую строку\nВвод:";
						std::cin >> secondMenu;
					} while (secondMenu < '1' && secondMenu >
						'3');
					startNum = 0;
					switch (secondMenu)
					{
					case'1':
					{
						strIndif++;
						delete[] startNum;
						startNum = new char[128];
						delete* (str.begin() + index);
						str.erase(str.begin() + index);
						str.insert(str.begin() + index, new	indString);
						cls;
						std::cout << "Ввод строки: ";
						std::cin.ignore();
						std::cin.getline(startNum, 128);
						*str[index] = startNum;
					}break;
					case'2':
					{
						strDec++;
						delete[] startNum;
						startNum = new char[128];
						delete* (str.begin() + index);
						str.erase(str.begin() + index);
						str.insert(str.begin() + index, new	decString);
						cls;
						std::cout << "Ввод строки: ";
						std::cin.ignore();
						std::cin.getline(startNum, 128);
						*str[index] = startNum;
					}break;
					case'3':
					{
						strString++;
						delete[] startNum;
						startNum = new char[128];
						cls;
						std::cout << "Ввод строки: ";
						std::cin.ignore();
						std::cin.getline(startNum, 128);
						*str[index] = startNum;
					}break;
					}
					tempArr[index] = 1;
				} while (fullArr(tempArr, numElem) != numElem);
			}
		}break;
		case '3': return str;
		default: break;
		}
	} while (menu != '3');
	return str;
}
std::vector<string*> test(std::vector<string*> str)
{
	char menu = 0, secondMenu;
	int index = -1, secIndex = -1;
	const int size = str.size();
	string* tempString = new string;
	if (size == 0)
	{
		std::cout << "В программе нет записей...\n";
		pause;
		return str;
	}
	do
	{
		secondMenu = 0;
		cls;
		std::cout << " |-------------------|\n";
		std::cout << " | Тестирование |\n";
		std::cout << " |-------------------|\n\n";
		
			std::cout << "1. Строка\n2. Строка-идентификатор\n3. Десятичная строка\n4.Выход в меню\nВвод: ";
		std::cin >> menu;
		switch (menu)
		{
		case '1':
		{
			if (strString == 0)
			{
				std::cout << "\nНет записей с объектами	string\n";
				pause;
				break;
			}
			do
			{
				cls;
				std::cout << "В массиве объекты типа \"string\" находятся на индексе(-ах) : ";
				showTypeId(str, 1);
				std::cout << "\nВвод индекса: ";
				std::cin >> index;
			} while (index<0 || index>size || (typeid(string) !=
				typeid(*str[index])));
			do
			{
				cls;
				std::cout << " |------------------------------ - | \n";
				std::cout << " | Тестирование для строки | \n";
				std::cout << " |------------------------------ - | \n\n";
				std::cout << "1. Длина строки\n2. Присваивание левому операнду новое значение\n3.Кол - во использования конструктора копирования\n4.Выход в меню \"Тестирование\"\nВвод: ";
				std::cin >> secondMenu;
			} while (secondMenu < '1' && secondMenu>'4');
			switch (secondMenu)
			{
			case'1':
			{
				cls;
				std::cout << "Длина строки = " << str[index]->length() << '\n';
				pause;
			}break;
			case '2':
			{
				delete tempString;
				tempString = new string;
				cls;
				std::cout << "Ввод правого операнда: ";
				std::cin >> *tempString;
				cls;
				*str[index] = *tempString;

			}break;
			case'3': cls; std::cout << "Конструктор копирования для строки был использован " << str[index]->getCopy() << " раз\n";
				pause; break;
			default:break;
			}
		}break;
		case '2':
		{
			if (strIndif == 0)
			{
				std::cout << "\nНет записей с объектами сиидентификатор\n";
				pause;
				break;
			}
			do
			{
				cls;
				std::cout << "В массиве объекты типа \"Сиидентификатр\" находятся на индексе(-ах): ";
				showTypeId(str, 2);
				std::cout << "\nВвод индекса: ";
				std::cin >> index;
			} while (typeid(indString) != typeid(*str[index]));
			do
			{
				cls;
				std::cout << " |------------------------------------ | \n";
				std::cout << " | Тестирование для сиидентификатора |\n";
				std::cout << " |------------------------------------ | \n\n";
				std::cout << "1. Длина строки\n2. Присваивание левому операнду новое значение\n3.Кол - во использования конструктора копирования\n4.Последний символ в строке\n5.Вывод одного символа (оператор[])\n6.Сравнение(оператор > )\n7.Выход в меню \"Тестирование\"\nВвод: ";
				std::cin >> secondMenu;
			} while (secondMenu < '1' || secondMenu>'7');
			cls;
			switch (secondMenu)
			{
			case'1':
			{
				std::cout << "Длина строки = " << str[index]->length() << "\n";
				pause;
			}break;
			case '2':
			{
				delete tempString;

				tempString = new indString;
				cls;
				std::cout << "Ввод правого операнда: ";
				std::cin >> *tempString;
				cls;
				*str[index] = *tempString;
			}break;
			case'3': std::cout << "Конструктор копирования для строки был использован " << str[index]->getCopy() << " раз\n"; pause;
				break;
			case'4': std::cout << "Последний символ в строке \""
				<< str[index]->lastChar() << "\"\n"; pause; break;
			case'5':
			{
				do
				{
					cls;
					std::cout << "Ввод индекса си-строки от 0 до " << str[index]->length() - 1 << "\n";
					std::cin >> secIndex;
				} while (secIndex<0 || secIndex>str[index]->length());
				cls;
				std::cout << "Символ с индексом " << secIndex <<
					" = " << (*str[index])[secIndex] << '\n';
				pause;
			}break;
			case'6':
			{
				delete tempString;
				tempString = new indString;
				cls;
				std::cout << "Ввод правого операнда для сравнения: ";
				std::cin >> *tempString;
				cls;
				std::cout << ((*str[index] > *tempString) ?
					"Левый операнд больше правого\n" : "Правый операнд больше левого\n");
				pause;
			}break;
			default:break;
			}
		}break;
		case '3':
		{
			if (strDec == 0)
			{
				std::cout << "\nНет записей с объектами десятичной строки\n";
				pause;
				break;
			}
			do

			{
				cls;
				std::cout << "В массиве объекты типа\"Десятичная строка\" находятся на индексе(-ах): ";
				showTypeId(str, 3);
				std::cout << "\nВвод индекса: ";
				std::cin >> index;
			} while (typeid(decString) != typeid(*str[index]));
			do
			{
				cls;
				std::cout << " |------------------------------------ | \n";
				std::cout << " | Тестирование для десятичной - строки | \n";
				std::cout << " |------------------------------------ | \n\n";
				std::cout << "1. Длина строки\n2. Присваивание левому операнду новое значение\n3.Кол - во использования конструктора копирования\n4.Можно ли представить в формате unsigned int\n5.Сравнение(оператор > )\n7.Выход в меню \"Тестирование\"\nВвод: ";
				std::cin >> secondMenu;
			} while (secondMenu < '1' || secondMenu>'6');
			cls;
			switch (secondMenu)
			{
			case'1':
			{
				std::cout << "Длина строки = " << str[index]->length() << "\n";
				pause;
			}break;
			case '2':
			{
				delete tempString;
				tempString = new decString;
				cls;
				std::cout << "Ввод правого операнда: ";
				std::cin >> *tempString;
				cls;
				*str[index] = *tempString;
			}break;
			case'3': std::cout << "Конструктор копирования для строки был использован " << str[index]->getCopy() << " раз\n"; pause;
				break;
			case'4': std::cout << ((str[index]->trans()) ? "Можно представить в виде unsigned long" : "Нельзя представить в виде unsigned long") << '\n'; pause; break;
			case'5':
			{
				delete tempString;
				tempString = new decString;
				cls;
				std::cout << "Ввод правого операнда для сравнения: ";

				std::cin >> *tempString;
				cls;
				std::cout << ((*str[index] > *tempString) ?
					"Левый операнд больше правого\n" : "Правый операнд больше левого\n");
				pause;
			}break;
			default:break;
			}
		}break;
		}
	} while (menu != '4');
	return str;
}
int fullArr(const std::vector<bool> tempArr, const int num)
{
	int i = 0, summa = 0;
	for (i; i < num; ++i)
	{
		if (tempArr[i] == 1)
		{
			++summa;
		}
	}
	return summa;
}
void showFullArr(const std::vector<bool> tempArr, const int num)
{
	int i = 0;
	std::cout << "\nИндексы: ";
	for (i; i < num; ++i)
	{
		if (tempArr[i] == 1)
		{
			std::cout << i << " ";
		}
	}
	std::cout << "заполнен(-ы) данными.";
}
void showTypeId(const std::vector<string*> str, const int ok)
{
	int i = 0;
	const int size = str.size();
	switch (ok)
	{

	case 1:
	{
		for (i; i < size; ++i)
		{
			if (typeid(string) == typeid(*str[i]))
				std::cout << i << " ";
		}
	}break;
	case 2:
	{
		for (i; i < size; ++i)
		{
			if (typeid(indString) == typeid(*str[i]))
				std::cout << i << " ";
		}
	}break;
	default:
	{
		for (i; i < size; ++i)
		{
			if (typeid(decString) == typeid(*str[i]))
				std::cout << i << " ";
		}
	}break;
	}
}
