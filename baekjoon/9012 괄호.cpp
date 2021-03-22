#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n) {
		string str;
		cin >> str;
		queue<char> q;
		q.push(str[0]);
		for (int i = 1; i < str.size(); i++) {
			if (q.empty()) {
				q.push(str[i]);
				continue;
			}
			char front = q.front();
			if (front == '(' && str[i] == ')') {
				q.pop();
			}
			else {
				q.push(str[i]);
			}
		}
		if (q.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
		n--;
	}
}
