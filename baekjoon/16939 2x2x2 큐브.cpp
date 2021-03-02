#include <iostream>
using namespace std;
bool same(int a, int b, int c, int d) {
    if (a == b)
        if (b == c)
            if (c == d)
                return true;
    return false;
}
int main()
{
    int cube[25] = { 0, };
    for (int i = 1; i < 25; i++) {
        cin >> cube[i];
    }
    if (same(cube[13], cube[14], cube[15], cube[16])
        && same(cube[1], cube[3], cube[21], cube[23])
        && same(cube[5], cube[7], cube[2], cube[4])
        && same(cube[9], cube[11], cube[6], cube[8])
        && same(cube[22], cube[24], cube[10], cube[12])
        && same(cube[17], cube[18], cube[19], cube[20])) {
        cout << 1;
    }
    else if (same(cube[13], cube[14], cube[15], cube[16])
        && same(cube[1], cube[3], cube[6], cube[8])
        && same(cube[5], cube[7], cube[10], cube[12])
        && same(cube[9], cube[11], cube[21], cube[23])
        && same(cube[22], cube[24], cube[2], cube[4])
        && same(cube[17], cube[18], cube[19], cube[20])) {
        cout << 1;
    }
    else if (same(cube[1], cube[2], cube[3], cube[4])
        && same(cube[13], cube[14], cube[7], cube[8])
        && same(cube[5], cube[6], cube[19], cube[20])
        && same(cube[17], cube[18], cube[23], cube[24])
        && same(cube[21], cube[22], cube[15], cube[16])
        && same(cube[9], cube[10], cube[11], cube[12])) {
        cout << 1;
    }
    else if (same(cube[1], cube[2], cube[3], cube[4])
        && same(cube[17], cube[18], cube[7], cube[8])
        && same(cube[21], cube[22], cube[19], cube[20])
        && same(cube[13], cube[14], cube[23], cube[24])
        && same(cube[5], cube[6], cube[15], cube[16])
        && same(cube[9], cube[10], cube[11], cube[12])) {
        cout << 1;
    }
    else if (same(cube[5], cube[6], cube[7], cube[8])
        && same(cube[21], cube[22], cube[23], cube[24])
        && same(cube[1], cube[2], cube[16], cube[14])
        && same(cube[3], cube[4], cube[18], cube[20])
        && same(cube[17], cube[19], cube[11], cube[12])
        && same(cube[9], cube[10], cube[13], cube[15])) {
        cout << 1;
    }
    else if (same(cube[5], cube[6], cube[7], cube[8])
        && same(cube[21], cube[22], cube[23], cube[24])
        && same(cube[1], cube[2], cube[17], cube[19])
        && same(cube[9], cube[10], cube[18], cube[20])
        && same(cube[14], cube[16], cube[11], cube[12])
        && same(cube[3], cube[4], cube[13], cube[15])) {
        cout << 1;
    }
    else {
        cout << 0;
    }
}
