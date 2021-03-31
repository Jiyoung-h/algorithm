#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, answer{};
    cin >> n;
    int cow[11] = { 0, };
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (cow[a] == 0) {
            cow[a] = b + 1;
        }
        else {
            if (cow[a] != b + 1) {
                answer++;
                cow[a] = b + 1;
            }
        }
    }
    cout << answer;
}
