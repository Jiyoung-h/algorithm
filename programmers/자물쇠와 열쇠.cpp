#include <string>
#include <vector>
using namespace std;

void _rotate(vector<vector<int>>& key) {
    int m = key.size();
    vector<vector<int>> temp(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = key[m - j - 1][i];
        }
    }
    key = temp;
    return;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size();
    int n = lock.size();
    int dolki;
    int hom = 0;
    vector<pair<int, int>> vp;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (key[i][j] == 1) {
                vp.emplace_back(i, j);
            }
        }
    }
    dolki = vp.size();          // 열쇠 돌기의 개수
    for (auto& v : lock)
        for (auto& c : v)
            if (c == 0) ++hom;   // 자물쇠 홈의 개수
    if (hom > dolki) return false;
    if (hom == 0) return true;
    if (dolki == 0) return false;

    for (int turn = 0; turn < 4; ++turn) {
        if (turn != 0) _rotate(lock);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (lock[i][j] == 0) {
                    for (int first = 0; first < dolki; ++first) {
                        int match = 1;
                        for (int k = 0; k < dolki; ++k) {
                            if (k == first) continue;

                            auto y = (vp[k].first - vp[first].first) + i;
                            auto x = (vp[k].second - vp[first].second) + j;
                            if (y >= 0 && y < n && x >= 0 && x < n) {
                                if (lock[y][x] == 0)
                                    ++match;
                                else {  //돌기와 돌기가 만날 때
                                    match = -99999;
                                    break;
                                }
                            }
                        }
                        if (match == hom) return true;
                    }
                }
            }
        }
    }
    return false;
}
