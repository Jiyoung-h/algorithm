#include <string>
#include <iostream>
#include <map>
using namespace std;
map<char, bool> use;

string solution(string sentence) {
    string answer = "";
    while (!sentence.empty()) {
        if(!answer.empty()) answer = answer + " ";
        if (sentence[0] >= 65 && sentence[0] <= 90) { // 대문자로 시작
            answer = answer + sentence[0];
            if (sentence[1] >= 97 && sentence[1] <= 122) {
                char tmp = sentence[1];
                if (use[tmp]) return "invalid";
                use[tmp] = true;
                int i = 1;
                for (; i < sentence.length(); i = i + 2) {
                    if (sentence[i] == tmp && sentence[i + 1] >= 65 && sentence[i + 1] <= 90) {
                        answer = answer + sentence[i + 1];
                    }
                    else break;
                }
                sentence = sentence.substr(i);
            }
        }
        else {  // 소문자로 시작
            char tmp = sentence[0];
            if (use[tmp]) return "invalid";
            use[tmp] = true;
            int i = 1;
            for (; i < sentence.length(); i++) {
                if (sentence[i] >= 65 && sentence[i] <= 90) {   // 다음 문자가 대문자
                    answer = answer + sentence[i];
                }
                else if (sentence[i] == tmp) {
                    sentence = sentence.substr(i + 1);
                    break;
                }
                else { return "invalid"; }
            }
        }
    }
    return answer;
}
