/*���� 2_4*/

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

	printf("2������ �Է��Ͻÿ�(32�ڸ� ����)\n");
	scanf("%[01]", binary);

	bp = binary;
	dec = trsf(bp, dec);

	printf("\n%s = %d", binary, dec);

	return 0;
}