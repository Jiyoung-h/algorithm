#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;
int answer{};
vector<vector<int>> board;
int n;

int bMax() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > ans) {
                ans = board[i][j];
            }
        }
    }
    return ans;
}

void move(int d) {
    if (d == 0) {       // 오른쪽으로
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] != 0) q.push(board[i][j]);
                board[i][j] = 0;
            }
            int j = n - 1;
            while (!q.empty()) {
                int front = q.front();
                q.pop();
                if (board[i][j] == 0)
                    board[i][j] = front;
                else if (board[i][j] == front) {
                    board[i][j] *= 2;
                    j--;
                }
                else {
                    j--;
                    board[i][j] = front;
                }
            }
        }
    }
    else if (d == 1) {  // 왼쪽으로
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 0) q.push(board[i][j]);
                board[i][j] = 0;
            }
            int j = 0;
            while (!q.empty()) {
                int front = q.front();
                q.pop();
                if (board[i][j] == 0)
                    board[i][j] = front;
                else if (board[i][j] == front) {
                    board[i][j] *= 2;
                    j++;
                }
                else {
                    j++;
                    board[i][j] = front;
                }
            }
        }
    }
    else if (d == 2) {  // 아래로
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = n - 1; j >= 0; j--) {
                if (board[j][i] != 0) q.push(board[j][i]);
                board[j][i] = 0;
            }
            int j = n - 1;
            while (!q.empty()) {
                int front = q.front();
                q.pop();
                if (board[j][i] == 0)
                    board[j][i] = front;
                else if (board[j][i] == front) {
                    board[j][i] *= 2;
                    j--;
                }
                else {
                    j--;
                    board[j][i] = front;
                }
            }
        }
    }
    else if (d == 3) {  // 위로
        for (int i = 0; i < n; i++) {
            queue<int> q;
            for (int j = 0; j < n; j++) {
                if (board[j][i] != 0) q.push(board[j][i]);
                board[j][i] = 0;
            }
            int j = 0;
            while (!q.empty()) {
                int front = q.front();
                q.pop();
                if (board[j][i] == 0)
                    board[j][i] = front;
                else if (board[j][i] == front) {
                    board[j][i] *= 2;
                    j++;
                }
                else {
                    j++;
                    board[j][i] = front;
                }
            }
        }
    }
}

void dfs(int count) {
    if (count == 5) {
        int tmp = bMax();
        answer = (answer > tmp) ? answer : tmp;
    }
    else {
        vector<vector<int>> copy = board;
        for (int i = 0; i < 4; i++) {
            move(i);
            dfs(count + 1);
            board = copy;
        }
    }
}

int main() {
    cin >> n;
    board.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    dfs(0);
    cout << answer;
}
