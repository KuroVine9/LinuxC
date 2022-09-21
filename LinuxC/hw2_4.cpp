/*과제 2_4*/

#include <stdio.h>

unsigned int trsf(char* bp, unsigned int dec) {
	dec <<= 1;
	dec += *bp - '0';
	if (*++bp != '\0') {
		dec = trsf(bp, dec);
	}

	return dec;
}

int main() {
	unsigned int dec = 0;
	char binary[40];
	char* bp;

	printf("2진수를 입력하시오(32자리 이하)\n");
	scanf("%[01]", binary);

	bp = binary;
	dec = trsf(bp, dec);

	printf("\n%s = %d", binary, dec);

	return 0;
}