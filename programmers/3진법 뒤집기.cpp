#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    string three{};
    while(n/3 > 0){
        three += to_string(n%3);
        n = n/3;
    } // 3진법 변환
    three += to_string(n);
    int ten = 0;
    int tmp = 1;
    for(int i=three.size()-1; i>=0; i--){
        ten += (three[i]-'0')*tmp;
        tmp*=3;
    } // 10진법 
    return ten;
}
