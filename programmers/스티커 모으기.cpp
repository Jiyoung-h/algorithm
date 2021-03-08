#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = sticker[0];
    int n = sticker.size();
    vector<int> dp0(n);    // 0부터 시작
    vector<int> dp1(n);    // 1부터 시작
    
    dp0[0] = dp0[1] = sticker[0];       // 초기값
    dp1[0] = 0, dp1[1] = sticker[1];
    
    for(int i = 2; i < n; i++){
        if(i != n - 1) { // 마지막 스티커가 아니라면 
                            // (0부터 시작하면 n-1번째를 포함해선 안되기 때문)
            dp0[i] = max(dp0[i - 2] + sticker[i], dp0[i - 1]);
            answer = dp0[i];
        }
        dp1[i] = max(dp1[i - 2] + sticker[i], dp1[i - 1]);
    }
    answer = max(answer, dp1[sticker.size() - 1]);
    return answer;
}
