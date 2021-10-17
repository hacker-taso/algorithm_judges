// Start from 09:05PM Feb 14, 2017
// End at 09:17PM Feb 14, 2017
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> lt1(n);
    vector<int> lt2(m);
    for (int i=0; i<n; i++)
        cin >> lt1[i];
    for (int i=0; i<m; i++)
        cin >> lt2[i];
    long long maxVal=-(long long)1e9*1e9;
    int maxIdx = -1;
    for (int i=0; i<n; i++) {
        long long locMax = -(long long)1e9*1e9;
        for (int j=0; j<m; j++) {
            locMax = max((long long)lt1[i]*lt2[j], locMax);
        }
        if (maxVal < locMax) {
            maxIdx = i;
            maxVal = locMax;
        }
    }
    maxVal=-(long long)1e9*1e9;
    for (int i=0; i<n; i++) {
        if (i==maxIdx) continue;
        long long locMax = -(long long)1e9*1e9;
        for (int j=0; j<m; j++) {
            locMax = max((long long)lt1[i]*lt2[j], locMax);
        }
        maxVal = max(locMax, maxVal);
    }
    cout << maxVal <<endl;
}
