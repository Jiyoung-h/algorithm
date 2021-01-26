#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    char alpha = 'A';
    string str;
    int index;
    for (index = 1; index < 27; index++) {
        str = alpha;
        dic[str] = index;
        alpha++;
    }
    string tmp;
    tmp = msg[0];
    for (int i = 1; i < msg.size(); i++) {
        tmp = tmp + msg[i];
        if (!dic[tmp]) {
            string tmp1 = tmp.substr(0, tmp.size() - 1);
            answer.push_back(dic[tmp1]);
            dic[tmp] = index;
            index++;
            tmp.clear();
            i--;
        }
    }
    answer.push_back(dic[tmp]);

    return answer;
}
