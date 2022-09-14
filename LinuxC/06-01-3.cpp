#include <stdio.h>

int main() {
	int i = 31;
	int bin[32] = { 0, };
	int dec;

	scanf("%d", &dec);

	/*
	최종적으로 나오는 몫->MSB
	나머지-> ... 
	*/

	for (i = 31; i>0; i--) {
		if (dec / 2 < 2) {
			bin[i] = dec % 2;
			bin[i-1] = dec / 2;
			break;
		}
		else {
			bin[i] = dec % 2;
			dec /= 2;
		}
	}

	for (i = 0; i < 32; i++) {
		printf("%d", bin[i]);
	}

	return 0;
}