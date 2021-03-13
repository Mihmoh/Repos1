#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

struct student
{
	int number;
	char* surname;
	union expulsion
	{
		char date[17];
		int average;
	};
};

void output(struct student* list, int records, int n)			//функция ввода
{
	system("cls");
	int i;
	printf("========================================================== \n");
	printf("||Number||     Surname    || Date of expulsion  ||Av.Sc.||\n");
	printf("==========================================================\n");

	for (i = 0; i < records; i++)
	{
		
		if (list[i].average > 0 && list[i].average < n)
		{

			printf("||%6d||%16s||                    ||%6d||\n", list[i].number, list[i].surname, list[i].average);
		}
		else
		{
			printf("||%6d||%16s||%20s||      ||\n", list[i].number, list[i].surname, list[i].date);
		}

	}
	printf("==========================================================\n");
}

struct student* input(struct student* list, int records, int n)			//функция ввода
{
	int i, j;
	char s[17];
	strcpy(s, "-\0");

	system("cls");

	printf("Enter number of student's book: \n");
	while (!scanf("%d", &i))
	{
		rewind(stdin);
		system("cls");
		printf("Enter number of student's book: \n");

	}
	for (j = 0; j < records; j++)
	{
		if (i == list[j].number)
		{
			printf("Such number is already taken.\n\n");
			return list;
		}
	}

	if (i<1 || i>n)
	{
		printf("That number is either too big or too small.\n\n");
		return list;
	}

	list[records].number = i;

	puts("Enter student's surname: ");
	fflush(stdin);
	list[records].surname = (char*)malloc(30 * sizeof(char));
	gets(list[records].surname);
	gets(list[records].surname);

	puts("Enter expulsion date or symbol '-' if not expelled yet: ");
	fflush(stdin);
	gets(list[records].date);

	if (list[records].date[0] == s[0])
	{
		printf("Enter average score from 0 to 10: \n");	

		while (list[records].average > 10 || list[records].average < 0)
		{
			while (!scanf("%d", &list[records].average))
			{
				rewind(stdin);
				printf("Enter average score from 0 to 10: \n");
			}
			printf("Enter average score from 0 to 10: \n");
		}
	}

	return list;
}

