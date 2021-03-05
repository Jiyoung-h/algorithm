#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1;
    int end;
    int i;
    int length, count, remain;
    for(i=0; i<stations.size(); i++){
        if(stations[i] - w > start){    // 기지국이 닿지 않는 구간 start ~ end
            end = stations[i] - w - 1;
            length = end - start + 1;   // 구간의 길이
            count = length / (w*2+1);   // 기지국의 갯수 = 구간의 길이 / 기지국의 범위
            remain = ((length % (w*2+1)) > 0) ? 1 : 0;
            count += remain;            // 소숫점 올림
            answer += count;
        }
       start = stations[i] + w + 1;
    }
    if(stations[i-1] + w < n) {
        length = n - start + 1;
        count = length / (w*2+1);
        remain = ((length % (w*2+1)) > 0) ? 1 : 0;
        count += remain;
        answer += count;
    }
    return answer;
}
