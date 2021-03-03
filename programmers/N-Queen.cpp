#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool check[12][12] = {false, };
int answer = 0;
bool isTrue(int n, int row, int column)
{
    for(int i = 0; i < n; i++)
    {
        if(check[row][i] == true)
            return false;
        if(check[i][column] == true)
            return false;
        for(int j=0; j<n; j++){
            if((row-column == i-j || row+column ==i+j)&&check[i][j])
                return false;
        }
    }
    return true;
}
void dfs(int n, int row, int queen)
{
    if(queen == n) // queen을 n개 놓았으면
    {
        answer++;
        return;
    }
    
    for(int j = 0; j < n; j++)
    {
        if(isTrue(n, row, j))   // (row, j)에 놓을 수 있는지 가로, 세로, 대각선 검사
        {
            check[row][j] = true;
            dfs(n, row + 1, queen + 1); // row+1 행 재귀
            check[row][j] = false;
        }
    }
}
int solution(int n) {
    dfs(n, 0, 0);
    return answer;
}
