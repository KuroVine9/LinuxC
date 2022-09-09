#include <stdio.h>
#define SIZE 10

int main() {
	int i, j;
	int num;

	for (i = 0; i < SIZE; i++) {
		num = i;
		for (j = 0; j < SIZE; j++) {
			num = ++num % 10;
			printf("%d ", num);
		}
		printf("\n");
	}

	return 0;
}