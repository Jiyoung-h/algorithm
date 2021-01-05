#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int height;
    int width;
    
    for(height=1; height<=yellow; height++){
        if(yellow%height == 0){
            width = yellow/height;
            if((2*(width+height)+4) == brown){
                answer.push_back(width+2);
                answer.push_back(height+2);
                break;
            }
        }
    }
    return answer;
}
