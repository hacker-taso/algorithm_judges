// Start at 05:32PM Feb 25, 2017
// End at 01:28AM Feb 25, 2017
#include<iostream>
#include<vector>
#define MOD 1000000007
using namespace std;

class IntersectingConvexHull {
private:
    int crossProduct(int x1, int y1, int x2, int y2) {
        return x1*y2 - x2*y1;
    }
    int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
        return crossProduct(x2-x1, y2-y1)*crossProduct(x3-x2, y3-y2);
    }
    bool doesCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        return (ccw(x1, y1, x2, y2, x3, y3)* ccw(x1, y1, x2, y2, x4, y4) < 0)
         && (ccw(x3, y3, x4, y4, x1, y1)*ccw(x3, y3, x4, y4, x2, y2) < 0);
    }
    int powTwo[101];
    int comb[101][101];
    void initComb() {
        for (int i=0; i<=100; i++) {
            comb[i][0] = 1;
            comb[i][1] = i;
            comb[i][i] = 1;
        }
        for (int n=1; n<=100; n++) {
            for (int r=1; r<=n-1; r++) {
                comb[n][r] = comb[n-1][r-1] + comb[n-1][r];
            }
        }
    }
    int getCombSum(int n1, int n2) {
        if (n2<n1) swap(n1, n2);
        if (n1<1) return 0;
        int diff = n2-n1;
        long long combSum = 0;
        combSum = (combSum + ((long long)powTwo[diff]-1) * (powTwo[n1]-1)) % MOD;
        for (int sel=1; sel<=n1-1; sel++) {
            combSum = (combSum + (long long)comb[n1][sel] * (powTwo[n1-sel]-1)) % MOD;
        }
        return (int)combSum;
    }
    public:
    int count(vector <int> x, vector <int> y) {
        powTwo[0] = 1;
        for (int i=1; i<=100; i++) {
            powTwo[i] = powTwo[i-1]*2 % MOD;
        }
        initComb();
        int n = x.size();
        long long cnt = 0;
        for (int i1=0; i1<n; i1++) {
            for (int i2=i1+1; i2<n; i2++) {
                for (int i3=0; i3<n; i3++) {
                    for (int i4=i3+1; i4<n; i4++) {
                        if (doesCross(x[i1], y[i1], x[i2], y[i2], x[i3], y[i3], x[i4], y[i4])) {
                            cout << i1 << "," << i2 << "," << i3 << "," << i4 <<":" << getCombSum(n-i2-1, n-i4-1) <<endl;
                            cnt = (cnt+getCombSum(n-i2-1, n-i4-1))%MOD;
                        }
                    }
                }
            }
        }
        return (int)cnt;
    }
};
