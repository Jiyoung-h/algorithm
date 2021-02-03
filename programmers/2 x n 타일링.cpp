#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    vector<int> d;
    for(int i=0; i<n; i++){
        if(i==0) d.push_back(1);
        else if(i==1) d.push_back(2);
        else d.push_back((d[i-1]+d[i-2])%1000000007);
    }
    int answer = d[n-1];
    return answer;
}
