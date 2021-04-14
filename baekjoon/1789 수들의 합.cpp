#include <iostream>
using namespace std;

int main()
{
	long long s;
	long long start, mid, end;
	long long n, sum;
	cin >> s;
	start = 1;
	end = s;
	while (start <= end) {
		mid = (start + end) / 2;
		sum = mid * (mid + 1) / 2;
		if (sum <= s) {
			n = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << n << endl;
}
