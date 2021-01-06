#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    for(int i=1; i<(1<<numbers.size()); i++){
        int sum = 0;
        for(int j=0; j<numbers.size(); j++){
            if(i&(1<<j)){
                sum += numbers[j];
            }
            else{
                sum -= numbers[j];
            }
        }
        if(sum == target) answer++;
    }
    return answer;
}