void search(struct student* list, int records, int n)			//функция поиска
{
	int j, i = 1, k, m, l;
	char s[30];
	do
	{
		system("cls");

		printf("\nChoose paremeter for searching: \n1 - student's book number, \n2 - surname, \n3 - expulsion date, \n4 - average score\n");
		while (!scanf("%d", &i))
		{
			rewind(stdin);
			system("cls");
			printf("\nChoose paremeter for searching: \n1 - student's book number, \n2 - surname, \n3 - expulsion date, \n4 - average score\n");

		}
		k = 0;

		if (i == 1)			//по номеру зачётки
		{
			printf("Enter student's book number\n");
			while (!scanf("%d", &j))
			{
				rewind(stdin);
				system("cls");
				printf("Enter student's book number\n");

			}
			printf("========================================================== \n");
			printf("||Number||     Surname    || Date of expulsion  ||Av.Sc.||\n");
			printf("==========================================================\n");
			for (i = 0; i < records; i++)
			{
				if (j == list[i].number)
				{
					if (list[i].average > 0 && list[i].average < n)
					{

						printf("||%6d||%16s||                    ||%6d||\n", list[i].number, list[i].surname, list[i].average);
					}
					else
					{
						printf("||%6d||%16s||%20s||      ||\n", list[i].number, list[i].surname, list[i].date);
					}
					k++;
				}
			}
			printf("==========================================================\n\n");
			if (k == 0)
			{
				printf("No matches found.\n\n");
			}
			else
			{
				printf("Total matches: %d\n\n", k);
			}

		}

		if (i == 2)			//по фамилии
		{
			m = 0;
			printf("Enter surname of elements, which you want to find:\n");
			fflush(stdin);
			gets(s);
			gets(s);

			printf("========================================================== \n");
			printf("||Number||     Surname    || Date of expulsion  ||Av.Sc.||\n");
			printf("==========================================================\n");

			for (i = 0; i < records; i++)
			{
				j = 0;
				k = 0;
				l = 0;
				while (s[j] == list[i].surname[j] && s[j] != '\0' && list[i].surname[j] != '\0')
				{
					k++;
					j++;
				}
				j = 0;
				while (list[i].surname[j] != '\0')
				{
					l++;
					j++;
				}
				if (k == l)
				{
					if (list[i].average > 0 && list[i].average < n)
					{

						printf("||%6d||%16s||                    ||%6d||\n", list[i].number, list[i].surname, list[i].average);
					}
					else
					{
						printf("||%6d||%16s||%20s||      ||\n", list[i].number, list[i].surname, list[i].date);
					}
					m++;
				}
			}

			printf("==========================================================\n\n");

			if (m == 0)
			{
				printf("No matches found.\n\n");
			}
			else
			{
				printf("Total matches: %d\n\n", m);
			}
		}

		if (i == 3)			//по дате отчисления
		{
			m = 0;
			printf("Enter expulsion date of elements, which you want to find:\n");
			fflush(stdin);
			gets(s);
			gets(s);

			printf("========================================================== \n");
			printf("||Number||     Surname    || Date of expulsion  ||Av.Sc.||\n");
			printf("==========================================================\n");

			for (i = 0; i < records; i++)
			{
				j = 0;
				k = 0;
				l = 0;
				while (s[j] == list[i].date[j] && s[j] != '\0' && list[i].date[j] != '\0')
				{
					k++;
					j++;
				}
				j = 0;
				while (list[i].date[j] != '\0')
				{
					l++;
					j++;
				}
				if (k == l)
				{
					if (list[i].average > 0 && list[i].average < n)
					{

						printf("||%6d||%16s||                    ||%6d||\n", list[i].number, list[i].surname, list[i].average);
					}
					else
					{
						printf("||%6d||%16s||%20s||      ||\n", list[i].number, list[i].surname, list[i].date);
					}
					m++;
				}
			}

			printf("==========================================================\n\n");

			if (m == 0)
			{
				printf("No matches found.\n\n");
			}
			else
			{
				printf("Total matches: %d\n\n", m);
			}
		}

		if (i == 4)			//по среднему баллу
		{
			printf("Enter average score\n");
			while (!scanf("%d", &j))
			{
				rewind(stdin);
				system("cls");
				printf("Enter average score\n");

			}
			printf("========================================================== \n");
			printf("||Number||     Surname    || Date of expulsion  ||Av.Sc.||\n");
			printf("==========================================================\n");
			for (i = 0; i < records; i++)
			{
				if (j == list[i].average)
				{
					if (list[i].average > 0 && list[i].average < n)
					{

						printf("||%6d||%16s||                    ||%6d||\n", list[i].number, list[i].surname, list[i].average);
					}
					else
					{
						printf("||%6d||%16s||%20s||      ||\n", list[i].number, list[i].surname, list[i].date);
					}
					k++;
				}
			}
			printf("==========================================================\n\n");
			if (k == 0)
			{
				printf("No matches found.\n\n");
			}
			else
			{
				printf("Total matches: %d\n\n", k);
			}
		}

		puts("Continue searching? 1 - yes, 0 - no.");
		while (!scanf("%d", &i))
		{
			rewind(stdin);
			system("cls");
			puts("Continue searching? 1 - yes, 0 - no.");
		}
	} while (i);
}



void maxscore(struct student* list, int records)
{
	system("cls");
	int i, max = 0;
	for (i = 0; i < records; i++)
	{
		if (list[i].average > max && list[i].average < 11)
		{
			max = list[i].average;
		}
	}

	printf("========================================================== \n");
	printf("||Number||     Surname    || Date of expulsion  ||Av.Sc.||\n");
	printf("==========================================================\n");

	for (i = 0; i < records; i++)
	{
		if (list[i].average == max)
		{
			if (list[i].average > 0 && list[i].average < 11)
			{

				printf("||%6d||%16s||                    ||%6d||\n", list[i].number, list[i].surname, list[i].average);
			}
			else
			{
				printf("||%6d||%16s||%20s||      ||\n", list[i].number, list[i].surname, list[i].date);
			}
		}
	}
	printf("==========================================================\n");
}



