#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void input_nums(int* lotto_nums);
void print_nums(int* lotto_nums);

void main() {
	int lotto_num[6];

	input_nums(lotto_num);
	print_nums(lotto_num);
}

void input_nums(int* lotto_nums) {
	int i = 0;

	while (i < 6) {
		printf("번호 입력 : ");
		scanf("%d", lotto_nums + i);

		if (i == 0) {	// 첫 번호는 그냥 입력
			i++;
			continue;
		}
		else {	// 이후 번호부터 중복 여부 확인 (break를 통해 for문 탈출)
			for (int j = 0; j < i; j++) {
				if (lotto_nums[i] == lotto_nums[j]) {
					printf("같은 번호가 있습니다! \n");
					break;
				}
				else if ((j == i - 1) && (lotto_nums[i] != lotto_nums[j])) {
					i++;
					break;
				}
			}
		}
	}
}

void print_nums(int* lotto_nums) {
	int i;

	printf("로또 번호 : ");
	for (i = 0; i < 6; i++)
		printf("%0d ", lotto_nums[i]);
}