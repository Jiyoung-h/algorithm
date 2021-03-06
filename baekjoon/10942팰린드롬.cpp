#include <iostream>
#include <cstring>
int d[2000][2000];
int a[2000];
int dp(int i, int j) {
    if (i == j) {
        return 1;
    } else if (i+1 == j) {
        if (a[i] == a[j]) {
            return 1;
        } else {
            return 0;
        }
    }
    if (d[i][j] != -1) {
        return d[i][j];
    }
    if (a[i] != a[j]) {
        return d[i][j] = 0;
    } else {
        return d[i][j] = dp(i+1,j-1);
    }
}
int main() {
    int n;
    cin >> n;
    int a;
    for (int i=0; i<n; i++) {
        cin >> a;
        a[i] = a;
    }
    memset(d,-1,sizeof(d));
    int m;
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << dp(s-1,e-1);
    }
    return 0;
}
