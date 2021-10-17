#include<iostream>
#include<algorithm>
using namespace std;


int solve(int a, int b, int n) {
    int ret = 0;
    int big = a;
    int small = b;
    while(true) {
        if (big < small)
            swap(big, small);
        small += big;
        ret += 1;
        if (n < small)
            break;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int a, b, n;
    for (int i=0; i<t; i++) {
        cin >> a >> b >> n;
        cout << solve(a, b, n) << endl;
    }
}
