#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 8장 실전 예제
// 입력받은 문장의 대문자를 찾아 소문자로 변환
void main() {
	char str[100];
	int cnt = 0;
	int str_size = sizeof(str) / sizeof(str[0]);


	printf("문장 입력 :");
	gets(str);	// 문장 입력 (띄어쓰기 포함)

	for (int i = 0; i < str_size; i++) {
		if ((str[i] >= 'A') && (str[i] <= 'Z')) {
			str[i] += 32;
			cnt++;
		}
	}

	printf("바뀐 문장 : %s \n", str);
	printf("바뀐 문자 수 : %d", cnt);
}