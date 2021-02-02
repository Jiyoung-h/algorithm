#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
vector<int> ans;
int n;
 
void solve(int idx, int sum, int plus, int minus, int mult, int div, vector<int> num) {
    //모든 숫자를 연산에 다 사용하면 return한다.
    if (idx == n) {
        ans.push_back(sum);
        return;
    }
    //하나를 넣냐 안넣냐가 아니라 4개 중 하나를 넣냐 안넣냐기 때문에 4가지 경우로 나뉜다.
    if (plus != 0) solve(idx + 1, sum + num[idx], plus - 1, minus, mult, div, num);
    if (minus != 0) solve(idx + 1, sum - num[idx], plus, minus - 1, mult, div, num);
    if (mult != 0) solve(idx + 1, sum * num[idx], plus, minus, mult - 1, div, num);
    if (div != 0) solve(idx + 1, sum / num[idx], plus, minus, mult, div - 1, num);
}
 
int main(int argc, char** argv) {
    cin >> n;
 
    vector<int> num(n);
    vector<int> op(4);
 
    for (int i = 0; i < n; i++)cin >> num[i];
    for (int i = 0; i < 4; i++)cin >> op[i];
 
    solve(1, num[0], op[0], op[1], op[2], op[3], num);
 
    auto res = minmax_element(ans.begin(), ans.end());
 
    printf("%d\n%d\n", *res.second, *res.first);
 
    return 0;
}
