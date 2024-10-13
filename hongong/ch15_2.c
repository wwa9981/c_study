#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 프로필 교환 프로그램
// void 포인터로 int형과 double형을 모두 처리할 수 있도록 만든다

void main(void) {
	int a_age = 0, b_age = 0;
	double a_height = 0.0, b_height = 0.0;

	printf("첫 번째 사람의 나이와 키 입력 : ");
	scanf("%d %lf", &a_age, &a_height);
	printf("두 번째 사람의 나이와 키 입력 : ");
	scanf("%d %lf", &b_age, &b_height);

	swap("int", &a_age, &b_age);
	swap("double", &a_height, &b_height);

	printf("첫 번째 사람의 나이와 키 : %d, %.1lf \n", a_age, a_height);
	printf("두 번째 사람의 나이와 키 : %d, %.1lf", b_age, b_height);
}

 void swap(char* type, void* a, void* b) {
 	if (strcmp(type, "int") == 0) {
 		int temp = 0;

 		temp = *((int*)a);
 		*((int*)a) = *((int*)b);
 		*((int*)b) = temp;
 	}
 	else if (strcmp(type, "double") == 0) {
 		double temp = 0.0;

 		temp = *((double*)a);
 		*((double*)a) = *((double*)b);
 		*((double*)b) = temp;
 	}
 }