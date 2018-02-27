// Start at 01:13AM Feb 25, 2017
// End at 01:28AM Feb 25, 2017
// Retrospection: I didn't use dontknow variable. I just return -1 when answer[i-1] == "Even"
#include<iostream>
#include<vector>
using namespace std;

class Robofactory {
private:
    public:
    int reveal(vector <int> query, vector <string> answer) {
        bool dontknow = false;
        for (int i=1; i<query.size(); i++) {
            if ((query[i]%2 == 1 && answer[i] == "Even") || (query[i]%2==0 && answer[i] == "Odd")) {
                return i;
            }
            if (answer[i-1] == "Even")
                dontknow = true;
        }
        if (dontknow)
            return -1;
        return 0;
    }
};
