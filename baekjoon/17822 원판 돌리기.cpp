#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m, t;
int answer{};
vector<vector<int>> board;
int sum;
int num;
void rotation(int n, int d, int k) {
    for (int i = 0; i < k; i++) {  // j번째 원판을 d방향으로 k만큼 회전
        if (d == 0) {
            int tmp = board[n][m - 1];
            for (int j = m - 1; j > 0; j--) {
                board[n][j] = board[n][j - 1];
            }
            board[n][0] = tmp;
        }
        else if (d == 1) {
            int tmp = board[n][0];
            for (int j = 0; j < m-1; j++) {
                board[n][j] = board[n][j + 1];
            }
            board[n][m - 1] = tmp;
        }
    }
}
void adjCheck() {
    vector<vector<bool>> check(n, vector<bool>(m));
    answer = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j + 1 < m && board[i][j] == board[i][j + 1] && board[i][j] != -1) {
                check[i][j] = check[i][j + 1] = true;
            }
            if (board[i][0] == board[i][m - 1] && board[i][0] != -1) {
                check[i][0] = check[i][m - 1] = true;
            }
            if (i + 1 < n && board[i][j] == board[i + 1][j] && board[i][j] != -1) {
                check[i][j] = check[i + 1][j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j]) {      // 지워야 할 수
                sum -= board[i][j];
                board[i][j] = -1;
                num--;
                flag = true;
            }
        }
    }
    if (!flag) {    // 지워야 할 수가 없으면 평균과 비교하여 +1, -1
        double avg = (double)sum / (double)num;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != -1 && board[i][j] > avg) {
                    board[i][j]--;
                    sum--;
                }
                else if (board[i][j] != -1 && board[i][j] < avg) {
                    board[i][j]++;
                    sum++;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> t;
    board.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            sum += board[i][j];
            num++;
        }
    }
    int x, d, k;
    for (int i = 0; i < t; i++) {   // 돌림 횟수
        cin >> x >> d >> k;
        for (int j = 0; j < n; j++) {   // 모든 원판
            if ((j + 1) % x == 0) { // x의 배수 원판이면
                rotation(j, d, k);  // j번째 원판을 d방향으로 k만큼 회전
            }
        }
        adjCheck();    // 돌릴 때마다 체크
        if (sum == 0) break;
    }
    cout << sum;
}
