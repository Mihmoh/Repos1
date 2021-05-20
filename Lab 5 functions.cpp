#include "Header.h"

int checkInput(int number) //проверка на ввод
{
	while (!scanf_s("%d", &number))
	{
		rewind(stdin);
		printf("Enter a number\n");
	}
	return number;
}

void continuationCondition() //пауза продолжения
{
	char s;
	rewind(stdin);
	printf("\nPress enter to continue... \n");
	scanf_s("%c", &s);
}

void menu(students* pointHead, students* pointerTail)		//меню
{
	int number = 0;
	do
	{
		do
		{
			system("CLS");
			printf_s("List of possible actions:\n1.Create a database.\n2.Print a database.\n3.Search info.\n4.Delete by given parameter.");
			printf_s("\n5.Save your database in file.\n6.Download your information from file.\n0.Exit.");
			printf("\nWrite number: ");
			number = checkInput(number);
			if (number < 0 || number > 7)
			{
				printf("Incorrect input. Try again.");
				continuationCondition();
				continue;
			}
		} while (1 < 0);
		switch (number)
		{
		case 1:
			pointHead = creator(pointHead, &pointerTail);
			break;
		case 2:
			printDatabase(pointHead);
			break;
		case 3:
			findStruct(pointHead);
			break;
		case 4:
			pointHead = findStructForDelete(pointHead, &pointerTail);
			break;
		case 5:
		{
			int choose;
			choose = chooseTypeOfFile();
			if (choose == 1)
				creatorTextFile(pointHead);
			else
				creatorBinFile(pointHead);
			break;
		}
		case 6:
			int choose;
			choose = chooseTypeOfFile();
			if (choose == 1)
				pointHead = downloadText(pointHead, &pointerTail);
			else
				pointHead = downloadBIN(pointHead, &pointerTail);
			break;

		case 0:
			system("CLS");
			printf("Session finished");
			return;
		}
	} while (1);
}


students* creator(students* pointerHead, students** pointerTail)		//создание очереди
{
	int counter = 0, number = 0, end = 1;
	students* pointerPrevious;
	system("CLS");
	printf("Creating a structure :\n");
	do
	{
		pointerPrevious = pointerHead;
		if (!(pointerPrevious = (students*)malloc(sizeof(students) * 1)))
		{
			printf("No memory.");
			return pointerPrevious;
		}
		counter++;

		printf_s("This is a student %d.\n\nEnter the number of student's book:\n", counter);
		pointerPrevious->studentBookNumber = checkInput(pointerPrevious->studentBookNumber);		//ввод номера зачётки

		printf("Enter the surname of student:\n");		//ввод фамилии
		pointerPrevious->surname = (char*)malloc(sizeof(char) * SIZE);
		rewind(stdin);
		fgets(pointerPrevious->surname, SIZE, stdin);
		for (int j = 0; ; j++)
		{
			if (pointerPrevious->surname[j] == '\n')
			{
				pointerPrevious->surname[j] = '\0';
				break;
			}
		}

		printf("What do you want to do?\n1. Expulsion date.\n2. The average score.\n");
		number = checkInput(number);
		if (number == 1)		//ввод даты
		{
			printf("Enter expulsion date in form of yyyy.mm.dd, where dd is day, mm is month.\n");
			int trigger, j, numbString;
			do
			{
				numbString = trigger = 0;
				rewind(stdin);
				fflush(stdin);
				gets_s(pointerPrevious->unon.date);
				if (strlen(pointerPrevious->unon.date) != SIZE_DATE - 1)
				{
					trigger = 1;
				}
				for (j = 0; j < 4; j++)
				{
					if (pointerPrevious->unon.date[j] > '9' || pointerPrevious->unon.date[j] < '0')
					{
						trigger = 1;
					}
				}
				for (j++; j < 7; j++)
				{
					if (pointerPrevious->unon.date[j] < '9' || pointerPrevious->unon.date[j] > '0')
					{
						numbString = (pointerPrevious->unon.date[j] - '0') + 10 * numbString;
					}
				}
				if (numbString > 12 || numbString < 0)
					trigger = 1;
				numbString = 0;
				for (j++; j < 10; j++)
				{
					if (pointerPrevious->unon.date[j] < '9' || pointerPrevious->unon.date[j] > '0')
					{
						numbString = (pointerPrevious->unon.date[j] - '0') + 10 * numbString;
					}
				}
				if (numbString > 31 || numbString < 0)
					trigger = 1;
				if (trigger == 1)
				{
					system("CLS");
					printf("Wrong input. Try again.");
					continue;
				}
				pointerPrevious->flg = 1;
				break;
			} while (1);
		}
		else if (number == 2)		//ввод среднего балла
		{
			printf("Enter the average score:\n");
			pointerPrevious->unon.averageScore = checkInput(pointerPrevious->unon.averageScore);
			pointerPrevious->flg = 2;
		}

		number = 0;
		printf("1 - continue\n0 - stop\n");
		end = checkInput(end);
		system("cls");

		if (pointerHead == nullptr)
			*pointerTail = pointerHead = pointerPrevious;
		else
		{
			(*pointerTail)->pointerNext = pointerPrevious;
			*pointerTail = pointerPrevious;
		}
	} while (end != 0);
	pointerPrevious->pointerNext = nullptr;

	return pointerHead;
}

