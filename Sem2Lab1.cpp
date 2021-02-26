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
	int i, j, records, k, l, m, p;
	char s[100];

	list[0].reg = 1;		//инициализация некоторых элементов структуры
	strcpy(list[0].mark, "opel\0");
	list[0].mileage = 15000;
	strcpy(list[0].master, "Peter\0");
	list[0].sum = 60;

	list[1].reg = 2;
	strcpy(list[1].mark, "toyota\0");
	list[1].mileage = 20000;
	strcpy(list[1].master, "Peter\0");
	list[1].sum = 100;

	list[2].reg = 3;
	strcpy(list[2].mark, "renault\0");
	list[2].mileage = 18000;
	strcpy(list[2].master, "Alex\0");
	list[2].sum = 50;

	list[3].reg = 4;
	strcpy(list[3].mark, "mazda\0");
	list[3].mileage = 12000;
	strcpy(list[3].master, "Mike\0");
	list[3].sum = 120;

	for (i = 4; i < 10; i++)			//структура по умолчанию
	{
		list[i].reg = i+1;
		strcpy(list[i].mark, "default\0");
		list[i].mileage = 17600;
		strcpy(list[i].master, "default\0");
		list[i].sum = 50;
	}

	records = 10;
	printf("Welcome to the autoservice interface.\n");

	do
	{
		
		printf("\nList of possible operations:\n1 - show current structure;\n2 - add new elements;\n3 - change elements;\n4 - search for specific elements;\n5 - delete element\n6 - sort the structure\n0 - exit.\n");
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
			continue;
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
				printf("\nChoose paremeter for searching: \n1 - registration number, \n2 - mark, \n3 - mileage, \n4 - master's name, \n5 - repair price,\n6 - partial match search by mark,\n7 - partial match search by master\n");
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

				if (i == 2)			//поиск по марке
				{
					m = 0;
					printf("Enter mark of elements, which you want to find:\n");
					fflush(stdin);
					gets(s);
					gets(s);

					for (i = 0; i < records; i++)
					{
						j = 0;
						k = 0;
						l = 0;
						while (s[j] == list[i].mark[j] && s[j] != '\0' && list[i].mark[j] != '\0')
						{
							k++;
							j++;
						}
						j = 0;
						while (list[i].mark[j] != '\0')
						{
							l++;
							j++;
						}
						if (k == l)
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
							m++;
						}
					}

					if (m == 0)
					{
						printf("No matches found.\n");
					}
					else
					{
						printf("Total matches: %d\n", m);
					}
				}

				if (i == 4)			//поиск по марке
				{
					m = 0;
					printf("Enter master of elements, which you want to find:\n");
					fflush(stdin);
					gets(s);
					gets(s);

					for (i = 0; i < records; i++)
					{
						j = 0;
						k = 0;
						l = 0;
						while (s[j] == list[i].master[j] && s[j] != '\0' && list[i].master[j] != '\0')
						{
							k++;
							j++;
						}
						j = 0;
						while (list[i].master[j] != '\0')
						{
							l++;
							j++;
						}
						if (k == l)
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
							m++;
						}
					}

					if (m == 0)
					{
						printf("No matches found.\n");
					}
					else
					{
						printf("Total matches: %d\n", m);
					}
				}

				if (i == 6)			//марка по частичному совпадению
				{
					m = 0;		//m - количество совпадений
					printf("Enter mark of elements, which you want to find:\n");
					fflush(stdin);
					gets(s);
					gets(s);

					j = 0;
					p = 0;			//p - длина введённого слова

					while (s[j] != '\0')
					{
						p++;
						j++;
					}

					for (i = 0; i < records; i++)
					{		
						

						j = 0;
						k = 0;
						l = 0;
						while (s[j] != '\0')
						{
							l = 0;
							while (list[i].mark[l] != '\0')
							{								
								if (s[j] == list[i].mark[l])
								{
									k++;
									break;
								}
								l++;
							}	
							j++;
						}

						
						if (k == p)
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
							m++;
						}
					}

					if (m == 0)
					{
						printf("No matches found.\n");
					}
					else
					{
						printf("Total matches: %d\n", m);
					}
				}

				if (i == 7)				// мастер по частичному совпадению
				{
					m = 0;		//m - количество совпадений
					printf("Enter master of elements, which you want to find:\n");
					fflush(stdin);
					gets(s);
					gets(s);

					j = 0;
					p = 0;			//p - длина введённого слова

					while (s[j] != '\0')
					{
						p++;
						j++;
					}

					for (i = 0; i < records; i++)
					{


						j = 0;
						k = 0;
						l = 0;
						while (s[j] != '\0')
						{
							l = 0;
							while (list[i].master[l] != '\0')
							{
								if (s[j] == list[i].master[l])
								{
									k++;
									break;
								}
								l++;
							}
							j++;
						}


						if (k == p)
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
							m++;
						}
					}

					if (m == 0)
					{
						printf("No matches found.\n");
					}
					else
					{
						printf("Total matches: %d\n", m);
					}
				}

				puts("Continue searching? 1 - yes, 0 - no.");
				scanf("%d", &i);
			} while (i);
			i = 1;
		}
		//==================================================
		if (i == 5)				//удаление структуры
		{
			do
			{
				printf("\nChoose parameter by which elements will be deleted:\n1 - registration number,\n2 - mark,\n3 - mileage,\n4 - master's name,\n5 - repair price.\n");
				scanf("%d", &i);

				if (i == 1)				//по регистрационному номеру
				{
					printf("Choose registration number of element. which you want to delete:\n");
					scanf("%d", &j);

					if (j < 1 || j > records)
					{
						printf("Error. Number is less than 0 or more than number of cars.\n");
						break;
					}

					j--;
					records--;

					for (j; j < records; j++)
					{
						list[j].reg = j + 1;
						i = 0;
						while (list[j + 1].mark[i] != '\0' || list[j].mark[i] != '\0')
						{
							list[j].mark[i] = list[j + 1].mark[i];
							i++;
						}
						list[j].mileage = list[j + 1].mileage;
						i = 0;
						while (list[j + 1].master[i] != '\0' || list[j].master[i] != '\0')
						{
							list[j].master[i] = list[j + 1].master[i];
							i++;
						}
						list[j].sum = list[j + 1].sum;
					}
				}

				if (i == 3)				//по пробегу
				{
					printf("Enter mileage of elements, which you want to delete:\n");
					scanf("%d", &l);					

					for (i = 0; i < records; i++)
					{
						if (l == list[i].mileage)
						{
							records--;
							j = i;
							for (j; j < records; j++)
							{
								list[j].reg = j + 1;
								k = 0;
								while (list[j + 1].mark[k] != '\0' || list[j].mark[k] != '\0')
								{
									list[j].mark[k] = list[j + 1].mark[k];
									k++;
								}
								list[j].mileage = list[j + 1].mileage;
								k = 0;
								while (list[j + 1].master[k] != '\0' || list[j].master[k] != '\0')
								{
									list[j].master[k] = list[j + 1].master[k];
									k++;
								}
								list[j].sum = list[j + 1].sum;
								i--;
							}
						}
					}
				}

				if (i == 5)				//по цене
				{
					printf("Enter repair price of elements, which you want to delete:\n");
					scanf("%d", &l);

					for (i = 0; i < records; i++)
					{
						if (l == list[i].sum)
						{
							records--;
							j = i;
							for (j; j < records; j++)
							{
								list[j].reg = j + 1;
								k = 0;
								while (list[j + 1].mark[k] != '\0' || list[j].mark[k] != '\0')
								{
									list[j].mark[k] = list[j + 1].mark[k];
									k++;
								}
								list[j].mileage = list[j + 1].mileage;
								k = 0;
								while (list[j + 1].master[k] != '\0' || list[j].master[k] != '\0')
								{
									list[j].master[k] = list[j + 1].master[k];
									k++;
								}
								list[j].sum = list[j + 1].sum;
								i--;
							}
						}
					}
				}

				if (i == 2)				//по марке
				{
					printf("Enter mark of elements, which you want to delete:\n");
					fflush(stdin);
					gets(s);
					gets(s);

					for (i = 0; i < records; i++)
					{
						j = 0;
						k = 0;
						l = 0;
						while (s[j] == list[i].mark[j] && s[j] != '\0' && list[i].mark[j] != '\0')
						{
							k++;
							j++;
						}
						j = 0;
						while (list[i].mark[j] != '\0')
						{
							l++;
							j++;
						}
						if (k==l)
						{
							records--;
							j = i;
							for (j; j < records; j++)
							{
								list[j].reg = j + 1;
								k = 0;
								while (list[j + 1].mark[k] != '\0' || list[j].mark[k] != '\0')
								{
									list[j].mark[k] = list[j + 1].mark[k];
									k++;
								}
								list[j].mileage = list[j + 1].mileage;
								k = 0;
								while (list[j + 1].master[k] != '\0' || list[j].master[k] != '\0')
								{
									list[j].master[k] = list[j + 1].master[k];
									k++;
								}
								list[j].sum = list[j + 1].sum;
								i--;
							}
						}
					}

				}

				if (i == 4)				//по мастеру
				{
					printf("Enter master of elements, which you want to delete:\n");
					fflush(stdin);
					gets(s);
					gets(s);

					for (i = 0; i < records; i++)
					{
						j = 0;
						k = 0;
						l = 0;
						while (s[j] == list[i].master[j] && s[j] != '\0' && list[i].master[j] != '\0')
						{
							k++;
							j++;
						}
						j = 0;
						while (list[i].master[j] != '\0')
						{
							l++;
							j++;
						}
						printf("\nk=%d", k);
						printf("\nl=%d", l);
						if (k == l)
						{
							records--;
							j = i;
							for (j; j < records; j++)
							{
								list[j].reg = j + 1;
								k = 0;
								while (list[j + 1].mark[k] != '\0' || list[j].mark[k] != '\0')
								{
									list[j].mark[k] = list[j + 1].mark[k];
									k++;
								}
								list[j].mileage = list[j + 1].mileage;
								k = 0;
								while (list[j + 1].master[k] != '\0' || list[j].master[k] != '\0')
								{
									list[j].master[k] = list[j + 1].master[k];
									k++;
								}
								list[j].sum = list[j + 1].sum;
								i--;
							}
						}
					}

				}

				printf("Continue deleting? 1 - yes, 0 - no.\n");
				scanf("%d", &i);
			} while (i);
			i = 1;
		}
		//==================================================
		if (i == 6)			//сортировка
		{
			do
			{
				printf("Choose parameter for sorting:\n1 - registration number,\n2 - mark,\n3 - mileage,\n4 - master's name,\n5 - repair price.\n");
				scanf("%d", &i);
				s[0] = '\0';

				if (i == 1)			//по регистрационному номеру
				{
					for (i = 0; i < records; i++)
					{
						for (j = i + 1; j < records; j++)
						{
							if (list[i].reg > list[j].reg)
							{
								k = list[i].reg;
								list[i].reg = list[j].reg;
								list[j].reg = k;

								k = 0;
								while (list[i].mark[k] != '\0' || list[j].mark[k] != '\0')
								{
									s[k] = list[i].mark[k];
									list[i].mark[k] = list[j].mark[k];
									list[j].mark[k] = s[k];
									k++;
								}

								k = list[i].mileage;
								list[i].mileage = list[j].mileage;
								list[j].mileage = k;

								k = 0;
								while (list[i].master[k] != '\0' || list[j].master[k] != '\0')
								{
									s[k] = list[i].master[k];
									list[i].master[k] = list[j].master[k];
									list[j].master[k] = s[k];
									k++;
								}

								k = list[i].sum;
								list[i].sum = list[j].sum;
								list[j].sum = k;

							}
						}
					}
					
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

				if (i == 3)			//по пробегу
				{
					for (i = 0; i < records; i++)
					{
						for (j = i + 1; j < records; j++)
						{
							if (list[i].mileage > list[j].mileage)
							{
								k = 0;
								k = list[i].reg;
								list[i].reg = list[j].reg;
								list[j].reg = k;

								k = 0;
								while (list[i].mark[k] != '\0' || list[j].mark[k] != '\0')
								{
									s[k] = list[i].mark[k];
									list[i].mark[k] = list[j].mark[k];
									list[j].mark[k] = s[k];
									k++;
								}
								k = 0;
								k = list[i].mileage;
								list[i].mileage = list[j].mileage;
								list[j].mileage = k;

								k = 0;
								while (list[i].master[k] != '\0' || list[j].master[k] != '\0')
								{
									s[k] = list[i].master[k];
									list[i].master[k] = list[j].master[k];
									list[j].master[k] = s[k];
									k++;
								}
								k = 0;
								k = list[i].sum;
								list[i].sum = list[j].sum;
								list[j].sum = k;

							}
						}
					}

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

				printf("Continue sorting? 1 - yes, 0 - no.\n");
				scanf("%d", &i);
			} while (i);
			i = 1;
		}
	} while (i);

	printf("\nGoodbye.\n");
}
