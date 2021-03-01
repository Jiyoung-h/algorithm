#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    bool check[201]{false, };
    for(int i=0; i<numbers.size()-1; i++){
        for(int j=i+1; j<numbers.size(); j++){
            int sum = numbers[i] + numbers[j];
            if(!check[sum]){                
                answer.push_back(sum);
                check[sum] = true;
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
