#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	int n, m;
	cin >> m >> n;
	vector<pair<string, int>> oper;
	string str; int a;
	for (int i = 0; i < n; i++) {
		cin >> str >> a;
		oper.push_back({ str, a });
	}
	int x = 0;
	int y = 0;
	int d = 0;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (oper[i].first == "MOVE") {
			int nx = x + dx[d] * oper[i].second;
			int ny = y + dy[d] * oper[i].second;
			if (nx <= m && ny <= m && nx >= 0 && ny >= 0) {
				x = nx;
				y = ny;
			}
			else {
				flag = true;
				break;
			}
		}
		else {
			if (oper[i].second == 0) {
				d++;
				if (d > 3)d -= 4;
			}
			else {
				d--;
				if (d < 0)d += 4;
			}
		}
		
	}
	if (flag) {
		cout << "-1";
	}
	else {
		cout << y << " " << x;
	}	
}
