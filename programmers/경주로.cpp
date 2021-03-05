#include <string>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int solution(vector<vector<int>> board) {
    struct S{
        int x;
        int y;  // 위치 x, y
        int d;  // 방향
        int p;  // 비용
        S(int x, int y, int d, int p) : x(x), y(y), d(d), p(p){};
    };
    queue<S> q;
    int n = board.size();
    vector<vector<int>> price(n, vector<int>(n));   // x,y 까지의 최소 비용
    if(board[0][1] == 0) {q.push(S(0,1,0,100)); price[0][1] = 100;}
    if(board[1][0] == 0) {q.push(S(1,0,2,100));  price[1][0] = 100;}
    price[0][0] = 1;
    while(!q.empty()){
        S c = q.front();
        int cx = c.x;
        int cy = c.y;
        int cd = c.d;
        int cp = c.p;
        q.pop();
        for(int i=0; i<4; i++){
            int nd = (cd + i)%4;
            int nx = cx + dx[nd];
            int ny = cy + dy[nd];
            if(nx < n && ny < n && nx >= 0 && ny >= 0 && board[nx][ny] == 0){
                if(i==0) {  // 방향을 틀지 않았으면
                    if(price[nx][ny]==0 || price[nx][ny] >= cp+100){
                        q.push(S(nx, ny, nd, cp+100));
                        price[nx][ny] = cp+100;
                    }
                }
                else {      // 방향을 틀었으면
                    if(price[nx][ny]==0 || price[nx][ny] >= cp+600){
                        q.push(S(nx, ny, nd, cp+600));
                        price[nx][ny] = cp+600;
                    }
                }
            }
        }
    }
    return price[n-1][n-1]; 
}
