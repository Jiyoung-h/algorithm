#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, m, k, answer;
vector<string> board;
map<char, vector<pair<int, int>>> mm;
map<string, int> memo;
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,-1,1,1,-1 };
int circle(int xy, int nm) {
	if (xy < nm && xy >= 0) return xy;
	if (xy >= nm) return xy - nm;
	if (xy < 0)return xy + nm;
}
void dfs(int x, int y, string str) {
	if (str.empty()) {
		answer++;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int nx = circle(x + dx[i], n);
		int ny = circle(y + dy[i], m);
		if (board[nx][ny] == str[0]) {
			dfs(nx, ny, str.substr(1, 5));
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	board.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < board[i].length(); j++) {
			mm[board[i][j]].push_back({ i, j });
		}
	}
	string str;
	for (int i = 0; i < k; i++) {
		cin >> str;
		if (!memo[str]) {
			answer = 0;
			for (int j = 0; j < mm[str[0]].size(); j++) {
				int x = mm[str[0]][j].first;
				int y = mm[str[0]][j].second;
				dfs(x, y, str.substr(1, 5));
			}
			memo[str] = answer;
		}
		cout << memo[str] << "\n";
	}
}
