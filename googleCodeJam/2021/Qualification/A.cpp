#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> arr;

int solve() {
    int sol = 0;
    for (int i=0; i<N-1; i++) {
        int pos = i;
        for (int j=i+1; j<N; j++) {
            if (arr[j] < arr[pos])
                pos = j;
        }
        sol += pos - i + 1;
        reverse(arr.begin() + i, arr.begin() + pos + 1);
    }
    return sol;
}

int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N;
        arr.resize(N);
        for (int j=0; j<N; j++)
            cin >> arr[j];
        cout << "Case #" << (i+1) << ": " << solve() << endl;
    }
}