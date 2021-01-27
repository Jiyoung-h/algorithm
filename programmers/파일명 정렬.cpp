#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<string> a, vector<string> b) {
    if (a[0] < b[0]) return true; 
    else { 
        if (a[0] == b[0]) 
            return stoi(a[1]) < stoi(b[1]); 
        else return false; 
    } 
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> v(files.size());
    for (int i = 0; i < files.size(); i++) {
        string tmp{};
        int j;
        for (j = 0; j < files[i].size(); j++) {
            if ((files[i][j] >= 65 && files[i][j] <= 90) || files[i][j] == ' ' || files[i][j] == '.' || files[i][j] == '-') {
                tmp = tmp + files[i][j];
            }
            else if (files[i][j] >= 97 && files[i][j] <= 122) {
                char c = files[i][j] - 32;
                tmp = tmp + c;
            }
            else {
                v[i].push_back(tmp);
                break;
            }
        }
        tmp.clear();
        for (; j < files[i].size(); j++) {
            if (tmp.size() == 5) break;
            if (files[i][j] >= 48 && files[i][j] <= 57) {
                tmp = tmp + files[i][j];
            }
            else break;
        }
        v[i].push_back(tmp);
        v[i].push_back(to_string(i));
    }
    stable_sort(v.begin(), v.end(), compare);
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(files[stoi(v[i][2])]);
    }
    return answer;
}
