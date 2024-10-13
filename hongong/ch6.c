#include <stdio.h>

void main(){
	int max;
	int i = 2;
	int j;
	int n = 0;

	printf("2 이상의 정수를 입력하세요 : ");
	scanf("%d", &max);

	while(i<=max){
		if (i == 2){
			printf("%d\t", i);
			n++;
			i++;
		}
		continue;
		for (j = 2; j < i; j++){
			if (i % j == 0)
				break;
			else if ((j == i-1) && (i % j != 0)){
				if (n == 4){
					printf("%d\n", i);
					n = 0;
				}
				else{
					printf("%d\t", i);
					n++;	
				}
			}
		}
		i++;
		continue;
	}
}