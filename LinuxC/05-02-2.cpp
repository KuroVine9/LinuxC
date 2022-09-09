#include <stdio.h>

int main() {
	int x;
	int sum = 0;
	int count = 0;
	double ave;

	while (1) {
		printf("양의 정수를 입력하시오(음수: 끝) :");
		scanf("%d", &x);

		if (x < 0) 
			break;
		//else if (x > 100)
		//	continue;
		else if (x <= 100) {
			sum += x;
			count++;
		}
	}
	ave = (double)sum / (double)count;

	printf("합계: %d, 평균: %d, 개수: %d\n", sum, ave, count);

	return 0;
}