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
        // 연결되어 있는 컴퓨터를 모두 체크했으면
        if (q.empty()) {
            answer++;
            int k;
            // 모든 컴퓨터를 체크했으면
            if (check.size() == n) {
                return answer;
            }
            for (k = 0; k < n; k++) {
                if (!check[k]) {
                    // 체크되어있지 않은 컴퓨터가 있으면 큐에 넣고 다시 bfs
                    q.push(k);
                    check[k] = true;
                    break;
                }
            }
        }
    }
}
