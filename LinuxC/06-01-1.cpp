/*
i->0~arr.length

if ( arr[i]�� arr[i+1]���� ū��)
->ũ�ٸ� ��ȯ
->�ݺ�

arr[i]���� �ּڰ� ����

-���� ����-
i+1~arr.length���� �ݺ�(���� ���������� i�� �̹� �ּڰ� ����-> ��ȯ ���ʿ�)

...
�ݺ�
*/

#include <stdio.h>

int main() {
	int arr[] = { 6,8,9,7,4,5,1,3,2 };

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for (int j = i; j < sizeof(arr) / sizeof(arr[0]); j++) {

		}
	}
}