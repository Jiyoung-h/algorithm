#include <iostream>
#include <vector>
using namespace std;
string gear[4];
bool check[4];
void rotation(int g, int d) {
    char left = gear[g][6];
    char right = gear[g][2];
    check[g] = true;
    if (d == 1) {
        char tmp = gear[g][7];
        for (int i = 7; i > 0; i--) {
            gear[g][i] = gear[g][i - 1];
        }
        gear[g][0] = tmp;
    }
    else {
        char tmp = gear[g][0];
        for (int i = 0; i < 7; i++) {
            gear[g][i] = gear[g][i + 1];
        }
        gear[g][7] = tmp;
    }
    if (g - 1 >= 0 && check[g - 1] == false) {
        if (gear[g - 1][2] != left) {
            rotation(g - 1, -d);
        }
    }
    if (g + 1 <= 3 && check[g + 1] == false) {
        if (gear[g + 1][6] != right) {
            rotation(g + 1, -d);
        }
    }
}
int main() {
    for (int i = 0; i < 4; i++) {
        cin >> gear[i];
    }
    int k;
    cin >> k;
    int n, d;
    for (int i = 0; i < k; i++) {
        cin >> n >> d;
        n--;
        fill_n(check, 4, false);
        rotation(n, d);
    }
    int answer = 0;
    if (gear[0][0] == '1')answer += 1;
    if (gear[1][0] == '1')answer += 2;
    if (gear[2][0] == '1')answer += 4;
    if (gear[3][0] == '1')answer += 8;
    cout << answer;
}
