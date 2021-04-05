#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n, m, h, answer;
vector<vector<int>> ladder;
bool iToi() {
	for (int i = 0; i < n; i++) {
		int cx = 0;
		int cy = i;
		while (cx < h && cy < n) {
			if (ladder[cx][cy] == 1) {
				cy++;
			}
			else if (ladder[cx][cy] == -1) {
				cy--;
			}
			cx++;
		}
		if (cx == h && cy == i) continue;
		else return false;
	}
	return true;
}
void check(int x, int y, int k) {
	if (k > 3) {
		return;
	}
	if (iToi()) {
		if (answer == -1 || answer > k) {
			answer = k;
			return;
		}
	}
	for (int i = x; i < h; i++) {
		int j = i == x ? y : 0;
		for (; j < n - 1; j++) {			
			if (ladder[i][j] == 0 && ladder[i][j + 1] == 0) {
				ladder[i][j] = 1;
				ladder[i][j + 1] = -1;				
				check(i, j, k + 1);
				ladder[i][j] = 0;
				ladder[i][j + 1] = 0;
			}
		}
	}
}
int main() {
	cin >> n >> m >> h;
	answer = -1;
	ladder.resize(h, vector<int>(n));
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ladder[--a][--b] = 1;
		ladder[a][b + 1] = -1;
	}
	check(0, 0, 0);
	cout << answer;
}
