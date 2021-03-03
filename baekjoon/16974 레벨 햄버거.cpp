#include <iostream>
using namespace std;
int n;
long long x;
long long total[51];
long long p[51];
long long solve(int n, long long x)
{
	if (n == 0) {	// 레벨 0 버거 = 패티
		if (x == 0) return 0;
		else if (x == 1) return 1;
	}

	if (x == 1)
		return 0; // 무조건 햄버거 번
	else if (x <= 1 + total[n - 1])	// n-1 레벨의 갯수보다 앞이면 맨 앞 빵을 제외하고 n-1 레벨에서 찾는다
		return solve(n - 1, x - 1);
	else if (x == 1 + total[n - 1] + 1)	// 절반 지점이면 n-1 레벨의 패티 개수 + 1
		return p[n - 1] + 1;
	else if (x <= 1 + total[n - 1] + 1 + total[n - 1])	// 절반보다 뒷 부분이면
		return 1 + p[n - 1] + solve(n - 1, x - 1 - total[n - 1] - 1);	// 절반까지는 p[n-1]개, 그 이후는 재귀 이용
	else
		return 2 * p[n - 1] + 1;	// 맨 끝이면

}
int main()
{
	cin >> n >> x;
	total[0] = 1;
	p[0] = 1;
	for (int i = 1; i <= n; ++i) {
		total[i] = 2 * total[i - 1] + 3;	// 전체 재료 = 빵+[i-1]+패티+[i-1]+빵
		p[i] = 2 * p[i - 1] + 1;			// 패티 수 
	}
	cout << solve(n, x) << "\n";
	return 0;
}
