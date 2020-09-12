#include<stdio.h>
int main() {
	int a, b;
	printf("BBEDITE a ");
	scanf_s("%d", &a);
	printf("BBEDITE b ");
	scanf_s("%d", &b);
	int d = 2, k = 0;
	for (int i = 0; i < 100; i) {
		if (a % d == 0 && b % d == 0) {
			k++;
			d++;
			if (k == 2) {
				break;
			}
		}
		else {
			if (d > a || d > b) {
				break;
			}
			d++;
		}
	}
	if (k == 2) {
		printf("ECTb KAK MINIMYM 2 O6wIX MHO)|(ITELA");
	}
	else {
		printf("HET 2 O6WIX MHO)|(ITELEN");
	}
}
