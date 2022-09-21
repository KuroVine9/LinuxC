#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
#if 0
	char* str[] = { "This", "Is", "The", "Test", "String!" };
	char* str2 = "String";

	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++) {
		printf("%s\n", str[i]);
	}

	printf("%s\n", str2);

	short arr[5] = { 1,2,3,4,5 };
	short* ptr1;
	short* ptr2;

	printf("%u\n", sizeof(char*) );
	ptr1 = arr;
	printf("%d\t%X\n", *ptr1, ptr1);
	ptr1++;
	printf("%d\t%X\n", *ptr1, ptr1);
#endif
	

	//int* array[5];
	//int* ap;
	//int** app;
	//int i, j;

	//app = array;
	//for (i = 0; i < 5; i++) {
	//	*app++ = (int*)calloc(10, sizeof(int));
	//}
	//srand(time(NULL));
	//app = array;

	//for (i = 0; i < 5; i++) {
	//	ap = *app++;
	//	for (j = 0; j < 10; j++) {
	//		*ap++ = rand() % 101;
	//	}

	//}
	//app = array;

	//for (i = 0; i < 5; i++) {
	//	ap = *app++;
	//	printf("\n%p: %p\n", app, ap);
	//	for (j = 0; j < 10; j++) {
	//		printf("%3d ", *ap++);
	//	}
	//	printf("\n");
	//}

	//return 0;

	int i = 0, * j, ** k;

	j = &i;
	k = &j;

	printf("%d", **k);

	return 0;
}
