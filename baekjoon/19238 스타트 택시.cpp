#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m, oil;
int tx, ty;
vector<vector<int>> board;
vector<pair<pair<int, int>, pair<int, int>>> guest;
vector<int> dis;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
bool flag;
pair<pair<int, int>, pair<int, int>> findShortestGuest() {
    pair<int, int> result;
    vector<vector<bool>> visited(n, vector<bool>(n));
    queue<pair<int, pair<int, int>>> q;
    // { 거리, {x, y} }
    q.push({ 0, { tx, ty } });
    visited[tx][ty] = true;
    // { { x, y }, { 거리, 인덱스 } }
    vector<pair<pair<int, int>, pair<int, int>>> tmp;
    while (!q.empty()) {
        int count = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        if (!tmp.empty() && tmp[0].second.first < count) break;
        if (board[cx][cy] - 10 >= 0) {
            tmp.push_back({ {cx, cy}, { count, board[cx][cy] - 10 } });
        }
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n 
                || board[nx][ny] == 1 || visited[nx][ny]) continue;
            q.push({ count + 1, {nx, ny} });
            visited[nx][ny] = true;
        }
    }
    if (tmp.empty()) { return { {-1, -1},{-1, -1} }; }
    sort(tmp.begin(), tmp.end());
    return tmp[0];
}
int goToGoal(int index) {
    int cx = guest[index].first.first;
    int cy = guest[index].first.second;
    int gx = guest[index].second.first;
    int gy = guest[index].second.second;
    vector<vector<bool>> visited(n, vector<bool>(n));
    queue<pair<pair<int, int>, int>> q;
    q.push({ { cx, cy }, 0 });
    visited[cx][cy] = true;
    while (!q.empty()) {
        cx = q.front().first.first;
        cy = q.front().first.second;
        int count = q.front().second;
        if (cx == gx && cy == gy) {
            return count;
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n
                || board[nx][ny] == 1 || visited[nx][ny]) continue;
            q.push({ { nx, ny }, count + 1 });
            visited[nx][ny] = true;
        }
    }
    return -1;
}
int main() {
    cin >> n >> m >> oil;
    board.resize(n, vector<int>(n));
    guest.resize(m);
    dis.resize(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    cin >> tx >> ty;
    tx--; ty--;
    int a, b, c, d;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        guest[i] = { {a, b},{c,d} };
        board[guest[i].first.first][guest[i].first.second] = i + 10;
    }
    bool flag = false;
    int tcount = 0;
    while (!flag) {
        // { { x, y }, { 거리, 인덱스 } }
        pair<pair<int, int>, pair<int, int>> tmp = findShortestGuest();
        int x = tmp.first.first;
        if (x == -1) {
            if (tcount != m) flag = true;
            break;
        }
        tcount++;
        int y = tmp.first.second;
        int distance = tmp.second.first;
        int index = tmp.second.second;
        oil -= distance;
        if (oil < 0) { flag = true; break; }
        board[x][y] = 0;
        int consum = goToGoal(index);
        if(consum == -1) { flag = true; break; }
        oil -= consum;
        if (oil < 0) { flag = true; break; }
        oil += (consum * 2);
        tx = guest[index].second.first;
        ty = guest[index].second.second;
    }
    if (!flag) cout << oil;
    else cout << -1;
}
