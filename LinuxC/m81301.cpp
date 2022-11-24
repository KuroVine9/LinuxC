#include <string>
#include <map>

using namespace std;

int solution(string s) {
    const map<string, int> apmap = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };
    int answer = 0;
    for (const auto& a : apmap)
    {
        size_t f_idx = 0;
        while ((f_idx = s.find(a.first)) != string::npos) {
            s.replace(f_idx, a.first.size(), to_string(a.second));
        }
    }
    for (const char& c : s) {
        answer *= 10;
        answer += c - '0';
    }
    return answer;
}