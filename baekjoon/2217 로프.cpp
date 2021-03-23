#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> rope(n);
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope.begin(), rope.end(), greater<>());
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int w = rope[i] * (i + 1);
		if (answer < w) {
			answer = w;
		}
	}
	cout << answer << "\n";
}
