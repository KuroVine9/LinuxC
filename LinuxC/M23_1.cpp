#include <stdio.h>

typedef struct point {
	int xpos;
	int ypos;
} Point;

void SwapPoint(Point *a, Point *b) {
	a->xpos ^= b->xpos;
	b->xpos ^= a->xpos;
	a->xpos ^= b->xpos;

	a->ypos ^= b->ypos;
	b->ypos ^= a->ypos;
	a->ypos ^= b->ypos;
}

void PrintPoint(Point a) {
	printf("(%d, %d)\n", a.xpos, a.ypos);
}

int main() {
	Point pos1 = { 2,4 };
	Point pos2 = { 5,7 };
	Point* pt;

	PrintPoint(pos1);
	PrintPoint(pos2);

	SwapPoint(&pos1, &pos2);
	printf("\n=====After SwapPoint()=====\n\n");

	PrintPoint(pos1);
	PrintPoint(pos2);
}