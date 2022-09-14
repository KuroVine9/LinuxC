#include <stdio.h>
#include <stdlib.h>

int main() {
	char* str[] = { "This", "Is", "The", "Test", "String!" };
	char* str2 = "String";

	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
		printf("%s\n", str[i]);
	}

	printf("%s\n", str2);

	return 0;
}