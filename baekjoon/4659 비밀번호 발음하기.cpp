#include <iostream>
using namespace std;

bool isVowel(char ch) {
    return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');
}

int main() {
    string str;
    while (1) {
        cin >> str;
        if (str == "end")
            break;
        bool flag = false;
        bool vowel = false;
        // 모음이 존재하는지, 연속하는 모음/자음의 개수
        int cv{}, cc{};
        // 이전 문자
        char pre = '#';
        for (int i = 0; i < str.length(); i++) {
            if (!isalpha(str[i])) {
                flag = true;
                break;
            }
            if (isVowel(str[i])) vowel = true;
            if (pre == str[i] && str[i] != 'e' && str[i] != 'o') {
                flag = true;
                break;
            }
            if (pre != '#' && isVowel(pre)== isVowel(str[i])) {
                int *c = (isVowel(pre)) ? &cv : &cc;
                (*c)++;
                if (*c > 2) {
                    flag = true;
                    break;
                }
            }
            else {
                if (isVowel(str[i])) {
                    cv++;
                    cc = 0;
                }
                else {
                    cc++;
                    cv = 0;
                }
            }
            pre = str[i];
        }
        if (vowel && !flag) {
            cout << '<' << str << '>' << " is acceptable.\n";
        }
        else {
            cout << '<' << str << '>' << " is not acceptable.\n";
        }
    }
}
