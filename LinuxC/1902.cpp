#include <stdio.h>
void binary(int num) {
	if (num > 1)
		binary(num >> 1);
	printf("%d", num % 2);
}

int main() {
	int num;
	scanf("%d", &num);
	binary(num);
	return 0;
}