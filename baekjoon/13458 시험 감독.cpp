#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<long long> students(n);
	for (long long i = 0; i < n; i++) {
		cin >> students[i];
	}
	long long b, c;
	cin >> b >> c;
	long long answer = n;
	for (long long i = 0; i < n; i++) {
		students[i] -= b;
		if (students[i] > 0) {
			answer += students[i] / c;
			if (students[i] % c > 0) answer++;
		}
	}
	cout << answer;
}