void printDatabase(students* pointerHead)		//просмотр очереди
{
	students* pointerPrevious;
	pointerPrevious = pointerHead;
	system("CLS");
	if (pointerHead == nullptr)
	{
		printf("You have not created database\n");
		continuationCondition();
		return;
	}
	printf_s("=========================================================================================\n\t\tYour database\n");
	printf_s("=========================================================================================\n||Student's book number ||\tSurname\t    ||Date of expulsion ||     Average score   ||");
	for (; ; )
	{
		printf("\n||----------------------||------------------||------------------||---------------------||\n");
		printf_s("||%12d\t        ||%12s      ||", pointerPrevious->studentBookNumber, pointerPrevious->surname);
		if (pointerPrevious->flg == 1) {
			printf("    %s    ||", pointerPrevious->unon.date);
			printf("\t    -          ||");
		}
		else if (pointerPrevious->flg == 2) {
			printf("        -         ||");
			printf("\t%6d\t       ||", pointerPrevious->unon.averageScore);
		}
		pointerPrevious = pointerPrevious->pointerNext;
		if (pointerPrevious == nullptr)
			break;
	}
	continuationCondition();
}

students* findStruct(students* pointerHead)			//поиск
{
	if (pointerHead == nullptr) {
		system("CLS");
		printf("You don't have a database. First create it.");
		continuationCondition();
		return pointerHead;
	}
	int choose = 0;
	students* pointerPrevious;
	pointerPrevious = pointerHead;
	choose = chooseParametr();
	switch (choose)
	{
	case 1:			//по номеру зачётки
	{
		int  numb = 0;
		printf("Enter the number of student's book you want to find:\n");
		numb = checkInput(numb);
		system("CLS");
		printf_s("=========================================================================================\n\t\tYour database\n");
		printf_s("=========================================================================================\n||Student's book number ||\tSurname\t    ||Date of expulsion ||     Average score   ||");
		while (pointerPrevious != nullptr) {
			if (pointerPrevious->studentBookNumber == numb) {
				printf("\n||----------------------||------------------||------------------||---------------------||\n");
				printf_s("||%12d\t        ||%12s      ||", pointerPrevious->studentBookNumber, pointerPrevious->surname);
				if (pointerPrevious->flg == 1) {
					printf("    %s    ||", pointerPrevious->unon.date);
					printf("\t    -          ||");
				}
				else if (pointerPrevious->flg == 2) {
					printf("        -         ||");
					printf("\t%6d\t       ||", pointerPrevious->unon.averageScore);
				}
			}
			pointerPrevious = pointerPrevious->pointerNext;
		}
		continuationCondition();
		break;
	}
	case 2:			//по фамилии
	{
		printf("Enter the surname of student:\n");
		char* findName;
		findName = (char*)malloc(sizeof(char) * 100);
		rewind(stdin);
		fgets(findName, 255, stdin);
		for (int j = 0; ; j++) {
			if (findName[j] == '\n') {
				findName[j] = '\0';
				break;
			}
		}
		system("CLS");
		printf_s("=========================================================================================\n\t\tYour database\n");
		printf_s("=========================================================================================\n||Student's book number ||\tSurname\t    ||Date of expulsion ||     Average score   ||");
		for (; pointerPrevious != nullptr;) {
			if (strcmp(pointerPrevious->surname, findName) == 0) {
				printf("\n||----------------------||------------------||------------------||---------------------||\n");
				printf_s("||%12d\t        ||%12s      ||", pointerPrevious->studentBookNumber, pointerPrevious->surname);
				if (pointerPrevious->flg == 1) {
					printf("    %s    ||", pointerPrevious->unon.date);
					printf("\t    -          ||");
				}
				else if (pointerPrevious->flg == 2) {
					printf("        -         ||");
					printf("\t%6d\t       ||", pointerPrevious->unon.averageScore);
				}

			}
			pointerPrevious = pointerPrevious->pointerNext;
		}
		continuationCondition();
		break;
	}
	case 3:			//по дате отчсления
	{
		char findDate[SIZE_DATE];
		do {
			system("CLS");
			printf("Enter the expulsion date, which you want to find in format yyyy.mm.dd (Example: 2003.12.04):\n");
			int numbString = 0, trigger = 0, j;
			rewind(stdin);
			fflush(stdin);
			gets_s(findDate);
			if (strlen(findDate) != SIZE_DATE - 1) {
				trigger = 1;
			}
			for (j = 0; j < 4; j++) {
				if (findDate[j] > '9' || findDate[j] < '0') {
					trigger = 1;
				}
			}
			for (j++; j < 7; j++) {
				if (findDate[j] < '9' || findDate[j] > '0') {
					numbString = (findDate[j] - '0') + 10 * numbString;
				}
			}
			if (numbString > 12 || numbString < 0)
				trigger = 1;
			numbString = 0;
			for (j++; j < 10; j++) {
				if (findDate[j] < '9' || findDate[j] > '0') {
					numbString = (findDate[j] - '0') + 10 * numbString;
				}
			}
			if (numbString > 31 || numbString < 0)
				trigger = 1;
			if (trigger == 1) {
				printf("Wrong input. Try again.");
				continuationCondition();
				continue;
			}
		} while (1 < 0);
		system("CLS");
		printf_s("=========================================================================================\n\t\tYour database\n");
		printf_s("=========================================================================================\n||Student's book number ||\tSurname\t    ||Date of expulsion ||     Average score   ||");
		for (; pointerPrevious != nullptr;) {
			if (strcmp(pointerPrevious->unon.date, findDate) == 0) {
				printf("\n||----------------------||------------------||------------------||---------------------||\n");
				printf_s("||%12d\t        ||%12s      ||", pointerPrevious->studentBookNumber, pointerPrevious->surname);
				if (pointerPrevious->flg == 1) {
					printf("    %s    ||", pointerPrevious->unon.date);
					printf("\t    -          ||");
				}
				else if (pointerPrevious->flg == 2) {
					printf("        -         ||");
					printf("\t%6d\t       ||", pointerPrevious->unon.averageScore);
				}
			}
			pointerPrevious = pointerPrevious->pointerNext;
		}
		continuationCondition();
		break;
	}
	case 4:			//по среднему баллу
	{
		int numb = 0;
		printf("Enter the average score:\n");
		numb = checkInput(numb);
		system("CLS");
		printf_s("=========================================================================================\n\t\tYour database\n");
		printf_s("=========================================================================================\n||Student's book number ||\tSurname\t    ||Date of expulsion ||     Average score   ||");
		for (; pointerPrevious != nullptr;) {
			if (pointerPrevious->unon.averageScore == numb) {
				printf("\n||----------------------||------------------||------------------||---------------------||\n");
				printf_s("||%12d\t        ||%12s      ||", pointerPrevious->studentBookNumber, pointerPrevious->surname);
				if (pointerPrevious->flg == 1) {
					printf("    %s    ||", pointerPrevious->unon.date);
					printf("\t    -          ||");
				}
				else if (pointerPrevious->flg == 2) {
					printf("        -         ||");
					printf("\t%6d\t       ||", pointerPrevious->unon.averageScore);
				}
			}
			pointerPrevious = pointerPrevious->pointerNext;
		}
		continuationCondition();
		break;
	}
	}
}

