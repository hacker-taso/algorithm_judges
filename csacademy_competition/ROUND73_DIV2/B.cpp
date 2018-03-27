#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> heights(N);
    for (int i=0; i<N; i++)
        cin >> heights[i];
    vector<long long> partialSum(N+1);
    sort(heights.begin(), heights.end());
    partialSum[0] = heights[0];
    for (int i=1; i<N; i++)
        partialSum[i] = partialSum[i-1] + heights[i];
    long long minSum = 0x987654329876ul;
    for (int i=0; i<N; i++) {
        long long neg = partialSum[i];
        long long pos = partialSum[N-1]-partialSum[i];
        long long tMul = 2*i-N+2;
        long long sumVal = -neg + pos;
        if (i<N-i) sumVal += tMul*heights[i+1];
        else sumVal += tMul*heights[i];
        minSum = min(sumVal, minSum);
    }
    cout << minSum << endl;
    return 0;
}
