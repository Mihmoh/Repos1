#include <iostream>
#include<stdio.h>
#include<locale.h>
int main() {	
	setlocale(LC_ALL, "Russian");
	int a, b;
	printf("Введите a ");
	scanf_s("%d", &a);
	printf("Введите b ");
	scanf_s("%d", &b);              //ввод данных
	int d = 2, k = 0;               //d - делитель к - количество
	for (int i = 0; i < 100; i) {            //бесконечный цикл
		if (a % d == 0 && b % d == 0) {      //проверка на общий множитель
			k++;
			d++;
			if (k == 2) {
				break;
			}
		}
		else {
			if (d > a || d > b) {            //проверка величины делителя
				break;
			}
			d++;
		}
	}
	if (k == 2) {
		printf("Есть как минимум два общих множителя");
	}
	else {
		printf("Нет двух общих множителей");
	}
}
