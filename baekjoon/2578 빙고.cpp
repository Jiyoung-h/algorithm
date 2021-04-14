#include<iostream>
#include<vector>
#include<map>
using namespace std;
bool isbingo(int board[][5]) {
    bool flag;
    int count = 0;
    for (int i = 0; i < 5; i++) {
        flag = false;
        for (int j = 0; j < 5; j++) {
            if (board[i][j] != 0) {
                flag = true;
                break;
            }
        }
        if (!flag) count++;
    }
    for (int i = 0; i < 5; i++) {
        flag = false;
        for (int j = 0; j < 5; j++) {
            if (board[j][i] != 0) {
                flag = true;
                break;
            }
        }
        if (!flag) count++;
    }
    flag = false;
    for (int i = 0; i < 5; i++) {
        if (board[i][i] != 0) {
            flag = true;
            break;
        }
    }
    if (!flag) count++;
    flag = false;
    for (int i = 0; i < 5; i++) {
        if (board[i][4 - i] != 0) {
            flag = true;
            break;
        }
    }
    if (!flag) count++;
    if (count >= 3) return true;
    else return false;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int bingo[5][5];
    map<int, pair<int, int>> m;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            cin >> bingo[i][j];
            m[bingo[i][j]] = { i, j };
        }            
    for (int i = 0; i < 25; i++) {
        int num;
        cin >> num;
        bingo[m[num].first][m[num].second] = 0;
        if (isbingo(bingo)) {
            cout << i + 1;
            break;
        }
    }
}
