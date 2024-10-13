#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 동적 할당 영역에 저장한 문자열을 함수로 출력하는 프로그램
// 배열 포인터를 받아야 하기 때문에 이중 포인터 사용 -> 매개변수 값을 변화시키면 문자열을 출력
// 포인터에 배열을 저장하면, 배열명처럼 사용이 가능함을 항상 기억해두자

void print_str(char** pa);

void main(void) {
	char temp[80];
	char* str[21] = { 0 };
	int i = 0;

	while (i < 20) {
		printf("문자열을 입력하세요 : ");
		gets(temp);
		
		if (strcmp(temp, "end") == 0) 
			break;

		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
	}

	print_str(str);

	for (i = 0; str[i] != NULL; i++) {
		free(str[i]);
	}
}

void print_str(char** pa){
	while (*pa != NULL) {	// pa가 참조하는 값(str의 포인터)이 NULL이 될 때까지 출력을 반복
		printf("%s \n", *pa);
		pa++;
	}
}