#include <vector>
#include <string.h>
using namespace std;

int MOD = 20170805;

int down[501][501]; // (x, y)에서 아래쪽으로 갈 수 있는 경우의 수
int right[501][501]; // (x, y)에서 오른쪽으로 갈 수 있는 경우의 수

int solution(int m, int n, vector<vector<int>> city_map) {
   int answer;
   memset(down, 0, sizeof(down));
   memset(right, 0, sizeof(right));
   down[1][1] = right[1][1] = 1;
   for (int i=1 ; i<=m ; i++) {
       for (int j=1 ; j<=n ; j++) {
           if (city_map[i-1][j-1] == 0) {
               // 아래쪽, 오른쪽으로 직진, 꺾기 가능
               down[i][j] += (down[i-1][j] + right[i][j-1]) % MOD;
               right[i][j] += (down[i-1][j] + right[i][j-1]) % MOD;
          } else if (city_map[i-1][j-1] == 1) {
               // 이동 불가능
               down[i][j] = 0;
               right[i][j] = 0;
          } else {
               // 아래쪽은 계속 아래쪽, 오른쪽은 계속 오른쪽으로 이동 가능
               down[i][j] = down[i-1][j];
               right[i][j] = right[i][j-1];
          }
      }
  }
   return right[m][n] % MOD;
}
