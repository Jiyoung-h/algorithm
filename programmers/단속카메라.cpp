#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int temp = routes[0][1];
    for(int i=0; i<routes.size(); i++){
        if(temp < routes[i][0]){    // 뒷차가 들어오기 전에 앞차가 나가면
            answer++;               // 카메라 추가
            temp = routes[i][1];    // 기준을 뒷차로 변경
        }                                               // 뒷차가 먼저 나가면
        if (temp >= routes[i][1]) temp = routes[i][1];  // 기준을 뒷차로 변경
    }
    return answer;
}
