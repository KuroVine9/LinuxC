#include <iostream>

int gcd(int x, int y) {
	return (y == 0 ? x : gcd(y, x % y));
}

int main() {
	int x, y;

	std::cin >> x >> y;
	std::cout << gcd(x, y) << std::endl;
	std::cout << x * (y / gcd(x, y));

	return 0;
}