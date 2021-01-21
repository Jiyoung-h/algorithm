#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<vector<string>> words(record.size());
    for (int i = 0; i < record.size(); i++) {
        int nstart = 0;
        string tmp{};
        for (int j = 0; j < record[i].length(); j++) {
            tmp.clear();
            if (record[i][j] == ' ') {
                tmp = record[i].substr(nstart, j - nstart);
                nstart = j + 1;
            }
            if (j == record[i].length()-1) {
                tmp = record[i].substr(nstart, record[i].size() - nstart);
            }
            if (tmp != "") {
                words[i].push_back(tmp);
            }
        }
    }
    map<string, string> name;
    for (int i = 0; i < words.size(); i++) {
        if (words[i].size() > 2) {
            name[words[i][1]] = words[i][2];
        }
    }

    for (int i = 0; i < words.size(); i++) {
        string tmp;
        if (words[i][0] == "Enter") tmp = "님이 들어왔습니다.";
        else if (words[i][0] == "Leave") tmp = "님이 나갔습니다.";
        else continue;
        answer.push_back(name[words[i][1]] + tmp);
    }
    
    return answer;
}
