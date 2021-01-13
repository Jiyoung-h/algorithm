#include <iostream>
#include <algorithm>
using namespace std;
using namespace std;

const int dx[6] = { -1,-1,0,0,1,1 };
const int dy[6] = { 0,1,-1,1,-1,0 };

int n, ans, col[51][51];
char e[51][51];

void dfs(int x, int y, int c) {
	col[x][y] = c;
	ans = max(ans, 1);
	for (int i = 0; i < 6; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		if (!(0 <= nx && nx < n && 0 <= ny && ny < n)) continue;
		if (e[nx][ny] != 'X') continue;
		if (col[nx][ny] == -1) dfs(nx, ny, 1 - c);
		ans = max(ans, 2);
		if (col[nx][ny] == c) ans = max(ans, 3);
	}
}

int main() {
	int i, j;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> e[i];
	memset(col, -1, sizeof(col));
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (e[i][j] == 'X' && col[i][j] == -1)
				dfs(i, j, 0);
	cout << ans;
	return 0;
}
