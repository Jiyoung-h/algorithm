#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;
    vector<int> ind;
    
    for(int i=0; i<3; i++) ind.push_back(1);
    for(int i=0; i<nums.size()-3; i++) ind.push_back(0);
    sort(ind.begin(), ind.end());
    do{
        for(int i=0; i<ind.size(); i++){
            if(ind[i]==1){
                sum += (int)nums[i];
            }
        }
        
        int p;
        for(p=2; p<sum; p++){
            if(sum%p == 0){
                break;
            }
        }
        if(p == sum) answer++;
        
        sum = 0;
    } while(next_permutation(ind.begin(), ind.end()));
    return answer;
}
