#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> a;

void solve() {
    vector<int> evenIdxs;
    vector<int> oddIdxs;
    for (int i=0; i<n*2; i++) {
        if (a[i]%2 == 0)
            evenIdxs.push_back(i);
        else
            oddIdxs.push_back(i);
    }
    if (oddIdxs.size() % 2 == 1) {
        oddIdxs.pop_back();
        evenIdxs.pop_back();
    } else {
        if (0<oddIdxs.size()) {
            oddIdxs.pop_back();
            oddIdxs.pop_back();
        } else {
            evenIdxs.pop_back();
            evenIdxs.pop_back();
        }
    }
    for (int i=0; i<oddIdxs.size(); i+=2)
        cout << (oddIdxs[i]+1) << " " << (oddIdxs[i+1]+1) << endl;
    for (int i=0; i<evenIdxs.size(); i+=2)
        cout << (evenIdxs[i]+1) << " " << (evenIdxs[i+1]+1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        a = vector<int>(2*n);
        for (int j=0; j<n*2; j++)
            cin >> a[j];
        solve();
    }
}
