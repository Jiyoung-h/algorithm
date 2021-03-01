#include <string>
#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    vector<int> top(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[j][i]!=0){
                top[i] = j; // 각 열의 초기 top 구하기
                break;
            }
        }
    }
    stack<int> q;
    q.push(0);
    for(int i=0; i<moves.size(); i++){
        int r = moves[i] - 1;
        int k;
        if(top[r] < n)
            k = board[top[r]][r];
        else    // 바닥까지 모두 꺼냈으면
            continue;
        if(q.empty()){
            q.push(k);
        }
        else{
            int p = q.top();
            if(k==p){ // stack의 맨 위 인형과 같으면 꺼낸다
                q.pop();
                answer+=2;
            }         // 아니면 넣는다
            else{
                q.push(k);
            }
        }     
        top[r]++;     // 그 열의 top 위치를 한 칸 아래로 이동 
    }
    return answer;
}
