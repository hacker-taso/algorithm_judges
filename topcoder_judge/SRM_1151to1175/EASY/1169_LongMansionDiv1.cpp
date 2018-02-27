// start from 09:51PM, Jan 23, 2018
// complete at 10:12PM, Jan 23, 2018
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class LongMansionDiv1 {
private:
    vector<int> partialSum;
    void fillPartialSum(vector<int>& t) {
        partialSum = vector<int>(t.size());
        partialSum[0] = t[0];
        for (int i=1; i<t.size(); i++) {
            partialSum[i] = partialSum[i-1] + t[i];
        }
    }
    public:
    long long minimalTime(vector <int> t, int sX, int sY, int eX, int eY) {
        fillPartialSum(t);
        long long minTime = 0x1234567812345678ll;
        long long cand;
        for (int i=0; i<t.size(); i++) {
            // move in sY
            cand = abs(partialSum[sX] - partialSum[i])+(sX<i ? t[sX] : t[i]);
            cand += ((long long)abs(sY-eY)-1) * t[i];
            cand += abs(partialSum[eX] - partialSum[i])+(eX<i ? t[eX] : t[i]);
            minTime = min(cand, minTime);
        }
        return minTime;
    }
};
