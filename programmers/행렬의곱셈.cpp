#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
vector<vector<int>> answer;
   for (int i = 0; i < arr1.size(); i++) {
        vector<int> tmp;
        for (int j = 0; j < arr2[0].size(); j++) {
            int sum{};
            for (int n = 0; n < arr1[0].size(); n++) {
                sum = sum + arr1[i][n] * arr2[n][j];
            }
            tmp.push_back(sum);
        }
        answer.push_back(tmp);
    }
    return answer;
}
