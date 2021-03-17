#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	int count = 0;
  // 시간 초과를 피하기 위하여 시작을 목표 층과 가장 가깝게 이동시킨다
	if (s > g) {
		if (d == 0) {
			cout << "use the stairs";
			return 0;
		}
		else {
			// 내려가는 횟수 = 내려가야 하는 층 수 / 한번에 내려갈 수 있는 층 수 
			count = (s - g) / d;
			s -= count * d;
		}
	}
	else if (s < g) {
		if (u == 0) {
			cout << "use the stairs";
			return 0;
		}
		else {
			// 올라가는 횟수 = 올라가야 하는 층 수 / 한번에 올라갈 수 있는 층 수 
			count = (g - s) / u;
			s += count * u;
		}
	}
	vector<bool> check(f + 1);
	check[s] = true;
	queue<pair<int, int>> q;
	q.push({ s, count });
	while (!q.empty()) {
		int pos = q.front().first;
		int count = q.front().second;
		q.pop();
		if (pos == g) {
			cout << count;
			return 0;
		}
		if (pos + u <= f && !check[pos + u]) {
			q.push({ pos + u, count + 1 });
			check[pos + u] = true;
		}
		if (pos - d >= 1 && !check[pos - d]) {
			q.push({ pos - d, count + 1 });
			check[pos - d] = false;
		}
	}
	cout << "use the stairs";
}
