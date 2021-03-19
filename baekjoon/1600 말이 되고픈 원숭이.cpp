#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
int mx[4] = { 0,0,-1,1 };
int my[4] = { -1,1,0,0 };
int hx[8] = { -2,-2,-1,-1,1,1,2,2 };
int hy[8] = { -1, 1,-2,2,-2,2,-1,1 };
bool visited[201][201][31] = { false, };
struct S {
	int x;
	int y;
	int k;
	int n;
	S(int x, int y, int k, int n) :x(x), y(y), k(k), n(n) {};
};
int main() {
	int k, w, h;
	cin >> k >> w >> h;
	vector<vector<int>> board(h, vector<int>(w));	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
		}
	}
	// 위치 x, y, 말처럼 이동한 횟수 n
	queue<S> q;
	q.push(S(0, 0, 0, 0));
	visited[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int n = q.front().k;
		int count = q.front().n;
		q.pop();
		if (x == h - 1 && y == w - 1) {
			cout << count;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + mx[i];
			int ny = y + my[i];
			if (nx < h && ny < w && nx >= 0 && ny >= 0 && !visited[nx][ny][n] && board[nx][ny] == 0) {
				q.push(S(nx, ny, n, count + 1));
				visited[nx][ny][n] = true;
			}
		}
		if (n < k) {
			for (int i = 0; i < 8; i++) {
				int nx = x + hx[i];
				int ny = y + hy[i];
				if (nx < h && ny < w && nx >= 0 && ny >= 0 && !visited[nx][ny][n + 1] && board[nx][ny] == 0) {
					q.push(S(nx, ny, n + 1, count + 1));
					visited[nx][ny][n + 1] = true;
				}
			}
		}
	}
    cout << -1;
}
