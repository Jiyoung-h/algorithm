#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;

	long long timesNum = times.size();
	sort(times.begin(), times.end());
    
	long long start = (n * times.front()) / timesNum;   // 최소 시간
	long long end = n * times.back();   // 최대 시간
	long long mid = 0;                  // 이진 탐색
	while (start <= end) {
		long long num = 0;
		mid = (start + end) / 2;    // 평균값
		for (int i = 0; i < timesNum; i++) {
			num += mid / times[i];  // 현재시간만큼 각 심사관이 처리할 수 있는 모든 인원수를 더한다
		}
		if (num < n) start = mid + 1;   // 인원수가 n보다 작으면 start 범위를 옮긴다
		else {                          // 인원수가 n보다 크거나 같으면 end의 범위를 옮긴다
			end = mid - 1;
			answer = mid;               // n을 만들 수 있는 현재시간 중 최소값
		}
	}

	return answer;
}
