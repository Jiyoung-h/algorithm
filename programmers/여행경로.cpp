#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool dfs(string airport, vector<vector<string>> ticket, vector<string>& answer, vector<bool>& visit, int cnt) {
    answer.push_back(airport);
    if (cnt == ticket.size()) return true;  // 마지막 티켓
    for (int i = 0; i < ticket.size(); i++) {
        if (ticket[i][0] == airport && !visit[i]) {
            visit[i] = true;
            if (dfs(ticket[i][1], ticket, answer, visit, cnt + 1)) return true; // 차례대로 return
            visit[i] = false;
        }
    }
    answer.pop_back();  // 빠져나왔으면 뺀다
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visit(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, answer, visit, 0);

    return answer;
}
