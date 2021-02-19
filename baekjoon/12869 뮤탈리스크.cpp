#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
 
int ans=0;
int attack[3]={9,3,1};
int visited[61][61][61]={0};
 
struct str{
    int scv1;
    int scv2;
    int scv3;
    int cnt;
    str(int scv1,int scv2,int scv3,int cnt):scv1(scv1),scv2(scv2),scv3(scv3),cnt(cnt){};
};
 
int main(){
    
    int N;
    cin>>N;
    
    int scv[3]={0}; //scv의 체력
    for(int i=0;i<N;i++)
        cin>>scv[i];
    
    sort(scv,scv+3); //다음 순열을 위해 정렬
    
    queue<str> q;
    q.push(str(scv[0],scv[1],scv[2],0));
    visited[scv[0]][scv[1]][scv[2]]++;
    
    while(!q.empty()){
        
        scv[0]=q.front().scv1;
        scv[1]=q.front().scv2;
        scv[2]=q.front().scv3;
        int cnt=q.front().cnt;
        q.pop();
        
        if(scv[2]==0){ //오름차순으로 정렬된 것 중에 가장 큰게 0이면
            ans=cnt;
            break;
        }
        
        int temp_scv[3]={0};
        do{
            
            for(int i=0;i<3;i++)
                temp_scv[i]=(scv[i]-attack[i]>0)? scv[i]-attack[i]:0;
            
            sort(temp_scv,temp_scv+3);
            
            if(!visited[temp_scv[0]][temp_scv[1]][temp_scv[2]]){
                visited[temp_scv[0]][temp_scv[1]][temp_scv[2]]++;
                q.push(str(temp_scv[0],temp_scv[1],temp_scv[2],cnt+1));
            }
            
        }while(next_permutation(scv,scv+3)); //다음 순열
        
    }
    
    cout<<ans<<endl;
    return 0;
}
