#include <iostream>
#include <algorithm>
using namespace std;
 
int map[1002][1002], dp[1002][1002];
int N, M;
 
int main(void)
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
        {
            cin >> map[i][j];
            dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
            dp[i][j] += map[i][j];
        }
    cout << dp[N][M] << endl;
    return 0;
}
