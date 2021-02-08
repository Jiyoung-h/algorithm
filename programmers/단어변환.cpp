#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 1;
    queue<pair<string, int>> q;
    queue<pair<string, int>> tmp_q;
    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    for (int i = 0; i < words.size(); i++) {
        int count = 0;
        for (int j = 0; j < begin.size(); j++) {
            if (begin[j] == words[i][j])
                count++;
        }
        if (count == begin.size() - 1)
            q.push(make_pair(words[i], i));
    }
    while (!q.empty()) {
        pair<string, int> p;
        p = q.front();
        q.pop();
        string str = p.first;

        if (str == target)
            return answer;
        for (int i = p.second + 1; i < words.size(); i++) {
            int count = 0;
            for (int j = 0; j < str.size(); j++) {
                if (str[j] == words[i][j])
                    count++;
            }
            if (count == str.size() - 1)
                tmp_q.push(make_pair(words[i], i));
        }
        if (q.empty()) {
            q = tmp_q;
            answer++;
            while (!tmp_q.empty())
                tmp_q.pop();
        }
    }
    return answer;
}
