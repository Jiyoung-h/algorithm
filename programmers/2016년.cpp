#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string day[7] = {"THU","FRI","SAT","SUN","MON","TUE","WED"};
    int date[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int tmp = b;
    for(int i=0; i<a-1; i++){
        tmp += date[i];
    }
    return day[tmp%7];
}
