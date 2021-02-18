#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    int w=weak.size();
    int d=dist.size();
    sort(dist.begin(), dist.end());
    for(int i=0; i<w-1; i++){
        weak.push_back(n+weak[i]);
    } // 1, 5, 6, 10, 13, 17, 18
    for(int i=0; i<d; i++){ // 사람의 수
        for(int j=0; j<w; j++){ // 외벽
            vector<int> tmp;
            for(int k=d-1-i; k<d; k++){
                tmp.push_back(dist[k]);
            } // i(사람의 수)만큼 투입
            do{
             int idx = 0; 
                for(int k = 0; k <= i; k++){ // 친구 투입 
                    int start = weak[j + idx] + tmp[k]; 
                    while(weak[j + idx + 1] <= start){ 
                        idx++; 
                    } 
                    idx++; 
                } 
                if(idx >= w) // 다 고쳤으면
                    return i + 1; 
            }while(next_permutation(tmp.begin(), tmp.end()));
        }
    }
    return answer;
}
