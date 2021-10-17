#include<iostream>
#include<algorithm>
using namespace std;


int solve(int n) {
    if (n%2 == 0) {
        return n / 2;
    } else {
        return (n-1)/2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int n;
    for (int i=0; i<t; i++) {
        cin >> n;
        cout << solve(n) << endl;
    }
}
