#include <vector> 
using namespace std;
 
struct build {
    int column;
    int row;
};
 
build arr[101][101];
 
bool columnCheck(int x, int y, int n) {
    if (y == 0) return true;
    if (arr[x][y - 1].column) return true;
    if (x > 0 && arr[x - 1][y].row) return true;
    if (x < n && arr[x][y].row) return true;
    return false;
}
 
bool rowCheck(int x, int y, int n) {
    if (arr[x][y - 1].column) return true;
    if (x < n && arr[x + 1][y - 1].column) return true;
    if (x > 0 && x < n && arr[x + 1][y].row && arr[x - 1][y].row) return true;
    return false;
}
 
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer; 
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
 
        if (b == 1 && a == 0) { //기둥 설치
            if (columnCheck(x, y, n)) arr[x][y].column = 1;
        }
        else if (b == 1 && a == 1) { // 보 설치
            if (rowCheck(x, y, n)) arr[x][y].row = 1;
        }
        else if (b == 0 && a == 0) { // 기둥 삭제
            bool check = true;
            arr[x][y].column = 0;
 
            if (y < n && arr[x][y + 1].column && !columnCheck(x, y + 1, n)) check = false;
            else if (y < n && arr[x][y + 1].row && !rowCheck(x, y + 1, n)) check = false;
            else if (x > 0 && arr[x - 1][y + 1].row && y < n && !rowCheck(x - 1, y + 1, n)) check = false; 
            if (!check) arr[x][y].column = 1; 
        }
        else if (b == 0 && a == 1) { // 보 삭제
            bool check = true;
            arr[x][y].row = 0;
 
            if (arr[x][y].column && !columnCheck(x, y, n)) check = false;
            else if (x < n && arr[x + 1][y].column && !columnCheck(x + 1, y, n)) check = false;
            else if (x > 0 && arr[x - 1][y].row && !rowCheck(x - 1, y, n)) check = false;
            else if (x < n && arr[x + 1][y].row && !rowCheck(x + 1, y, n)) check = false; 
            if (!check) arr[x][y].row = 1;
        } 
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (arr[i][j].column) {
                answer.push_back({ i, j, 0 });
            }
            if (arr[i][j].row) {
                answer.push_back({ i, j, 1 });
            }
        }
    } 
    return answer;
}
