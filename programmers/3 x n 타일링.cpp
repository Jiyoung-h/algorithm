#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    if(n % 2 == 1) return 0;
    long long DP[5010] = { 0, };
    DP[0] = 1;
    DP[2] = 3;
    for(int i = 4; i <= n ; i = i + 2) {
        DP[i] = DP[i - 2] * 3;
        for(int j = i - 4; j >= 0 ; j = j - 2) {
            DP[i] = DP[i] + DP[j] * 2;
        }
        DP[i] = DP[i] % 1000000007;
    }
   return (int)DP[n];
}
