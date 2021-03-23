#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	n = 1000 - n;
	int answer = 0;
	int m;

	m = n / 500;
	answer += m;
	n -= m * 500;

	m = n / 100;
	answer += m;
	n -= m * 100;

	m = n / 50;
	answer += m;
	n -= m * 50;

	m = n / 10;
	answer += m;
	n -= m * 10;

	m = n / 5;
	answer += m;
	n -= m * 5;

	answer += n;
	cout << answer;
}
