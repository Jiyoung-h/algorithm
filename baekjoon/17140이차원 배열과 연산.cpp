#include <iostream>
#include <queue>
#include <map>
using namespace std;
int r, c, k, total_r, total_c;
int A[100][100]; // 1 ~ 100
map<int, int> cnt;
struct Info {
	int num, count;
};
bool operator<(const Info &v1, const Info &v2) {
	if (v1.count == v2.count) return v1.num > v2.num;
	return v1.count > v2.count;
}
void Input() {
	cin >> r >> c >> k;
	total_r = total_c = 3;
	for (int i = 0; i < total_r; ++i) {
		for (int j = 0; j < total_c; ++j) {
			cin >> A[i][j];
		}
	}
}
void Task() {
	for (int t = 0; t <= 100; ++t) {
		if (A[r - 1][c - 1] == k) {
			cout << t << "\n";
			return;
		}
		priority_queue<Info> pq;
		if (total_r >= total_c) { // R 연산
			for (int i = 0; i < total_r; ++i) {
				for (int j = 0; j < total_c; ++j) {
					if (A[i][j] == 0) continue;
					if (cnt.count(A[i][j]) == 0) cnt[A[i][j]] = 1;
					else cnt[A[i][j]]++;
					A[i][j] = 0;
				}
				for (auto e : cnt) {
					pq.push({ e.first, e.second });
				}
				cnt.clear();
				int len = pq.size() * 2;
				for (int j = 0; j < len; j += 2) {
					A[i][j] = pq.top().num; A[i][j + 1] = pq.top().count;
					pq.pop();
				}
				if (total_c < len) total_c = len;
			}
		}
		else { // C 연산
			for (int i = 0; i < total_c; ++i) {
				for (int j = 0; j < total_r; ++j) {
					if (A[j][i] == 0) continue;
					if (cnt.count(A[j][i]) == 0) cnt[A[j][i]] = 1;
					else cnt[A[j][i]]++;
					A[j][i] = 0;
				}
				for (auto e : cnt) {
					pq.push({ e.first, e.second });
				}
				cnt.clear();
				int len = pq.size() * 2;
				for (int j = 0; j < len; j += 2) {
					A[j][i] = pq.top().num; A[j + 1][i] = pq.top().count;
					pq.pop();
				}
				if (total_r < len) total_r = len;
			}
		}
	}
	cout << -1 << "\n";
}
int main() {
	Input();
	Task();
	return 0;
}
