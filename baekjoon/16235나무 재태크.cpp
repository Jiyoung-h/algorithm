#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int a[10][10];
int d[10][10];
int p[10][10];
vector<int> tree[10][10];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int main() {
    int n, m, l;
    cin >> n >> m >> l;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j]; // 추가되는 양분
            d[i][j] = 5;    // 양분
        }
    }
    while (m--) {
        int x, y, age;
        cin >> x >> y >> age;
        tree[x-1][y-1].push_back(age);
    }
    while (l--) {
        memset(p,0,sizeof(p));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                vector<int> temp;   // 나무의 새로운 나이
                sort(tree[i][j].begin(), tree[i][j].end()); // 나이가 어린 나무부터 양분을 먹음
                int dead = 0;   // 죽은 나무 양분
                for (int x : tree[i][j]) {
                    if (x <= d[i][j]) { // 양분이 충분하면
                        d[i][j] -= x; // 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다.
                        temp.push_back(x+1);
                        if ((x+1) % 5 == 0) { // 번식하는 나무는 나이가 5의 배수
                            for (int k=0; k<8; k++) {
                                int nx = i+dx[k];
                                int ny = j+dy[k];
                                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                                    p[nx][ny] += 1; // 인접한 8개의 칸에 나이가 1인 나무
                                }
                            }
                        }
                    } else {
                        dead += x/2; // 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
                    }
                }
                tree[i][j] = temp;  // 새로운 나이
                d[i][j] += dead;    // 죽은 나무는 양분
                d[i][j] += a[i][j]; // 양분 추가
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; k<p[i][j]; k++) { // p : 나이가 1인 새로운 나무
                    tree[i][j].push_back(1);
                }
            }
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans += (int)tree[i][j].size();
        }
    }
    cout << ans << '\n';
    return 0;
}
