#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int id;
	int kor;
	int eng;
	int math;
	int sum;
	double avrg;
	char score;
	char name[20];
} student;

void print_student(student* sp);
void sort_student(student* sp);

void main() {
	student s1 [5];
	student* sp;

	sp = s1;

	for (int i = 0; i < 5; i++) {
		printf("학번 : ");
		scanf("%d", &((sp + i)->id));
		printf("이름 : ");
		scanf("%s", &((sp + i)->name));
		printf("국어, 영어, 수학 점수 : ");
		scanf("%d %d %d", &((sp + i)->kor), &((sp + i)->eng), &((sp + i)->math));
		
		(sp + i)->sum = ((sp + i)->kor) + ((sp + i)->eng) + ((sp + i)->math);
		(sp + i)->avrg = (double)((sp + i)->sum) / 3.0;

		if ((sp + i)->avrg >= 90)
			(sp + i)->score = 'A';
		else if ((sp + i)->avrg >= 80)
			(sp + i)->score = 'B';
		else if ((sp + i)->avrg >= 70)
			(sp + i)->score = 'C';
		else
			(sp + i)->score = 'F';
	}
	printf("# 정렬 전 데이터...\n");
	print_student(sp);

	sort_student(sp);
	printf("# 정렬 후 데이터...\n");
	print_student(sp);
}

void print_student(student* sp) {
	for (int i = 0; i < 5; i++) {
		printf("%5d %5s %5d %5d %5d %5d %5.1lf %5c \n", (sp + i)->id, (sp + i)->name, (sp + i)->kor, (sp + i)->eng, (sp + i)->math, (sp + i)->sum, (sp + i)->avrg, (sp + i)->score);
	}
}

void sort_student(student* sp) {
	student temp;

	for (int i = 1; i < 5; i++) {
		for (int j = 0; j < i - 1; j++) {
			if ((sp + i)->sum > (sp + j)->sum) {
				temp = *(sp + i);
				*(sp + i) = *(sp + j);
				*(sp + j) = temp;
			}
		}
	}
}