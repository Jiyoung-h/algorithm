#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int memo[31][31];
int dp(int n, int m) {
    if (memo[n][m] > 0) return memo[n][m];
    else {
        int tmp = 0;
        for (int i = n - 1; i < m; i++) {
            tmp += dp(n - 1, i);
        }
        memo[n][m] = tmp;
        return memo[n][m];
    }
}
int main() {
    int N;
    cin >> N;
    for (int i = 1; i < 31; i++) {
        memo[i][i] = 1;
        memo[1][i] = i;
    }
    while (N--) {
        int n, m;
        cin >> n >> m;
        cout << dp(n, m) << "\n";
    }
}
