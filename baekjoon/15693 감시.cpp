#include <iostream>
using namespace std;
int n, m;
vector<pair<pair<int, int>, int>> cctv;
int cn, answer = -1;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0,1,0,-1 };

vector<vector<int>> go(int index, int d, vector<vector<int>> room) {
    int x = cctv[index].first.first;
    int y = cctv[index].first.second;
    while (x >= 0 && x < n && y >= 0 && y < m) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if (room[nx][ny] == 6) break;
            else if (room[nx][ny] < 0 && room[nx][ny] > 6) continue;
            room[nx][ny] = 9;
        }
        x = nx;
        y = ny;
    }
    return room;
}
int countBlind(vector<vector<int>> room) {
    int count{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (room[i][j] == 0) count++;
        }
    }
    return count;
}
void solve(int index, vector<vector<int>> room) {
    if (index == cn) {
        int temp = countBlind(room);
        if (answer == -1 || temp < answer) {
            answer = temp;
        }
    }
    else {
        int k = cctv[index].second;
        if (k == 1) {
            for (int i = 0; i < 4; i++) {
                vector<vector<int>> tmp = go(index, i, room);
                solve(index + 1, tmp);
            }
        }
        else if (k == 2) {
            for (int i = 0; i < 2; i++) {
                vector<vector<int>> tmp = go(index, i, room);
                tmp = go(index, i + 2, tmp);
                solve(index + 1, tmp);
            }
        }
        else if (k == 3) {
            for (int i = 0; i < 4; i++) {
                vector<vector<int>> tmp = go(index, i, room);
                tmp = go(index, (i + 1) % 4, tmp);
                solve(index + 1, tmp);
            }
        }
        else if (k == 4) {
            for (int i = 0; i < 4; i++) {
                vector<vector<int>> tmp = go(index, i, room);
                tmp = go(index, (i + 1) % 4, tmp);
                tmp = go(index, (i + 2) % 4, tmp);
                solve(index + 1, tmp);
            }
        }
        else {
            vector<vector<int>> tmp = room;
            for (int i = 0; i < 4; i++) {
                tmp = go(index, i, tmp);
            }
            solve(index + 1, tmp);
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int>> room(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
            if (room[i][j] > 0 && room[i][j] < 6) {
                cctv.push_back({ {i,j}, room[i][j] });
            }
        }
    }

    cn = cctv.size();
    solve(0, room);

    cout << answer;
}
