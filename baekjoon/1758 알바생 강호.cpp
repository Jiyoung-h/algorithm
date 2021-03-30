#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> tip(n);
	for (long long i = 0; i < n; i++) {
		cin >> tip[i];
	}
	sort(tip.begin(), tip.end(), greater<>());
	long long sum{};
	for (long long i = 0; i < tip.size(); i++) {
		long long tmp = tip[i] - i;
		if (tmp <= 0) {
			break;
		}
		else {
			sum += tmp;
		}
	}
	cout << sum;
}
