#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start_t, end_t;
    
    for(int i = 0; i < lines.size(); i++)
    {
        string h, m, s, ms;
        int ih, im, is, process;
        
        lines[i].pop_back();
        h = lines[i].substr(11, 2); // 시
        m = lines[i].substr(14, 2); // 분
        s = lines[i].substr(17, 2); // 초
        ms = lines[i].substr(20, 3); // 밀리초
        process = stof(lines[i].substr(24, 5)) * 1000;
        
        ih = stoi(h) * 3600 * 1000;
        im = stoi(m) * 60 * 1000;
        is = stoi(s) * 1000 + stoi(ms); // 모두 밀리초로 변환
        
        start_t.push_back(ih + im + is - process + 1);  // 시작시간
        end_t.push_back(ih + im + is);  //끝시간
    }
    
    for(int i = 0; i < lines.size(); i++)
    {
        int end_time = end_t[i] + 1000; // 1초 구간
        int count = 0;
        
        for(int j = i; j < lines.size(); j++)
        {
            if(start_t[j] < end_time)   // 시작 시간이 1초가 끝나는 시간보다 앞이면
                count++;
        }
        
        if(answer < count)
            answer = count;
    }
    return answer;
}
