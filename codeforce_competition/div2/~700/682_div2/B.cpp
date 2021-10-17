#include<iostream>
#include<vector>
#include<set>
#define yes "YES"
#define no "NO"
using namespace std;
vector<int> bArr;
int n;

bool solve() {
    set<int> st;
    for (int i=0; i<bArr.size(); i++) {
        if (st.find(bArr[i]) != st.end())
            return true;
        st.insert(bArr[i]);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        bArr.resize(n);
        for (int j=0; j<n; j++)
            cin >> bArr[j];
        if (solve())
            cout << yes << endl;
        else
            cout << no << endl;
    }
}
