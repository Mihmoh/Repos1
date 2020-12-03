//12. В текстовом окне задан многострочный текст. Слова отделяются друг от друга пробелами. Каждое предложение в тексте заканчивается точкой.  Выделять слова с удвоенной гласной. 

#include <locale.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;                
	int m;         
	int g=0,l=0,k=0; 
	char** text;
	printf("Введите кол-во строк\n");
	scanf_s("%d", &n);
	text = (char**)malloc(n * sizeof(char*));
	printf("Введите кол-во символов в строке\n");
	scanf_s("%d", &m);
	m += 2;
	for (int i = 0; i < n; i++)
	{
		text[i] = (char*)malloc(m * sizeof(char));
	}
	printf("Введите строки \n");
	for (int i = 0; i < n; i++)
	{
		rewind(stdin);
		fgets(text[i], m, stdin);

	}

	
	for (int j = 0; j < n; j++)
	{
		
		for (int i = 0; i < m; i++)
		{
			
			k++;
			if (text[j][i] == 'a' || text[j][i] == 'e' || text[j][i] == 'i' || text[j][i] == 'o' || text[j][i] == 'u' || text[j][i] == 'y' || text[j][i] == 'A' || text[j][i] == 'E' || text[j][i] == 'I' || text[j][i] == 'O' || text[j][i] == 'U' || text[j][i] == 'Y')
			{
				g++;
			}
			if (text[j][i] == 'b' || text[j][i] == 'c' || text[j][i] == 'd' || text[j][i] == 'f' || text[j][i] == 'g' || text[j][i] == 'h' || text[j][i] == 'j' || text[j][i] == 'k' || text[j][i] == 'l' || text[j][i] == 'm' || text[j][i] == 'n' || text[j][i] == 'p' || text[j][i] == 'q' || text[j][i] == 'r' || text[j][i] == 's' || text[j][i] == 't' || text[j][i] == 'v' || text[j][i] == 'w' || text[j][i] == 'x' || text[j][i] == 'z' || text[j][i] == 'B' || text[j][i] == 'C' || text[j][i] == 'D' || text[j][i] == 'F' || text[j][i] == 'G' || text[j][i] == 'H' || text[j][i] == 'J' || text[j][i] == 'K' || text[j][i] == 'L' || text[j][i] == 'M' || text[j][i] == 'N' || text[j][i] == 'P' || text[j][i] == 'Q' || text[j][i] == 'R' || text[j][i] == 'S' || text[j][i] == 'T' || text[j][i] == 'V' || text[j][i] == 'W' || text[j][i] == 'X' || text[j][i] == 'Z')
			{
				g = 0;
			}
			if (text[j][i] == " ")
			{
				k = 0;
			}
			if (g == 2)
			{
				text[j][i] = " ";
				text[j][i-1] = " ";
				g = 0;
				
			}
			
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		printf("%s", text[i]);

	}	
	

}

