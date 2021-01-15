#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 100001
using namespace std;
vector<int> a[MAX];
vector<int> order(MAX);
bool v[MAX];
vector<int> bfs_order;

bool compare(int& u, int& v)
{
    return order[u] < order[v];
}

void dfs(int x)
{
    if (v[x]) return;
    v[x] = true;
    bfs_order.push_back(x);
    for (int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        if (!v[y])
        {
            dfs(y);
        }
    }
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int q, w;
        cin >> q >> w;
        a[q].push_back(w);
        a[w].push_back(q);
    }
    vector<int> b(MAX);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        order[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(a[i].begin(), a[i].end(), compare);
    }
    dfs(1);
    vector<int> ::iterator iter = bfs_order.begin();
    bfs_order.insert(iter, 0);
    bool find = true;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] != bfs_order[i])
        {
            find = false;
            cout << "0" << ' ';
            return 0;
            break;
        }
    }
    cout << "1" << endl;
    return 0;
}
