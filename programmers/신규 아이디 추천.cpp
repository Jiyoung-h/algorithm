#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string id = new_id;
    string tmp{};
    for(int i=0; i<id.length(); i++){
        // 1단계 : 대문자->소문자
        if(isupper(id[i])){ 
            tmp += tolower(id[i]);
            continue;
        }
        // 2단계
        if(islower(id[i]) || id[i] == '-' ||id[i] == '_' ||id[i]=='.' || isdigit(id[i])){
            tmp += id[i];
            continue;
        }
    }
    id = "";
    for(int i=0; i<tmp.length(); i++){
        // 3단계 (마침표가 연속하지 않으면 삽입)
        if(tmp[i]=='.'){
            if(!(i < tmp.length()-1 && tmp[i+1]=='.')){
                id += '.';
                continue;   
            }
        }
        else id+=tmp[i];
    }
    // 4단계
    if(id[0]=='.') id = id.substr(1);
    if(id[id.length()-1]=='.') id = id.substr(0, id.length()-1);
    // 5단계
    if(id=="") id="a";
    // 6단계
    if(id.length()>=16) id = id.substr(0, 15);
    // 7단계
    while(id.length()<=2){
        id+=id[id.length()-1];
    }
    // 4단계 반복
    if(id[0]=='.') id = id.substr(1);
    if(id[id.length()-1]=='.') id = id.substr(0, id.length()-1);
    return id;
}
