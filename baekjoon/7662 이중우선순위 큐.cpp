#include<iostream>
#include<set>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		multiset<int> arr;
		int n; 
		cin >> n;
		for (int i = 0; i < n; i++) {
			char a; 
			cin >> a;
			int x; 
			cin >> x;
			if (a == 'I')
				arr.insert(x);
			else {
				if (arr.empty())
					continue;
				if (x == 1) {
					auto end = arr.end();
					end--;
					arr.erase(end);
				}
				else {
					arr.erase(arr.begin());
				}
			}
		}
		if (arr.empty())
			cout << "EMPTY" << "\n";
		else {
			auto end = arr.end();
			end--;
			cout << *(end) << " " << *arr.begin() << "\n";
		}
	}
	return 0;
}
