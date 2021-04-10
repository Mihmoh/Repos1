//Текстовые файлы
//1.	С клавиатуры заполнить файл целыми числами (так, чтобы каждое число занимало одинаковое количество байт).  Вывести все числа из файла на экран.
//2.	Найти в файле минимальное число и вывести его на экран(если таких чисел несколько, вывести все).
//3.	Все максимальные числа заменить на минимальные, а все минимальные – на максимальные.
//Бинарные файлы
//1.	С клавиатуры заполнить файл целыми числами.
//2.	Посчитать, сколько в файле элементов с максимальным значением.
//3.	Заменить все максимальные элементы значением минимального элемента.



#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <io.h>
#include <locale.h>

char* nameOfTheFileText(char* nameFile)
{
	do
	{
		int j = 0;
		char temp;
		nameFile = (char*)calloc(1, sizeof(char));
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

void print(FILE *f)                     //функция ввода
{
	int i;
	if (!f) return;
	rewind(f);
	printf("\n|");
	while(1)
	{  fscanf(f, "%d", &i);
	   printf(" %d", i);
	   if(feof(f)) break;
	}
	printf("|");
}

void print_bin(FILE* f)                     //функция ввода
{
	int i;
	if (!f) return;
	rewind(f);
	printf("\n|");
	while (1)
	{
		fread(&i, sizeof(int), 1, f);
		if (feof(f))  break;
		printf(" %d", i);
	}
	printf("|");
}

int main()
{
	FILE *f, *f1, *f2;
	int i, j=0, j2=0, a, min=0, kmin=0, max=0, kmax=0, k=0;
	char* nameFile = NULL;
	if (nameFile == NULL)
	{
		nameFile = nameOfTheFileText(nameFile);
	}
	
	do
	{
		printf("1 - work with text file; 2 - work with binary file\n");
		while (!scanf("%d", &i))
		{
			rewind(stdin);
			printf("\n1 - work with text file; 2 - work with binary file\n");
		}

		if (i == 1)			//работа с текстовыми файлами
		{
			f1 = fopen(nameFile, "w+t");
			f2 = fopen("bbb.txt", "w+t");
			while (1)          //ввод чисел
			{
				printf("Enter a number. 999 - stop entering\n");
				while (!scanf("%d", &i))
				{
					rewind(stdin);
					printf("Enter a number. 999 - stop entering\n");
				}
				if (i == 999) break;
				rewind(f1);
				fseek(f1, 0, 2);
				fprintf(f1, " %d", i);
				system("cls");
			}
			rewind(f1);
			fscanf(f1, "%d", &min);
			rewind(f1);
			fscanf(f1, "%d", &max);
			rewind(f1);

			while (1)         //нахождение максимального и минимального числа
			{
				fscanf(f1, "%d", &i);
				if (min >= i)
				{
					min = i;
				}
				if (max <= i)
				{
					max = i;
				}
				if (feof(f1)) break;
			}
			rewind(f1);

			while (1)            //подсчёт минимальных и максимальных чисел
			{
				fscanf(f1, "%d", &i);
				if (min == i)
				{
					kmin++;
				}
				if (max == i)
				{
					kmax++;
				}
				if (feof(f1)) break;
			}

			printf("\nThe minimal numbers are: ");         //вывод минимальных чисел
			for (i = 0; i < kmin; i++)
			{
				printf(" %d", min);
			}
			printf("\nThe maximal number is %d. Its quantity is %d\n", max, kmax);
			print(f1);
			rewind(f1);


			while (1)        //замена минимальных на максимальные и максимальных на минимальные в другом файле
			{
				if (j == kmin + kmax) break;
				fscanf(f1, "%d", &i);
				if (min == i)
				{
					fprintf(f2, " %d", max);
					j++;
					continue;
				}
				if (max == i)
				{
					fprintf(f2, " %d", min);
					j++;
					continue;
				}
				fprintf(f2, " %d", i);
				if (feof(f1) || j == kmin + kmax) break;
			}
			rewind(f1);
			rewind(f2);

			while (1)            //перезапись чисел из другого файла в первый
			{
				fscanf(f2, " %d", &i);
				fprintf(f1, " %d", i);
				if (feof(f2) || feof(f1)) break;
			}

			print(f1);
			fclose(f1);
			fclose(f2);

			return 0;
		}

		if (i == 2)			//работа с бинарными файлами
		{
			f = fopen(nameFile, "w+b");
			rewind(f);
			while (1)
			{

				printf("Enter a number. 999 - stop entering\n");
				while (!scanf("%d", &i))
				{
					rewind(stdin);
					printf("Enter a number. 999 - stop entering\n");
				}
				if (i == 999) break;
				rewind(f);

				fseek(f, 0, 2);
				fwrite(&i, sizeof(int), 1, f);
				system("cls");
			}
			rewind(f);

			print_bin(f);
			rewind(f);

			fread(&min, sizeof(int), 1, f);
			rewind(f);
			do                       //нахождение минимального и максимального значений
			{
				fread(&j, sizeof(int), 1, f);
				if (feof(f))  break;
				if (max < j)
				{
					max = j;
				}
				if (min > j)
				{
					min = j;
				}
			} while (1);
			rewind(f);

			do               //замена максимального значения минимальным
			{
				fread(&j, sizeof(int), 1, f);
				if (feof(f))  break;
				if (max == j)
				{
					k++;
					fseek(f, 0 - sizeof(int), 1);
					fwrite(&min, sizeof(int), 1, f);
					rewind(f);
				}
			} while (1);
			printf("\n The biggest number is %d. The minimal number is %d. Number of the biggest numbers is %d\n", max, min, k);
			rewind(f);

			print_bin(f);
			rewind(f);

			fclose(f);
			return 0;
		}
		
	} while (i);
	
}
