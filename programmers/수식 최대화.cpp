#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> op;
    string tmp = "";
    for(int i=0; i<expression.size(); i++){
        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
            num.push_back(stoll(tmp));
            op.push_back(expression[i]);
            tmp = "";
        } else tmp.push_back(expression[i]);
    }
    num.push_back(stoll(tmp));
    string perm="+-*";
    sort(perm.begin(), perm.end());
    
    do{
        vector<long long> copyNum = num;
        vector<char> copyOp = op;
        for(int i=0; i<perm.size(); i++){
            for(int j=0; j<copyOp.size(); j++){
                if(perm[i]==copyOp[j]){
                    if(copyOp[j]=='+')
                        copyNum[j]=copyNum[j]+copyNum[j+1];
                    else if(copyOp[j]=='-')
                        copyNum[j]=copyNum[j]-copyNum[j+1];
                    else
                        copyNum[j]=copyNum[j]*copyNum[j+1];
                    copyNum.erase(copyNum.begin()+j+1);
                    copyOp.erase(copyOp.begin()+j);
                    j--;
                }
            }
        }
        answer=max(answer, abs(copyNum[0]));
    } while(next_permutation(perm.begin(), perm.end()));
    return answer;
}
