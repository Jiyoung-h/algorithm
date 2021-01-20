#include <string>
#include <iostream>
#include <vector>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<string> board1, board2;

    for (int i = 0; i < n; i++) {
        string tmp = "";
        for (int j = m - 1; j >= 0; j--) {
            tmp = tmp + board[j].substr(i, 1);
        }
        board1.push_back(tmp);
    }

    while (1) {
        bool check[30][30] = { false, };
        bool replay = false;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < board1[i].size(); j++) {
                if (board1[i][j] == board1[i + 1][j]
                    && board1[i][j] == board1[i][j + 1]
                    && board1[i][j] == board1[i + 1][j + 1]) {
                    check[i][j] = true;
                    check[i + 1][j] = true;
                    check[i][j + 1] = true;
                    check[i + 1][j + 1] = true;
                    replay = true;
                }
            }
        }
        if (replay) {
            for (int i = 0; i < n; i++) {
            string tmp = "";
                for (int j = 0; j < board1[i].size(); j++) {
                    if (!check[i][j]) {
                        tmp = tmp + board1[i].substr(j, 1);
                    }
                }
                board2.push_back(tmp);
            }
            board1 = board2;
            board2.clear();
        }
        else {
            for (int i = 0; i < board1.size(); i++) {
                answer = answer + board1[i].length();
            }
            return m * n - answer;
        }
    }
}
