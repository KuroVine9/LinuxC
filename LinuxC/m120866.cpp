#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board) {
    typedef struct Point{
        Point(int x, int y) : x(x), y(y) {}
        int x, y;
    } Point;
    vector<Point> bomb;
    int answer = 0;
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 1) bomb.push_back(Point(i, j));
        }
    }

    return answer;
}