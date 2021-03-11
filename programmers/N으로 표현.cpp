#include <unordered_set>
#define MAXN 8
using namespace std;

int solution(int N, int number) {
	int answer = -1, std = 0;
	unordered_set<int> us[8];
    // us[ 연산횟수 - 1 ] = { 나올 수 있는 수 }
	for (int i = 0; i < 8; i++) {
		std = 10 * std + 1;
		us[i].insert(std * N);
	}
    // EX) us[0] : N, us[7] : NNNNNNNN
	for (int i = 0; i < 8; i++) {       // 총 연산 횟수 i
		for (int j = 0; j < i; j++) {   // (j번 연산) □ (i-j-1번 연산) = (i번 연산)
			for (auto& op1 : us[j]) {
				for (auto& op2 : us[i - j - 1]) {
					us[i].insert(op1 + op2);
					us[i].insert(op1 - op2);
					us[i].insert(op1 * op2);
					if (op2 != 0) {
						us[i].insert(op1 / op2);
					}
				}
			}
		}
		if (us[i].count(number) > 0) { // number가 존재하면 연산 횟수를 반환
			answer = i + 1;
			break;
		}
	}
	return answer;
}
