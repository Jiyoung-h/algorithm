using namespace std;

int solution(int n, int a, int b)
{
    int temp = 1;
    int round = 0;
    for(int i=1; i<=20; i++){
        temp *= 2;
        round++;
        if(temp == n) break;
    }
    int front = 1;
    int back = n;
    while(1){
        if(a>((back+front)/2) && b>((back+front)/2)){
            front = back/2 + 1;
            round--;
        }
        else if(a<=((back+front)/2) && b<=((back+front)/2)){
            back = back/2;
            round--;
        }
        else{
            return round;
        }
    }
}
