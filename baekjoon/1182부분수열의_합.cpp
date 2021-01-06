#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution(vector<int> numbers, int target) {
	int answer = 0;
	for (int i = 1; i < (1 << numbers.size()); i++) {
		int sum = 0;
		for (int j = 0; j < numbers.size(); j++) {
			if (i & (1 << j)) {
				sum += numbers[j];
			}
		}
		if (sum == target) answer++;
	}
	cout << answer;
}

int main() {
	vector<int> numbers;
	int target;
	int a;
	int n;
	cin >> n;
	cin >> target;
	for (int i = 0; i < n; i++) {
		cin >> a;
		numbers.push_back(a);
	}
	solution(numbers, target);
}