int chooseParametr() //функция выбора параметра
{
	int number = 0;
	do {
		printf("\n1.By the number of student's book.\n2.By surname.\n3.By expulsion date.\n4.By the average score.\nEnter a number: ");
		number = checkInput(number);
		if (number > 5 || number < 0) {
			printf("Incorrect input. Try again.");
			continuationCondition();
			system("CLS");
			continue;
		}
	} while (1 < 0);
	switch (number) {
	case 1: return 1;
	case 2: return 2;
	case 3: return 3;
	case 4: return 4;
	}
	return 0;
}

int chooseTypeOfFile() //функция выбора типа файла
{
	int numb = 0;
	printf("Choose the desired file:\n1.Text file.\n2.Bynary file.\nEnter number: ");
	do {
		numb = checkInput(numb);
		if (numb > 2 || numb < 0) {
			printf("Incorrect input. Try again.");
			continuationCondition();
			system("CLS");
			printf("Choose the desired file:\n1.Text file.\n2.Bynary file.\nEnter number: ");
			continue;
		}
	} while (1 < 0);
	if (numb == 2)
		return 2;
	else
		return 1;
}

students* downloadText(students* pointerHead, students** pointerTail) //функция загрузки текстового файла
{
	pointerHead = nullptr;
	char* name;
	students* pointerPrevious = nullptr, * pointerBuffer;
	char checker;
	name = (char*)malloc(sizeof(char) * 30);
	FILE* file;
	system("CLS");
	printf("Write the name file, what you want to find:\n");
	rewind(stdin);
	fgets(name, 30, stdin);
	for (int i = 0; ; i++)
	{
		if (name[i] == '\n')
		{
			name[i++] = '.';
			name[i++] = 't';
			name[i++] = 'x';
			name[i++] = 't';
			name[i++] = '\0';
			name = (char*)realloc(name, sizeof(char) * i);
			break;
		}
	}
	file = fopen(name, "r");
	if (file == nullptr) {
		printf("File not found... Check input.\n Return to the menu...");
		continuationCondition();
		return pointerHead;
	}
	system("CLS");
	printf("Reading information from a file...");

	//////////////////////////////////////////////////////////////////
	{
		pointerHead = (students*)malloc(sizeof(students) * 1);
		while (1) {
			fscanf(file, "%c", &checker);
			if (checker >= '0' && checker <= '9')
			{
				fseek(file, -1, SEEK_CUR);
				break;
			}
		}
		fscanf(file, "%d", &pointerHead->studentBookNumber);
		while (1) {
			fscanf(file, "%c", &checker);
			if ((checker > '0' && checker < '9') || (checker > 'A' && checker < 'z'))
			{
				fseek(file, -1, SEEK_CUR);
				break;
			}
		}
		pointerHead->surname = (char*)malloc(sizeof(char) * SIZE);
		fscanf(file, "%s", pointerHead->surname);
		while (1) {
			fscanf(file, "%c", &checker);
			if ((checker > '0' && checker < '9') || (checker > 'A' && checker < 'z') || (checker == '-')) {
				fseek(file, -1, SEEK_CUR);
				break;
			}
		}
		if (checker != '-') {
			fscanf(file, "%s", &pointerHead->unon.date);
		}
		else {
			pointerHead->flg = 2;
			fseek(file, 1, SEEK_CUR);
		}
		while (1) {
			fscanf(file, "%c", &checker);
			if ((checker > '0' && checker < '9') || (checker > 'A' && checker < 'z') || (checker == '-')) {
				fseek(file, -1, SEEK_CUR);
				break;
			}
		}
		if (checker != '-') {
			fscanf(file, "%d", &pointerHead->unon.averageScore);

		}
		else
			pointerHead->flg = 1;
		for (;;) {
			fscanf(file, "%c", &checker);
			if (checker == '\n') {
				break;
			}
		}
		fscanf(file, "%c", &checker);
		pointerBuffer = pointerHead;
	}
	/////////////////////////////////////////////////////////////////

	while (!feof(file)) {
		pointerPrevious = (students*)malloc(sizeof(students) * 1);
		while (1) {
			fscanf(file, "%c", &checker);
			if (checker >= '0' && checker <= '9')
			{
				fseek(file, -1, SEEK_CUR);
				break;
			}
		}
		fscanf(file, "%d", &pointerPrevious->studentBookNumber);
		while (1) {
			fscanf(file, "%c", &checker);
			if ((checker > '0' && checker < '9') || (checker > 'A' && checker < 'z'))
			{
				fseek(file, -1, SEEK_CUR);
				break;
			}
		}
		pointerPrevious->surname = (char*)malloc(sizeof(char) * SIZE);
		fscanf(file, "%s", pointerPrevious->surname);
		while (1) {
			fscanf(file, "%c", &checker);
			if ((checker > '0' && checker < '9') || (checker > 'A' && checker < 'z') || (checker == '-')) {
				fseek(file, -1, SEEK_CUR);
				break;
			}
		}
		if (checker != '-') {
			fscanf(file, "%s", &pointerPrevious->unon.date);
		}
		else {
			pointerPrevious->flg = 2;
			fseek(file, 1, SEEK_CUR);
		}
		while (1) {
			fscanf(file, "%c", &checker);
			if ((checker > '0' && checker < '9') || (checker > 'A' && checker < 'z') || (checker == '-')) {
				fseek(file, -1, SEEK_CUR);
				break;
			}
		}
		if (checker != '-') {
			fscanf(file, "%d", &pointerPrevious->unon.averageScore);

		}
		else
			pointerPrevious->flg = 1;
		for (;;) {
			fscanf(file, "%c", &checker);
			if (checker == '\n') {
				break;
			}
		}
		fscanf(file, "%c", &checker);
		pointerBuffer->pointerNext = pointerPrevious;
		pointerBuffer = pointerPrevious;
		pointerPrevious = nullptr;
	}
	pointerBuffer->pointerNext = nullptr;
	*pointerTail = pointerBuffer;
	fclose(file);
	return pointerHead;

}

