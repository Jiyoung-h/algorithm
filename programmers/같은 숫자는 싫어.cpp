#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    for(int i=1; i<arr.size(); i++){
        if(arr[i]!=arr[i-1]){
            answer.push_back(arr[i-1]); // 달라졌을때 앞글자를 가져온다
        }
    }
    // 맨 뒤글자는 비교상대가 없으므로 
    answer.push_back(arr[arr.size()-1]);
    return answer;
}
