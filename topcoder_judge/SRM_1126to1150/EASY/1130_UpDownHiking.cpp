// Start at 00:09 AM, Feb 09, 2018
// End at 00:15 AM, Feb 09, 2018
#include<iostream>
using namespace std;

struct UpDownHiking {

public:
    int maxHeight(int N, int A, int B) {
        int sol = 0;
        for (int up=0; up<=N; up++) {
            int down = N-up;
            sol = max(min(up*A, down*B), sol);
        }
        return sol;
    }
};
