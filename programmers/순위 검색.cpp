#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size());
    vector<vector<string>> keyword(query.size());
    vector<vector<string>> infoWord(info.size());
    for (int i = 0; i < info.size(); i++) {
        int nstart = 0;
        int j;
        string tmp{};
        for (j = 0; j < info[i].size(); j++) {
            if (info[i][j] == ' ') {
                tmp = info[i].substr(nstart, j - nstart);
                nstart = j + 1;
                infoWord[i].push_back(tmp);
            }
        }
        tmp = info[i].substr(nstart);
        infoWord[i].push_back(tmp);
    }
    for (int i = 0; i < query.size(); i++) {
        int nstart = 0;
        int j;
        string tmp{};
        for (j = 0; j < query[i].size(); j++) {
            if (query[i].substr(j, 4) == "and ") {
                tmp = query[i].substr(nstart, j - nstart - 1);
                nstart = j + 4;
                keyword[i].push_back(tmp);
            }
            if (query[i][j] >= 48 && query[i][j] <= 57) {
                tmp = query[i].substr(nstart, j - nstart - 1);
                keyword[i].push_back(tmp);
                tmp = query[i].substr(j);
                keyword[i].push_back(tmp);
                break;
            }
        }
    }
    for (int i = 0; i < keyword.size(); i++) {
        for (int j = 0; j < infoWord.size(); j++) {
            if (keyword[i][0] != "-") { if (keyword[i][0] != infoWord[j][0]) continue; }
            if (keyword[i][1] != "-") { if (keyword[i][1] != infoWord[j][1]) continue; }
            if (keyword[i][2] != "-") { if (keyword[i][2] != infoWord[j][2]) continue; }
            if (keyword[i][3] != "-") { if (keyword[i][3] != infoWord[j][3]) continue; }
            if (stoi(keyword[i][4]) > stoi(infoWord[j][4])) { continue; }
            answer[i]++;
        }
    }
    return answer;
}
