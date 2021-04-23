#include <iostream>
#include <vector>
using namespace std;
int n, k, nn, zero;
vector<int> a;
vector<bool> robot;
void rotation() {
    int tmp = a.back();
    a.erase(a.end() - 1);
    a.insert(a.begin(), tmp);
    bool rtmp = robot.back();
    robot.erase(robot.end() - 1);
    robot.insert(robot.begin(), rtmp);
}
void moveRobot() {
    for (int i = n - 2; i >= 0; i--) {
        if (robot[i]) {
            int j = i + 1;
            if (!robot[j] && a[j] > 0) {
                robot[j] = true;
                robot[i] = false;
                a[j]--;
                if (a[j] == 0) zero++;
            }
        }
    }
}
void addRobot() {
    if (!robot[0] && a[0] > 0) {
        robot[0] = true;
        a[0]--;
        if (a[0] == 0) zero++;
    }
}
int main() {
    cin >> n >> k;
    nn = n * 2;
    a.resize(nn);
    robot.resize(nn);
    for (int i = 0; i < nn; i++) {
        cin >> a[i];
    }
    int round{};
    while (1) {
        round++;
        rotation();
        if (robot[n - 1]) robot[n - 1] = false;
        moveRobot();
        if (robot[n - 1]) robot[n - 1] = false;
        addRobot();
        if (zero >= k) break;
    }
    cout << round;
}
