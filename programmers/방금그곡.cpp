#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    vector<vector<string>> music(musicinfos.size());
    string tmp{};
    for (int j = 0; j < m.length(); j++) {
        if (m[j + 1] == '#') {
            if (m[j] == 'C') tmp = tmp + "Q";
            else if (m[j] == 'D') tmp = tmp + "W";
            else if (m[j] == 'F') tmp = tmp + "E";
            else if (m[j] == 'G') tmp = tmp + "R";
            else if (m[j] == 'A') tmp = tmp + "Y";
            j++;
        }
        else tmp = tmp + m.substr(j, 1);
    }
    m = tmp;
    for (int i = 0; i < musicinfos.size(); i++) {
        int nstart = 0;
        int sharp = 0;
        string tmp{};
        for (int j = 0; j < musicinfos[i].size(); j++) {
            if (musicinfos[i][j + 1] == '#') {                
                if(musicinfos[i][j] == 'C') tmp = tmp +"Q";
                else if (musicinfos[i][j] == 'D') tmp = tmp + "W";
                else if (musicinfos[i][j] == 'F') tmp = tmp + "E";
                else if (musicinfos[i][j] == 'G') tmp = tmp + "R";
                else if (musicinfos[i][j] == 'A') tmp = tmp + "Y";
                j++;
            }
            else if (musicinfos[i][j] == ',') {
                music[i].push_back(tmp);
                tmp = "";
            }
            else {
                tmp = tmp + musicinfos[i].substr(j, 1);
            }            
        }
        music[i].push_back(tmp);

        int hour1 = stoi(music[i][0].substr(0, 2));
        int min1 = stoi(music[i][0].substr(3, 2));
        int hour2 = stoi(music[i][1].substr(0, 2));
        int min2 = stoi(music[i][1].substr(3, 2));
        int term = (60 * hour2 + min2) - (60 * hour1 + min1);

        while (music[i][3].size() != term) {
            if (music[i][3].size() > term) {
                music[i][3] = music[i][3].substr(0, term);
            }
            else if (music[i][3].size() < term) {
                music[i][3] += music[i][3];
            }
        }
        int index = music[i][3].find(m);
        if (index != -1) {
            return music[i][2];
        } 
    }
    return "(None)";
}
