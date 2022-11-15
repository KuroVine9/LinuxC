#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

int main() {
	std::vector<char> v = { 'A' ,'B','C','D','E','F' };
	int intArray[] = { 1,2,3,4,5,6,7 };
	std::for_each(v.begin(), v.end(), [](auto ch) {std::cout << ch; });
	std::cout << std::endl;
	std::for_each(intArray, &intArray[7], [](auto ch) {std::cout << ch << " "; });
	return 0;
}