#include <stdio.h>
#include <math.h>

int main() {
	unsigned int index = 0, dec = 0;
	char binary[40];
	int count = 0;
	scanf("%[01]", binary);


	for (; binary[index + 1] != '\0'; index++) {
		dec += binary[index] - '0';
		dec *= 2;
	}
	printf("\n\n%d", dec);

	return 0;
}