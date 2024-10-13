#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void swap (double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

// 9장 실전 예제
void main() {
	double max, mid, min;

	printf("실수 3개 정의 : ");
	scanf("%lf%lf%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("정렬된 값 출력 : %.1lf, %.1lf, %.1lf\n", max, mid, min);
}

void swap(double* pa, double* pb) {
	double temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void line_up(double* maxp, double* midp, double* minp) {
	if (*maxp < *midp)
		swap(maxp, midp);
	if (*maxp < *minp)
		swap(maxp, minp);
	if (*midp < *minp)
		swap(midp, minp);
}