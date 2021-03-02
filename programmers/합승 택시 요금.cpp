#include <string>
#include <vector>
using namespace std;

int adj[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    // 플로이드를 위해 충분히 큰 값으로 초기화
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			adj[i][j]=10000000;

	for(int i=1;i<=n;i++) adj[i][i]=0;

	for(auto v:fares){
		adj[v[0]][v[1]]=v[2];
		adj[v[1]][v[0]]=v[2];
	}

    // 플로이드 와샬
    // J -> K 의 최솟값은 J->K, J->I->K 중에 있다. (3중 for문)
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]);

    // 충분히 큰 값으로 초기화
	answer = 1e9;

    // 브루트 포스
    // S->I : 합승, I->A, I->B : 각자 이동
	for(int i=1;i<=n;i++)
		answer=min(answer,adj[s][i]+adj[i][a]+adj[i][b]);
	
  return answer;
}
