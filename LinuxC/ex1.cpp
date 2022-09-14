#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct { // ����ü polynomial ����
	int degree; // ���׽��� ������ ������ ����
	float coef[MAX_DEGREE]; // ���׽��� �� ���� ����� ������ 1���� �迭
} polynomial;

polynomial addPoly(polynomial, polynomial);
void printPoly(polynomial);

int main() {
	polynomial A = { 3,{ 4,3,5,0 } }; // ���׽� A�� �ʱ�ȭ
	polynomial B = { 4,{ 3,1,0,2,1 } }; // ���׽� B�� �ʱ�ȭ
	polynomial C;

	C = addPoly(A, B); // ���׽� A, B�� ���� ������ �����ϱ� ���� addPoly �Լ� ȣ��

	printf("\n A(x) ="); printPoly(A); // ���׽� A ���
	printf("\n B(x) ="); printPoly(B); // ���׽� B ���
	printf("\n C(x) ="); printPoly(C); // ���׽� C ���

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