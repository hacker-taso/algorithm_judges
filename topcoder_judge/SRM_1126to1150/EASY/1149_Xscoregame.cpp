// Retry
// Comment on http://codeforces.com/blog/entry/49911
// Retrospection:
// 1. I didn't think about using a value of dp as a key of state.
// 2. I can use bitmask to express combination of selections from a set.
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

// key: least significant bits of curValue X, curSelected in bits
// value: maxValue of curValue X
// (for example 100001 on curSelected means the first and the last already used)
int dp[64][32768];

class Xscoregame {
private:
    public:
    int getscore(vector <int> A) {
        int n = A.size();
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i=0; i<n; i++) {
                if (cur & (1<<i)) continue;
                int next = cur | (1<<i);
                for (int j=0; j<64; j++) {
                    if (dp[j][cur] == -1) continue;
                    int nextVal = (dp[j][cur]^A[i]) + dp[j][cur];
                    dp[nextVal%64][next] = max(dp[nextVal%64][next], nextVal);
                }
                if (__builtin_ctz(next) == i)
                    q.push(next);
            }
        }
        int maxVal = 0;
        for (int i=0; i<64; i++) {
            maxVal = max(dp[i][(1<<n)-1], maxVal);
        }
        return maxVal;
    }
};
