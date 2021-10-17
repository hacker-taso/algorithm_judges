#include <string>
#include <vector>

using namespace std;

bool isBigger(string s) {
    if (s.size() == 3)
        return s.compare("110") > 0;
    if (s.size() == 1)
        return s == "1";
    return s == "11";
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (string se: s) {
        int pos = 0;
        for (int i=0; i+3<=se.size(); i++) {
            if (se.substr(i, 3) == "110") {
            }
        }
        answer.push_back(se);
    }
    return answer;
}