#include <iostream>
#include <queue>
using namespace std;
struct cmp {
    bool operator()(pair<long long, long long> a, pair<long long, long long> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

int main() {
    int n;
    cin >> n;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp> q;
    long long a, b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) {
            if (q.empty()) cout << 0 << "\n";
            else {
                cout << q.top().second << "\n";
                q.pop();
            }
        }
        else {
            q.push({ abs(a), a });
        }
    }
}
