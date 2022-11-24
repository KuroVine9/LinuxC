#include <string>
#include <vector>

using namespace std;

bool compare(vector<int> A, vector<int> B)
{
	return ((A[0] == B[0]) || (A[1] == B[1]));
}

int solution(vector<vector<int>> dots) {
	for (auto& dot : dots) {
		if (!compare(dots[0], dot))
			return abs(dots[0][0] - dot[0]) * abs(dots[0][1] - dot[1]);
	}
	return NULL;
}