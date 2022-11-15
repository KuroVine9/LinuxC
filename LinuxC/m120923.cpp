#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int num, int total) {
	vector<int> answer;
	int st_num = total / num;
	if (total % num == 0) {
		answer.push_back(st_num);
		for (int count = 1; num != 1; count++, num-=2) {
			answer.push_back(st_num + count);
			answer.push_back(st_num - count);
		}
	}
	else {
		answer.push_back(st_num);
		answer.push_back(st_num + 1);
		for (int count = 1; num != 2; count++, num -= 2) {
			answer.push_back(st_num + count + 1);
			answer.push_back(st_num - count);
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	int num, total;
	cin >> num >> total;
	vector<int> &v = solution(num, total);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}