#include <iostream>

using namespace std;
int _state = 0;
int read() {
	return (!_state ? _state++ : 1);
}

int main() {
	cout << read();
	cout << read();
	cout << read();
	_state = 0;
	cout << read();
	cout << read();
}