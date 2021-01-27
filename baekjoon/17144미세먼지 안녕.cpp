#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int r, c, t;
int board[50][50];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int airx2;
int airy;

void spread() {
    int diff[50][50] = { 0, };
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] != 0 && board[i][j] != -1) {
                int tmp = board[i][j] / 5;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (board[nx][ny] != -1 && nx >= 0 && nx < r && ny >= 0 && ny < c) {
                        diff[nx][ny] = diff[nx][ny] + tmp;
                        board[i][j] = board[i][j] - tmp;
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (diff[i][j] != 0) {
                board[i][j] += diff[i][j];
            }
        }
    }
}
void aircondition() {
    int airx1 = airx2 - 1;

    for (int i = airx1 - 1; i > 0; i--)
        board[i][0] = board[i - 1][0];
    for (int i = 0; i < c - 1; i++)
        board[0][i] = board[0][i + 1];
    for (int i = 1; i <= airx1; i++)
        board[i - 1][c - 1] = board[i][c - 1];
    for (int i = c - 1; i > 1; i--)
        board[airx1][i] = board[airx1][i - 1];
    board[airx1][1] = 0;

    for (int i = airx2 + 1; i < r - 1; i++)
        board[i][0] = board[i + 1][0];
    for (int i = 0; i < c - 1; i++)
        board[r - 1][i] = board[r - 1][i + 1];
    for (int i = r - 1; i >= airx2; i--)
        board[i][c - 1] = board[i - 1][c - 1];
    for (int i = c - 1; i > 1; i--)
        board[airx2][i] = board[airx2][i - 1];
    board[airx2][1] = 0;
}
int main() {
    cin >> r >> c >> t;
    int a;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a;
            if (a == -1) {
                airx2 = i;
                airy = j;
            }
            board[i][j] = a;
        }
    }

    for (int i = 0; i < t; i++) {
        spread();
        aircondition();
    }
    int answer = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] != 0) {
                answer += board[i][j];
            }
        }
    }
    cout << answer + 2;
}
