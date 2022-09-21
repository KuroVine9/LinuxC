/*과제 2_1*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int* array, * ap, * max, * min;
	int i;
	srand(time(NULL));

	array = (int*)calloc(100, sizeof(int));
	
	ap = array;

	max = ap;	//초기화
	min = ap;
	for (i = 0; i < 100; i++, ap++) {
		printf("%d ", *ap = rand());

		if (*max < *ap) {
			max = ap;
		}
		else if (*min > *ap) {
			min = ap;
		}
	}

	printf("\nmax = %d, min = %d\n", *max, *min);
	free(array);

	return 0;
}