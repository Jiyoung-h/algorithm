#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int size = citations.size();
    sort(citations.begin(), citations.end());
    if(citations.back()==0)return 0;
    for(int i=size-1; i>=0; i--){
        if(i==0) return size;
        if(citations[i-1]<=size-i) return size-i;
    }
}
