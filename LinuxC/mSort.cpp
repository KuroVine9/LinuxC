#include <iostream>

using namespace std;

void swap(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

int main() {
	int count, min;
	int* input;

	cin >> count;
	input = new int[count];

	for (int i = 0; i < count; i++) cin >> input[i];

	for (int i = 0; i < count; i++) {
		min = input[i];
		for (int j = i; j < count; j++) {
			if (input[j] < input[i]) swap(input[j], input[i]);
		}
	}

	for (int i = 0; i < count; i++) cout << input[i] << endl;


	return 0;
}