void creatorTextFile(students* pointerHead) //функция создания текствого файла
{
	char* name;
	name = (char*)malloc(sizeof(char) * 30);
	FILE* file;
	system("CLS");
	printf("Write the name of a new file:\n");
	rewind(stdin);
	fgets(name, 30, stdin);
	for (int i = 0; ; i++) {
		if (name[i] == '\n') {
			name[i++] = '.';
			name[i++] = 't';
			name[i++] = 'x';
			name[i++] = 't';
			name[i++] = '\0';
			name = (char*)realloc(name, sizeof(char) * i);
			break;
		}
	}
	file = fopen(name, "w+t");
	recursTextFile(pointerHead, file);
	fclose(file);
}

void recursTextFile(students* pointerHead, FILE* file) //функция записи в текстовый файл всего стека кроме головы
{
	students* pointerPrevious;
	pointerPrevious = pointerHead;
	while (1)
	{
		system("CLS");
		fprintf(file, " %d %s ", pointerPrevious->studentBookNumber, pointerPrevious->surname);
		if (pointerPrevious->flg == 1) {
			fprintf(file, " %s ", pointerPrevious->unon.date);
			fprintf(file, " - \n");
		}
		else if (pointerPrevious->flg == 2) {
			fprintf(file, " - ");
			fprintf(file, " %d \n", pointerPrevious->unon.averageScore);
		}

		if (pointerPrevious->pointerNext == nullptr) break;
		pointerPrevious = pointerPrevious->pointerNext;
	}

	printf("Saving succesful\n");
}

