#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> m;
    for(int n : nums){
        m[n]++;
    }
    if(m.size() >= nums.size()/2) return nums.size()/2;
    else return m.size();
}
