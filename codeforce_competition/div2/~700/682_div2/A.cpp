#include<iostream>
using namespace std;

void solve(int n) {
    for (int i=0; i<n; i++) {
        cout << 1;
        if (i+1 < n)
            cout << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        solve(n);
    }
}
