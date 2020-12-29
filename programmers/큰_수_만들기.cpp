#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int front = 0;
    int maxindex = 0;
    int pos = k;
    for(int j=pos; j<=number.length()-1; j++){
        int max = 0;
        for(int i=front; i<=j; i++){
            if(number[i]-'0' > max){
                max = number[i]-'0';
                maxindex = i;
            }
        }
        front = maxindex + 1;
        answer = answer + to_string(max);
    }
    return answer;
}
