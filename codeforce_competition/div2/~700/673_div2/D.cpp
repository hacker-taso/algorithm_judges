#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> arr;
void solve() {
    int sum = 0;
    for (int i=0; i<arr.size(); i++)
        sum += arr[i];
    if (sum % n != 0) {
        cout << -1 << endl;
        return;
    }
    int target = sum/n;
    vector<int> op1, op2, op3;
    for (int i=1; i<arr.size(); i++) {
        int idx = i+1;
        int x = arr[i]/idx;
        if (x == 0)
            continue;
        op1.push_back(idx);
        op2.push_back(1);
        op3.push_back(x);
        arr[i] -= x*idx;
        arr[0] += x*idx;
    }
    for (int i=arr.size()-1; 0<i; i--) {
        int idx = i+1;
        int x = idx + target - arr[i]; // arr[i] + x*1 == idx + target
        if (arr[0] < x) {
            int x2 = target - arr[i];
            if (arr[0] < x2) {
                cout << -1 << endl;
                return;
            }
            op1.push_back(1);
            op2.push_back(idx);
            op3.push_back(x);
            arr[0] -= x;
            continue;
        }
        // arr(idx) + x == idx + target
        op1.push_back(1);
        op2.push_back(idx);
        op3.push_back(x);
        arr[0]-=x;
        // arr(idx) - idx == target
        op1.push_back(idx);
        op2.push_back(1);
        op3.push_back(1);
        arr[0]+=x;
    }
    cout << op1.size() << endl;
    for (int i=0; i<op1.size(); i++) {
        cout << op1[i] << " " << op2[i] << " " << op3[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        arr = vector<int>(n);
        for (int j=0; j<n; j++)
            cin >> arr[j];
        solve();
    }
}
