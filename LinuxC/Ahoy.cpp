#include <stdio.h>
#include <stdlib.h>


int* Ahoy1;
int* Ahoy2;
int* Ahoy3;
int tw1 = 0, tw2 = 0, tw3 = 0;
int tmp1, tmp2, tmp3;
int num;
void PrintAhoy(int disk, char from, char to) {
	int count1 = 0, count2 = 0, count3 = 0;
	if (from == 'A') {
		tw1 -= (1 << (disk - 1));
	}
	else if (from == 'B') {
		tw2 -= (1 << (disk - 1));
	}
	else if(from=='C') {
		tw3 -= (1 << (disk - 1));
	}

	if (to == 'A') {
		tw1 += (1 << (disk - 1));
	}
	else if (to == 'B') {
		tw2 += (1 << (disk - 1));
	}
	else if(to=='C') {
		tw3 += (1 << (disk - 1));
	}
	tmp1 = tw1;
	tmp2 = tw2;
	tmp3 = tw3;

	for (int i = num-1; i >=0; i--) {
		if (tw1 - (1 << i) >= 0) {
			Ahoy1[num - count1 - 1] = i+1;
			tw1 -= (1 << i);
			count1++;
		}
		if (tw2 - (1 << i) >= 0) {
			Ahoy2[num - count2 - 1] = i + 1;
			tw2 -= (1 << i);
			count2++;
		}
		if (tw3 - (1 << i) >= 0) {
			Ahoy3[num - count3 - 1] = i + 1;
			tw3 -= (1 << i);
			count3++;
		}
	}
	for (; count1<num; count1++) {
		Ahoy1[num - count1 - 1] = 0;
	}
	for (; count2 < num; count2++) {
		Ahoy2[num - count2 - 1] = 0;
	}
	for (; count3 < num; count3++) {
		Ahoy3[num - count3 - 1] = 0;
	}
	int i, j=0;
	for (i = 0; i < num; i++) {
		if (Ahoy1[i] >0) {
			for (j = 0; j < Ahoy1[i]; j++) {
				printf("*");
			}
		}
		for (; j < 11; j++) {
			printf(" ");
		}
		printf("\t\t");
		j = 0;

		if (Ahoy2[i] > 0) {
			for (j = 0; j < Ahoy2[i]; j++) {
				printf("*");
			}
		}
		for (; j < 11; j++) {
			printf(" ");
		}
		printf("\t\t");
		j = 0;

		if (Ahoy3[i] > 0) {
			for (j = 0; j <Ahoy3[i]; j++) {
				printf("*");
			}
		}
		for (; j < 11; j++) {
			printf(" ");
		}
		j = 0;

		printf("\n");
	}

	tw1 = tmp1;
	tw2 = tmp2;
	tw3 = tmp3;
	printf("-----A-----\t\t-----B-----\t\t-----C-----\n\n\n");


}

//void MoveAhoy(int num, bool* Ahoy1, bool* Ahoy2, bool* Ahoy3) {
//	int TopArr[3] = { 1,100,100 };
//	int stt;
//	int dtn;
//	int tmp1, tmp2;
//	for (int i = 0; i < num; i++) {
//		for (int j = 0; j < initArr[i], j++) {
//			if (i==0 && j==0) {
//				Ahoy1[0] = false;
//				TopArr[0] = 100;
//				if (num % 2 == 0) {
//					Ahoy2[4] = true;
//					TopArr[1] = 1;
//				}
//				else {
//					Ahoy3[4] = true;
//					TopArr[2] = 1;
//				}
//			}
//
//			if (Ahoy1[numArr[i][j] - 1] == true) {
//				stt = 1;
//
//				for (int k = 0; k < num; k++) {
//					
//				}
//			}
//			else if (Ahoy2[numArr[i][j] - 1] == true) {
//				stt = 2;
//			}
//			else if (Ahoy3[numArr[i][j] - 1] == true) {
//				stt = 3;
//			}
//
//			if(numArr[i][j]>TopArr[0])
//			numArr[i][j]
//		}
//	}
//}
int** numArr;
int* initArr;
void MakeSeq(int num) {
	initArr = (int*)calloc(num, sizeof(int));
	numArr = (int**)calloc(num, sizeof(int*));
	for (int i = 0; i < num; i++) {
		initArr[i] = 1 << i;
		numArr[i] = (int*)calloc(initArr[i], sizeof(int));
	}


	for (int i = 0; i < num; i++) {
		numArr[i][0] = i+1;
		int k = 0, l = 0;
		for (int j = 1; j < initArr[i]; j++) {
			numArr[i][j] = numArr[k][l];
			l++;
			if (l >= initArr[k]) {
				l = 0;
				k++;
			}
		}
	}

	for (int i = 0, ArrSizeNum=1; i < num; i++,ArrSizeNum<<=1) {
		for (int j = 0; j < ArrSizeNum; j++) {
			printf("%d ", numArr[i][j]);
		}
		printf("\n");
	}
}

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) {
		printf("No.1 disk moves from %c to %c\n", from, to);
		PrintAhoy(1,from,to);
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("No.%d disk moves from %c to %c\n",n, from, to);
		PrintAhoy(n,from,to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}

int main() {
	int i, count = 1;

	scanf("%d", &num);

	Ahoy1 = (int*)calloc(num, sizeof(int));
	Ahoy2 = (int*)calloc(num, sizeof(int));
	Ahoy3 = (int*)calloc(num, sizeof(int));

	for (i = 0; i < num; i++) {
		Ahoy1[i] = i+1;
		Ahoy2[i] = 0;
		Ahoy3[i] = 0;
		tw1 += (1 << i);
	}
	printf("INITIAL STATE\n");
	PrintAhoy(0, '\0', '\0');
	hanoi_tower(num, 'A', 'B', 'C');

	return 0;
}