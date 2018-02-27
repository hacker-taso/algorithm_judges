// start from 09:25PM, Jan 21, 2018
// complete at 09:32PM, Jan 21, 2018
// It was too easy, too.
#include<iostream>
using namespace std;
class MaximumRange {
private:
    public:
    int findMax(string s) {
        int plusCnt = 0;
        for (int i=0; i<s.size(); i++) {
            plusCnt += s[i] == '+';
        }
        int minusCnt = s.size() - plusCnt;
        return max(plusCnt, minusCnt);
    }
};
