#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, sum{}, answer{};
int a[21][21];

bool isOK(int x, int y, int d1, int d2) {
	if (1 <= x && x + d1 + d2 <= n)
		if (1 <= y - d1 && y + d2 <= n)
			if(d1 > 0 && d2 > 0)
				return true;
	return false;
}
vector<vector<bool>> isArea5(int x, int y, int d1, int d2) {
	vector<vector<bool>> tmp(n+1, vector<bool>(n+1));
	for (int i = 0; i <= d1; i++) {
		tmp[x + i][y - i] = true;
		tmp[x + d2 + i][y + d2 - i] = true;
	}
	for (int i = 0; i <= d2; i++) {
		tmp[x + i][y + i] = true;
		tmp[x + d1 + i][y - d1 + i] = true;
	}
	return tmp;
}
void solve(int x, int y, int d1, int d2) {
	if (!isOK(x, y, d1, d2)) return;	
	int area[5] = { 0,0,0,0,0 };
	vector<vector<bool>> wall = isArea5(x, y, d1, d2);
	for (int i = 1; i < x + d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (wall[i][j]) break;
			area[0] += a[i][j];
		}
	}
	for (int i = 1; i <= x + d2; i++) {
		for (int j = n; j >= y+1; j--) {
			if (wall[i][j]) break;
			area[1] += a[i][j];
		}
	}
	for (int i = x + d1; i <= n; i++) {
		for (int j = 1; j < y - d1 + d2; j++) {
			if (wall[i][j]) break;
			area[2] += a[i][j];
		}
	}
	for (int i = x + d2+1; i <= n; i++) {
		for (int j = n; j >= y - d1 + d2; j--) {
			if (wall[i][j]) break;
			area[3] += a[i][j];
		}
	}
	area[4] = sum - area[0] - area[1] - area[2] - area[3];
	int min = *min_element(area, area + 5);
	int max = *max_element(area, area + 5);
	if (answer == 0 || answer > max - min) {
		answer = max - min;
	}
}
int main() {	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			sum += a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					solve(i, j, d1, d2);
				}
			}			
		}
	}
	cout << answer;
}
