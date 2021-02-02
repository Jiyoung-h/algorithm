#include <string>
#include <vector>
using namespace std;
 
int f[1000000];
 
int find(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else if(f[n] != 0)
    {
        return f[n];
    }
    else
    {
        return f[n] = (find(n-1) + find(n-2)) % 1234567;
    }
}
 
int solution(int n) 
{
    int answer = find(n);
    return answer;
}
