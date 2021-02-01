#include <unordered_set>
#define MAXN 8
using namespace std;

int solution(int N, int number) {
	int answer = -1, std = 0;
	// 원소의 개수가 적고 빠른 성능을 원할 땐 unordered_set
	unordered_set<int> us[MAXN];	// us[횟수] 
	for (int i = 0; i < MAXN; i++) {
		std = 10 * std + 1;	// 1, 11, 111, ...
		us[i].insert(std * N);	// 5, 55, 555, ...
	}
	for (int i = 1; i < MAXN; i++) { // i : 연산 횟수
		for (int j = 0; j < i; j++) {
			for (auto& op1 : us[j]) {			// op1 : j번 연산한 값
				for (auto& op2 : us[i - j - 1]) {	// op2 : (i-j-1)번 연산한 값
					us[i].insert(op1 + op2);	// op1 과 op2 를 연산해야 연산횟수가 i 번
 					us[i].insert(op1 - op2);
					us[i].insert(op1 * op2);
					if (op2 != 0) {
						us[i].insert(op1 / op2);
					}
				}
			}
		}
		if (us[i].count(number) > 0) {	// number가 존재하면 멈춤
			answer = i + 1;
			break;
		}
	}
	return answer;
}
