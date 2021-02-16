#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;
struct compare {
    bool operator()(pair<int, int>a, pair<int, int>b){
        if(a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    }
};
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> temp;     
    vector<priority_queue<pair<int, int>, vector<pair<int, int>>, compare>> song;
    vector<int> sum;
    int gi = 1;
    for (int i = 0; i < genres.size(); i++) {
        if (!temp[genres[i]]) {
            temp[genres[i]] = gi++;
            song.push_back({});
            song[gi - 2].push(make_pair(plays[i], i));
            sum.push_back(plays[i]);
        }
        else {
            int si = temp[genres[i]] - 1;
            song[si].push(make_pair(plays[i], i));
            sum[si] += plays[i];
        }
    }
    priority_queue<pair<int, int>> sum2;
    for (int i = 0; i < sum.size(); i++) {
        sum2.push(make_pair(sum[i], i));
    }
    while(!sum2.empty()) {
        pair<int, int> p = sum2.top();
        sum2.pop();
        pair<int, int> q = song[p.second].top();
        answer.push_back(q.second);
        song[p.second].pop();
        if(!song[p.second].empty()){
            q = song[p.second].top();
            answer.push_back(q.second);
        }
    }
    return answer;
}
