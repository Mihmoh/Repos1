#include <stdio.h>
#include <conio.h>
#include <string.h>

struct autoservice
{
	int reg;
	char mark[20];
	int mileage;
	char master[30];
	int sum;
};


int main()
{
	struct autoservice list[100];
	int i, j, records, k;

	list[0].reg = 1;		//инициализация некоторых элементов структуры
	strcpy(list[0].mark, "Opel");
	list[0].mileage = 15000;
	strcpy(list[0].master, "Peter");
	list[0].sum = 60;

	list[1].reg = 2;
	strcpy(list[1].mark, "Toyota");
	list[1].mileage = 20000;
	strcpy(list[1].master, "Peter");
	list[1].sum = 100;

	list[2].reg = 3;
	strcpy(list[2].mark, "Renault");
	list[2].mileage = 18000;
	strcpy(list[2].master, "Alex");
	list[2].sum = 50;

	list[3].reg = 4;
	strcpy(list[3].mark, "Mazda");
	list[3].mileage = 12000;
	strcpy(list[3].master, "Mike");
	list[3].sum = 120;

	for (i = 4; i < 10; i++)			//структура по умолчанию
	{
		list[i].reg = i+1;
		strcpy(list[i].mark, "default");
		list[i].mileage = 17600;
		strcpy(list[i].master, "default");
		list[i].sum = 50;
	}

	records = 10;
	printf("Welcome to the autoservice interface.\n");

	do
	{
		
		printf("\nList of possible operations:\n1 - show current structure;\n2 - add new elements;\n3 - change elements;\n4 - search for specific elements;\n5 - delete element\n0 - exit.\n");
		scanf("%d", &i);
		//================================================
		if (i == 1)
		{
			for (i = 0; i < records; i++)			//проосмотр структуры
			{
				printf("Registration number: %d \n", list[i].reg);
				printf("Car's mark:");
				puts(list[i].mark);
				printf("Mileage: %d km\n", list[i].mileage);
				printf("Master's name: ");
				puts(list[i].master);
				printf("Repair price %d $\n", list[i].sum);
				printf("==================================\n");
			}
		}
		//=======================================================
		if (i == 2)
		{
			do				//добавление новых элементов
			{
				printf("Registration number: %d\n", records + 1);
				list[records].reg = records + 1;

				puts("Input mark: ");
				fflush(stdin);
				gets(list[records].mark);
				gets(list[records].mark);

				puts("Input run: ");
				scanf("%d", &list[records].mileage);

				puts("Input master's name: ");
				fflush(stdin);
				gets(list[records].master);
				gets(list[records].master);

				puts("Input repair price: ");
				scanf("%d", &list[records].sum);

				records++;

				if (records == 99)
				{
					printf("Limit is reached. \n");
					break;
				}

				puts("1 - next car; 0 - stop input:");
				scanf("%d", &i);
			} while (i);
			i = 1;
		}
		//=======================================================
		if (i == 3)				//изменение структуры
		{
			do
			{
				printf("Choose registration number of element, which you want to change.\n");
				scanf("%d", &j);
				if (j < 1 || j > records)
				{
					printf("Error. Number is less than 0 or more than number of cars.\n");
					break;
				}

				printf("Registration number: %d\n", j);
				j--;
				list[j].reg = j + 1;

				puts("Input mark: ");
				fflush(stdin);
				gets(list[j].mark);
				gets(list[j].mark);

				puts("Input run: ");
				scanf("%d", &list[j].mileage);

				puts("Input master's name: ");
				fflush(stdin);
				gets(list[j].master);
				gets(list[j].master);

				puts("Input repair price: ");
				scanf("%d", &list[j].sum);

				puts("Continue changing? 1 - yes, 0 - no.");
				scanf("%d", &i);
			} while (i);
			i = 1;
		}
		//=============================================
		if (i == 4)			//поиск
		{
			do
			{
				printf("\nChoose paremeter for searching: 1 - registration number, 2 - mark, 3 - mileage, 4 - master's name, 5 - repair price.\n");
				scanf("%d", &i);

				k = 0;

				if (i == 1)				//поиск по регистрационному номеру
				{
					printf("Enter registration number:\n");
					scanf("%d", &j);
					for (i = 0; i < records; i++)
					{
						if (j == list[i].reg)
						{
							printf("Match found:\n");
							printf("Registration number: %d \n", list[i].reg);
							printf("Car's mark:");
							puts(list[i].mark);
							printf("Mileage: %d km\n", list[i].mileage);
							printf("Master's name: ");
							puts(list[i].master);
							printf("Repair price %d $\n", list[i].sum);
							printf("==================================\n");
							k++;
						}
					}
					if (k == 0)
					{
						printf("No matches found.\n");
					}
					else
					{
						printf("Total matches: %d\n", k);
					}
				}

				if (i == 3)				//поиск по пробегу
				{
					printf("Enter mileage:\n");
					scanf("%d", &j);
					for (i = 0; i < records; i++)
					{
						if (j == list[i].mileage)
						{
							printf("Match found:\n");
							printf("Registration number: %d \n", list[i].reg);
							printf("Car's mark:");
							puts(list[i].mark);
							printf("Mileage: %d km\n", list[i].mileage);
							printf("Master's name: ");
							puts(list[i].master);
							printf("Repair price %d $\n", list[i].sum);
							printf("==================================\n");
							k++;
						}
					}
					if (k == 0)
					{
						printf("No matches found.\n");
					}
					else
					{
						printf("Total matches: %d\n", k);
					}
				}

				if (i == 5)				//поиск по цене
				{
					printf("Enter repair price:\n");
					scanf("%d", &j);
					for (i = 0; i < records; i++)
					{
						if (j == list[i].sum)
						{
							printf("\nMatch found:\n");
							printf("Registration number: %d \n", list[i].reg);
							printf("Car's mark:");
							puts(list[i].mark);
							printf("Mileage: %d km\n", list[i].mileage);
							printf("Master's name: ");
							puts(list[i].master);
							printf("Repair price %d $\n", list[i].sum);
							printf("==================================\n");
							k++;
						}
					}
					if (k == 0)
					{
						printf("No matches found.\n");
					}
					else
					{
						printf("Total matches: %d\n", k);
					}
				}

				puts("Continue searching? 1 - yes, 0 - no.");
				scanf("%d", &i);
			} while (i);
			i = 1;
		}
		//==================================================
		if (i == 5)
		{
			do
			{
				printf("Choose registration number of element. which you want to delete:\n");
				scanf("%d", &j);

				if (j < 1 || j > records)
				{
					printf("Error. Number is less than 0 or more than number of cars.\n");
					break;
				}

				for (j; j < records; j++)
				{

				}
			} while (i);
			i = 1;
		}

	} while (i);

	printf("\nGoodbye.\n");
}
