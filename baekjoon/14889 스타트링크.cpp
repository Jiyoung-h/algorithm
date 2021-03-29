#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> c;
int solution(int index, vector<int> start, vector<int> link) {
	if (index == n) {
		if (start.size() != n / 2 || link.size() != n / 2) return -1;
		int sPower{}, lPower{};
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
				sPower += c[start[i]][start[j]];
				lPower += c[link[i]][link[j]];
			}
		}
		int diff = sPower - lPower;
		if (diff < 0)diff = -diff;
		return diff;
	}

	if (start.size() > n / 2 || link.size() > n / 2) return -1;
	
	int result = -1;
	start.push_back(index);
	int ans1 = solution(index + 1, start, link);
	start.pop_back();
	if (result == -1 || (ans1 != -1 && result > ans1)) {
		result = ans1;
	}

	link.push_back(index);
	int ans2 = solution(index + 1, start, link);
	link.pop_back();
	if (result == -1 || (ans2 != -1 && result > ans2)) {
		result = ans2;
	}
	return result;
}

int main() {
	cin >> n;
	c.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}
	vector<int> start, link;
	cout << solution(0, start, link);
}
