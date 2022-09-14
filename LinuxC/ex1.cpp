#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct { // 구조체 polynomial 정의
	int degree; // 다항식의 차수를 저장할 변수
	float coef[MAX_DEGREE]; // 다항식의 각 항의 계수를 저장할 1차원 배열
} polynomial;

polynomial addPoly(polynomial, polynomial);
void printPoly(polynomial);

int main() {
	polynomial A = { 3,{ 4,3,5,0 } }; // 다항식 A의 초기화
	polynomial B = { 4,{ 3,1,0,2,1 } }; // 다항식 B의 초기화
	polynomial C;

	C = addPoly(A, B); // 다항식 A, B에 대한 덧셈을 수행하기 위해 addPoly 함수 호출

	printf("\n A(x) ="); printPoly(A); // 다항식 A 출력
	printf("\n B(x) ="); printPoly(B); // 다항식 B 출력
	printf("\n C(x) ="); printPoly(C); // 다항식 C 출력

	getchar();

	return 0;
}

polynomial addPoly(polynomial A, polynomial B) {
	int i;
	float coef[MAX_DEGREE] = {0,};
	int MAX = MAX(A.degree, B.degree);
	int MIN = -MAX(-A.degree, -B.degree);
	polynomial C;

	for (i = 0; i <= MAX(A.degree, B.degree); i++) {
		coef[i] =
			(MAX - MIN > i && MIN == A.degree ? 0 : A.coef[i - (MAX - A.degree)])
			+ (MAX - MIN > i && MIN == B.degree ? 0 : B.coef[i - (MAX - B.degree)]);
		
	}

	C.degree = MAX(A.degree, B.degree);
	for (i = 0; i <= MAX; i++) {
		C.coef[i] = coef[i];
	}

	return C;
}

void printPoly(polynomial X) {
	for (int i = 0; i <= X.degree; i++) {
		printf("%dx^%d", (int)X.coef[i], X.degree-i);
		if (i < X.degree) {
			printf(" + ");
		}
	}
}