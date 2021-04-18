//Текстовые файлы
//1.	С клавиатуры заполнить файл целыми числами (так, чтобы каждое число занимало одинаковое количество байт).  Вывести все числа из файла на экран.
//2.	Найти в файле минимальное число и вывести его на экран(если таких чисел несколько, вывести все).
//3.	Все максимальные числа заменить на минимальные, а все минимальные – на максимальные.
//Бинарные файлы
//1.	С клавиатуры заполнить файл целыми числами.
//2.	Посчитать, сколько в файле элементов с максимальным значением.
//3.	Заменить все максимальные элементы значением минимального элемента.



#include "Header.h"

int main()
{
	int number = 0;
	FILE* file = nullptr;
	number = typeOfFile(number);
	switch (number)
	{
	case 1:
		number = menuText(file);
		break;
	case 2:
		//menuBin(file);
		break;
	}
	
}

//main

#include "Header.h"

int typeOfFile(int number)
{
	printf("1-text\n2-bin\n");
	number = checkInput(number);
	return number;
}

int checkInput(int number)
{
	while (!scanf_s("%d", &number))
	{
		rewind(stdin);
		printf("Enter a number\n");
	}
	return number;
}

int menuText(FILE* file)
{
	char* nameFile = nullptr;
	int number = 0, min = 0, max = 0;
	if (nameFile == NULL)
	{
		nameFile = nameOfTheFileText(nameFile);
	}
	do
	{
		system("cls");
		printf("1-create file\n2-output\n3-add to file\n4-find min\n5-swap\n6-exit\n");
		number = checkInput(number);		
		switch (number)
		{
		case 1:
			creatorTextFile(file, nameFile);
			break;
		case 2:
			outputText(file, nameFile);
			break;
		case 3:
			addToFileText(file, nameFile);
			break;
		case 4:
			min = findMin(file, nameFile);
			printf("The minimal number is %d\n", min);
			continualCondition();
			break;
		case 6:
			return 0;
		}
	} while (1);
}

char* nameOfTheFileText(char* nameFile)
{
	do
	{
		int j = 0;
		char temp;
		nameFile = (char*)calloc(1, sizeof(char));
		rewind(stdin);
		printf("Enter the name of file: ");
		while (1)
		{
			scanf_s("%c", &temp);
			if (temp == '\n')
			{
				break;
			}
			nameFile = (char*)realloc(nameFile, (j + 1) * sizeof(char));
			nameFile[j] = temp;
			j++;
		}
		nameFile = (char*)realloc(nameFile, (j + 4) * sizeof(char));
		nameFile[j++] = '.';
		nameFile[j++] = 't';
		nameFile[j++] = 'x';
		nameFile[j++] = 't';
		nameFile[j] = '\0';
		system("cls");
	} while (strcmp(nameFile, "con.txt") == 0 || strcmp(nameFile, "aux.txt") == 0 || strcmp(nameFile, "nul.txt") == 0 || strcmp(nameFile, "prn.txt") == 0);
	return nameFile;
}

char* creatorTextFile(FILE* file, char* nameFile)
{
	int number = 0;
	file = fopen(nameFile, "w+t");
	while (1)          //ввод чисел
	{
		printf("Enter a number. 999 - stop entering\n");
		number = checkInput(number);
		if (number == 999) break;
		fprintf(file, " %d", number);
		system("cls");
	}
	rewind(file);
	fclose(file);
	return nameFile;
}

void outputText(FILE* file, char* nameFile)
{
	file = fopen(nameFile, "r");
	int number;
	if (!file) return;
	rewind(file);
	printf("\n|");
	while (1)
	{
		fscanf(file, "%d", &number);
		printf(" %d", number);
		if (feof(file)) break;
	}
	printf(" |\n");
	fclose(file);
	continualCondition();
}

void continualCondition()
{
	char s;
	rewind(stdin);
	printf("Press enter to continue... ");
	scanf_s("%c", &s);
}

void addToFileText(FILE* file, char* nameFile)
{
	int number = 0;
	file = fopen(nameFile, "a");
	while (1)          //ввод чисел
	{
		printf("Enter a number. 999 - stop entering\n");
		number = checkInput(number);
		if (number == 999) break;
		fprintf(file, " %d", number);
		system("cls");
	}
	rewind(file);
	fclose(file);
}

int findMin(FILE* file, char* nameFile)
{
	file = fopen(nameFile, "r");
	int min = 0, number = 0;
	fscanf(file, "%d", &min);
	rewind(file);
	while (1)         //нахождение максимального и минимального числа
	{
		fscanf(file, "%d", &number);
		if (min >= number)
		{
			min = number;
		}		
		if (feof(file)) break;
	}
	rewind(file);
	fclose(file);
	return min;
}

//functions

#pragma once
#pragma warning(disable: 4996)

#include <Windows.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <io.h>

int typeOfFile(int);
int checkInput(int);
void continualCondition();

char* creatorTextFile(FILE*, char*);
int menuText(FILE*);
char* nameOfTheFileText(char*);
void addToFileText(FILE*, char*);
void outputText(FILE*, char*);
int findMin(FILE*, char*);
int findMax(FILE*, char*);



//header
