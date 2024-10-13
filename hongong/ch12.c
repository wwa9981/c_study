#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// scanf : 버퍼에서 공백이 없는 문자열을 입력받는다.
// gets : enter를 치기까지 작성한 문자열을 입력받는다. (\n을 \0로 변환해서 배열에 저장함) : char *gets (char *str)
// fgets : 최대 배열의 크기까지만 문자열을 입력받는다. (\n까지 배열에 저장하고 \0을 붙임) : fgets (str, sizeof(str), stdin); 

// puts : 문자열을 출력하고 자동 줄바꿈
// fputs : 문자열을 출력하고 줄 바꾸지 않음

//void main(void)
//{
//	char str1[15];
//	char str2[15];

//	printf("단어 입력 : ");
//	scanf("%s", str1);

//	if (strlen(str1) <= 5)
//		strcpy(str2, str1);
//	else {
//		strncpy(str2, str1, 5);
//		str2[5] = '\0';
//		strncat(str2, "**********", strlen(str1) - 5);
//	}

//	printf("입력한 단어 : %s, 생략한 단어 : %s\n", str1, str2);
//}

void swap(char* pa, char* pb);
void sort(char* str1, char* str2, char* str3);

void main(void) {
	char str1 [15];
	char str2 [15];
	char str3 [15];

	printf("세 단어 입력 : ");
	scanf("%s%s%s", str1, str2, str3);

	sort(str1, str2, str3);
	printf("정렬 결과 : %s, %s, %s", str1, str2, str3);
}

void swap(char* pa, char* pb) {
	char temp [15];
	strcpy(temp, pa);
	strcpy(pa, pb);
	strcpy(pb, temp);
}

void sort(char* str1, char* str2, char* str3) {
	if (strcmp(str1, str2) == 1)	// 1번이 2번보다 더 늦으면 swap
		swap(str1, str2);
	if (strcmp(str1, str3) == 1)	// 1번이 3번보다 더 늦으면 swap
		swap(str1, str3);
	if (strcmp(str2, str3) == 1)	// 2번이 3번보다 더 늦으면 swap
		swap(str2, str3);
}