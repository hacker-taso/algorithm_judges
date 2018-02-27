// Retry
// start from about 03:00PM, Feb 10, 2018
// It took about 1 hours to complete.
#include<iostream>
#include<cmath>
using namespace std;

class RememberWords {
private:
    public:
    string isPossible(int d1, int d2, int w1, int w2) {
        int min1 = max((int)ceil((double)w1/d1 - (double)(d1-1)/2), 0);
        int min2 = max((int)ceil((double)w2/d2 - (double)(d2-1)/2), 0);
        int w1Remain = (w1-min1*d1);
        int w2Remain = (w2-min2*d2);
        int max1, max2;
        if (d1>1) {
            max1 = ceil((double)w1Remain/((d1-1)*2) + min1);
            int tmp = (-1+sqrt(1 + (long long)8*w1)) / 2 ;
            if (w1 <= 2 && 0<w1)
                tmp = 1;
            if (tmp<=d1)
                max1 = max(tmp, max1);
        } else {
            max1 = min1;
        }
        if (d2>1) {
            max2 = ceil((double)w2Remain/((d2-1)*2) + min2);
            int tmp = (-1+sqrt(1 + (long long)8*w2)) / 2 ;
            if (w2 <= 2 && 0<w2)
                tmp = 1;
            if (tmp<=d2)
                max2 = max(tmp, max2);
        } else {
            max2 = min2;
        }
        if (max1+1 < min2 || max2+1 < min1)
            return "Impossible";
        else
            return "Possible";
    }
};
