#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(vector<int> numbers) {
	vector<int> temp;
	for (int i = 1; i < (1 << numbers.size()); i++) {
		int sum = 0;
		for (int j = 0; j < numbers.size(); j++) {
			if (i & (1 << j)) {
				sum += numbers[j];
			}
		}
		temp.push_back(sum);
	}
	sort(temp.begin(), temp.end());
	if (temp[0] != 1){
        cout << 1;
        return;
    } 
	int i;
	for (i = 1; i < temp.size(); i++) {
		if (temp[i] - temp[i - 1] > 1) {
			cout << temp[i - 1] + 1;
			return;
		}
	}
	cout << temp[i - 1] + 1;
    return;
}

int main() {
	vector<int> numbers;
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		numbers.push_back(a);
	}
	solution(numbers);
}
