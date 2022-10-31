#include <stdio.h>


#if 1
int main() {
	int i, j, rank;
	int stud[10] = { 45,92,88,34,88,95,82,59,70,76 };

	for (i = 0; i < 10; i++) {
		for (rank = 1, j = 0; j < 10; j++) 
			if (stud[i] < stud[j]) rank++;
		printf("%d : %dÀ§\n", stud[i], rank);
	}

	return 0;
}

#endif