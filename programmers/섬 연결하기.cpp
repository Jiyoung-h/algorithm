#include <string>
#include <vector>
using namespace std;
bool check(vector<bool> visit);

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	vector<bool> visit(n);
	vector<vector<int>> graphs(n,vector<int>(n));
    
	int minCost = costs[0][2];
	int minNode1=costs[0][0];
   	int minNode2=costs[0][1];
    
	for (int i = 0; i < costs.size(); i++) {
		graphs[costs[i][0]][costs[i][1]] = costs[i][2];
		graphs[costs[i][1]][costs[i][0]] = costs[i][2];
		if (costs[i][2] < minCost) {
			minCost = costs[i][2];
			minNode1 = costs[i][0];
			minNode2 = costs[i][1];
		}
	}
    
	answer += minCost;
	visit[minNode1] = true;
	visit[minNode2] = true;
	minCost = -1;
	
	while (check(visit)) {
		for (int i = 0; i < visit.size(); i++) {
			if (visit[i] != true)
				continue;
			for (int j = 0; j < visit.size(); j++) {
				if ((minCost == -1 || minCost > graphsi][j]) && visit[j] != true && graphs[i][j] != 0) {
					minCost = graphs[i][j];
					minNode1 = i;
					minNode2 = j;
				}
			}
		}
		visit[minNode1] = true;
		visit[minNode2] = true;
		answer += min;
		min = -1;
	}
	return answer;
}

bool check(vector<bool> visit) {   // 모두 방문
	for (int i = 0; i < visit.size(); i++) {
		if (visit[i] == false) {
			return true;
		}
	}
	return false;
}
