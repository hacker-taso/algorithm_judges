#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
vector<int> b;
int n, m;

void solve() {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int aIdx = 0;
    int bIdx = 0;
    while (aIdx < n && bIdx < m) {
        if (a[aIdx] == b[bIdx]) {
            cout << "YES" << endl;
            cout << 1 << " " << a[aIdx] << endl;
            return;
        } else if (a[aIdx] < b[bIdx]) {
            aIdx++;
        } else {
            bIdx++;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> m;
        a = vector<int>(n);
        b = vector<int>(m);
        for (int j=0; j<n; j++)
            cin >> a[j];
        for (int j=0; j<m; j++)
            cin >> b[j];
        solve();
    }
}
