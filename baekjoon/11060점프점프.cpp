#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
	int tmp = 0;
	int n, a;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a);
	}
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		pair<int, int> p = q.front();
		int ind = p.first;
		int ans = p.second;
		q.pop();
		for (int i = 1; i <= arr[ind]; i++) {
			if (ind + i == n - 1) {
				cout << ans + 1;
				return 0;
			}
			q.push(make_pair(ind + i, ans + 1));
		}
	}
	cout << -1;
	return 0;
}
