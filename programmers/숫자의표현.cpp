#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> sum;
    sum.push_back(0);
    for (int i = 1; i <= n; i++) {
        int tmp = sum.back() + i;
        sum.push_back(tmp);
    }
    for (int i = n; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            if (sum[i] - sum[j] == n) { 
                answer++; 
                break;
            }
            else if (sum[i] - sum[j] < n) continue;
            else break;
        }
    }
    return answer;
}
