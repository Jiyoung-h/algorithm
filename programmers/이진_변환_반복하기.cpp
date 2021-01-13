#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string tenToTwo(int N){
    string S = "";
    while (N > 0)
    {
        S += ((N % 2) + '0');
        N /= 2;
    }
    reverse(S.begin(), S.end());
    return S;
}

vector<int> solution(string s) {
    vector<int> answer;
    int round = 0;
    int erase = 0;
    while(s != "1"){
        round++;
        int Ocount{}, Icount{};
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]=='0') {
               Ocount++;
            }
            else Icount++;
        }
        erase += Ocount;
        s = tenToTwo(Icount);
    }
    answer.push_back(round);
    answer.push_back(erase);
    return answer;
}
