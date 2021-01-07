#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    string word1 = "";
    string word2 = "";
    string z = "";
    int zindex = 0;
    for (int i = 0; i < words.size(); i++) {
        word1 = words[i];
        if (z[0] != word1[0] && i != 0) {
            answer.push_back((i % n) + 1);
            answer.push_back((i / n) + 1);
            return answer;
        }
        else {
             for (int j = 0; j < i; j++) {
                if (words[i] == words[j]) {
                    answer.push_back((i % n) + 1);
                    answer.push_back((i / n) + 1);
                    return answer;
                }
            }
        }
        word2 = words[i];
        zindex = word2.length() - 1;
        z = word2[zindex];
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
