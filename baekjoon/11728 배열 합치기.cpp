#include <iostream>
using namespace std;
int a [1000001];
int b [1000001];
int main() {	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	int i{}, j{};
	while (i < n && j < m) {
		if (a[i] < b[j]) {
			cout << a[i++] << " ";
		}
		else {
			cout << b[j++] << " ";
		}
	}
	while (j < m) {
		cout << b[j++] << " ";
	}
	while (i < n) {
		cout << a[i++] << " ";
	}
}
