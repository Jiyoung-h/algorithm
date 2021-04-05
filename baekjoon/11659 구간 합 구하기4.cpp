#include <iostream>
#include <vector>
using namespace std;
int main() {	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> sum(n + 1); // 1번째 수부터 i번째 수까지의 합
	int a{}, b{};
	for (int i = 0; i < n; i++) {
		cin >> b;
		a += b;
		sum[i + 1] = a;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << sum[b] - sum[--a] << "\n";
	}
}
