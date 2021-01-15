#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
string friends = "ACFJMNRT" ;

int solution(int n, vector<string> data) {
    int answer = 0;
    sort(friends.begin(), friends.end());
    do {
        map<char, int> m;
        for (int i = 0; i < friends.length(); i++) {
            m[friends[i]] = i;
        }
        for (int i = 0; i < data.size(); i++) {
            char op = data[i][3];
            int sum = data[i][4] - '0';
            int tmp = abs(m[data[i][0]] - m[data[i][2]]) - 1;
            if (op == '=' && tmp == sum){}
            else if (op == '<' && tmp < sum){}
            else if (op == '>' && tmp > sum){}
            else {
                answer--; break;
            }
        }
        answer++;
    } while (next_permutation(friends.begin(), friends.end()));
    return answer;
}
