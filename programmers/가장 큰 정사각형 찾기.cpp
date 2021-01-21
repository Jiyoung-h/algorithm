#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solution(vector<vector<int>> board)
{
   int answer = 0;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == 1) {
				int n = 1;
				while(1) {
					if (i+n>board.size()-1||j+n>board[0].size()-1|| board[i + n][j + n] != 1) {
						answer = max(n, answer);
						break;
					}
					int p, q;
					for (p = 0; p < n; p++) {
						if (board[i + p][j + n] != 1) { answer = max(n, answer); break; }
					}
					for (q = 0; q < n; q++) {
						if (board[i + n][j + q] != 1) { answer = max(n, answer); break; }
					}
					if (p != n || q != n) break;
					n++;
				}
			}
		}
	}
	return answer*answer;
}
