#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
bool check[8];
int blen, ulen;
set<string> s;
 
void solve(int index, string res, vector<string> user_id, vector<string> banned_id) {
    if (index == blen) {
        sort(res.begin(), res.end());
        s.insert(res);
        return;
    }
    string bid = banned_id[index]; // index 번째 불량 사용자 아이디 검사
    int bidlen = bid.size();
 
    for (int i = 0; i < ulen; i++) {
        string uid = user_id[i];
 
        if (uid.size() != bidlen) continue;
        if (check[i]) continue; // 이미 불량 사용자로 사용한 경우
 
        bool flag = true;
        for (int j = 0; j < bidlen; j++) {
            if (bid[j] == '*') continue;
            if (uid[j] != bid[j]) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            check[i] = true;
            solve(index + 1, res + to_string(i), user_id, banned_id);
            // index+1 번째 불량 사용자 검사 (재귀)
            check[i] = false;
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
 
    ulen = user_id.size();
    blen = banned_id.size();
 
    solve(0, "", user_id, banned_id);
    answer = s.size();
 
    return answer;
}
