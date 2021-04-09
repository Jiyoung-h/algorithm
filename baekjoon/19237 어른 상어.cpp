#include<iostream>
#include<vector>
using namespace std;
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int n, m, k;
vector<pair<pair<int, int>, int>> shark;
vector<vector<vector<int>>> sharkD;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> board(n, vector<pair<int, int>>(n));
    // board = { 상어 번호, 남은 냄새 시간 }
    // shark[상어 번호] = { 위치 {x, y}, 방향 d }
    shark.resize(m + 1);    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j].first;
            if (board[i][j].first != 0) {
                shark[board[i][j].first] = { {i, j}, 0 };
                board[i][j].second = k;
            }
        }
    }
    for (int i = 1; i <= m; i++)
        cin >> shark[i].second;
    sharkD.resize(m + 1, vector<vector<int>>(5, vector<int>(4)));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int d = 0; d < 4; d++) {
                cin >> sharkD[i][j][d];
            }
        }
    }
    int count = 1;
    while (1) {
        if (count > 1000) break;
        // tmp : 상어들의 위치 이동을 임시 저장하는 벡터
        vector<pair<pair<int, int>, int>> tmp(m + 1);
        for (int i = 1; i <= m; i++) {
            if (shark[i].second == -1) continue;
            int x = shark[i].first.first;
            int y = shark[i].first.second;
            int d = shark[i].second;
            bool flag = false;
            for (int j = 0; j < 4; j++) {
                int nd = sharkD[i][d][j];
                int nx = x + dx[nd];
                int ny = y + dy[nd];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (board[nx][ny].first == 0) {
                    tmp[i] = { { nx, ny }, nd };
                    flag = true;
                    break;
                }
            }
            // 인접한 칸에 빈칸이 없으면 자신의 냄새가 있는 칸으로 이동
            if (!flag) {
                for (int j = 0; j < 4; j++) {
                    int nd = sharkD[i][d][j];
                    int nx = x + dx[nd];
                    int ny = y + dy[nd];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (board[nx][ny].first == i) {
                        tmp[i] = { { nx, ny }, nd };
                        break;
                    }
                }
            }
        }
        int move = 0;
        for (int i = 1; i <= m; i++) {
            if (tmp[i].second == 0) continue;
            int x = tmp[i].first.first;
            int y = tmp[i].first.second;
            if (board[x][y].first == 0 || board[x][y].first == i) {
                board[x][y] = { i, k + 1 };
               shark[i] = tmp[i];
               move++;
            }
            else {
                // 번호가 작은 상어가 해당 칸에 위치해 있으면 잡아 먹힌다
                shark[i] = { {-1, -1}, -1 };
            }
        }
        // 움직인 상어가 1마리면 break
        if (move == 1)
            break;
        // 남은 냄새 시간을 1씩 감소시킨다
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) {
                if (board[i][j].second > 0) {
                    board[i][j].second--;
                    if (board[i][j].second == 0) board[i][j].first = 0;
                }
            }            
        }
        count++;
    }
    cout << (count > 1000 ? -1 : count);
}
