#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> pattern(3);
    pattern[0] = {1,2,3,4,5};
    pattern[1] = {2,1,2,3,2,4,2,5};
    pattern[2] = {3,3,1,1,2,2,4,4,5,5};
    int correct[3] = {0, };
    
    for(int i=0; i<3; i++){
        for(int j=0; j<answers.size(); j++){
            int psize = pattern[i].size();
            if(answers[j] == pattern[i][j%psize])
                correct[i]++;
        }
    }
    
    int maxScore = max(max(correct[0],correct[1]),correct[2]);
    for (int i=0; i<3; i++){
        if(correct[i] == maxScore) answer.push_back(i+1);
    }
    return answer;
}
