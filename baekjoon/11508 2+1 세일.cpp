#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	long long answer{};
	cin >> n;
	vector<int> milk(n);
	for (int i = 0; i < n; i++)
		cin >> milk[i];
	sort(milk.begin(), milk.end(), greater<>());
	for (int i = 0; i < n; i++) {
		if (i % 3 != 2) answer += milk[i];
	}
	cout << answer;
}
