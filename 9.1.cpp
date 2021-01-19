#include<stdio.h>
#include<Windows.h>
void revers(char* s);
int main() {
	long float n;
	int k, j = 0;
	char* s;
	s = (char*)calloc(100, sizeof(char));
	scanf("%lf", &n);
	scanf("%d", &k);

	int f = n;
	int i = 0;
	while ((f / k) > 0) {
		if (f % k <= 9) {
			s[i] = (f % k) + '0';
			i++;
		}
		else if ((f % k) > 9) {
			s[i] = ((f % k) - 10) + 'A';
			i++;
		}
		f = f / k;
	}
	if (f % k <= 9) {
		s[i] = (f % k) + '0';
		i++;
	}
	else if ((f % k) > 9) {
		s[i] = ((f % k) - 10) + 'A';
		i++;
	}
	if ((n - (int)n) == 0) {
		s[i] = '\0';
		revers(s);
	}
	else if ((n - (int)n) > 0) {
		s[i] = '\0';
		revers(s);
		s[i] = '.';
		i++;
		long float z;
		z = n - (int)n;
		while (z != 0 && j < 10) {
			z = z * k;
			if ((int)z >= 0 && (int)z <= 9) {
				s[i] = (int)z + '0';
			}
			else {
				s[i] = ((int)z - 10) + 'A';
			}
			z = z - (int)z;
			i++;
			j++;
		}
	}


	s[i] = '\0';
	puts(s);
	return 0;
}
void revers(char* s) {
	static int i = 0, j = 0;
	char l;
	if (s[i] == '\0') {
		i--;
		return;
	}
	l = s[i];
	i++;
	revers(s);
	s[j] = l;
	j++;
}
