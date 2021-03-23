#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
// 0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽
int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> board(n, vector<int>(n));
	int x, y;
	vector<pair<int, int>> apples;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		apples.push_back({ x - 1, y - 1 });
		board[x - 1][y - 1] = 1;
	}
	cin >> k;
	char c;
	vector<pair<int, char>> dir;
	for (int i = 0; i < k; i++) {
		cin >> x >> c;
		dir.push_back({ x, c });
	}
	queue<pair<int, int>> q;
	q.push({ 0,0, });	// x, y, d
	int idx = 0;
	int d = 0;
	int time = 0;
	pair<int, int> head = { 0,0 };
	board[0][0] = 2;
	while (1) {
		int cx = head.first;
		int cy = head.second;
		if (idx < k && dir[idx].first == time) {
			if (dir[idx].second == 'D') {
				d++;
				if (d > 3)d -= 4;
			}
			else {
				d--;
				if (d < 0)d += 4;
			}
			idx++;
		}
		int nx = cx + dx[d];
		int ny = cy + dy[d];
		time++;
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			break;
		}
		if (board[nx][ny] == 2) {
			break;
		}
		if (board[nx][ny] == 1) {
			board[nx][ny] = 0;
		}
		else {
			board[q.front().first][q.front().second] = 0;
			q.pop();
		}
		q.push({ nx, ny });
		board[nx][ny] = 2;
		head = { nx, ny };
	}
	cout << time;
}
