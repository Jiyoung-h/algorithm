#include<iostream>
#include<vector>
using namespace std;

struct horse
{
	int x, y, d;
	bool is_bottom;
} h[10];

int N, K;
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };
int turn[] = { 0, 2, 1, 4, 3 };
int color[13][13];
vector<int> info[13][13];

int move(int i)
{
	int nx = h[i].x + dx[h[i].d];
	int ny = h[i].y + dy[h[i].d];

	// 경계를 넘거나 파란 칸
	if (nx <= 0 || ny <= 0 || nx > N || ny > N || color[nx][ny] == 2)
	{
		// 방향 전환
		h[i].d = turn[h[i].d];

		nx = h[i].x + dx[h[i].d];
		ny = h[i].y + dy[h[i].d];

		// 반대 방향도 파랑
		if (nx <= 0 || ny <= 0 || nx > N || ny > N || color[nx][ny] == 2)
			return 0;
	}

	vector<int>& cur = info[h[i].x][h[i].y];
	vector<int>& next = info[nx][ny];
	// 하얀 칸
	if (color[nx][ny] == 0)
	{	// ABC -> DE 이동하면 DE ABC 가 되므로 A는 바닥이 아니다
		if (!next.empty()) h[cur.front()].is_bottom = false;
		// 끝에 삽입
		next.insert(next.end(), cur.begin(), cur.end());
	}
	// 빨간 칸
	else if (color[nx][ny] == 1)
	{
		// ABC -> DE 이동하면 DE CBA 가 된다
		next.insert(next.end(), cur.rbegin(), cur.rend());
		h[next.back()].is_bottom = false;
		h[next.front()].is_bottom = true;
	}
	h[next.front()].x = h[next.back()].x = nx;
	h[next.front()].y = h[next.back()].y = ny;
	cur.clear();
	return next.size();
}

int simulation()
{
	int round, stack_cnt;
	for (round = 1; round <= 1000; ++round)
	{
		for (int i = 0; i < K; ++i)
		{
			if (h[i].is_bottom)
			{
				stack_cnt = move(i);
				if (stack_cnt >= 4)
					return round;
			}
		}
	}
	return -1;
}

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> color[i][j];

	for (int i = 0; i < K; ++i)
	{
		cin >> h[i].x >> h[i].y >> h[i].d;
		h[i].is_bottom = true;
		info[h[i].x][h[i].y].push_back(i);
	}
	cout << simulation();
	return 0;
}
