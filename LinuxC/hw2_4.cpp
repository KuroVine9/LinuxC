/*과제 2_4*/

#include <stdio.h>

int main() {
	unsigned int dec = 0;
	char binary[40];
	char* bp;

	printf("2진수를 입력하시오(32자리 이하)\n");
	scanf("%[01]", binary);

	bp = binary;
	
	do {
		dec <<= 1;
		dec += *bp - '0';
	} while (*++bp != '\0');


	printf("\n%s = %d", binary, dec);

	return 0;
}