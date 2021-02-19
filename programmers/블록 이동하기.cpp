#include <vector>
#include <queue>
using namespace std;
 
int n;
bool visit[100][100][4];
 
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
 
//회전할 때 지나칠 곳
int ndx[] = { -1,1,1,-1 };
int ndy[] = { 1,1,-1,-1 };
 
struct Robot {
    int x;
    int y;
    int dir;
    int time;
    Robot(int a, int b, int d, int t) {
        x = a;
        y = b;
        dir = d;
        time = t;
    }
};
 
bool rangeCheck(int x, int y, int xx, int yy) {
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    if (xx < 0 || xx >= n || yy < 0 || yy >= n) return false;
 
    return true;
}
 
 
int solution(vector<vector<int>> board) {
 
    queue<Robot> q;
    q.push(Robot(0, 0, 0, 0));
    visit[0][0][0] = true;
 
    n = board.size();
    int destX = n - 1;
    int destY = n - 1;
 
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        int time = q.front().time;
        q.pop();
 
        //로봇의 나머지 한칸
        int xx = x + dx[dir];
        int yy = y + dy[dir];
 
 
        //로봇의 한칸이라도 도착하면 종료
        if (x == destX && y == destY) return time;
        if (xx == destX && yy == destY) return time;
 
 
        int nx, ny, nxx, nyy;
 
        //우, 하, 좌, 상 이동
        for (int k = 0; k < 4; k++) {
            nx = x + dx[k];
            ny = y + dy[k];
            nxx = xx + dx[k];
            nyy = yy + dy[k];
            
            //이동할 곳의 범위 체크
            if (!rangeCheck(nx, ny, nxx, nyy)) continue;
            //이동할 곳의 방문 체크
            if (visit[nx][ny][dir]) continue;
            //이동할 수 있는지 체크
            if (board[nx][ny] == 1 || board[nxx][nyy] == 1) continue;
 
            visit[nx][ny][dir] = true;
            q.push(Robot(nx, ny, dir, time + 1));
 
        }
 
 
        //x,y 를 축으로 90도 회전
        for (int i = 1; i < 4; i += 2) {
            int ndir = (dir + i) % 4;
            nxx = x + dx[ndir];
            nyy = y + dy[ndir];
 
            int rx, ry; //회전하면서 지나갈 곳의 좌표
            if (i == 1) {
                //시계방향 회전인 경우
                rx = x + ndx[ndir];
                ry = y + ndy[ndir];
            }
            else {
                //반시계방향 회전인 경우
                rx = x + ndx[dir];
                ry = y + ndy[dir];
            }
            
            if (!rangeCheck(rx, ry, nxx, nyy)) continue;
            if (visit[x][y][ndir]) continue;
            if (board[nxx][nyy] == 1) continue;
            if (board[rx][ry]) continue;
 
            visit[x][y][ndir] = true;
            q.push(Robot(x, y, ndir, time + 1));
        }
        
 
        //xx, yy 를 축으로 90도 회전
        dir = (dir + 2) % 4; //xx, yy가 기준이므로 방향이 반대로 바뀐다.
        for (int i = 1; i < 4; i += 2) {
            int ndir = (dir + i) % 4;
            nx = xx + dx[ndir];
            ny = yy + dy[ndir];
 
            int rx, ry; //회전하면서 지나갈 곳의 좌표
            if (i == 1) {
                //시계방향 회전인 경우
                rx = xx + ndx[ndir];
                ry = yy + ndy[ndir];
            }
            else {
                //반시계방향 회전인 경우
                rx = xx + ndx[dir];
                ry = yy + ndy[dir];
            }
 
            if (!rangeCheck(nx, ny, rx, ry)) continue;
            if (board[nx][ny] == 1) continue;
            if (board[rx][ry] == 1) continue;
 
            ndir = (ndir + 2) % 4;
            if (visit[nx][ny][ndir]) continue;
            visit[nx][ny][ndir] = true;
            q.push(Robot(nx, ny, ndir, time + 1));
        }
        
 
 
    }
 
}