void recursHeadTextFile(students* pointerHead, FILE* file) //функция сохранения головы стека в текстовый файл
{
	students* pointerPrevious;
	pointerPrevious = pointerHead;
	system("CLS");
	fprintf(file, " %d %s ", pointerPrevious->studentBookNumber, pointerPrevious->surname);
	if (pointerPrevious->flg == 1) {
		fprintf(file, " %s ", pointerPrevious->unon.date);
		fprintf(file, " - \n");
	}
	else if (pointerPrevious->flg == 2) {
		fprintf(file, " - ");
		fprintf(file, " %d \n", pointerPrevious->unon.averageScore);
	}

	printf("Saving succesful\n");
	continuationCondition();
}

void creatorBinFile(students* pointerHead) //функция создания бинарного файла
{
	char* name;
	name = (char*)malloc(sizeof(char) * 30);
	FILE* file;
	system("CLS");
	printf("Write the name of a new file:\n");
	rewind(stdin);
	fgets(name, 30, stdin);
	for (int i = 0; ; i++) {
		if (name[i] == '\n') {
			name[i++] = '.';
			name[i++] = 'b';
			name[i++] = 'i';
			name[i++] = 'n';
			name[i++] = '\0';
			name = (char*)realloc(name, sizeof(char) * i);
			break;
		}
	}
	file = fopen(name, "w+b");
	recursBINFile(pointerHead, file);
	fclose(file);
}

