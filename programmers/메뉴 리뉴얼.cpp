#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

void DFS(map<string, int>& dic, string& order, string comb, int index, int depth) {
    if (depth == comb.length()) {
        dic[comb]++;  // dic['AB']++ => 'AB'가 등장한 횟수
        return;
    }

    for (int i = index; i < order.length(); i++) {
        comb[depth] = order[i];
        DFS(dic, order, comb, i + 1, depth + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<string, int> dic;

    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end()); // AB=BA 이기 때문에 정렬
        for (int j = 0; j < course.size(); j++) { // course 에 해당하는 모든 조합 구하기
            string comb = "";
            comb.resize(course[j]);
            DFS(dic, orders[i], comb, 0, 0);
        }   // (dic, order, comb, index, depth
    }       // depth가 comb의 길이에 도달하면 조합 완성되어 dfs 종료
    
    vector<pair<string, int>> sorted;
    for (auto& order : dic) 
        if (order.second > 1)   // map의 원소들을 pair로 옮겨서 정렬, 2번 이상 등장한 것들
            sorted.push_back(make_pair(order.first, order.second));
    sort(sorted.begin(), sorted.end(), cmp);
    // Value에 의한 내림차순 정렬 (가장 많이 등장한 조합 순)
    
    for(int i = 0; i < course.size(); i++){
        int max = 0;
        // 메뉴의 수가 course[i]인 것 중 가장 많이 등장한 조합 구하기
        for(int j = 0; j < sorted.size(); j++){
            if (sorted[j].first.length() != course[i]) // 메뉴의 수
                continue;
            else if (max == 0){ // 최대값이 없으면
                answer.push_back(sorted[j].first);
                max = sorted[j].second;
            }
            else if (max == sorted[j].second) // 최대값과 같으면 (이미 내림차순이므로)
                answer.push_back(sorted[j].first);
            else 
                break;
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
