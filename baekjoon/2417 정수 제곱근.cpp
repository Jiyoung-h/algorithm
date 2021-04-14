#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	unsigned long long sq;
	unsigned long long n;
	cin >> n;
	sq = sqrt(n);
	if (sq * sq == n)
		cout << sq << endl;
	else
		cout << sq + 1 << endl;
}
