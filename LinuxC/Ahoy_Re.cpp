#include <stdio.h>
#include <stdlib.h>
#define SEQ_SIZE(X) ((1 << X) - 1)
#define DISK_NUM(X) (1 << (X - 1))

void PrintScrn(int*tower,int num) {
	int count1 = 0, count2 = 0, count3 = 0;
	int tmp1, tmp2, tmp3;
	int* PrintArr1 = (int*)calloc(num, sizeof(int));
	int* PrintArr2 = (int*)calloc(num, sizeof(int));
	int* PrintArr3 = (int*)calloc(num, sizeof(int));

	tmp1 = tower[0];
	tmp2 = tower[1];
	tmp3 = tower[2];

	for (int i = num - 1; i >= 0; i--) {
		if (tmp1 - (1 << i) >= 0) {
			PrintArr1[num - count1 - 1] = i + 1;
			tmp1 -= (1 << i);
			count1++;
		}
		if (tmp2 - (1 << i) >= 0) {
			PrintArr2[num - count2 - 1] = i + 1;
			tmp2 -= (1 << i);
			count2++;
		}
		if (tmp3 - (1 << i) >= 0) {
			PrintArr3[num - count3 - 1] = i + 1;
			tmp3 -= (1 << i);
			count3++;
		}
	}
	for (; count1 < num; count1++) {
		PrintArr1[num - count1 - 1] = 0;
	}
	for (; count2 < num; count2++) {
		PrintArr2[num - count2 - 1] = 0;
	}
	for (; count3 < num; count3++) {
		PrintArr3[num - count3 - 1] = 0;
	}
	int i, j = 0;
	for (i = 0; i < num; i++) {
		if (PrintArr1[i] > 0) {
			for (j = 0; j < PrintArr1[i]; j++) {
				printf("*");
			}
		}
		for (; j < 11; j++) {
			printf(" ");
		}
		printf("\t\t");
		j = 0;

		if (PrintArr2[i] > 0) {
			for (j = 0; j < PrintArr2[i]; j++) {
				printf("*");
			}
		}
		for (; j < 11; j++) {
			printf(" ");
		}
		printf("\t\t");
		j = 0;

		if (PrintArr3[i] > 0) {
			for (j = 0; j < PrintArr3[i]; j++) {
				printf("*");
			}
		}
		for (; j < 11; j++) {
			printf(" ");
		}
		j = 0;

		printf("\n");
	}

	free(PrintArr1);
	free(PrintArr2);
	free(PrintArr3);
	printf("-----A-----\t\t-----B-----\t\t-----C-----\n");
}

int* MakeSeq(int num, int* Arr) {
	int count = 0;
	for (int i = 0; i < num; i++) {
		Arr[count++] = i + 1;
		for (int j = 0; j < SEQ_SIZE(i); j++, count++) {
			Arr[count] = Arr[j];
		}
	}
	return Arr;
}

void AhoyMove(int num, int* Seq, int* top, int*tower) {
	int i, j, k, tmp;
	int yuusen[3] = { 0 };
	int max;
	char From, To;

	printf("\nINITIAL STATE\n\n");
	PrintScrn(tower, num);
	printf("\n\n");

	for (i = 0; i < SEQ_SIZE(num); i++) {
		for (j = 0; j < 3; j++) {
			if (top[j] == Seq[i]) {
				From = j;
				break;
			}
		}
		if (i == 0) {
			To = (num % 2 == 0 ? 1 : 2);
		}
		else {
			yuusen[0] = 0;
			yuusen[1] = 0;
			yuusen[2] = 0;
			for (j = 0; j < 3; j++) {
				if (j == (int)From) continue;

				if (top[j] == Seq[i] + 1) {
					yuusen[j] = 4;
					break;
				}
				else if (top[j] == 0) {
					yuusen[j] = 2;
					continue;
				}
				else if (Seq[i] - top[j] > 0) {
					continue;
				}
				else if ((top[j] - Seq[i]) % 2 == 1) {
					yuusen[j] = 3;
					continue;
				}
				else if ((top[j] - Seq[i]) % 2 == 0) {
					yuusen[j] = 1;
					continue;
				}
			}
			for (j = 0, max = yuusen[0], To = j; j < 3; j++) {
				if (yuusen[j] > max) {
					max = yuusen[j];
					To = j;
				}
			}

		}
		//INIT
		tower[(int)From] -= DISK_NUM(Seq[i]);
		tower[(int)To] += DISK_NUM(Seq[i]);

		tmp = tower[(int)From];
		for (k = num; k > 0; k--) {
			if (tmp == 0 && k == num) {
				top[(int)From] = 0;
				break;
			}
			tmp = (tmp - DISK_NUM(k) >= 0 ? tmp - DISK_NUM(k) : tmp);
			if (tmp == 0) {
				top[(int)From] = k;
				break;
			}
		}
		tmp = tower[(int)To];
		for (k = num; k > 0; k--) {
			if (tmp == 0 && k == num) {
				top[(int)To] = 0;
				break;
			}
			tmp = (tmp - DISK_NUM(k) >= 0 ? tmp - DISK_NUM(k) : tmp);
			if (tmp == 0) {
				top[(int)To] = k;
				break;
			}
		}

		PrintScrn(tower,num);
		printf(" MOV No.%d disk From %c To %c\n\n\n\n", Seq[i], From + 65, To + 65);

	}
}

int main() {
	int* seq;
	int top[3] = {1,0,0};	//타워 맨 위 디스크
	int tower[3] = { 0 };	//타워 디스크 인포
	int num;
	int count = 0;

	scanf("%d", &num);

	seq = (int*)calloc(SEQ_SIZE(num), sizeof(int));
	seq = MakeSeq(num, seq);

#if 0
	for (int i = 0; i < SEQ_SIZE(num); i++) {
		printf("%d", seq[i]);
	}
	printf("\n\n");
	//시퀸스 출력 예제
#endif
	tower[0] = SEQ_SIZE(num);
	AhoyMove(num, seq, top, tower);
	free(seq);

	return 0;
}