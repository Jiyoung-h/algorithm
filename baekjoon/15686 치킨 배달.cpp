#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n, m, answer;
vector<pair<int, int>> store;
vector<pair<int, int>> house;
// 폐업시키지 않을 치킨집 count개, 치킨집 index까지, 현 치킨 거리 distance
void go(int count, int index, vector<int> distance) {
    if (count == m) {
        int sum = 0;
        for (int i = 0; i < distance.size(); i++)
            sum += distance[i];
        if (answer > sum) answer = sum;
        return;
    }
    for (int i = index; i < store.size(); i++) {
        int r = store[i].first;
        int c = store[i].second;
        int dis = 0;
        vector<int> tmp = distance;
        for (int j = 0; j < house.size(); j++) {
            int r1 = house[j].first;
            int c1 = house[j].second;
            tmp[j] = min((abs(r - r1) + abs(c - c1)), distance[j]);
        }
        go(count + 1, i + 1, tmp);
    }
}
int main()
{
    cin >> n >> m;
    int a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if (a == 2) {
                store.push_back({ i, j });
            }
            else if (a == 1) {
                house.push_back({ i, j });
            }
        }
    }
    vector<int> distance(house.size(), 10000);
    answer = 100000;
    go(0, 0, distance);
    cout << answer;
}
