/*°úÁ¦ 2_2*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int* array[5], * ap, ** app;
	int i, j;

	srand(time(0));
	app = array;

	for (i = 0; i < 5; i++) {
		*app++ = (int*)calloc(10, sizeof(int));
	}
	
	app = array;
	for (i = 0; i < 5; i++) {
		ap = *app++;
		for (j = 0; j < 10; j++) {
			*ap++ = rand() % 101;
		}
	}

	app = array;
	for (i = 0; i < 5; i++) {
		ap = *app++;
		printf("\n%p : %p\n", app, ap);

		for (j = 0; j < 10; j++) {
			printf("%3d ", *ap++);
		}
		printf("\n");
	}

	return 0;
}