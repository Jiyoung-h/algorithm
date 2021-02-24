#include <string>
#include <set>
#include <iostream>
using namespace std;
struct Adj {
    int x1;
    int y1;
    int x2;
    int y2;
    Adj(int x1, int y1, int x2, int y2) :x1(x1), y1(y1), x2(x2), y2(y2) {}
    bool operator <(const Adj& rhs) const
    {
        if (x1 < rhs.x1) { return true; }
        if (rhs.x1 < x1) { return false; }
        if (y1 < rhs.y1) { return true; }
        if (rhs.y1 < y1) { return false; }
        if (x2 < rhs.x2) { return true; }
        if (rhs.x2 < x2) { return false; }
        if (y2 < rhs.y2) { return true; }
        if (rhs.y2 < y2) { return false; }
        return false;
    }
};

int solution(string dirs) {
    int answer = 0;
    set<Adj> check;
    pair<int, int> pos = make_pair(5, 5);
    for (int i = 0; i < dirs.length(); i++) {
        int x1 = pos.first;
        int y1 = pos.second;
        int x2 = x1;
        int y2 = y1;
        if (dirs[i] == 'U') {
            x2--;
        }
        if (dirs[i] == 'D') {
            x2++;
        }
        if (dirs[i] == 'R') {
            y2++;
        }
        if (dirs[i] == 'L') {
            y2--;
        }
        if (x2 > 10 || x2 < 0 || y2>10 || y2 < 0) {
            x2 = x1;
            y2 = y1;
        }
        struct Adj a(x1, y1, x2, y2);
        struct Adj b(x2, y2, x1, y1);
        if (x1 != x2 || y1 != y2) {
            if (check.find(a) == check.end() && check.find(b) == check.end()) {
                check.insert(a);
                check.insert(b);
                answer++;
            }
        }
        pos = make_pair(x2, y2);
        cout << x2 << ',' << y2 << endl;
    }
    return answer;
}
