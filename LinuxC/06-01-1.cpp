/*
i->0~arr.length

if ( arr[i]가 arr[i+1]보다 큰가)
->크다면 교환
->반복

arr[i]에는 최솟값 존재

-다음 루프-
i+1~arr.length까지 반복(이전 루프에서의 i는 이미 최솟값 존재-> 교환 불필요)

...
반복
*/

#include <stdio.h>

int main() {
	int arr[] = { 6,8,9,7,4,5,1,3,2 };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (int j = i; j < sizeof(arr) / sizeof(arr[0]); j++) {

		}
	}
}