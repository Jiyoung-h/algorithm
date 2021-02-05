#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> q;
    map<int, bool> check;
    int i = 0;
    check[i] = true;
    q.push(i);
    while (1) {
        int pos = q.front();
        q.pop();
        for (int j = 0; j < n; j++) {
            if (computers[pos][j] == 1 && pos != j && !check[j]) {
                q.push(j);
                check[j] = true;
            }
        }
        if (q.empty()) {
            answer++;
            int k;
            if (check.size() == n) {
                return answer;
            }
            for (k = 0; k < n; k++) {
                if (!check[k]) {
                    q.push(k);
                    check[k] = true;
                    break;
                }
            }
        }
    }
}
