#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<string> arrive;
    int hour = 9;
    int min = 0;
    arrive.push_back("0" + to_string(hour) + ":0" + to_string(min));
    for(int i=1; i<n; i++){ // 버스 도착 시간을 string 으로 넣기
        min += t;
        if(min > 59){
            hour++;
            min -=  60;
        }
        string str;
        if(hour < 10)
            str = "0" + to_string(hour) + ":";
        else str = to_string(hour) + ":";        
        if(min < 10)
            arrive.push_back(str+"0"+to_string(min));
        else arrive.push_back(str+to_string(min));
    }
    
    sort(timetable.begin(), timetable.end());
    vector<int> count(arrive.size());
    int ti{}, ai{};
    string last;
    while(1){
        if(ti == timetable.size()) break;
        if(ai == arrive.size()) break;
        if(arrive[ai] >= timetable[ti]){
            if(count[ai] == m){ // 버스가 꽉 찼으면
                ai++; // 다음 버스
            }
            else{   // 탈 수 있으면
                last = timetable[ti];
                count[ai]++;
                ti++; // 태우고 다음 사람
            }
        }
        else{       // 버스를 놓쳤으면
            ai++;   // 다음 버스
        }
    }
    if(count[arrive.size()-1] == m){ // 마지막 버스가 꽉찼으면
        hour = stoi(last.substr(0, 2));
        min = stoi(last.substr(3, 2)) - 1;
        if(min < 0){
            hour--;
            min += 60;
        }
        if(hour < 10)
            answer = "0" + to_string(hour) + ":";
        else answer = to_string(hour) + ":";        
        if(min < 10)
            answer = answer + "0" + to_string(min);
        else answer = answer + to_string(min);
    }
    else{ // 꽉 차지 않았으면 버스 시간에 맞춰서
        answer = arrive[arrive.size()-1];
    }
    return answer;
}
