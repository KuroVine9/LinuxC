/*과제 2_3*/

#include <stdio.h>

int main() {
	int i, j, size;
	int* dp;
	int dim[5][5] = {
		 {4,5,7,8,9}
		,{5,2,4,6,2}
		,{4,7,8,5,2}
		,{3,5,8,9,6}
		,{7,5,6,9,8} };
	int max_count;

	max_count = sizeof(dim) / sizeof(dim[0]);
	size = sizeof(dim) / sizeof(int);

	printf("초기 행렬\n");
	dp = &dim[0][0];
	for (i = 0; i < max_count; i++) {
		for (j = 0; j < max_count; j++) {
			printf("%d ", *dp++);
		}
		printf("\n");
	}
	printf("\n");

	dp = &dim[0][0];
	for (i = 0; i < size; i++) {
		if (i % 5 > i / 5) {
			*(dp + i) ^= dp[(i % 5)*5+(i/5)];
			dp[(i % 5) * 5 + (i / 5)] ^= *(dp + i);
			*(dp + i) ^= dp[(i % 5) * 5 + (i / 5)];
		}
	}
	/*
	행, 열 번호가 같으면 스킵->mod 5와 /5연산결과가 같으면 스킵
	num1 - num6
	num4 - num20
	*/
	printf("전치 행렬\n");
	dp = &dim[0][0];
	for (i = 0; i < max_count; i++) {
		for (j = 0; j < max_count; j++) {
			printf("%d ", *dp++);
		}
		printf("\n");
	}
	printf("\n");
}