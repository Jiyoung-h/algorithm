#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0,0 };
int n, m;
vector<vector<int>> board;
vector<vector<int>> space;
vector<vector<bool>> visit;
vector<int> table;

void bfs(int x, int y, int index) {
	queue<pair<int, int>> q;
	q.push({ x ,y });
	space[x][y] = index;
	visit[x][y] = true;
	int count = 1;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			if (nx < n && ny < m && nx >= 0 && ny >= 0) {
				if (board[nx][ny] == 0 && !visit[nx][ny]) {
					q.push({ nx, ny });
					visit[nx][ny] = true;
					space[nx][ny] = index;
					count++;
				}
			}
		}
	}
	table.push_back(count);
}
int main() {
	cin >> n >> m;
	board.resize(n, vector<int>(m));  // 입력
	space.resize(n, vector<int>(m));  // 빈칸의 index
	visit.resize(n, vector<bool>(m)); // 빈칸을 방문했는지

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {
			board[i][j] = input[j] - '0';
		}
	}
	
	int index = 1;
	table.push_back(0); // table[빈칸의 index] = 인접한 빈칸의 갯수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 && !visit[i][j]) {
				bfs(i, j, index);
				index++;
			}
		}
	}
	vector<vector<int>> answer(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				set<int> s;
				answer[i][j] = 1;
				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					if (nx < n && ny < m && nx >= 0 && ny >= 0) {
						if (board[nx][ny] == 0)
							s.insert(space[nx][ny]);	// 인접한 빈칸의 index
					}
				}   // s에 들어있는 빈칸 index의 
				for (auto k : s) answer[i][j] += table[k];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << answer[i][j] % 10;
		}
		cout << "\n";
	}
}
