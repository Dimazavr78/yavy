#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include "menu.h"
#define cls system("cls")
#define pause system("pause")
// Вспомогательные глобальные переменные, который проверяют: были ли введены данные стэков char и

bool okInitializingFloat = 0, okInitializingChar = 0;
using namespace std;
// Метод основного алгоритма + взаимодействия с меню
bool menu::OpenMenu()
{
	char exitMenu = 0;
	// Вывод меню в консоль
	RendererMenu(0);
	cin >> exitMenu;
	// Выбор одного из пунктов меню
	switch (exitMenu)
	{
		// Вызов метода добавления/изменения/удаления данных стэка char и float
	case'1':Initialization(); break;
	case'2':
	{
		// Проверка на наличие данных в стэке
		if (okInitializingFloat * okInitializingChar == 1)
		{
			// Вывод данных в стэке на экран
			OutputOfAllStack();
		}
	}break;
	case'3':
	{
		// Проверка на наличие данных в стэке
		if (okInitializingFloat * okInitializingChar == 1)
		{
				// Перестановка элементов стэка в обратном порядке
				InvertingStack();
		}
	}break;
	default:break;
	}
	return (exitMenu == '4') ? 0 : 1;
}
// Метод добавления/изменения/удаления данных стэка char и float
void menu::Initialization()
{
	char chooseInitialization = 0;
	// Цикл выбора одного из пунктов меню
	while (chooseInitialization != '1' && chooseInitialization != '2')
	{
		RendererMenu(1);
		cin >> chooseInitialization;
	}
	// Вызов методов инициализации отдельных стэков
	switch (chooseInitialization)
	{
	case'1':InitializationFloat(); break;
	default:InitializationChar(); break;
	}
}
// Метод вывода названия каждого пункта меню
void menu::RendererMenu(uint16_t CharacterOutputSelection)
{
	cls;
	if (CharacterOutputSelection == 0)
	{
		cout <<
			"|============================================================================ | \n";
			cout << "| Главное меню| \n";
			cout <<
			"|============================================================================ | \n\n";
			cout << "1. Инициализация массивов\n2. Вывод массивов\n3. Перестановка элементов массивов в обратном порядке\n4.Выход\n------ - \nВыборпункта меню : ";
	}
	if (CharacterOutputSelection == 1)
	{
		cout <<
			"|============================================================================ | \n";
			cout << "| Инициализация| \n";
			cout <<
			"|============================================================================ | \n\n";
			cout << "1. Инициализация массива float\n2. Инициализация массиваchar\n------ - \nВыбор пункта меню : ";
			
	}
	if (CharacterOutputSelection == 2)
	{
		cout <<
			"|============================================================================ | \n";
			cout << "| Массивы были перестроены| \n";
			cout <<
			"|============================================================================ | \n\n";
			return;
	}
	if (CharacterOutputSelection == 3)
	{
		cout <<
			"|============================================================================ | \n";
			cout << "| Инициализация float| \n";
			cout <<
			"|============================================================================ | \n\n";
			cout << "1. Добавление элемента\n2. Удаление элемента\n3.Завершение инициализации\n------ - \nВыбор пункта меню : ";
	}
	if (CharacterOutputSelection == 4)
	{
		cout <<
			"|============================================================================ | \n";
			cout << "| Инициализация char| \n";
			cout <<
			"|============================================================================ | \n\n";
			cout << "1. Добавление элемента\n2. Удаление элемента\n3.Завершение инициализации\n------ - \nВыбор пункта меню : ";
	}
	if (CharacterOutputSelection == 5)
	{
		cout <<
			"|============================================================================ | \n";
			cout << "| Завершение программы| \n";
			cout <<
			"|============================================================================ | \n\n";
			Sleep(1000);
	}
}
// Метод инициализации стэка типа float
void menu::InitializationFloat()
{

		
		char initializationMenu = 0;
	string strData;
	float data = 0.;
	while (initializationMenu != '3')
	{
		RendererMenu(3);
		cin >> initializationMenu;
		cls;
		switch (initializationMenu)
		{
		case'1':
		{
			cout << "Ввод числа: ";
			cin >> strData;
			// Проверка на корректный ввод строки
			CheckingCorrectInputFloat(strData);
			// Перевод string в float
			data = stof(strData);
			// Добавление числа в стэк
			floatArray.push(data);
		}break;
		case'2':
		{
			// Вызов исключения, если не было данных в стэке
			try
			{
				cout << "Число " << floatArray.top() << " удалено изстэка\n";
					floatArray.pop();
			}
			catch (const exception& ex)
			{
				cout << ex.what() << '\n';
			}
			pause;
		}break;
		}
	}
	// Если okInitializingFloat равен 1, значит стэк типа float был инициализирован
	okInitializingFloat = 1;
	// Проверка на наличие данных в стэке
	if (floatArray.empty())
	{
		okInitializingFloat = 0;
	}
}
// Метод инициализации стэка типа char
void menu::InitializationChar()
{
	
		char initializationMenu = 0;
	char data = '0';
	
		while (initializationMenu != '3')
		{
			RendererMenu(4);
			cin >> initializationMenu;
			cls;
			switch (initializationMenu)
			{
			case'1':
			{
				cout << "Ввод символа: ";
				cin >> data;
				// Добавление данных в стэк
				charList.push(data);
			}break;
			case'2':
			{
				// Вызов исключения, если в стэке не было данных
				try
				{
					cout << "Символ " << charList.top() << " удален из стэка\n";
						charList.pop();
				}
				catch (const exception& ex)
				{
					cout << ex.what() << '\n';
				}
				pause;
			}break;
			}
		}
	// Если okInitializingChar равен 1, значит стэк типа float был инициализирован
	okInitializingChar = 1;
	// Проверка на наличие данных в стэке
	if (charList.empty())
	{
		okInitializingChar = 0;
	}
}
// Метод вывода всех данных стэков с типами данных char и float
void menu::OutputOfAllStack()
{
	// Создание временных типов данных стэков со СХ: вектор и список
	Stack<float> tempFloat;
	Stack<char, List> tempChar;
	cls;
	cout << "Массив float: ";
	// Цикл, который выводит все элементы стэка char
	while (!floatArray.empty())
	{
		// Проверка на наличие данных в стэке char
		try
		{
			cout << floatArray.top() << " ";
			tempFloat.push(floatArray.top());
			floatArray.pop();
		
		}
		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}
	cout << "\nМассив char: ";
	// Цикл, который выводит все элементы стэка float
	while (!charList.empty())
	{
		// Проверка на наличие данных в стэке float
		try
		{
			cout << charList.top();
			tempChar.push(charList.top());
			charList.pop();
		}
		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}
	// Обратное добавление данных в стэк float
	while (!tempFloat.empty())
	{
		try
		{
			floatArray.push(tempFloat.top());
			tempFloat.pop();
		}
		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}
	// Обратное добавление данных в стэк char
	while (!tempChar.empty())
	{
		try
		{
			charList.push(tempChar.top());
			tempChar.pop();
		}
		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}
	cout << "\n";
	pause;
}
// Метод перевода данных из стэка в обратный порядок
void menu::InvertingStack()
{
	
		// Создание временных типов данных стэков со СХ: вектор и список
		Stack<float> tempFloat;
	Stack<char, List> tempChar;
	// Цикл, который добавляет данные во временный стэк float
	while (!floatArray.empty())
	{
		try
		{
			tempFloat.push(floatArray.top());
			floatArray.pop();
		}
		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}
	// Цикл, который добавляет данные во временный стэк char
	while (!charList.empty())
	{
		try
		{
			tempChar.push(charList.top());
			charList.pop();
		}
		catch (const exception& ex)
		{
			cout << ex.what() << '\n';
		}
	}
	// Перемещение данных из временных стэков в основной
	floatArray = move(tempFloat);
	charList = move(tempChar);
	RendererMenu(2);
}
// Проверка на корректный ввод вещественного числа
void menu::CheckingCorrectInputFloat(string& str)
{
	
		bool okPoint = 0, okNumber = 0;
	size_t j, i = 0;
	string s = ".0987654321";
	string s1 = "";
	for (i; i < str.length(); ++i)
	{
		okNumber = 0;
		for (j = 0; j < 11; ++j)
		{
			if (str[i] == s[j])
			{
				okNumber = 1;
				if (!okPoint || (str[i] != '.') || (str[i] != ','))
				{
					if (str[i] == ',')
					{
						str[i] = '.';
					}
					
						s1 = s1 + str[i];
				}
				if ((str[i] == '.' || str[i] == ',') && !okPoint)
				{
					okPoint = 1;
				}
			}
		}
		if (!okNumber)
		{
			str = "0.";
			return;
		}
	}
	str = s1;
}
// Декструктор + вызов функции вывода сообщения о завершении программы
menu::~menu()
{
	RendererMenu(5);
}