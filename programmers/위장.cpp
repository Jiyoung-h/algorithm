#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    for(vector<string> c : clothes){
        m[c[1]]++; // m['옷의 종류']++;
    }
    int answer = 1;
    map<string, int>::iterator it;
    for(it = m.begin(); it != m.end(); it++){
        answer *= it->second + 1; // (개수 + 1) => 1은 선택 안 하는 경우
    }
    return answer-1; // 모두 선택 안 하는 경우를 빼줌
}
