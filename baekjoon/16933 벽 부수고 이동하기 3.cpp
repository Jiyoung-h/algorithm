#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1,-1 };
struct S {
	int x;	// 위치 x, y
	int y;
	int k;	// 벽 부신 횟수
	int d;	// 거리
	bool day;
	S(int x, int y, int k, int d, bool day) :x(x), y(y), k(k), d(d), day(day) {};
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	string input;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {
			board[i][j] = input[j] - '0';
		}
	}
	queue<S> q;
	q.push(S(0, 0, 0, 1, true));
	vector<vector<vector<bool>>> check(n, vector<vector<bool>>(m, vector<bool>(k + 1)));
	check[0][0][0] = true;
	int answer = 0;
	while (!q.empty()) {
		S p = q.front();
		q.pop();
		int cx = p.x;
		int cy = p.y;
		int ck = p.k;
		int cd = p.d;
		bool cday = p.day;
		if (cx == n - 1 && cy == m - 1) {
			cout << cd;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < n && ny < m && nx >= 0 && ny >= 0 && !check[nx][ny][ck]) {
				if (board[nx][ny] == 0) {	// 빈칸
					q.push(S(nx, ny, ck, cd + 1, !cday));
					check[nx][ny][ck] = true;
				}
				else {	// 벽
					if (ck + 1 <= k && !check[nx][ny][ck + 1]) { // 횟수가 남아 있으면
						if (cday) {
							q.push(S(nx, ny, ck + 1, cd + 1, !cday));
							check[nx][ny][ck + 1] = true;
						}
						else {	 // 벽이면서 밤
							q.push(S(cx, cy, ck, cd + 1, !cday));
						}
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}
