#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
string a;
string b;
int n;

void solve() {
    int diff[2] = {0, 0};
    vector<int> ops;
    int i=n-1;
    // add one op.
    vector<int> evenA(a.begin(), a.end());
    for (; 0<=i; i--) {
        if (evenA[i] == b[i])
            continue;
        if (evenA[0] == b[i]) {
            ops.push_back(1);
            if (evenA[0] == '0')
                evenA[0] = '1';
            else
                evenA[0] = '0';
            ops.push_back(i+1);
            reverse(evenA.begin(), evenA.begin()+(i+1));
            for (int j=0; j<i+1; j++) {
                if (evenA[j] == '0')
                    evenA[j] = '1';
                else
                    evenA[j] = '0';
            }
        } else {
            ops.push_back(i+1);
            reverse(evenA.begin(), evenA.begin()+(i+1));
            for (int j=0; j<i+1; j++) {
                if (evenA[j] == '0')
                    evenA[j] = '1';
                else
                    evenA[j] = '0';
            }
        }
        break;
    }
    bool isEven = false; // odd회 시행했음.

    // ops is not empty now.
    for (; 0<=i; i--) {
        if (isEven && evenA[i+diff[isEven]] == b[i] || !isEven && a[i+diff[isEven]] == b[i])
            continue;
        if (isEven && evenA[diff[isEven]] == b[i] || !isEven && a[i+diff[isEven]] == b[i]) {
            diff[isEven] += ops[ops.size()-1] - i;
            ops.push_back(1);
            ops.push_back(i+1);
        } else {
            diff[isEven] += ops[ops.size()-1] - i;
            ops.push_back(i+1);
        }
        isEven = !isEven;
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
