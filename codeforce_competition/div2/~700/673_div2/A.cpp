#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int n, k;
vector<int> arr;
int solve() {
    int minVal = numeric_limits<int>::max(); 
    int minIdx = -1;
    for (int i=0; i<n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIdx = i;
        }
    }
    int ret = 0;
    for (int i=0; i<n; i++) {
        if (i == minIdx)
            continue;
        ret += (k-arr[i])/minVal;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> k;
        arr = vector<int>(n);
        for (int j=0; j<n; j++)
            cin >> arr[j];
        cout <<solve() <<endl;
    }
}
