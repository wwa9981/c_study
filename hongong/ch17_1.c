#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// linked list

struct node {
	int num;
	struct node *next;
};

void main(void) {
	struct node a = {10, 0};	// next가 정의되지 않았을 땐, null 포인터로 초기화
	struct node b = {20, 0};
	struct node c = {30, 0};

	struct node *head = &a, *current;

	printf("head->num : %d \n", head->num);
	printf("head->next->num : %d \n", head->next->num);
	
	printf("print all \n");
	current = head;
	while(current != NULL;){
		printf("%d ", current->num);		
	}
}
