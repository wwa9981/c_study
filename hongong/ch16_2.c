#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 소수 계산 프로그램 

int prime(int a);

void main(void) {
	int target;
	int row;
	int col;
	int** matrix;

	printf("양수 입력 : ");
	scanf("%d", &target);
	row = ((target - 2) / 5) + 1;
	
	matrix = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {
		if (i == row - 1) {
			col = (target - 2) % 5;
		}
		else {
			col = 5;
		}

		matrix[i] = (int*)malloc(col * sizeof(int));
		for (int j = 0; j < col; j++)
			matrix[i][j] = (i * 5) + (j + 2);
	}

	for (int i = 0; i < row; i++) {
		if (i == row - 1) {
			col = (target - 2) % 5;
		}
		else {
			col = 5;
		}
		printf("\n");
		for (int j = 0; j < col; j++) {
			if (prime(matrix[i][j]))
				printf("%5c", 'X');
			else
				printf("%5d", matrix[i][j]);
		}
	}

	for (int i = 0; i < row; i++) {
		free(matrix[i]);
	}

	free(matrix);
}

int prime(int a) {
	if (a == 2)
		return 0;

	for (int i = 2; i < a; i++) {
		if (a % i == 0)
			return 1;
	}

	return 0;
}