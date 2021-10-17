#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


unsigned long long solve(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    for (int i=arr.size()-1; 0<=i; i--) {
        int tmp1 = arr[i] & arr[i+1];
        int tmp2 = arr[i] | arr[i+1];
        arr[i] = tmp1;
        arr[i+1] = tmp2;
        if (arr[i] < arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    unsigned long long ret = 0;
    for (int i=0; i<arr.size(); i++) {
        ret += (unsigned long long)arr[i] * (unsigned long long)arr[i];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << solve(arr) << endl;
}
