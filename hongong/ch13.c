#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 2개의 전역 변수에 값을 입력하교 교환 후 출력하는 프로그램

void input_data(int* a, int* b);
void swap_data(void);
void print_data(int a, int b);

int a, b;	// 전역 변수

void main(void) {
	input_data(&a, &b);
	swap_data();
	print_data(a, b);
}

void input_data(int* a, int* b) {
	printf("두 정수 입력 : ");
	scanf("%d%d", a, b);	// 포인터를 입력받았으므로, a, b로 넣어줌
}

void swap_data() {	// 전역 변수를 swap
	int temp = 0;

	temp = a;
	a = b;
	b = temp;
}

void print_data(int a, int b) {
	printf("두 정수 출력 : %d, %d", a, b);
}