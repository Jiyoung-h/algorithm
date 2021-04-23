#include <iostream>
#include <algorithm>
using namespace std;
int N, n;
int num[9] = { 0, 0, 1, 7, 4, 2, 0, 8, 10 };
long long dp[101];

int main() {
    for (int i = 1; i < 9; i++) {
        dp[i] = num[i];
    }
    dp[6] = 6;
    for (int i = 9; i < 101; i++) {
        dp[i] = dp[i - 2] * 10 + num[2];

        for (int j = 3; j < 8; j++) {
            dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);
        }
    }
    cin >> N;

    while (N--) {
        cin >> n;
        cout << dp[n] << " ";
        while (n) {
            if (n % 2 != 0) {
                cout << 7;
                n -= 3;
            }
            else {
                cout << 1;
                n -= 2;
            }
        }
        cout << "\n";
    }
}
