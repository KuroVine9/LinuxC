/*���� 2_4*/

#include <stdio.h>

int main() {
	unsigned int dec = 0;
	char binary[40];
	char* bp;

	printf("2������ �Է��Ͻÿ�(32�ڸ� ����)\n");
	scanf("%[01]", binary);

	bp = binary;
	
	do {
		dec <<= 1;
		dec += *bp - '0';
	} while (*++bp != '\0');


	printf("\n%s = %d", binary, dec);

	return 0;
}