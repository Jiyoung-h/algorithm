#include <vector>
#include <iostream>
using namespace std;
int minSum = 0;

void dfs(vector<int> marble, int sum, int cnt, int total) {
    if (cnt == total) {
        if (minSum < sum) minSum = sum;
        return;
    }
    for (int i = 1; i < marble.size() - 1; i++) {
        vector<int> marble2(marble);
        marble2.erase(marble2.begin() + i);
        dfs(marble2, sum + marble[i - 1] * marble[i + 1], cnt + 1, total);
    }
}
int main() {
    int n, a;
    cin >> n;
    vector<int> marble;
    for (int i = 0; i < n; i++) {
        cin >> a;
        marble.push_back(a);
    }
    int total = marble.size() - 2;
    dfs(marble, 0, 0, total);

    cout << minSum;
}
