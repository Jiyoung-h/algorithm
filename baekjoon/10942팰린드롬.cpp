#include <iostream>
using namespace std;
int pld[2001];
int d[2001][2001];
int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &pld[i]);
	for (int i = 1; i <= N; i++) d[i][i] = 1;
	for (int i = 1; i < N; i++) if (pld[i] == pld[i + 1]) d[i][i + 1] = 1;
	for (int i = 2; i < N; i++)
		for (int j = 1; j <= N-i ; j++)
			if (pld[j] == pld[i + j] && d[j + 1][i + j - 1]) d[j][i + j] = 1;
	scanf("%d", &M);
	while (M--){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", d[s][e]);
	}
	return 0;
}
