#include <vector>
#include <iostream>
using namespace std;
int r, c, m;
vector<vector<int>> shark;
int answer = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0, 1,-1 }; 
void catches (int n) {	// n열에 있는 상어 잡기
	int index = -1;
	for (int i = 0; i < shark.size(); i++) {
		if (!shark[i].empty()) {
			if (shark[i][1] == n) {
				if (index == -1)
					index = i;
				else if (shark[index][0] > shark[i][0])
					index = i;	// n열에 있는 상어 중 행이 작은 상어 index
			}
		}
	}
	if (index != -1) {		// 상어를 잡았으면 삭제
		answer += shark[index][4];
		shark[index].clear();
	}
}
void move() {
	vector<vector<int>> location(r + 1, vector <int>(c + 1, -1)); // location[r][c] = -1 초기화
	for (int i = 0; i < shark.size(); i++) {
		if (!shark[i].empty()) {
			for (int j = 0; j < shark[i][2]; j++) {
				if (shark[i][0] == 1 && shark[i][3] == 1) shark[i][3] = 2;
				if (shark[i][0] == r && shark[i][3] == 2) shark[i][3] = 1;
				if (shark[i][1] == 1 && shark[i][3] == 4) shark[i][3] = 3;
				if (shark[i][1] == c && shark[i][3] == 3) shark[i][3] = 4;
				shark[i][0] = shark[i][0] + dx[shark[i][3] - 1];
				shark[i][1] = shark[i][1] + dy[shark[i][3] - 1];
			}
			// 상어의 위치 location[x][y] = 상어 index 저장
			if (location[shark[i][0]][shark[i][1]] == -1) location[shark[i][0]][shark[i][1]] = i;
			else {	// 이미 존재하면 상어의 무게 비교하여 작은 상어를 삭제
				if (shark[location[shark[i][0]][shark[i][1]]][4] > shark[i][4]) {
					shark[i].clear();
				}
				else {
					shark[location[shark[i][0]][shark[i][1]]].clear();
				}
			}
		}
	}
} 
int main() {
	cin >> r >> c >> m;
	int a;
	vector<int> s;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a;
			s.push_back(a);
		}
		shark.push_back(s);
		s.clear();
	}	
	// shark[i][0]:행, shark[i][1]:열, shark[i][2]:속력, shark[i][3]:방향, shark[i][4]:크기  
	for (int i = 1; i <= c; i++) {
		catches(i);
		move();
	}
	cout << answer;
}
