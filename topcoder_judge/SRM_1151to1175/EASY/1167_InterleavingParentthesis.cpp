// Retry
// Start from 01:58 AM Feb 5, 2018.
// End at 02:21 AM Feb 5, 2018. 
// Retrospection:
// 1. I didn't think a corner case where there's no valid complete string.
//  (i == s1.size() && j == s2.size() && openCnt == closeCnt) <= in this part, I didn't think openCnt!=closeCnt case.
// 2. 
#include<iostream>
#include<cstring>
#define MOD 1000000007
using namespace std;

class InterleavingParenthesis {
private:
    string s1, s2;
    int openCntS1[2501];
    int openCntS2[2501];
    int cache[2501][2501];
    int countValid(int i, int j) {
        if (s1.size() < i || s2.size() < j)
            return 0;
        int &ret = cache[i][j];
        if (ret!=-1) return ret;
        int total = i+j;
        int openCnt = openCntS1[i]+openCntS2[j];
        int closeCnt = total - openCnt;
        if (openCnt < closeCnt) {
            ret = 0;
            return ret;
        }
        if (i == s1.size() && j == s2.size() && openCnt == closeCnt) {
            ret = 1;
            return ret;
        }
        ret = (countValid(i+1, j) + countValid(i, j+1)) %MOD;
        return ret;
    }
    void init() {
        memset(cache, -1, sizeof(cache));
        openCntS1[0] = 0;
        openCntS2[0] = 0;
        for (int i=1; i<=s1.size(); i++) {
            openCntS1[i] = openCntS1[i-1] + (s1[i-1] == '(');
        }
        for (int i=1; i<=s2.size(); i++) {
            openCntS2[i] = openCntS2[i-1] + (s2[i-1] == '(');
        }
    }
    public:
    int countWays(string s1_, string s2_) {
        s1 = s1_;
        s2 = s2_;
        init();
        return countValid(0, 0);
    }
};
 