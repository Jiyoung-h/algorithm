#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    if(n <= 2) return 1;
	vector<vector<int>> rank(n, vector<int>(n));
	for (int i = 0; i < results.size(); i++) {
		rank[results[i][0] - 1][results[i][1] - 1] = 1;
		rank[results[i][1] - 1][results[i][0] - 1] = -1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) { rank[i][j] = 2; continue; }
			if (rank[i][j] == 1) {
				for (int k = 1; k < n; k++) {
					if (rank[j][k] == 1) {
						rank[i][k] = 1;
						rank[k][i] = -1;
					}
				}
			}
			else if (rank[i][j] == -1) {
				for (int k = 1; k < n; k++) {
					if (rank[j][k] == -1) {
						rank[i][k] = -1;
						rank[k][i] = 1;
					}
				}
			}
		}
	}
	bool ans;
	for (int i = 0; i < n; i++) {
		ans = true;
		for (int j = 0; j < n; j++) {
			if (rank[i][j] == 0) ans = false;
		}
		if (ans) answer++;
	}
    return answer;
}
