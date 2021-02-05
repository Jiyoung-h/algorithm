#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if (a[2] < b[2]) return true;
    else return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    map<int, bool> check;
    sort(costs.begin(), costs.end(), compare);
    for (int i = 0; i < costs.size(); i++) {
        if (check.size() == n) return answer;
        if (check[costs[i][0]] && check[costs[i][1]]) continue;
        check[costs[i][0]] = true;
        check[costs[i][1]] = true;
        answer += costs[i][2];
    }
}
