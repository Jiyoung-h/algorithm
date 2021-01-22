
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
 
vector<vector<string>> relations;
vector<int> ans;
int row;
int col;
 
int check_min(int bit)
{
    for(int i = 0; i < ans.size(); i++)
    {
        if((ans[i] & bit) == ans[i])
        {
            return 0;
        }
    }
    return 1;
}
 
int solution(vector<vector<string>> relation) 
{
    relations = relation;
    row = relation.size();
    col = relation[0].size();
    
    for(int i = 1; i < (1 << col); i++)
    {
        map<string, int> check;
        for(int j = 0; j < row; j++)
        {
            string now;
            
            for(int k = 0; k < col; k++)
            {
                if(i & (1 << k))
                {
                    now += relation[j][k];        
                }
            }
            check[now] = 1;
        }
        if(check.size() == row && check_min(i) == 1)
        {
            ans.push_back(i);
        }
   }
    return ans.size();
}
 
