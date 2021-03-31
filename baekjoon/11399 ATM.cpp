#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int answer;

int sum(vector<int> p) {
    int tmp{}, result{};
    for (int i = 0; i < n; i++) {
        tmp += p[i];
        result += tmp;
    }
    return result;
}

int main() {
    cin >> n;
    answer = 10000000;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    answer = sum(p);
    cout << answer;
}
