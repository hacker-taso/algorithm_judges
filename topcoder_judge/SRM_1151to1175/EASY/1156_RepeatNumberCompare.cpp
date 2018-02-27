// start from 11:15PM, Jan 17, 2018
// complete at 11:24PM, Jan 17, 2018
// Good!
#include<iostream>
using namespace std;
class RepeatNumberCompare {
    public:
    string compare(int x1, int k1, int x2, int k2) {
        string x1s = to_string(x1);
        string x2s = to_string(x2);
        string x1Repeated, x2Repeated;
        for (int i=0; i<k1; i++) {
            x1Repeated += x1s;
        }
        for (int i=0; i<k2; i++) {
            x2Repeated += x2s;
        }
        string sol;
        if (x1Repeated.size() < x2Repeated.size()) {
            sol = "Less";
        } else if (x2Repeated.size() < x1Repeated.size()) {
            sol = "Greater";
        } else {
            if (x1Repeated < x2Repeated)
                sol = "Less";
            else if (x2Repeated < x1Repeated)
                sol = "Greater";
            else
                sol = "Equal";
        }
        return sol;
    }
};
