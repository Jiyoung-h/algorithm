#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> gem_count; // 구간에 포함된 보석의 종류
    set<string> gem_kind(gems.begin(), gems.end());
    int kind = gem_kind.size(); // 보석의 종류
    int distance{}, start{};
    int end = gems.size() - 1;

    for (int i = 0; i < gems.size(); i++) {
        gem_count[gems[i]]++;
        if (gem_count.size() >= kind) { // 모든 보석을 포함하는 지점을 찾음
            end = i;
            break;
        }
    }

    answer = { start + 1, end + 1 };
    distance = end - start;

    while (end < gems.size()) { // 끝까지 탐색할 때까지
        string gem = gems[start];
        gem_count[gem]--;   // start에 해당하는 보석 감소
        start++;            // start 포인터 이동

        if (gem_count[gem] == 0) {  // start에 있던 보석이 0개이면
            end++;                  // end 포인터 이동
            while (end < gems.size()) {
                gem_count[gems[end]]++; // end에 해당하는 보석 증가
                if (gems[end] == gem)   // start에 있던 보석이 나올 때까지
                    break;
                end++;                  // end 포인터 이동
            }
        }
        if (end - start < distance) {   // 최소구간이 나오면
            answer = { start + 1, end + 1 };
            distance = end - start;
        }
    }
    return answer;
}
