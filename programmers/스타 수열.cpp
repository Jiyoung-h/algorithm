#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int Max(int A, int B) { return A > B ? A : B; }
bool Cmp(int A, int B) { return A > B ? true : false; }
 
int solution(vector<int> a)
{
    int answer = -1;
    vector<int> Cnt(a.size() + 1, 0);
    // 숫자의 갯수를 카운트
    for (int i = 0; i < a.size(); i++) Cnt[a[i]]++;
 
    for (int i = 0; i < Cnt.size(); i++)
    {   // 존재하지 않거나 최댓값이 아니면 continue
        if (Cnt[i] == 0) continue;
        if (Cnt[i] <= answer) continue;
        int Result = 0; 
        // 교집합이 되는 수 i
        for (int j = 0; j < a.size() - 1; j++)
        {   // 둘 다 i가 아니거나, 둘이 같은 수이면 continue
            if (a[j] != i && a[j + 1] != i) continue;
            if (a[j] == a[j + 1]) continue;            
            Result++;
            j++;
        }
        // 최댓값
        answer = Max(answer, Result);
    }
    // 교집합이 되는 수도 함께 세야하므로 x2
    return answer * 2;
}
