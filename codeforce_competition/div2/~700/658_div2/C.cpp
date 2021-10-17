#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string a;
string b;
int n;

void solve() {
    vector<int> ops;
    for (int i=n-1; 0<=i; i--) {
        if (a[i] == b[i])
            continue;
        if (a[0] == b[i]) {
            ops.push_back(1);
            if (a[0] == '0')
                a[0] = '1';
            else
                a[0] = '0';
            ops.push_back(i+1);
            reverse(a.begin(), a.begin()+(i+1));
            for (int j=0; j<i+1; j++) {
                if (a[j] == '0')
                    a[j] = '1';
                else
                    a[j] = '0';
            }
        } else {
            ops.push_back(i+1);
            reverse(a.begin(), a.begin()+(i+1));
            for (int j=0; j<i+1; j++) {
                if (a[j] == '0')
                    a[j] = '1';
                else
                    a[j] = '0';
            }
        }
    }
    cout << ops.size();
    for (int i=0; i<ops.size(); i++) {
        cout << " " << ops[i];
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        cin >> a;
        cin >> b;
        solve();
    }
}
