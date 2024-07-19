#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"
#include "Header1.h"

using namespace std;

Pizzeria data[10] = { 0,0,0,0,0 };
unsigned count = 0;

eCMD Menu()
{
	while (true)
	{
		system("cls");
		printf("Выберите действие\n");
		printf("1 - Открыть файл\n");
		printf("2 - Посмотреть данные\n");
		printf("3 - Сохранить в файл\n");
		printf("4 - Выход\n");
		fflush(stdin);
		unsigned choise;
		scanf("%u", &choise);
		switch (choise)
		{
		case 1: return CMD_READ;
		case 2: return CMD_SHOW;
		case 3: return CMD_SAVE;
		case 4: return CMD_EXIT;
		default:printf("Введена неправильная команда\n"); system("pause");
		}
	}
}
int main()
{
	system("chcp 1251");
	eCMD cmd = CMD_NONE;
	while (true)
	{
		if (cmd == CMD_EXIT)
		{
			break;
		}
		cmd = Menu();
		switch (cmd)
		{
		case CMD_SHOW: ShowData(); break;
		case CMD_READ: Read(); break;
		case CMD_SAVE: Save(); break;
		}
	}
}