#include <iostream>
#include <vector>
using namespace std;

int main() {
    int cry{}, uncry{};
    string str;
    cin >> str;
    string quack = "quack";
    vector<string> duck;
    bool flag = false;
    for (int i = 0; i < str.length(); i++) {
        if (duck.empty() && str[i] != 'q') {            
            flag = true;
            break;
        }
        else {
            if (str[i] == 'q') {
                if (uncry > 0) uncry--;
                cry++;
                duck.push_back("q");
            }
            else if (str[i] == 'k') {
                for (int j = 0; j < duck.size(); j++) {
                    if (duck[j].size() == 4) {
                        duck.erase(duck.begin() + j);
                        cry--;
                        uncry++;
                        flag = true;
                        break;
                    }
                }
                flag = !flag;
                if (flag) break;
            }
            else {
                for (int j = 0; j < duck.size(); j++) {
                    int index = duck[j].size();
                    if (quack[index] == str[i]) {
                        duck[j] += str[i];
                        flag = true;
                        break;
                    }
                }
                flag = !flag;
                if (flag) break;
            }
        }
    }
    if (!duck.empty()) flag = true;
    if (flag) cout << -1;
    else cout << cry + uncry;
}
