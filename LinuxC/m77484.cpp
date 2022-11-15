    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    bool isContain(vector<int> source, int val) {
        bool answer = false;
        for (int n : source) answer = answer || (val == n);
        return answer;
    }

    vector<int> solution(vector<int> lottos, vector<int> win_nums) {
        vector<int> answer;
        int min_mchg = 0; //일치한 번호의 개수
        int count = 0;  //0의 개수
        for (int n : win_nums) {
            if (isContain(lottos, n)) min_mchg++;
        }
        sort(lottos.begin(), lottos.end());
        for (int n : lottos) {
            if (n != 0) break;
            count++;
        }

        switch (min_mchg + count) {
        case 0:
        case 1:
            answer.push_back(6);
            answer.push_back(6);
            break;
        default:
            answer.push_back(7 - (min_mchg + count));
            answer.push_back(7 - (min_mchg==0?1:min_mchg));

        }
        /*answer.push_back(7 - (min_mchg + count));
        answer.push_back(7 - min_mchg);*/

        return answer;
    }