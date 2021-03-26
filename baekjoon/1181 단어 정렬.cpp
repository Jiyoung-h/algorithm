#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, string>> words;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		words.push_back({ str.size(), str });
	}
	sort(words.begin(), words.end(), cmp);
	str = words[0].second;
	cout << words[0].second << "\n";
	for (int i = 1; i < n; i++) {
		if (str != words[i].second) {
			cout << words[i].second << "\n";
			str = words[i].second;
		}
	}
}
