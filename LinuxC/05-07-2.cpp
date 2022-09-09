#include <stdio.h>

int main() {
	int chk;

	for (chk = 1; chk <= 19; chk++) {
		if ((chk * 2) + ((19 - chk) * 4) == 60)
			printf("´ß: %d, °­¾ÆÁö: %d", chk, 19 - chk);
	}
	return 0;
}