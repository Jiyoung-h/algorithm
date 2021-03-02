#include <string>
#include <queue>
#include <vector>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    for(int i=0; i<bridge_length; i++)
        bridge.push(0); // 먼저 0으로 다리를 모두 채운다
    int sum = 0;
    int i = 0;
    int size = truck_weights.size();
    while(!bridge.empty()){
        int front = bridge.front();
        if(i > size-1){ // 트럭을 모두 보냈으면 다리에 넣을 것 없이 내보낸다
            bridge.pop();
        }
        else {
            if(sum-front+truck_weights[i] <= weight){ // 다음 트럭을 넣을 수 있으면
                bridge.pop();
                bridge.push(truck_weights[i]);
                sum = sum - front + truck_weights[i];
                i++;
            }
            else{ // 넣을 수 없으면 0 을 넣는다
                bridge.pop();
                bridge.push(0);
                sum = sum - front;
            }
        }
        answer++;
    }
    return answer;
}
