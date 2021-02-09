#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, j = 0, time = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    while (j < jobs.size() || !pq.empty()) {
        if (jobs.size() > j&& time >= jobs[j][0]) {
            pq.push(jobs[j++]);     // 들어올 시간이 됐으면
            continue;               // pq에 삽입
        }
        if (!pq.empty()) {          // 다음 일이 들어오지 않으면
            time += pq.top()[1];    // jobs[i][1] 이 작은 순서대로 처리
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
            time = jobs[j][0];      // 대기시간 절약
    }
    return answer / jobs.size();
}
