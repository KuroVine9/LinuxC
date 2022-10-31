#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#if 0
typedef union {
	char bf[4];
	int x;
} test;


int main() {
	test test = { 'a','b','c','d' };

	printf("%c, %X", test.bf[1], test.x);

	return 0;
}

#endif

#if 0

typedef struct {
	char name[20];
	int korean, english;
}stud;

char* search(stud* aa, char* name) {
	int i;
	if (strstr(aa->name, name)) return aa->name;
	else return NULL;
}

int main() {
	stud students[3] = { {"Hong Gil Dong", 95,83}, {"Park Gi Dong",90,78}, {"Kim Gi Joong", 79,77} };
	char* name = "Dong", i;
	//char* result = (char*)malloc(50);
	char* result;
	for (i = 0; i < 3; i++) {
		result = search(&students[i], name);
		if (result) printf("%s\n", result);
	}
	//free(result);

	return 0;
}

#endif

typedef struct {
	char* name;
	int* arr;
}st;

int main() {
	st* test;
	test = (st*)malloc(sizeof(st));

	test->name = "test";
	test->name = "234";

	int ar[2] = { 0,1 };
	int* p;
	p = ar;
	test->arr = ar;

	printf("%p\n", &"test");


	printf("%s", test->name);
	printf("\n%d", *test->arr++);
	printf("\n%d", *test->arr++);
	printf("\n%d", *test->arr);

	return 0;
}