#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> t(n + 1);
    vector<int> p(n + 1);
    vector<int> dp(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
        if (i + t[i] > n + 1) p[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int k = 0;
        while (i + t[i] + k <= n + 1) { 
            dp[i + t[i] + k] = max(dp[i + t[i] + k], dp[i] + p[i]);
            k++;
        }
    }
    cout << dp[n + 1];
}
