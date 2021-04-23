#include<iostream>
#include<vector>
using namespace std;
int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };
int n, m, k;
struct Fireball {
    int w;
    int d;
    int s;
    Fireball() {};
    Fireball(int w, int d, int s) : w(w), d(d), s(s) {};
};
vector<vector<vector<Fireball>>> board;
void move() {
    vector<vector<vector<Fireball>>> tmp(n, vector<vector<Fireball>>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < board[i][j].size(); p++) {
                int r = i;
                int c = j;
                int w = board[i][j][p].w;
                int d = board[i][j][p].d;
                int s = board[i][j][p].s;
                int nr = (r + (dr[d] * s)) % n;
                int nc = (c + (dc[d] * s)) % n;
                while (nc < 0) nc += n;
                while (nr < 0) nr += n;
                tmp[nr][nc].push_back(Fireball(w, d, s));
            }
        }
    }
    board = tmp;
}
void divide() {
    vector<Fireball> tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j].size() > 1) {
                int sw{}, ss{};
                bool flag0 = true, flag1 = true;
                for (int p = 0; p < board[i][j].size(); p++) {
                    sw += board[i][j][p].w;
                    ss += board[i][j][p].s;
                    if (board[i][j][p].d % 2 == 0) flag1 = false;
                    else flag0 = false;
                }
                sw /= 5;
                ss /= board[i][j].size();
                board[i][j].clear();
                vector<int> dd(4);
                if (flag0 || flag1) {
                    dd = { 0,2,4,6 };
                }
                else {
                    dd = { 1,3,5,7 };
                }
                if (sw != 0) {
                    for (int p = 0; p < 4; p++) {
                        tmp.push_back(Fireball(sw, dd[p], ss));
                    }                
                }
                board[i][j] = tmp;
                tmp.clear();
            }          
        }
    }
}
int remain() {
    int sum{};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < board[i][j].size(); p++) {
                sum += board[i][j][p].w;
            }
        }
    }
    return sum;
}
int main(void)
{
    cin >> n >> m >> k;
    board.resize(n, vector<vector<Fireball>>(n));
    int r, c, w, d, s;
    for (int i = 0; i < m; i++) {
        cin >> r >> c >> w >> s >> d;
        board[r - 1][c - 1].push_back(Fireball(w, d, s));
    }
    while (k--) {
        move();
        divide();        
    }
    cout << remain() << endl;
}
