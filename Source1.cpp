#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header1.h"
#include <iostream>

extern Pizzeria data[10];
extern unsigned count;
void Read()
{
	char filename[20];
	printf("������� �������� �����\n");
	scanf("%s", filename);
	FILE* input = fopen(filename, "r");
	if (!input)
	{
		printf("������� ����� ���\n");
		return;
	}
	int lines = -1;
	char str[200];
	while (!feof(input))
	{
		fgets(str, sizeof(Pizzeria), input);
		lines++;
	}
	rewind(input);
	count = lines;
	for (int i = 0; i < count; i++)
	{
		fscanf(input, "%[^;];%[^;];%[^;];%f;%d\n", data[i].name, data[i].type, data[i].code, &data[i].price, &data[i].kolvo);
	}
	printf("���� ������� ������\n");
	system("pause");
	fclose(input);
}
void Save()
{
	char filename[20];
	printf("������� �������� �����\n");
	scanf("%s", filename);
	FILE* output = fopen(filename, "w");
	for (int i = 0; i < count; i++)
	{
		fprintf(output, "%s;%s;%s;%.2f;%d\n", data[i].name, data[i].type, data[i].code, data[i].price, data[i].kolvo);
	}
	fclose(output);
	printf("���������\n");
	system("pause");
}
eCMD MenuTwo()
{
	while (true)
	{
		puts("\n�������� ��������:");
		puts("1 - �������������\n2 - ��������\n3 - �������\n4 - �����������\n5 - ����� �� ��������\n6 - ������� ����\n7 - �����");
		unsigned option;
		scanf("%u", &option);
		switch (option)
		{
		case 1: return CMD_EDIT;
		case 2: return CMD_ADD;
		case 3: return CMD_DELETE;
		case 4: return CMD_SORT;
		case 5: return CMD_FIND;
		case 6: return CMD_AVG;
		case 7: return CMD_EXIT;
		default: printf("����� ������� ���\n"); system("pause");
		}
	}
}
void ShowData()
{
	eCMD cmd = CMD_NONE;
	while (cmd != CMD_EXIT)
	{
		system("cls");
		printf("|  #  |   ��������   |      ���      |  ���  | ����, ��� | ���-��, �� |\n");
			for (int i = 0; i < count; i++)
			{
				printf("|%5d|%14s|%15s|%7s|%11.2f|%12d|\n", i + 1, data[i].name, data[i].type, data[i].code, data[i].price, data[i].kolvo);
			}
		cmd = MenuTwo();
		switch (cmd)
		{
		case CMD_ADD: Add(); break;
		case CMD_EDIT: Edit(); break;
		case CMD_DELETE: Delete(); break;
		case CMD_SORT: Sort(); break;
		case CMD_FIND: Find(); break;
		case CMD_AVG: AveragePrice(); break;
		}
	}
}
void Add()
{
	printf("������� ����� �� ������ ��������?\n");
	int countoflines;
	scanf("%d", &countoflines);
	count += countoflines;
	for (int i = count - countoflines; i < count; i++)
	{
		printf("������� �������� ���������\n");
		scanf("%s", data[i].name);
		printf("������� ��� ���������\n");
		scanf("%s", data[i].type);
		printf("������� ���\n");
		scanf("%s", data[i].code);
		printf("������� ����\n");
		if (scanf("%f", &data[i].price) != 1)
		{
			printf("������\n");
			system("pause");
			return;
		}
		printf("������� ���-��\n");
		if (scanf("%d", &data[i].kolvo) != 1)
		{
			printf("������\n");
			system("pause");
			return;
		}
	}
}
void Edit()
{
	printf("������� ����� ������, ������� �� ������ ��������:\n");
	int b;
	scanf_s("%d", &b);
	if (b<1 || b>count)
	{
		printf("������ ������ ���\n");
		return;
	}

	printf("��������, ��� �� ������ ��������: 1 - ��������, 2 - ��� , 3 - ���, 4 - ����, 5 - ���-��\n");
	int v;
	scanf_s("%d", &v);
	printf("������� ����� ������:\n");

	switch (v) {
	case 1:
		scanf("%s", data[b - 1].name);
		break;
	case 2:
		scanf("%s", data[b - 1].type);
		break;
	case 3:
		scanf("%s", data[b-1].code);
		break;
	case 4:
		scanf("%f", &data[b - 1].price);
		break;
	case 5:
		scanf("%d", &data[b - 1].kolvo);
		break;
	default:
		printf("������: ������������ ����� ���������.\n");
		system("pause");
	}
}
void Delete()
{
	printf("������� ����� ������ ��� ��������\n");
	int line;
	scanf("%d", &line);
	if (line<1 || line > count)
	{
		printf("������������ ����� ������\n");
		system("pause");
		return;
	}
	line--;
	for (; line < count - 1; line++)
	{
		data[line] = data[line+1];
	}
	count--;
	printf("�������\n");
	system("pause");
}
void Sort()
{
	printf("� ����� ������� ������ �����������? 1 - ����������� 2 - ��������\n");
	int choise;
	scanf("%d", &choise);
	if (choise == 1)
	{
		for (unsigned i = 0; i < count - 1; ++i) {
			for (unsigned j = 0; j < count - i - 1; ++j) {
				if (data[j].price > data[j + 1].price) {
					std::swap(data[j], data[j + 1]);
				}
			}
		}
	}
	else if (choise == 2)
	{
		for (unsigned i = 0; i < count - 1; ++i) {
			for (unsigned j = 0; j < count - i - 1; ++j) {
				if (data[j].price < data[j + 1].price) {
					std::swap(data[j], data[j + 1]);
				}
			}
		}
	}
	printf("�������������\n");
	system("pause");
}
void Find()
{
	printf("������� �������� ���������\n");
	char str[20];
	bool find = false;
	scanf("%s", str);
	for (int i = 0; i < count; i++)
	{
		if (strstr(str, data[i].name))
		{
			printf("|%5d|%14s|%15s|%7s|%11.2f|%12d|\n", i + 1, data[i].name, data[i].type, data[i].code, data[i].price, data[i].kolvo);
			system("pause");
			find = true;
		}
	}
	if (find == false)
	{
		printf("������ ��������� ���\n"); system("pause");
	}
}
void AveragePrice()
{
	double sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += data[i].price;
	}
	printf("������� ���� �� ���� ����������: %.2lf", double(sum) / double(count));
	system("pause");
}

