#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, k;
vector<string> dic;
map<string, int> m;
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    
	cin >> n >> k;
	dic.resize(n);
	string str;
	for (int i = 0; i < n; i++) {
		cin >> dic[i];
		m[dic[i]] = i + 1;
	}
	while(k){
		cin >> str;
		if (isdigit(str[0])) {
			cout << dic[stoi(str) - 1] << "\n";
		}
		else {
			cout << m[str] << "\n";
		}
		k--;
	}	
}
