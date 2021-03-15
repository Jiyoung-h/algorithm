#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n;
vector<vector<char>> board;
vector<vector<char>> board1;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int x, int y, vector<vector<char>>& board) {
	char color = board[x][y];
	queue<pair<int, int>> q;
	q.push({ x, y });
	board[x][y] = -1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < n && ny < n && nx >= 0 && ny >= 0) {
				if (board[nx][ny] == color) {
					board[nx][ny] = -1;
					q.push({ nx, ny });
				}
			}
		}
	}
}

int main() {
	cin >> n;
	board.resize(n, vector<char>(n));
	board1.resize(n, vector<char>(n));
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			board1[i][j] = board[i][j] = str[j];
			if (board1[i][j] == 'R') {
				board1[i][j] = 'G';
			}
		}
	}
	int index1 = 0;
	int index2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'R' || board[i][j] == 'G' || board[i][j] == 'B') {
				bfs(i, j, board);
				index1++;
			}
			if (board1[i][j] == 'G' || board1[i][j] == 'B') {
				bfs(i, j, board1);
				index2++;
			}
		}
	}
	cout << index1 << " " << index2;
}
