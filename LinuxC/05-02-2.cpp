#include <stdio.h>

int main() {
	int x;
	int sum = 0;
	int count = 0;
	double ave;

	while (1) {
		printf("���� ������ �Է��Ͻÿ�(����: ��) :");
		scanf("%d", &x);

		if (x < 0) 
			break;
		//else if (x > 100)
		//	continue;
		else if (x <= 100) {
			sum += x;
			count++;
		}
	}
	ave = (double)sum / (double)count;

	printf("�հ�: %d, ���: %d, ����: %d\n", sum, ave, count);

	return 0;
}