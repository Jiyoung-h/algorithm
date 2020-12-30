#include <string>
#include <algorithm>
#include <vector>

using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), cmp);
    int l = 0;
    int r = people.size()-1;
    
    while(l<r){
    	int sum = people[l] + people[r];
        if(sum>limit){
        	l++; 
        } else {
        	l++;
            r--;
        }
        answer++;
    }
    if(l == r) answer++;
    return answer;
}
