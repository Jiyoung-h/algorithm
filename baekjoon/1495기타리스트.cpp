#include <vector>
#include <iostream>
using namespace std;
int n, s, m;

int main() {
    cin >> n >> s >> m;
    vector<int> vol(n);
    int sum = s;
    for (int i = 0; i < n; i++) {
        cin >> vol[i];
        sum += vol[i];
    }
    //i곡을 j볼륨으로 연주할수 있으면 1, 아니면 0
    vector<vector<int>> guitar(n + 1, vector<int>(m + 1));
    guitar[0][s] = 1;
    if (sum == m) { cout << m; return 0; }
    else if (sum < m) { cout << sum; return 0; }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (guitar[i][j] == 1) {
                    if (j + vol[i] <= m) {
                        guitar[i + 1][j + vol[i]] = 1;
                    }
                    if (j - vol[i] >= 0) {
                        guitar[i + 1][j - vol[i]] = 1;
                    }
                }
            }
        }
        for (int j = m; j >= 0; j--) {
            if (guitar[n][j] == 1) {
                cout << j;
                return 0;
            }
        }
        cout << -1;
    }
}
