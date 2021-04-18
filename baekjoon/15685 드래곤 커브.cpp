#include<iostream>
#include<vector>
using namespace std;
int N, x, y, d, g;
int board[101][101];
vector<int> dir;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0 ,-1 ,0 };
void dragonCurve()
{
    int s = dir.size();
    for (int i = s - 1; i >= 0; i--)
    {
        int nd = (dir[i] + 1) % 4;
        x = x + dx[nd];
        y = y + dy[nd];
        board[x][y] = 1;
        dir.push_back(nd);
    }
}
void count()
{
    int cnt = 0;
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            if (board[i][j] == 1 && board[i + 1][j] == 1 && board[i][j + 1] == 1&& board[i + 1][j + 1] == 1)
                cnt++;

    cout << cnt << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> y >> x >> d >> g;
        dir.clear();

        board[x][y] = 1;
        x = x + dx[d];
        y = y + dy[d];
        board[x][y] = 1;

        dir.push_back(d);
        for (int j = 0; j < g; j++)
            dragonCurve();
    }
    count();
}
