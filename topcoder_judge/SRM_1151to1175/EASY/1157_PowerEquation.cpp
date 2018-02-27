// Retry2.
// start from 10:03PM, Feb 01, 2018
// complete at 11:39PM, Feb 01, 2018
// Retrospection:
// 1. Finding expression of a=x^i and c=x^j was difficult.
// 2. It is difficult to find good constraint like x<=sqrtn, splitting case into a==1, a<c and so on.
// 3. There was a bug.for (imax=0,a=x; a<=n; imax++,a*=x);
// Because x<=sqrtn, I thought I can set a int. But there could be integer overflow.
// That's the reason why I optimized code a lot until I found the bug.
#include<iostream>
#include<cmath>
#include<cstring>
#define MOD 1000000007
using namespace std;

class PowerEquation {
private:
    int cache[33][33];
    int imaxCache[33];
    int GCD(int i, int j) {
        if (j==0)
            return i;
        return GCD(j, i%j);
    }
    int LCM(int i, int j) {
        int &ret = cache[i][j];
        if (ret!=-1) return ret;
        ret = i*j/GCD(j, i%j);
        return ret;
    }
    public:
    int count(int n) {
        int sqrtn = (sqrt(n) + 10e-7);
        int cnt = 0, imax;
        bool visited[35000];
        memset(visited, 0, sizeof(visited));
        memset(cache, -1, sizeof(cache));
        memset(imaxCache, -1, sizeof(imaxCache));
        // assume a<c && a!=1
        for (int x=2; x<=sqrtn; x++) {
            if (visited[x])
                continue;
            long long a=x;
            for (imax=0; a<=n; imax++) {
                a*=x;
            }
            int &imaxCacheVal = imaxCache[imax];
            if (imaxCacheVal != -1) {
                cnt = (cnt+imaxCacheVal)%MOD;
                for (int expo=x; expo<=sqrtn; expo*=x)
                    visited[expo] = true;
                continue;
            }
            // a = x^i, c=x^j, i*b = j*d = LCM(i,j)*C
            // LCM(i,j)*C/i = (LCM(i,j)/i)*C = b <= n
            // num of C = n/(LCM(i,j)/i)
            // but a=4^2 == 2^4 => should be removed.
            imaxCacheVal = 0;
            for (int i=1; i<=imax; i++) {
                for (int j=i+1; j<=imax; j++) {
                    int lcm = LCM(i, j);
                    imaxCacheVal = (imaxCacheVal+n/(lcm/i))%MOD;
                }
            }
            cnt = (cnt+imaxCacheVal)%MOD;
            for (int expo=x; expo<=sqrtn; expo*=x)
                visited[expo] = true;
        }
        // c<a case
        cnt = 2*cnt % MOD;
        // a==c and a!=1 case => b and d should be same [1,n]
        cnt = ((long long)cnt+(long long)(n-1)*n) % MOD;
        // a==c and a==1 case => b and d can be any value [1,n]
        cnt = ((long long)cnt+(long long)n*n) % MOD;
        return cnt;
    }
};
