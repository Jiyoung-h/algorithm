#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    vector<string> result(1);   // 정렬된 두 vector의 차집합
    set_difference(participant.begin(), participant.end(), completion.begin(), completion.end(), result.begin()); 
    answer = result[0];
    return answer;
}
