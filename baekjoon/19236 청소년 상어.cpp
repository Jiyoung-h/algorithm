#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
vector<int> answer;
void dfs(pair<pair<int, int>, int> shark, int eaten, vector<vector<pair<int, int>>> board, map<int, pair<int, int>> location) {
	for (int i = 1; i <= 16; i++) {
		if (location.find(i) == location.end()) continue;
		int x = location[i].first;
		int y = location[i].second;
		int d = board[x][y].second;
		int nx, ny;
		while (1) {
			nx = x + dx[d];
			ny = y + dy[d];
			if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
				if (nx != shark.first.first || ny != shark.first.second)
					break;
			d = (d + 1) % 8;
			board[x][y].second = d;
		}
		location[board[x][y].first] = { nx, ny };
		location[board[nx][ny].first] = { x, y };
		swap(board[nx][ny], board[x][y]);
	}
	int nx = shark.first.first, ny = shark.first.second;
	while (1) {
		nx += dx[shark.second];
		ny += dy[shark.second];
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
			if (board[nx][ny] != make_pair(-1, -1)) {
				pair<int, int> tmp = board[nx][ny];
				board[nx][ny] = { -1, -1 };
				location.erase(tmp.first);
				dfs({ {nx, ny}, tmp.second }, eaten + tmp.first, board, location);
				location[tmp.first] = { nx, ny };
				board[nx][ny] = tmp;
			}
		}
		else {
			answer.push_back(eaten);
			break;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int a, b;
	vector<vector<pair<int, int>>> board(4, vector<pair<int, int>>(4));
	map<int, pair<int, int>> location;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			board[i][j] = { a, b - 1 };
			location[a] = { i, j };
		}
	}
	pair<pair<int, int>, int> shark;
	shark.first = { 0,0 };
	shark.second = board[0][0].second;
	int eaten = board[0][0].first;
	location.erase(board[0][0].first);
	board[0][0] = { -1,-1 };
	dfs(shark, eaten, board, location);
	cout << *max_element(answer.begin(), answer.end());
}
