#pragma once
enum eCMD
{
	CMD_EXIT = -1, CMD_NONE, CMD_READ, CMD_SHOW,
	CMD_EDIT, CMD_ADD, CMD_DELETE, CMD_SORT,
	CMD_FIND, CMD_SAVE, CMD_AVG
};

struct Pizzeria
{
	char name[20];
	char type[20];
	char code[20];
	float price;
	int kolvo;
};