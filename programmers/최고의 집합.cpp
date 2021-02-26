#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq;
    if(s/n < 1) return {-1};
    for(int i=0; i<n; i++){
        pq.push(s/n);
    }
    for(int i=0; i<s%n; i++){
        int num = pq.top() + 1;
        pq.pop();
        pq.push(num);
    }
    for(int i=0; i<n; i++){
        answer.push_back(pq.top());
        pq.pop();
    }
    return answer;
}
