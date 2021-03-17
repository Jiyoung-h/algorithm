#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n+1);
    vector<bool> check(n+1);
    for(int i=0; i<edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    check[1] = true;
    vector<pair<int, int>> dis;
    while(!q.empty()){
        int pos = q.front().first;
        int count = q.front().second;
        q.pop();
        for(int i=0; i<graph[pos].size(); i++){
            if(!check[graph[pos][i]]){
                q.push({graph[pos][i], count + 1});
                dis.push_back({count + 1, graph[pos][i]});
                check[graph[pos][i]] = true;
            }
        }
    }
    sort(dis.begin(), dis.end(), greater<pair<int, int>>());
    int max = dis[0].first;
    for(int i=0; i<dis.size(); i++){
        if(max == dis[i].first)
            answer++;
        else
            break;
    }
    return answer;
}
