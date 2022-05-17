#include <iostream>
#include "menu.h"
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Вспомогательный тип данных основного алгоритма
	menu programm;
	// Работа основного алгоритма
	while (programm.OpenMenu());
	return 0;
}
