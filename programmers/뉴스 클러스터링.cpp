#include <string>
#include <queue>
#include <set>
using namespace std;

int solution(string str1, string str2) {
    int answer = 65536;
    int intersection{}, unionsection{};
    multiset<string> s1, s2;
    for(int i=0; i<str1.length(); i++){
        if(str1[i]<=90 && str1[i]>=65){ // 대문자면
            str1[i]=str1[i]+32; // 소문자로 변환
        }
        if(str1[i-1]<=122 && str1[i-1]>=97 && str1[i]<=122 && str1[i]>=97){
            string a = str1.substr(i-1, 2);
            s1.insert(a);
        }
    }
    for(int i=0; i<str2.length(); i++){
        if(str2[i]<=90 && str2[i]>=65){
            str2[i]=str2[i]+32;
        }
        if(str2[i-1]<=122 && str2[i-1]>=97 && str2[i]<=122 && str2[i]>=97){
            string a = str2.substr(i-1, 2);
            s2.insert(a);
        }
    }
    if(s1.empty() && s2.empty()) return answer;
    multiset<string> copy1(s1);
    
    multiset<string>::iterator iter;
    for(iter = s1.begin(); iter != s1.end(); iter++){
        string a = *iter;
        if(s2.find(a)!=s2.end()) {
            intersection++;
            s2.erase(s2.find(a));
        }
        else unionsection++;
    }
    unionsection=unionsection+intersection+s2.size();
    answer = answer/unionsection*intersection;
    return answer;
}
