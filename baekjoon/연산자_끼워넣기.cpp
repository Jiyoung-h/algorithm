#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int A[100];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int plus, minus, multi, div;
	cin >> plus >> minus >> multi >> div;
	vector <int> opt;
	vector <int> ans;

	for (int i = 0; i < plus; i++) opt.push_back(0);
	for (int i = 0; i < minus; i++) opt.push_back(1);
	for (int i = 0; i < multi; i++) opt.push_back(2);
	for (int i = 0; i < div; i++) opt.push_back(3);

	do {
		int sum = A[0];
		for (int i = 1; i < N; i++) {
			int num = A[i];
			if (opt[i - 1] == 0)	sum += num;
			if (opt[i - 1] == 1)	sum -= num;
			if (opt[i - 1] == 2)	sum *= num;
			if (opt[i - 1] == 3)	sum /= num;
		}
		ans.push_back(sum);
	} while (next_permutation(opt.begin(), opt.end()));
	cout << *max_element(ans.begin(), ans.end()) << endl;
	cout << *min_element(ans.begin(), ans.end());
}