void recursBINFile(students* pointerHead, FILE* file) //функция записи в бинарный файл
{
	students* pointerPrevious;
	pointerPrevious = pointerHead;
	while (1)
	{
		fwrite(&pointerPrevious->flg, sizeof(int), 1, file);
		fwrite(&pointerPrevious->studentBookNumber, sizeof(int), 1, file);
		int counter = 0;
		char symbol;
		while (1)
		{
			symbol = pointerPrevious->surname[counter];
			fwrite(&symbol, sizeof(char), 1, file);
			if (symbol == '\0') break;
			counter++;
		}
		if (pointerPrevious->flg == 1)
			fwrite(pointerPrevious->unon.date, sizeof(char), SIZE_DATE, file);
		else
			fwrite(&pointerPrevious->unon.averageScore, sizeof(int), 1, file);

		if (pointerPrevious->pointerNext == nullptr) break;
		pointerPrevious = pointerPrevious->pointerNext;
	}
}

students* downloadBIN(students* pointerHead, students** pointerTail) //функция загрузки из бинарного файла
{
	pointerHead = nullptr;
	char* name;
	students* pointerPrevious = nullptr, * pointerBuffer;
	char checker;
	name = (char*)malloc(sizeof(char) * 30);
	FILE* file;
	system("CLS");
	printf("Write the name file, what you want to find:\n");
	rewind(stdin);
	fgets(name, 30, stdin);
	for (int i = 0; ; i++) {
		if (name[i] == '\n') {
			name[i++] = '.';
			name[i++] = 'b';
			name[i++] = 'i';
			name[i++] = 'n';
			name[i++] = '\0';
			name = (char*)realloc(name, sizeof(char) * i);
			break;
		}
	}
	file = fopen(name, "r+b");
	if (file == nullptr) {
		printf("File not found... Check input.\n Return to the menu...");
		continuationCondition();
		return pointerHead;
	}
	system("CLS");
	printf("Reading information from a file...");
	rewind(file);

	//////////////////////////////////
	{
		pointerHead = (students*)malloc(sizeof(students) * 1);
		fread(&pointerHead->flg, sizeof(int), 1, file);
		fread(&pointerHead->studentBookNumber, sizeof(int), 1, file);
		pointerHead->surname = (char*)malloc(sizeof(char) * SIZE);
		int counter = 0;
		char symbol;
		while (1)
		{
			fread(&symbol, sizeof(char), 1, file);
			pointerHead->surname[counter] = symbol;
			if (symbol == '\0')break;
			counter++;
		}
		if (pointerHead->flg == 1) {
			fread(&pointerHead->unon.date, sizeof(char), SIZE_DATE, file);
		}
		else {
			fread(&pointerHead->unon.averageScore, sizeof(int), 1, file);
		}
		pointerBuffer = pointerHead;
	}
	////////////////////////////////////

	do
	{
		pointerPrevious = (students*)malloc(sizeof(students) * 1);
		fread(&pointerPrevious->flg, sizeof(int), 1, file);
		fread(&pointerPrevious->studentBookNumber, sizeof(int), 1, file);
		pointerPrevious->surname = (char*)malloc(sizeof(char) * SIZE);
		int counter = 0;
		char symbol;
		while (1)
		{
			fread(&symbol, sizeof(char), 1, file);
			pointerPrevious->surname[counter] = symbol;
			if (symbol == '\0')break;
			counter++;
		}
		if (pointerPrevious->flg == 1) {
			fread(&pointerPrevious->unon.date, sizeof(char), SIZE_DATE, file);
		}
		else {
			fread(&pointerPrevious->unon.averageScore, sizeof(int), 1, file);
		}
		pointerPrevious->pointerNext = pointerPrevious;
		pointerBuffer->pointerNext = pointerPrevious;
		pointerBuffer = pointerPrevious;
		pointerPrevious = nullptr;
		fread(&symbol, sizeof(char), 1, file);
		if (feof(file))
		{
			break;
		}
		else
		{
			fseek(file, -1, SEEK_CUR);
		}
	} while (!feof(file));
	pointerBuffer->pointerNext = nullptr;
	*pointerTail = pointerBuffer;
	fclose(file);
	return pointerHead;
}

