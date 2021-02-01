#include <unordered_set>
using namespace std;

int solution(int N, int number) {
	int answer = -1, std = 0;
	// 원소의 개수가 적고 빠른 성능을 원할 땐 unordered_set
	unordered_set<int> s[8];	// us[횟수] 
	for (int i = 0; i < 8; i++) {
		std = 10 * std + 1;	// 1, 11, 111, ...
		s[i].insert(std * N);	// 5, 55, 555, ...
	}
	for (int i = 1; i < 8; i++) { // i : 연산 횟수
		for (int j = 0; j < i; j++) {
			for (auto& op1 : s[j]) {			// op1 : j번 연산한 값
				for (auto& op2 : s[i - j - 1]) {	// op2 : (i-j-1)번 연산한 값
					s[i].insert(op1 + op2);	// op1 과 op2 를 연산해야 연산횟수가 i 번
 					s[i].insert(op1 - op2);
					s[i].insert(op1 * op2);
					if (op2 != 0) {
						s[i].insert(op1 / op2);
					}
				}
			}
		}
		if (s[i].count(number) > 0) {	// number가 존재하면 멈춤
			answer = i + 1;
			break;
		}
	}
	return answer;
}
