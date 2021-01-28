#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> t(triangle);
    for (int i = 0; i < triangle.size() - 1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            t[i + 1][j] = max(t[i][j] + triangle[i + 1][j], t[i + 1][j]);
            t[i + 1][j + 1] = max(t[i][j] + triangle[i + 1][j + 1], t[i + 1][j + 1]);
        }
    }
    sort(t[t.size() - 1].begin(), t[t.size() - 1].end());
    return t[t.size() - 1].back();
}
