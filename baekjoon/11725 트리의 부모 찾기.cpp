#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
int parent[100001];
bool visited[100001];
void findParent(int x) {
    visited[x] = true;
    for (int i = 0; i < adj[x].size(); i++) {
        int next = adj[x][i];
        if (visited[next] == false) {
            parent[next] = x;
            findParent(next);
        }
    }
}
int main() {
    int N;
    cin >> N;
    int a, b;
    adj.resize(N + 1);
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    findParent(1);
    for (int i = 2; i <= N; i++)
        cout << parent[i] << '\n';
}
