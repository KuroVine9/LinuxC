#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* str, * pos, count = 0, search[10];
	str = (char*)malloc(400);
	strcpy(str, "ȫ�浿���� ����� ���� �ѱ��� ��ǥ �����̾߱�� �Ƿο� ������ ����� �� �Ҽ��̴�. " 
		"��û��, �������� ���Ҿ� �ѱ��� ��ǥ���� �����Ҽ��� ������. ");
	printf("�˻��� �ܾ �Է��Ͻÿ�: ");
	scanf("%s", search);

	for (pos = str; pos != NULL;(pos = strstr(pos, search))) {
		if ((pos = strstr(pos, search)) != NULL) {
			count++;
			pos += strlen(search);
		}
	}

	printf("\"%s\"��(��) %d�� ����. \n", search, count);
	return 0;
}