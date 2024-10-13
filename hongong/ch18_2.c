#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	FILE* afp, *bfp, *cfp;
	char *str_a[10];	// a.txt에 등록된 단어 리스트

	char* res;
	char temp[20];
	int i = 0;

	// 1. fopen
	afp = fopen("a.txt", "r");
	if (afp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	bfp = fopen("b.txt", "r");
	if (bfp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	cfp = fopen("c.txt", "a");
	if (cfp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	// 2. a.txt 단어 등록 및 b.txt 단어 탐색
	while (1) {
		res = fgets(temp, sizeof(temp), afp);
		if (res == NULL) {
			break;
		}
		if (temp[strlen(temp) - 1] == '\n') {
			temp[strlen(temp) - 1] = '\0';
		}
			
		str_a[i] = (char*)malloc(sizeof(temp));	// \0을 넣어주므로, sizeof(temp) + 1로 안 해도 됨
		strcpy(str_a[i], temp);
		printf("str_a[%d] = %s\n", i, str_a[i]);
		i++;
	}

	while (1) {
		res = fgets(temp, sizeof(temp), bfp);
		if (res == NULL) {
			break;
		}
		if (temp[strlen(temp) - 1] == '\n') {
			temp[strlen(temp) - 1] = '\0';
		}

		printf("temp = %s\n", temp);

		for (int j = 0; j < i; j++) {
			if (strcmp(temp, str_a[j]) == 0) {
				printf("strcmp! : temp = %s , str_a[%d] = %s\n", temp, j, str_a[j]);
				break;
			}
			if ((j == i - 1) && (strcmp(temp, str_a[j]) != 0)) {
				fputs(temp, cfp);
				fputs("\n", cfp);
			}
		}
	}

	// 3. fclose
	fclose(afp);
	fclose(bfp);
	fclose(cfp);
	for (int j = 0; j < i; j++) {
		free(str_a[j]);
	}
	
	return 0;
}