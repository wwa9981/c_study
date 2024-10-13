// 길이가 가장 긴 단어 찾기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void)
{
	int res;
	char ch;

	int cnt = 0;
	int max = 0;

	while (1)
	{
		res = scanf("%c", &ch);

		if (res == -1)	// Ctrl + Z를 통해 종료 시 결과 출력 
		{
			printf("가장 긴 단어의 길이 : %d", max);
			break;
		}

		if (ch == '\n')	// 단어가 끝났을 때 길이 확인
		{
			if (cnt > max) max = cnt;
			cnt = 0;
			getchar();	// 개행 문자 삭제
		}

		cnt++; // 단어가 안 끝났을 때 카운팅
	}
}