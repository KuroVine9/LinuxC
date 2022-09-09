#include <stdio.h>

int main() {
	int x = 5820703;
	int mtp = 1;
	int count = 0;

	while (x % mtp != x) {
		mtp *= 10;
		count++;
	}
	
	printf("%d\n", count);
	

	return 0;
}