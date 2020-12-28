#include <string>
#include <vector>
using namespace std;
int forward(string name){
    int a = 'A';
    int z = 'Z';
    int answer = 0;
    for (int i=0; i<name.length(); i++){
        int n = name[i];
        n = min(n - a, z - n + 1);
        answer = n + answer;
        answer++;
    }
    for (int i=name.length()-1; i>=0; i--){
        if(name[i]=='A') answer --;
        else break;
    }
    return answer;
}
int backward(string name){ 
    int a = 'A';
    int z = 'Z';
    int answer = 0;
    int n = name[0];
    n = min(n - a, z - n + 1);
    answer = n + answer;
    answer++;
    for (int i=name.length()-1; i>0; i--){
        int n = name[i];
        n = min(n - a, z - n + 1);
        answer = n + answer;
        answer++;
    }
    for (int i=1; i<name.length(); i++){
        if(name[i]=='A') answer --;
        else break;
    }
    return answer;
}
int solution(string name) {
    int answer = 0;
    answer = min(forward(name), backward(name));
    if (answer == 0) return answer;
    else return answer - 1;
}