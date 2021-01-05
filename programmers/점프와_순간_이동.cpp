#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    while(1){
        if(n == 1){
            ans++;
            break;
        }
        if(n%2 ==0){
            n = n/2;
        }
        else{
            n = (n - 1)/2;
            ans++;
        }
    }
    return ans;
}
