#include <string>
using namespace std;
bool check(string p) {
    int t = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') t++;
        else {
            t--;
            if (t < 0) return false;
        }
    }
    return true;
}
 
string recursion(string p) {    
    if (p == "") return p;
    string v = "";
    string u = "";
    int L = 0;
    int R = 0;
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == '(') L++;
        else R++;
        if (L == R) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    if (check(u)) return u + recursion(v);
    else{
        string temp = "(";
        temp += recursion(v) + ")";
        u = u.substr(1, u.length()-2);
        for (int i = 0; i < u.length(); i++) {
            if (u[i] == '(') temp += ')';
            else temp += '(';
        }
        return temp;
    }
}
 
string solution(string p) {
    if (check(p)) return p;
    return recursion(p);
}
