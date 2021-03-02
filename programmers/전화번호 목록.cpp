#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    for(int i=0; i<phone_book.size(); i++){
        for(int j=i+1; j<phone_book.size(); j++){
            if(phone_book[i].size() < phone_book[j].size()){
                string str = phone_book[j].substr(0, phone_book[i].size());
                if(phone_book[i] == str)
                    return false;
            }
            if(phone_book[i].size() > phone_book[j].size()){
                string str = phone_book[i].substr(0, phone_book[j].size());
                if(phone_book[j] == str)
                    return false;
            }
        }
    }
    return answer;
}
