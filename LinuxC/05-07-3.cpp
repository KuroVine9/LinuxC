#include <stdio.h>
#include <stdlib.h>
#define SWCH(i,num) (i > num ? num * 2 - i : i)

int main() {
	int i, j, num;

	printf("1부터 10까지의 int 입력 : ");
	scanf("%d", &num);

	for (i = 1; i < num * 2; i++) {
		for (j = abs(num - i); j < num - 1; j++) {
			printf(" ");
		}
		for (j = SWCH(i, num) - 1; j < abs(num - i) * 2 + SWCH(i, num); j++) {
			printf("%d", num - abs(num - j - 1));
		}
		printf("\n");
	}

	return 0;
}