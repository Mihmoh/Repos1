#include <stdio.h>
#include <stdlib.h>
void revers(char*, int, int);
int main()
{
	char* str = nullptr;
	int i, j = -1, m;
	int i1, j1;
	do {
		printf_s("Vvodite n:\nn = ");
		if ((i = scanf_s("%d", &m)) == 0) {
			rewind(stdin);
			system("cls");
			printf_s("Try again\n");
			continue;
		}
		str = (char*)malloc(sizeof(char) * m);
	} while (str == nullptr);
	rewind(stdin);
	fgets(str, m, stdin);
	i = 0;
	while (*(str + i) != '\0') {
		j++;
		if (*(str + i) == '\n') str[i] = '\0';
		i++;
	}
	j--;
	if (str[j] == ' ')while (str[j] == ' ')j--;
	i = 0;
	revers(str, i, j);
	for (i1 = 0, j1 = 0; str[i1] != ' '; i1++, j1++);
	i1--;
	revers(str, i, i1);
	puts(str);
	if (str[j] == ' ')while (str[j] == ' ')j--;
	for (i1 = j; str[i1] != ' '; i1--);
	i1++;
	revers(str, i1, j);
	i1--;
	revers(str, j1, i1);
	puts(str);
}
void revers(char* str, int i, int j) {
	int m;
	do {
		m = str[j];
		str[j] = str[i];
		str[i] = m;
		i++;
		j--;
	} while (i < j || i == j);
}
