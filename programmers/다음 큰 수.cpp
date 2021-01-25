using namespace std;
int count(int n)
{
    int cnt = 0;
    for (int i = 0; i < 21; i++)
    {
        if (n & 1 << i)  //Shift 연산(1을 i번만큼 밀면서 1인지 확인)
            cnt++;
    }
    return cnt;
}

int solution(int n) {
    int num = count(n);
    while (count(++n) != num);
    return n;
}
