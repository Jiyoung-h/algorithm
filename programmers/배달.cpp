#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<vector<pair<int, int>>> adj(N+1);
    vector<vector<bool>> check(N+1, vector<bool>(K+1));
    vector<bool> check1(N+1);
    for(int i=0; i<road.size(); i++){
        adj[road[i][0]].push_back({road[i][1], road[i][2]});
        adj[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    int v, length, nv, nlength;
    check[1][0] = true;
    check1[1] = true;
    while(!q.empty()){
        v = q.front().first;        // 현재 위치
        length = q.front().second;  // 현재까지 걸린 시간
        q.pop();
        for(int i=0; i<adj[v].size(); i++){
            nv = adj[v][i].first;
            nlength = adj[v][i].second;
            if(length + nlength <= K && !check[nv][length + nlength]){
                q.push({nv, length + nlength});
                check[nv][length + nlength] = true; // 해당 마을에 해당 거리로 방문했었는지
                if(!check1[nv]){
                    check1[nv] = true;              // 해당 마을에 방문했었는지
                    answer++;
                }
            }
        }
    }
    return answer + 1;  // 1번 마을까지 더해서
}
