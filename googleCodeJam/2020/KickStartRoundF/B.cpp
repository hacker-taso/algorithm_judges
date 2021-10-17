#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, K;
vector<pair<int, int>> intervals; // [starts[i], ends[i]]

int solve() {
    sort(intervals.begin(), intervals.end());
    int maxCover = 0;
    int cnt = 0;
    for (int i=0; i<N; i++) {
        if (intervals[i].second <= maxCover)
            continue;
        int robotDeployed = max(maxCover+1, intervals[i].first);
        int requiredUntil = intervals[i].second;
        int requiredRange = requiredUntil-robotDeployed+1;
        int deployedCnt = requiredRange / K + ((requiredRange%K) != 0);
        maxCover = robotDeployed + deployedCnt * K - 1;
        cnt += deployedCnt;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N >> K;
        intervals = vector<pair<int,int>>(N);
        int tmp1, tmp2;
        for (int j = 0; j < N; j++) {
            cin >> tmp1 >> tmp2;
            intervals[j] = make_pair(tmp1, tmp2-1);
        }
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
}