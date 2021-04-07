#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;	
	cin >> n;
	vector<int> drink(n);
	for (int i = 0; i < n; i++)
		cin >> drink[i];
	sort(drink.begin(), drink.end(), greater<>()); 
	double answer = drink[0];
	for (int i = 1; i < n; i++) {
		answer += drink[i] / double (2);
	}
	cout << answer;
}