int main()
{
	void output(struct student* list, int records, int n);
	struct student* input(struct student* list, int records, int n);
	void search(struct student* list, int records, int n);
	void maxscore(struct student* list, int records);
	struct student* list;
	int i, j, records, k, l, n;
	char s[100];
	n = 100;

	do				//изменение выделяемой памяти
	{
		printf("Do you want to change number of possible elements? 1 - yes, 0 - no:\n");
		while (!scanf("%d", &i))
		{
			rewind(stdin);
			printf("1 - yes, 0 - no\n");
		}
		if (i == 0)
		{
			break;
		}
		printf("Enter number of elements. 10 is minimum:\n");
		while (!scanf("%d", &n))
		{
			rewind(stdin);
			printf("Enter number of elements. 10 is minimum:\n");
		}
		if (n > 9)
		{
			i = 0;
		}
		else
		{
			i = 1;
			printf("Entered number which is less than 10.\n");
		}
	} while (i);


	if (!(list = (struct student*)malloc(n * sizeof(struct student))))
	{
		printf("Memory has not been allocated\n");
		return 0;
	}

	records = 10;


	list[0].number = 1;		//инициализация некоторых элементов структуры
	list[0].surname = (char*)malloc(30 * sizeof(char));
	strcpy(list[0].surname, "Ivanov\0");
	list[0].average = 7;

	list[1].number = 2;
	list[1].surname = (char*)malloc(30 * sizeof(char));
	strcpy(list[1].surname, "Smirnov\0");
	list[1].average = 6;

	list[2].number = 3;
	list[2].surname = (char*)malloc(30 * sizeof(char));
	strcpy(list[2].surname, "Sobolev\0");
	list[2].average = 7;

	for (i = 3; i < 10; i++)
	{
		list[i].number = i + 1;
		list[i].surname = (char*)malloc(30 * sizeof(char));
		strcpy(list[i].surname, "default\0");
		strcpy(list[i].date, "01.01.2021\0");
	}

	do
	{

		printf("\nList of possible operations:\n1 - show current structure;\n2 - add new elements;\n3 - search for specific elements;\n4 - delete element\n5 - show students with the biggest average score\n6 - delete exposed students\n0 - exit.\n\n");
		while (!scanf("%d", &i))
		{
			rewind(stdin);
			system("cls");
			printf("\nList of possible operations:\n1 - show current structure;\n2 - add new elements;\n3 - search for specific elements;\n4 - delete element\n5 - show students with the biggest average score\n6 - delete exposed students\n0 - exit.\n\n");
		}


		if (i == 1)
		{
			output(list, records, n);
		}

		if (i == 2)
		{
			do
			{
				list = input(list, records, n);
				printf("1 - next student, 0 - stop input\n");
				while (!scanf("%d", &i))
				{
					rewind(stdin);
					system("cls");
					printf("1 - next student, 0 - stop input\n");
				}
				if (list[records].number < 1 || list[records].number < 1)
				{
					records--;
				}
				records++;
			} while (i);
			i = 100;
		}

		if (i == 3)			//поиск
		{
			search(list, records, n);
		}

		if (i == 4)			//удаление
		{

			do
			{
				system("cls");
				printf("\nChoose parameter by which elements will be deleted:\n1 - student's book number,\n2 - surname,\n3 - expolsion date,\n4 - average score\n");
				while (!scanf("%d", &i))
				{
					rewind(stdin);
					system("cls");
					printf("\nChoose parameter by which elements will be deleted:\n1 - student's book number,\n2 - surname,\n3 - expolsion date,\n4 - average score\n");
				}

				if (i == 1)				//по зачётке
				{
					printf("Enter student's book number of elements, which you want to delete:\n");
					while (!scanf("%d", &l))
					{
						rewind(stdin);
						system("cls");
						printf("Enter student's book number of elements, which you want to delete:\n");
					}

					for (i = 0; i < records; i++)
					{
						if (l == list[i].number)
						{
							records--;
							j = i;
							for (j; j < records; j++)
							{
								list[j].number = list[j + 1].number;
								k = 0;
								while (list[j + 1].surname[k] != '\0' || list[j].surname[k] != '\0')
								{
									list[j].surname[k] = list[j + 1].surname[k];
									k++;
								}
								k = 0;
								while (list[j + 1].date[k] != '\0' || list[j].date[k] != '\0')
								{
									list[j].date[k] = list[j + 1].date[k];
									k++;
								}
								list[j].average = list[j + 1].average;
								i--;
							}
						}
					}
					i = 101;
				}

				if (i == 4)				//по среднему баллу
				{
					printf("Enter average score of elements, which you want to delete:\n");
					while (!scanf("%d", &l))
					{
						rewind(stdin);
						system("cls");
						printf("Enter average score of elements, which you want to delete:\n");
					}

					for (i = 0; i < records; i++)
					{
						if (l == list[i].average)
						{
							records--;
							j = i;
							for (j; j < records; j++)
							{
								list[j].number = list[j + 1].number;
								k = 0;
								while (list[j + 1].surname[k] != '\0' || list[j].surname[k] != '\0')
								{
									list[j].surname[k] = list[j + 1].surname[k];
									k++;
								}
								k = 0;
								while (list[j + 1].date[k] != '\0' || list[j].date[k] != '\0')
								{
									list[j].date[k] = list[j + 1].date[k];
									k++;
								}
								list[j].average = list[j + 1].average;
								i--;
							}
						}
					}
					i = 101;
				}

				if (i == 2)				//по фамилии
				{
					printf("Enter surname of elements, which you want to delete:\n");
					fflush(stdin);
					gets(s);
					gets(s);

					for (i = 0; i < records; i++)
					{
						j = 0;
						k = 0;
						l = 0;
						while (s[j] == list[i].surname[j] && s[j] != '\0' && list[i].surname[j] != '\0')
						{
							k++;
							j++;
						}
						j = 0;
						while (list[i].surname[j] != '\0')
						{
							l++;
							j++;
						}
						if (k == l)
						{
							records--;
							j = i;
							i--;
							for (j; j < records; j++)
							{
								list[j].number = list[j + 1].number;
								k = 0;
								while (list[j + 1].surname[k] != '\0' || list[j].surname[k] != '\0')
								{
									list[j].surname[k] = list[j + 1].surname[k];
									k++;
								}
								k = 0;
								while (list[j + 1].date[k] != '\0' || list[j].date[k] != '\0')
								{
									list[j].date[k] = list[j + 1].date[k];
									k++;
								}
								list[j].average = list[j + 1].average;
							}
						}
					}
					i = 101;
				}

				if (i == 3)				//по дате отчисления
				{
					printf("Enter date of expulsion of elements, which you want to delete:\n");
					fflush(stdin);
					gets(s);
					gets(s);

					for (i = 0; i < records; i++)
					{
						j = 0;
						k = 0;
						l = 0;
						while (s[j] == list[i].date[j] && s[j] != '\0' && list[i].date[j] != '\0')
						{
							k++;
							j++;
						}
						j = 0;
						while (list[i].date[j] != '\0')
						{
							l++;
							j++;
						}
						if (k == l)
						{
							records--;
							j = i;
							i--;
							for (j; j < records; j++)
							{
								list[j].number = list[j + 1].number;
								k = 0;
								while (list[j + 1].surname[k] != '\0' || list[j].surname[k] != '\0')
								{
									list[j].surname[k] = list[j + 1].surname[k];
									k++;
								}
								k = 0;
								while (list[j + 1].date[k] != '\0' || list[j].date[k] != '\0')
								{
									list[j].date[k] = list[j + 1].date[k];
									k++;
								}
								list[j].average = list[j + 1].average;
							}
						}
					}

				}

				puts("Continue deleting? 1 - yes, 0 - no.");
				while (!scanf("%d", &i))
				{
					rewind(stdin);
					system("cls");
					puts("Continue deleting? 1 - yes, 0 - no.");
				}
			} while (i);
			i = 1;
		}

		if (i == 5)				//нахождение студентов с максимальным баллом
		{
			maxscore(list, records);
		}

		if (i == 6)
		{
			system("cls");
			for (i = 0; i < records; i++)
			{
				strcpy(s, "-\0");
				if (list[i].average > 10 || list[i].average < 0)
				{
					records--;
					j = i;
					for (j; j < records; j++)
					{
						list[j].number = list[j + 1].number;
						k = 0;
						while (list[j + 1].surname[k] != '\0' || list[j].surname[k] != '\0')
						{
							list[j].surname[k] = list[j + 1].surname[k];
							k++;
						}
						k = 0;
						while (list[j + 1].date[k] != '\0' || list[j].date[k] != '\0')
						{
							list[j].date[k] = list[j + 1].date[k];
							k++;
						}
						list[j].average = list[j + 1].average;
					}
					i--;
				}
			}
			i = 101;
		}


	} while (i);


	free(list);
}
