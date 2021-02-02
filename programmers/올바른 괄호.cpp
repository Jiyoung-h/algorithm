#include<string>
using namespace std;

bool solution(string s)
{
  bool answer = true;
  int st = 0;
  for(int i=0; i<s.size(); i++){
    if(s[i] == '(') st++;
    else st--;
    if(st < 0) answer = false;
  }
  if(st != 0) answer = false;
    return answer;
}
