// I messed up with this problem and took quite a lot of time to solve this problem.
// I should have thought sum[i] is distance from 0 and I should have known this problem can be solved using just one partial sum
// not two partial sums.
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> lengths(N);
    for (int i=0; i<N; i++) {
        cin >> lengths[i];
    }
    vector<int> sum(N+1);
    sum[0] = 0;
    for (int i=1; i<=N; i++) { // one index
        sum[i] = sum[i-1] + lengths[i-1];
    }
    int minCap;
    int minVal = 0x76543210;
    for (int cand=0; cand<N; cand++) {
        int curMaxVal = 0;
        for (int other=0; other<N; other++) {
            curMaxVal = max(curMaxVal, 
                min(cand < other ? sum[other]-sum[cand] : sum[cand]-sum[other],
                cand < other ? sum[N]-sum[other]+sum[cand] :
                                sum[N]-sum[cand]+sum[other]
                )
            );
            cout << (cand < other ? sum[other]-sum[cand] : sum[cand]-sum[other]) << ":";
            cout << (cand < other ? sum[N]-sum[other]+sum[cand] :
                                sum[N]-sum[cand]+sum[other]) << endl;
        }
        cout << curMaxVal <<endl;
        if (curMaxVal < minVal) {
            minCap = cand;
            minVal = curMaxVal;
        }
    }
    cout << minCap + 1 << endl;
}