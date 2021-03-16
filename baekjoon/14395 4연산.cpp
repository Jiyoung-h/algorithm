#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

int main() {
	long long n, end;
	cin >> n >> end;
	if (n == end) {
		cout << 0;
		return 0;
	}
	queue<pair<long long, string>> q;
	q.push({ n, "" });
	set<long long> check;
	check.insert(n);
	while (!q.empty()) {
		long long x = q.front().first;
		string op = q.front().second;
		q.pop();
		if (x == end) {
			cout << op;
			return 0;
		}
		long long tmp = x * x;
		if (tmp <= 10e9 && check.find(tmp) == check.end()) {
			q.push({ tmp, op + "*" });
			check.insert(tmp);
		}
		tmp = x + x;
		if (tmp <= 10e9 && check.find(tmp) == check.end()) {
			q.push({ tmp, op + "+" });
			check.insert(tmp);
		}
		if (check.find(0) == check.end()) {
			q.push({ 0, op + "-" });
			check.insert(0);
		}
		if (x != 0) {
			if (check.find(1) == check.end()) {
				q.push({ 1, op + "/" });
				check.insert(1);
			}
		}
	}
	cout << -1;
	return 0;
}
