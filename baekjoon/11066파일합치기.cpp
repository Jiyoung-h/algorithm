#include <iostream>
#include <cstring>
int a[501];
int d[501][501];
int go(int i, int j) {  // i부터 j까지 합치기
    if (i == j) {
        return 0;
    }
    if (d[i][j] != -1) {
        return d[i][j];
    }
    int &ans = d[i][j];
    int sum = 0;
    for (int k=i; k<=j; k++) {  
        sum += a[k];
    }
    for (int k=i; k<=j-1; k++) {
        int temp = go(i, k) + go(k+1, j) + sum; // i~k 합친 비용 + k+j 합친 비용 + 전체 합친 비용
        if (ans == -1 || ans > temp) {  // 최소값 찾기
            ans = temp;
        }
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(d,-1,sizeof(d));
        int n;
        cin >> n;
        int a;
        for (int i=1; i<=n; i++) {
            cin >> a;
            a[i] = a;
        }
        cout<< go(1, n) << endl;
    }
    return 0;
}
