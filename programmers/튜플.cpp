#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    string num{};
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '{' && s[i] != ',' && s[i] != '}') {
            num += s[i];
        }
        else {
            if (num.length() != 0) {
                answer.push_back(stoi(num));
                num = "";
            }
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}
