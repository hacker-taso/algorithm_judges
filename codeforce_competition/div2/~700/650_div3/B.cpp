#include<iostream>
#include<vector>
using namespace std;


int solve(vector<int>& arr) {
    int evenWrong = 0;
    int oddWrong = 0;
    for (int i=0; i<arr.size(); i++) {
        if (i%2 == 0 && arr[i]%2 != 0)
            evenWrong++;
        else if (i%2 == 1 && arr[i]%2 != 1)
            oddWrong++;
    }
    if (evenWrong != oddWrong)
        return -1;
    return evenWrong;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int n;
    for (int i=0; i<t; i++) {
        cin >> n;
        vector<int> arr(n);
        for(int j=0; j<n; j++)
            cin >> arr[j];
        cout << solve(arr) << endl;
    }
}
