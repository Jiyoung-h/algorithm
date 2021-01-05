#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int a;
	vector<int> number;
	vector<bool> temp;

	while (1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> a;
			number.push_back(a);
		}

		temp.resize(number.size());

		for (int i = 0; i < 6; i++)	temp[i] = true;

		do {
			for (int i = 0; i < number.size(); ++i) {
				if (temp[i])
					cout << number[i] << ' ';
			}
			cout << endl;
		} while (prev_permutation(temp.begin(), temp.end()));
		cout << endl;
		number.clear();
		temp.clear();
	}
}
