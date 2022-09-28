#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* str, * pos, count = 0, search[10];
	str = (char*)malloc(400);
	strcpy(str, "홍길동전은 허균이 지은 한국의 대표 의적이야기로 의로운 도적을 소재로 한 소설이다. " 
		"심청전, 춘향전과 더불어 한국의 대표적인 고전소설로 꼽힌다. ");
	printf("검색할 단어를 입력하시오: ");
	scanf("%s", search);

	for (pos = str; pos != NULL;(pos = strstr(pos, search))) {
		if ((pos = strstr(pos, search)) != NULL) {
			count++;
			pos += strlen(search);
		}
	}

	printf("\"%s\"은(는) %d번 나옴. \n", search, count);
	return 0;
}