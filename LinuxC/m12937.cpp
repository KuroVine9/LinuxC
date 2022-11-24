#include <vector>

using namespace std;

int findBigYaksu(int a, int b) {
    return (b ? findBigYaksu(b, a % b) : a);
}

void makeYaksuArr(vector<int> arr, vector<int>& yaksu) {
    if (arr.size() == 1) {
        yaksu.push_back(arr[0]);
    }

    int temp = findBigYaksu(arr[0], arr[1]);
    arr.erase(arr.begin(), ++(arr.begin()));
    for (auto a : arr) temp = findBigYaksu(temp, a);

    for (int i = temp; i > 1; i--) {
        if (!(temp % i)) yaksu.push_back(i);
    }  //1을 제외한 약수를 내림차순으로 반환
}

bool isDiv(int num, vector<int> arr) {
    bool temp = true;
    for (auto a : arr) temp = temp && (a % num != 0);
    //arr중 하나라도 나누어지면 false 리턴
    return temp;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    vector<int> yaksu;
    makeYaksuArr(arrayA, yaksu);
    for (auto a : yaksu) {
        if (isDiv(a, arrayB)) {
            answer = a;
            break;
        }
    }
    yaksu = vector<int>();

    makeYaksuArr(arrayB, yaksu);
    for (auto a : yaksu) {
        if (isDiv(a, arrayA)) {
            if (a > answer) answer = a;
            break;
        }
    }
    return answer;
}
