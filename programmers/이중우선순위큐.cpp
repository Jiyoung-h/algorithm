#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
vector<int> solution(vector<string> operations) {
	vector<int> answer;
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;
	map<int, bool> check;

	for (int i = 0; i < operations.size(); i++) {
		string operation;
		int number;
		stringstream ss(operations[i]);
		ss >> operation >> number;
		if (operation == "I") {
			pq1.push(number);
			pq2.push(number);
		}
		else if (operation == "D") {
			if (number == 1) {
				while (!pq1.empty() && check[pq1.top()]) {
					pq1.pop();
				}
				if (pq1.empty()) continue;
				check[pq1.top()] = true;
				pq1.pop();
			}
			else {
				if (pq2.empty()) continue;
				while (!pq2.empty() && check[pq2.top()]) {
					pq2.pop();
				}
				if (pq1.empty()) continue;
				check[pq2.top()] = true;
				pq2.pop();
			}
		}
	}
	if (pq1.size() == 0 || pq2.size() == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		while (!pq1.empty() && check[pq1.top()]) {
			pq1.pop();
		}
		answer.push_back(pq1.top());
		while (!pq2.empty() && check[pq2.top()]) {
			pq2.pop();
		}
		answer.push_back(pq2.top());
	}
	return answer;
}
