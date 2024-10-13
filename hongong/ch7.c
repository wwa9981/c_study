#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int rec_func(int n);

void main() {
	int a;
	a = rec_func(10);
	printf("%d", a);
}

int rec_func(int n) {
	int sum;

	if (n == 1) {
		return 1;
	}
	else {
		sum = (rec_func(n - 1) + n);
		return sum;
	}
}