students* findStructForDelete(students* pointerHead, students** pointerTail) //функция, которая находит, что удалить
{
	if (pointerHead == nullptr)
	{
		system("CLS");
		printf("You don't have a database. First create it.");
		continuationCondition();
		return pointerHead;
	}
	int choose = 0;
	students* pointerPrevious;
	pointerPrevious = pointerHead;
	choose = chooseParametr();
	switch (choose)
	{
	case 1:			//по номеру зачётки
	{
		int  numb = 0;
		printf("Enter the number of student's book you want to find:\n");
		numb = checkInput(numb);
		system("CLS");
		printf_s("=========================================================================================\n\t\tYour database\n");
		printf_s("=========================================================================================\n||Student's book number ||\tSurname\t    ||Date of expulsion ||     Average score   ||");
		while (pointerPrevious != nullptr)
		{
			if (pointerPrevious->studentBookNumber == numb) {
				printf("\n||----------------------||------------------||------------------||---------------------||\n");
				printf_s("||%12d\t        ||%12s      ||", pointerPrevious->studentBookNumber, pointerPrevious->surname);
				if (pointerPrevious->flg == 1) {
					printf("    %s    ||", pointerPrevious->unon.date);
					printf("\t    -          ||");
				}
				else if (pointerPrevious->flg == 2)
				{
					printf("        -         ||");
					printf("\t%6d\t       ||", pointerPrevious->unon.averageScore);

				}
				printf("\nThis the element, which you want to delete\n");
				continuationCondition();
				pointerHead = deleteStruct(pointerPrevious, pointerHead, pointerTail);
				return pointerHead;
			}
			pointerPrevious = pointerPrevious->pointerNext;
		}
		continuationCondition();
		break;
	}
	case 2:			//по фамилии
	{
		printf("Enter the surname of student:\n");
		char* findName;
		int numb = 0;
		findName = (char*)malloc(sizeof(char) * 100);
		rewind(stdin);
		fgets(findName, 255, stdin);
		for (int j = 0; ; j++) {
			if (findName[j] == '\n') {
				findName[j] = '\0';
				break;
			}
		}
		system("CLS");
		printf_s("=========================================================================================\n\t\tYour database\n");
		printf_s("=========================================================================================\n||Student's book number ||\tSurname\t    ||Date of expulsion ||     Average score   ||");
		for (; pointerPrevious != nullptr;)
		{
			if (strcmp(pointerPrevious->surname, findName) == 0)
			{
				printf("\n||----------------------||------------------||------------------||---------------------||\n");
				printf_s("||%12d\t        ||%12s      ||", pointerPrevious->studentBookNumber, pointerPrevious->surname);
				if (pointerPrevious->flg == 1) {
					printf("    %s    ||", pointerPrevious->unon.date);
					printf("\t    -          ||");
				}
				else if (pointerPrevious->flg == 2) {
					printf("        -         ||");
					printf("\t%6d\t       ||", pointerPrevious->unon.averageScore);
				}

				printf("\nThis the element, which you want to delete\n");
				continuationCondition();
				pointerHead = deleteStruct(pointerPrevious, pointerHead, pointerTail);
				return pointerHead;
			}
			pointerPrevious = pointerPrevious->pointerNext;
		}
		continuationCondition();
		break;
	}
	case 3:			//по дате отчсления
	{
		char findDate[SIZE_DATE];
		do {
			system("CLS");
			printf("Enter the expulsion date, which you want to find in format yyyy.mm.dd (Example: 2003.12.04):\n");
			int numbString = 0, trigger = 0, j;
			int numb = 0;
			rewind(stdin);
			fflush(stdin);
			gets_s(findDate);
			if (strlen(findDate) != SIZE_DATE - 1) {
				trigger = 1;
			}
			for (j = 0; j < 4; j++) {
				if (findDate[j] > '9' || findDate[j] < '0') {
					trigger = 1;
				}
			}
			for (j++; j < 7; j++) {
				if (findDate[j] < '9' || findDate[j] > '0') {
					numbString = (findDate[j] - '0') + 10 * numbString;
				}
			}
			if (numbString > 12 || numbString < 0)
				trigger = 1;
			numbString = 0;
			for (j++; j < 10; j++) {
				if (findDate[j] < '9' || findDate[j] > '0') {
					numbString = (findDate[j] - '0') + 10 * numbString;
				}
			}
			if (numbString > 31 || numbString < 0)
				trigger = 1;
			if (trigger == 1) {
				printf("Wrong input. Try again.");
				continuationCondition();
				continue;
			}
		} while (1 < 0);
		system("CLS");
		printf_s("=========================================================================================\n\t\tYour database\n");
		printf_s("=========================================================================================\n||Student's book number ||\tSurname\t    ||Date of expulsion ||     Average score   ||");
		for (; pointerPrevious != nullptr;) {
			if (strcmp(pointerPrevious->unon.date, findDate) == 0) {
				printf("\n||----------------------||------------------||------------------||---------------------||\n");
				printf_s("||%12d\t        ||%12s      ||", pointerPrevious->studentBookNumber, pointerPrevious->surname);
				if (pointerPrevious->flg == 1) {
					printf("    %s    ||", pointerPrevious->unon.date);
					printf("\t    -          ||");
				}
				else if (pointerPrevious->flg == 2) {
					printf("        -         ||");
					printf("\t%6d\t       ||", pointerPrevious->unon.averageScore);
				}

				printf("\nThis the element, which you want to delete\n");
				continuationCondition();
				pointerHead = deleteStruct(pointerPrevious, pointerHead, pointerTail);
				return pointerHead;
			}
			pointerPrevious = pointerPrevious->pointerNext;
		}
		continuationCondition();
		break;
	}
	case 4:			//по среднему баллу
	{
		int numb = 0;
		printf("Enter the average score:\n");
		numb = checkInput(numb);
		system("CLS");
		printf_s("=========================================================================================\n\t\tYour database\n");
		printf_s("=========================================================================================\n||Student's book number ||\tSurname\t    ||Date of expulsion ||     Average score   ||");
		for (; pointerPrevious != nullptr;) {
			if (pointerPrevious->unon.averageScore == numb) {
				printf("\n||----------------------||------------------||------------------||---------------------||\n");
				printf_s("||%12d\t        ||%12s      ||", pointerPrevious->studentBookNumber, pointerPrevious->surname);
				if (pointerPrevious->flg == 1) {
					printf("    %s    ||", pointerPrevious->unon.date);
					printf("\t    -          ||");
				}
				else if (pointerPrevious->flg == 2) {
					printf("        -         ||");
					printf("\t%6d\t       ||", pointerPrevious->unon.averageScore);
				}

				printf("\nThis the element, which you want to delete\n");
				continuationCondition();
				pointerHead = deleteStruct(pointerPrevious, pointerHead, pointerTail);
				return pointerHead;
			}
			pointerPrevious = pointerPrevious->pointerNext;
		}
		continuationCondition();
		break;
	}
	}
	return pointerHead;
}

