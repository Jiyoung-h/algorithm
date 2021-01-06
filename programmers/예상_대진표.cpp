using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while(a!=b){
       if(a%2!=0) a=a+1;
       if(b%2!=0) b=b+1;
       a=a/2;
       b=b/2;
       answer++;
    }
    return answer;
}
