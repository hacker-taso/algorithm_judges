#include<iostream>
#include<vector>
using namespace std;

int a, b;

void solve() {
    for (int i=0; i<n; i++) {
        cout << 4*n - 2*i;
        if (i != n-1)
            cout << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        solve();
    }
}