students* deleteStruct(students* pointerPrevious, students* pointerHead, students** pointerTail) // функция удаления
{
	int number = 0;
	students* pointerDel = nullptr;
	students* pointerNotDel = nullptr;
	printf_s("Are you sure?\n1.Yes\n2.No\n");
	do {
		number = checkInput(number);
		if (number > 3 || number < 0) {
			printf("Incorrect input. Try again.");
			continuationCondition();
			system("CLS");
			printf_s("Are you sure?\n1.Yes\n2.No\n");
			continue;
		}
	} while (1 < 0);
	if (number == 2)
		return pointerHead;
	pointerNotDel = pointerHead;
	if (pointerNotDel == pointerPrevious) //если нужно удалить первый элемент
	{
		if (pointerPrevious->pointerNext != nullptr) //если есть больше одного
		{
			pointerHead = pointerPrevious->pointerNext;
			free(pointerNotDel);
			return pointerHead;
		}
		else //если есть всего один элемент
		{

			free(pointerNotDel);
			pointerHead = nullptr;
			return pointerHead;
			*pointerTail = nullptr;
		}
	}
	else //если нужно удалить не первый элемент
	{
		while (pointerNotDel->pointerNext != pointerPrevious)
		{
			pointerNotDel = pointerNotDel->pointerNext;
		}
		pointerDel = pointerNotDel->pointerNext;
		pointerNotDel->pointerNext = pointerDel->pointerNext;
		while (1)
		{
			if (pointerNotDel->pointerNext == nullptr)
			{
				*pointerTail = pointerNotDel;
				break;
			}
			pointerNotDel = pointerNotDel->pointerNext;
		}
		free(pointerDel);
		return pointerHead;
	}
}
