#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    int nstart = 0;
    vector<int> number;
    string str{};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            str = s.substr(nstart, i - nstart + 1);
            nstart = i + 1;
            number.push_back(stoi(str));
        }
    }
    str = s.substr(nstart, s.size() - nstart + 1);
    number.push_back(stoi(str));
    
    sort(number.begin(), number.end());
    string min = to_string(number.front());
    string max = to_string(number.back());
    answer = min + " " + max;

    return answer;
}
