#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) 
{
    int answer = 0;
    vector<int> adj[201];
    int dp[201][201];
    
    for(int i = 0; i < edge_list.size(); i++)
    {
        adj[edge_list[i][0]].push_back(edge_list[i][1]);
        adj[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    fill(&dp[0][0], &dp[200][200], 99999999);
    
    // dp[i][j] : 경로의 i번째 위치가 j번 도시가 되면서 i번째 위치까지의 경로가 valid하게 고쳐야 하는 최소 횟수
    dp[0][gps_log[0]] = 0;
    for(int i=1;i<k-1;i++)
    {
        for(int j=1;j<=n;j++)
        {   // i번째 위치가 j번 도시가 아니면 1번 고쳐야한다
            int add = (gps_log[i] == j ? 0 : 1);
            // 그 전에 j번 도시였으면 valid할 수 있다 (한번 더 머무름)
            dp[i][j] = min(dp[i][j], dp[i-1][j] + add);
            // j번 도시와 인접한 도시 p
            for(auto p : adj[j])
            {   // 그 전에 p번 도시였으면 valid할 수 있다
                dp[i][j] = min(dp[i-1][p] + add, dp[i][j]);
            }
        }
    }
    
    answer = 99999999;
    // 마지막 도시에서 인접한 도시 p
    for(auto p : adj[gps_log.back()])
    {   // 마지막 전에 들렸던 도시가 p일때의 최솟값
        answer = min(answer, dp[gps_log.size()-2][p]);
    }
    if(answer == 99999999)
    {   // 정답을 구하지 못했을 때
        answer = -1;
    }
    return answer;
}
