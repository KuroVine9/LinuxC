#include <stdio.h>
#include <math.h>

int main() {
	int num, i;
	int count = 0;
	int result = 0;

	scanf("%d", &num);

	i = num;

	while (i > 0) {
		i /= 10;
		count++;
	}

	while (count > 0 ) {
		result += (num % 10) * pow(10,--count);
		num /= 10;
	}

	printf("%d", result);

	return 0;
}