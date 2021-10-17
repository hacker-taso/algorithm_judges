#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n, T;
vector<int> arr;
void solve() {
    map<int, int> m1, m2;
    for (int i=0; i<n; i++) {
        if (arr[i]*2 == T) {
            int cnt1 = 0, cnt2 = 0;
            if (m1.find(arr[i]) != m1.end())
                cnt1 = m1[arr[i]];
            if (m2.find(arr[i]) != m2.end())
                cnt2 = m2[arr[i]];
            if (cnt1 > cnt2)
                m2[arr[i]]++;
            else
                m1[arr[i]]++;
            continue;
        }
        if (m1.find(arr[i]) != m1.end())
            m1[arr[i]]++;
        else if (m2.find(arr[i]) != m2.end())
            m2[arr[i]]++;
        else if (m1.find(T-arr[i]) != m1.end())
            m2[arr[i]]++;
        else
            m1[arr[i]]++;
    }
    for (int i=0; i<n; i++) {
        if (m1.find(arr[i]) != m1.end()) {
            m1[arr[i]]--;
            if (m1[arr[i]] == 0)
                m1.erase(arr[i]);
            cout << 0;
        }
        else {
            m2[arr[i]]--;
            if (m2[arr[i]] == 0)
                m2.erase(arr[i]);
            cout << 1;
        }
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
        cin >> n >> T;
        arr = vector<int>(n);
        for (int j=0; j<n; j++)
            cin >> arr[j];
        solve();
    }
}
