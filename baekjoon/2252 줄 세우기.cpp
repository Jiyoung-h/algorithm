#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
int adj[100010];
vector<int> node[100010];
// 위상정렬 알고리즘
int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b; 
        cin >> a >> b;
        // 진입 차수 adj
        adj[b]++;
        node[a].push_back(b);
    }
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (adj[i] == 0) q.push(i);
        // 진입 차수가 0인 노드들을 큐에 삽입
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " ";
        for (int i = 0; i < node[front].size(); i++)
        {   // 큐에서 꺼낸 노드와 연결된 간선들을 지워준다
            int next = node[front][i];
            adj[next]--;
            // 집입 차수가 0이 되면 큐에 삽입
            if (adj[next] == 0) q.push(next);
        }
    }
    cout << endl;
}
