using namespace std;

int Gcm(int x, int y)
{
    int i;
    for (i = (x < y)? x : y; x > 1; i--) {
        if (x % i == 0 && y % i == 0) break;
    }
    return i;
}

long long solution(int w,int h) {
    long long answer = 1;
    int gcm = Gcm(w, h);
    int gw = w / gcm;
    int gh = h / gcm;
    int i = gh / gw;
    int diff = gh - gw*i - 1;
    answer = (gw*(i+1) + diff)*gcm;
    long long times = long(h) * long(w);
    answer = times - answer;
    return answer;
}
