// Retry (https://www.topcoder.com/blog/single-round-match-714-editorials/)
// start from 00:02AM, Feb 02, 2018
// complete at 00:08AM, Feb 02, 2018
// Retrospection:
// 1. Because there should be some conditions satisfied after each action,
//  I can make valid result of movements from backward.
//  Last one should be ")".
//  If first "(" from backside shown, then this ( could be used to remove any ")" discovered.
//  If second "(" from backside shown, then among remaining ")" discovered we can choose anyone.
//  and so on.
#include<iostream>
#include<cmath>
#define MOD 1000000007
using namespace std;

class ParenthesisRemoval {
private:
    public:
    int countWays(string s) {
        int closeCnt = 0;
        int sol = 1;
        for (int i=s.size()-1; 0<=i; i--) {
            if (s[i] == ')') {
                closeCnt++;
            } else {
                sol = (long long)sol * closeCnt % MOD;
                closeCnt--;
            }
        }
        return sol;
    }
};
