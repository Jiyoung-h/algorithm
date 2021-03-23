#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<string> set1;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		set1.insert(str);
	}
	int answer = 0;
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (set1.find(str) != set1.end())
			answer++;
	}
	cout << answer;
}
