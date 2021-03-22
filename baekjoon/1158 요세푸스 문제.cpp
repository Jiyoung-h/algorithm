#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> num;
	for (int i = 0; i < n; i++) {
		num.push_back(i + 1);
	}
	int idx = -1;
	cout << "<";
	while (num.size() > 1) {
		idx += k;
		while (idx > num.size() - 1) {
			idx -= num.size();
		}
		cout << num[idx]<<", ";
		num.erase(num.begin() + idx);
		idx--;
	}
	cout << num[0] << ">";
}
