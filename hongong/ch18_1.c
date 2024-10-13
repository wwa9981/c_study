#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	FILE* fp;
	char str[20];

	fp = fopen("a.txt", "a+");
	if (fp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		printf("과일 이름 : ");
		scanf("%s", str);
		if (strcmp(str, "end") == 0)
		{
			break;
		}
		else if (strcmp(str, "list") == 0)
		{
			fseek(fp, 0, SEEK_SET);	// 파일 입출력 전환 -> fseek : 버퍼 데이터를 하드디스크로 출력시킨 다음, 위치 지시자를 처음으로 위치시킨다.
			while (1)
			{
				fgets(str, sizeof(str), fp);
				if (feof(fp))	// 파일의 끝에 도달하면 0이 아닌 값을 출력함
				{
					break;
				}
				printf("%s", str);
			}
		}
		else
		{
			fprintf(fp, "%s\n", str);
		}
	}
	fclose(fp);
	return 0;
}