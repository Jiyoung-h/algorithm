#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<long long> li(n);
	for (int i = 0; i < n; i++) {
		cin >> li[i];
	}
	sort(li.begin(), li.end());
	int i{}, j = n - 1;
	long long min = 10000000000;
	long long ans1, ans2;
	while (i < j) {
		if (abs(li[i] + li[j]) < min) {
			ans1 = li[i];
			ans2 = li[j];
			min = abs(li[i] + li[j]);
			if (min == 0) break;
		}
		if (li[i] + li[j] > 0) j--;
		else if (li[i] + li[j] < 0) i++;
	}
	cout << ans1 << " " << ans2;
}
