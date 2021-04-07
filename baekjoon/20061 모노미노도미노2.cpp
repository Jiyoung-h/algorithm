#include <iostream>
#include <vector>
using namespace std;
int n;
int td[3][2] = { {0, 0},{0, 1},{1, 0} };
vector<pair<int, pair<int, int>>> info;
vector<vector<int>> blue;
vector<vector<int>> green;
int answer{};
void blockDown(int t, int row, vector<vector<int>> &board) {
	int i = 5;
	for (; i >= 0; i--) {
		int ni = i + td[t][0];
		int nrow = row + td[t][1];
		if (ni > 5) continue;
		if (board[i][row] == 1 || board[ni][nrow] == 1) { 
			board[i + 1][row] = 1;
			board[ni + 1][nrow] = 1;
			return; 
		}
	}
	board[0][row] = 1;
	board[0 + td[t][0]][row + td[t][1]] = 1;
}
void blockBreak(vector<vector<int>>& board) {
	vector<int> row;
	for (int i = 5; i >= 0; i--) {
		if (board[i] == vector<int>({1, 1, 1, 1})) row.push_back(i);
	}
	for (int i = 0; i < row.size(); i++) {
		board.erase(board.begin() + row[i]);
		answer++;
		board.push_back({ 0, 0, 0, 0 });
	}		
}
void eraseDown(vector<vector<int>>& board) {
	int count{};
	for (int i = 5; i >= 4; i--) {
		if (board[i] != vector<int>({ 0, 0, 0, 0 })) {
			count++;
		}
	}
	for (int i = 0; i < count; i++) {
		board.erase(board.begin());
		board.push_back({ 0, 0, 0, 0 });
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	info.resize(n);
	// info (t, (x, y))
	for (int i = 0; i < n; i++) {
		cin >> info[i].first >> info[i].second.first >> info[i].second.second;
	}
	blue.resize(6, vector<int>(4));
	green.resize(6, vector<int>(4));
	for (int i = 0; i < n; i++) {
		int t = info[i].first - 1;
		int bt;
		if (t == 0) bt = 0;
		else if (t == 1) bt = 2;
		else bt = 1;
		int x = info[i].second.first;
		int y = info[i].second.second;		
		blockDown(bt, x, blue);
		blockDown(t, y, green);
		blockBreak(blue);
		blockBreak(green);
		eraseDown(blue);
		eraseDown(green);
	}
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (blue[i][j] == 1) cnt++;
			if (green[i][j] == 1) cnt++;
		}
	}
	cout << answer << "\n" << cnt;
}
