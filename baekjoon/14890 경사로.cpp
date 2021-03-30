#include <iostream>
#include <vector>
using namespace std;
int n, l;
vector<vector<int>> board1;
vector<vector<int>> board2;

int answer{};

void way(vector<vector<int>> board) {
	vector<vector<bool>> check(n, vector<bool>(n));
	for (int row = 0; row < n; row++) {
		bool flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (board[row][i] != board[row][i + 1]) {
				// 내려가는 경사로
				if (board[row][i] - board[row][i + 1] == 1) {
					int k = i + 1;
					int floor = board[row][k];
					while (k < n && board[row][k] == floor && k - (i + 1) < l && !check[row][k]) {
						check[row][k] = true;
						k++;
					}
					// 경사로의 길이
					if (k - (i + 1) < l) { flag = false; break; }
				}
				// 올라가는 경사로
				else if (board[row][i] - board[row][i + 1] == -1) {
					int k = i;
					int floor = board[row][k];
					while (k >= 0 && board[row][k] == floor && i - k < l && !check[row][k]) {
						check[row][k] = true;
						k--;
					}
					// 경사로의 길이
					if (i - k < l) { flag = false; break; }
				}
				else { flag = false; break; }
			}
		}
		if (flag) answer++;
	}
}
int main() {
	cin >> n >> l;
	board1.resize(n, vector<int>(n));
	board2.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board1[i][j];
			board2[j][i] = board1[i][j];
		}
	}
	way(board1);
	way(board2);
	cout << answer;
}
