#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
int n, s, e;
bool prime[10000];
int check[10000];
void eratos() {
    for (int i = 2; i * i < 10000; i++) {
        for (int j = i * i; j < 10000; j += i) {
            prime[j] = false;
        }
    }
}
void bfs(int start) {
    queue<int> q;
    q.push(start);
    check[start] = 0;
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        if (num == e) {
            return;
        }
        for (int i = 0; i < 4; i++) {
            string str = to_string(num);    // 정수를 문자열로 변환하여 한글자씩
            for (int j = 0; j < 10; j++) {  // 0부터 9까지 대입
                str[i] = j + '0';           // int + '0' = char
                int next = stoi(str);       // 다시 정수로 변환
                if (next >= 1000 && prime[next] == true && check[next] == -1) {
                    check[next] = check[num] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main() {
    memset(prime, true, sizeof(prime));
    eratos();
    cin >> n;

    while (n--) {
        memset(check, -1, sizeof(check));
        cin >> s >> e;
        bfs(s);
        if (check[e] != -1) {
            cout << check[e] << endl;
        }
        else {
            cout << "Impossible" << endl;
        }
    }
}
