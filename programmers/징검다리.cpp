#include <string>
#include <vector>
using namespace std;
bool calc(int n, const vector<int>& stones, int k) {
    int now = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - n <= 0)
            now++;
        else
            now = 0;
        if (now >= k)   
            return false;
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int left = 1;
    int right = 200000001;  // 이분탐색
    while (left <= right) {
        int mid = (left + right) / 2;
        if (calc(mid, stones, k))   // (mid)명이 건널 수 있는지
            left = mid + 1;         // 건널 수 있으면 오른쪽 탐색
        else                        // 건널 수 없으면 왼쪽 탐색
            right = mid - 1;
    }
    return left;
}
