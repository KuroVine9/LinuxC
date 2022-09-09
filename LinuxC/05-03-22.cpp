#include <stdio.h>
#define SIZE 10

int main() {
	int num = 0;
	int i = 0, j = 0;

	while (i < SIZE) {
		num = i;
		while (j < SIZE) {
			num = ++num % 10;
			printf("%d ", num);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
	return 0;
}