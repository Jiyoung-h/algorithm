#include <vector>
#include <string>
using namespace std;
vector<vector<int>> answer;

void hanoi(int n, int from, int to, int tmp){
    vector<int> temp = { from, to };
    if (n == 1) answer.push_back(temp);
    else{
        hanoi(n-1, from, tmp, to);  // 1 -> 2 로 N-1 개 이동
        answer.push_back(temp);     // 1 -> 3 으로 마지막 블록 이동
        hanoi(n-1, tmp, to, from);  // 2 -> 3 으로 N-1 개 이동
    }
}
vector<vector<int>> solution(int n){
    hanoi(n, 1, 3, 2); // 재귀를 이용 (1 -> 3 이동)
    return answer;
}
