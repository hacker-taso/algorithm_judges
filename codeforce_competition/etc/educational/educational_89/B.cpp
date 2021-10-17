#include<iostream>
#include<algorithm>
using namespace std;

int n, x, m;
int l[100];
int r[100];

int solve() {
    int rangeL = x;
    int rangeR = x;
    for (int i=0; i<m; i++) {
        if (rangeR < l[i] || r[i] < rangeL)
            continue;
        rangeL = min(l[i], rangeL);
        rangeR = max(r[i], rangeR);
    }
    int ret = rangeR - rangeL + 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> x >> m;
        for (int j=0; j<m; j++)
            cin >> l[j] >> r[j];
        cout << solve() << endl;
    }
}
