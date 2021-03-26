#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
	int answer = 0;
	int n;
	cin >> n;
	while (n) {
		string str;
		cin >> str;
		set<char> s;
		char c = str[0];
		s.insert(str[0]);
		bool flag = false;
		for (int i = 1; i < str.length(); i++) {
			if (c == str[i]) {
				continue;
			}
			else {
				if (s.find(str[i]) == s.end()) {
					c = str[i];
					s.insert(str[i]);
				}
				else {
					flag = true;
					break;
				}
			}
		}
		if (!flag) answer++;
		n--;
	}
	cout << answer;
}
