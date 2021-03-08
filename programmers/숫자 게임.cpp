#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int n = A.size();
    int apos = 0;
    int bpos = 0;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    if (A[n - 1] >= B[0])   // A에서 가장 작은것이 B에서 가장 큰것보다 크면
        return 0;
    
    for (int i = 0; i < n; i++) {
        if (A[apos] < B[bpos]) {
            bpos++;
            answer++;
        }   // B가 졌으면 A만 이동시키고, B가 이겼으면 둘 다 이동
        apos++;
    }
    return answer;
}
