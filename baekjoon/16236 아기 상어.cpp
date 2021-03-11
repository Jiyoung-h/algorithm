#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
tuple<int,int,int> bfs(vector<vector<int>> &a, int x, int y, int size) {
    // a: board, (x, y): 아기상어의 위치, size: 아기상어의 크기
    int n = a.size();
    vector<tuple<int,int,int>> ans;    // 먹을 수 있는 물고기 (거리, 위치 x, y)
    vector<vector<int>> d(n, vector<int> (n, -1));    // 움직인 거리
    queue<pair<int,int>> q;    // 아기상어의 움직임
    q.push(make_pair(x,y));
    d[x][y] = 0;
    while (!q.empty()) {
        tie(x,y) = q.front();
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && d[nx][ny] == -1) {
                bool ok = false;
                bool eat = false;
                if (a[nx][ny] == 0) {
                    ok = true;
                } else if (a[nx][ny] < size) { 
                    ok = eat = true;
                } else if (a[nx][ny] == size) { 
                    ok = true;
                }
                if (ok) {
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = d[x][y] + 1;
                    if (eat) {
                        ans.push_back(make_tuple(d[nx][ny],nx,ny));
                    }
                }
            }
        }
    }
    if (ans.empty()) {
        return make_tuple(-1,-1,-1);
    }
    // 먹을 수 있는 물고기를 거리순으로 정렬해서 첫번째 물고기를 반환
    // 정렬 : 거리순, 왼쪽에 있는순
    sort(ans.begin(), ans.end());
    return ans[0];
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    int x, y;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                tie(x, y) = make_pair(i, j);
                a[i][j] = 0;
                // 아기상어가 있던 자리는 빈칸
            }
        }
    }
    int ans = 0;
    int size = 2;
    int exp = 0;
    while (true) {
        int nx, ny, dist;
        tie(dist,nx,ny) = bfs(a, x, y, size);
        // 더이상 먹을 물고기가 없으면
        if (dist == -1) break;
        // 먹은 자리는 빈칸
        a[nx][ny] = 0;
        ans += dist;
        exp += 1;    // 먹은 물고기
        if (size == exp) {
            size += 1;
            exp = 0;
        }
        tie(x,y) = make_pair(nx,ny);
    }
    cout << ans << '\n';
    return 0;
}
