#include<iostream>
#include<vector>
#include<map>
using namespace std;
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    string str;
    vector<vector<char>> board(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            board[i][j] = str[j];
        }
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == 'x') {
                if (board[i][j] == '*') { 
                    flag = true;
                    continue; 
                }
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (board[nx][ny] == '*')count++;
                }
                board[i][j] = count + '0';
            }
        }
    }        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!flag && board[i][j] == '*') board[i][j] = '.';
            cout << board[i][j];
        }            
        cout << endl;
    }
}
