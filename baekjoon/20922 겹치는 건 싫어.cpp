#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	multiset<int> s;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int i{}, j{}, answer{};
	while (i <= j) {
		if (j == n) break;
		if (s.count(arr[j]) >= k) {
			while (arr[j] != arr[i]) {
				s.erase(arr[i]);
				i++; 
			}
			i++;
		}
		else s.insert(arr[j]);
		if (answer < j - i) answer = j - i;
		j++;
	}
	cout << answer + 1;
}
