#include <iostream>
#include <vector>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=0;
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length()));
    for(int i=1; i<s.length(); i++){
        if(s[i]==s[i-1]){
            dp[i-1][i]=true;
            answer=1;
        }
    }
    for(int i=2; i<s.length(); i++){
        if(s[i]==s[i-2]){
            dp[i-2][i]=true;
            answer=2;
        }
    }
    for(int i=3; i<=s.length(); i++){
        for(int j=i; j<s.length(); j++){
            if(s[j]==s[j-i] && dp[j-i+1][j-1]){
                dp[j-i][j]=true;
                answer = i;
            }
        }
    }
    return answer+1;
}
