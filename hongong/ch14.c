#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 가로 세로의 합 구하기
// 5x6 2차원 배열에서
// 각 행의 마지막 : 1~5열의 합
// 마지막 행 : 1~20까지의 합

void main(void) {
	int ary[5][6] = { {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20} };
	int row_sum = 0;
	int col_sum[5] = {0};

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			// 1 : 마지막 열
			if (i == 4) {
				if (j == 5) {
					ary[i][j] = row_sum;
				}
				else {
					ary[i][j] = col_sum[j];
					row_sum += ary[i][j];
				}
			}
			// 2 : 나머지
			else if (j == 5) {
				ary[i][j] = row_sum;
			}
			else {
				row_sum += ary[i][j];
				col_sum[j] += ary[i][j];
			}
		}
		row_sum = 0;
	}

	printf("======= 전체 배열의 값 ======= \n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%5d", ary[i][j]);
		}
		printf("\n");
	}
}