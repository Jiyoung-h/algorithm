#include <stdio.h>
long long d[1000001];
const long long mod = 10009LL;
const int limit = 100000;
int main() {
    d[0] = 1;
    for (int i=1; i<=limit; i++) {
        if (i-1 >= 0) {
            d[i] += d[i-1];
        }
    }
    for (int i=1; i<=limit; i++) {
        if (i-2 >= 0) {
            d[i] += d[i-2];
        }
    }
    for (int i=1; i<=limit; i++) {
        if (i-3 >= 0) {
            d[i] += d[i-3];
        }
    }
    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%lld\n",d[n]);
    }
}
