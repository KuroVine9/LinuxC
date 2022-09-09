#include <stdio.h>
#include <math.h>

int main() {
	int num, i=1;

	scanf("%d", &num);

	while (sqrt(num) > i) {
		if (sqrt(num) == i) {
			printf("%d\n", i);
		}
		else if (num % i == 0) {
			printf("%d, %d\n", i, num / i);
		}
		i++;
	}

	return 0;
}