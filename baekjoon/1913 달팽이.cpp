#include <iostream>
#include <vector>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
// 아래 -> 오른쪽 -> 위 -> 왼쪽
int main() {
	int n, k;
	cin >> n >> k;
	int ansx, ansy;
	vector<vector<int>> board(n, vector<int>(n));
	int mid = n / 2;
	int x = 0;
	int y = 0;
	int c = n * n;
    if (c == k) {
		ansx = x;
		ansy = y;
	}
	board[x][y] = c;
	int i = 0;
	while (!(x == mid && y == mid)) {
		while (1) {
			x += dx[i];
			y += dy[i];
			if (x > n - 1 || y > n - 1 || x < 0 || y < 0) {
				x -= dx[i];
				y -= dy[i];
				break;
			}
			if (board[x][y] == 0) {
				board[x][y] = --c;
				if (c == k) {
					ansx = x;
					ansy = y;
				}
			}
			else {
				x -= dx[i];
				y -= dy[i];
				break;
			}
		}
		i = (i + 1) % 4;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << ansx + 1 << " " << ansy + 1;
}
