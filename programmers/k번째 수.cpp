#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for(int x=0; x<commands.size(); x++){
        int i = commands[x][0];
        int j = commands[x][1];
        int k = commands[x][2];
        for(int y = i-1; y < j; y++){
            temp.push_back(array[y]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k-1]);
        temp.clear();
    }
    return answer;
}
