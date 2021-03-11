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
        h = lines[i].substr(11, 2);
        m = lines[i].substr(14, 2);
        s = lines[i].substr(17, 2);
        ms = lines[i].substr(20, 3);
        process = stof(lines[i].substr(24, 5)) * 1000;
        // 소수점 숫자를 float로 변환해서 1000을 곱해 정수로 만든다
        
        ih = stoi(h) * 3600 * 1000;
        im = stoi(m) * 60 * 1000;
        is = stoi(s) * 1000 + stoi(ms);
        // 시, 분, 초를 모두 밀리초로 변환
        
        start_t.push_back(ih + im + is - process + 1);
        // 시작시간 = 처리시간 - 소요시간
        end_t.push_back(ih + im + is);
    }
    
    for(int i = 0; i < lines.size(); i++)
    {
        int end_time = end_t[i] + 1000;
        // 해당 요청이 끝나고부터
        // 초당 최대 처리량을 계산하기 위해 제한시간 1000 밀리초를 더해준다
        int count = 0;
        
        for(int j = i; j < lines.size(); j++)
        {
            // 제한시간 안에 들어가면 카운트를 더해준다
            if(start_t[j] < end_time)
                count++;
        }
        
        if(answer < count)
            answer = count;
    }
    return answer;
}
