#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 포인터를 활용한 원하는 함수 선택 및 실행

void func(int (*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);


void main(void) {
	int i = 0;

	printf("1. 두 정수의 합\n");
	printf("2. 두 정수의 곱\n");
	printf("3. 더 큰 정수 출력\n");
	printf("원하시는 연산을 선택하세요 : ");
	scanf("%d", &i);

	switch (i) 
	{
	case 1: func(sum); break;
	case 2: func(mul); break;
	case 3: func(max); break;
	}

}

void func(int (*fp)(int, int)) {
	int a, b;
	int res;

	printf("원하시는 두 수를 입력하세요 : ");
	scanf("%d%d", &a, &b);

	res = fp(a, b);		// 함수명 = 주소 이므로, * 없이 바로 호출할 수 있다
	printf("결과 : %d", res);
}

int sum(int a, int b) {
	return a + b;
}

int mul(int a, int b) {
	return a * b;
}

int max(int a, int b) {
	if (a > b) 
		return a;
	else 
		return b;
}