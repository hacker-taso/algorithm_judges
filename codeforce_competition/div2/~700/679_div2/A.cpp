#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> nums;

void solve() {
    for (int i=0; i<n; i+=2) {
        cout << -nums[i+1] << " " << nums[i];
        if (i+2 < n)
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
        nums.resize(n);
        for (int j=0; j<n; j++)
            cin >> nums[j];
        solve();
    }
}
