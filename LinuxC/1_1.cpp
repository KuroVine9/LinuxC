#include <stdio.h>

int main() {
	int num,q;
	int div = 2;
	int count = 0;
	
	scanf("%d", &num);
	q = num;
	printf("%d = ", q);

	while (true) {
		if (num == 1 && count != 0) {
			printf("%d^%d\n", div, count);
			break;
		}
		else if (q/2 < div) {
			printf("%d\n", q);
			break;
		}
		else if (num % div == 0) {
			count++;
			num /= div;
		}
		else if (num % div != 0 && count != 0) {
			printf("%d^%d x ", div, count);
			div++;
			count = 0;
		}
		else {
			div++;
		}
	}
	
	return 0;
}