#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nums;

bool solve() {
    int pos = -1;
    for (int i=1; i<nums.size(); i++) {
        if (nums[i-1] < nums[i]) {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[j] == nums[i])
                    nums[j] -= nums[i-1];
                else {
                    break;
                }
            }
            nums[i] -= nums[i-1];
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return true;
    for (int i=pos+1; i<nums.size(); i++) {
        if (nums[i] < nums[i-1])
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        nums.resize(n);
        for (int j=0; j<n; j++)
            cin >> nums[j];
        if (solve()) {
            cout << "YES" <<endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
