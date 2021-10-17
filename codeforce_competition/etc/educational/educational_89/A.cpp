#include<iostream>
#include<algorithm>
using namespace std;


int solve(int a, int b) {
    int big = a;
    int small = b;
    if (big < small)
        swap(big, small);
    int diff = big - small;
    int useBig = min(diff, small);
    int ret = useBig;
    int postBig = big - useBig*2;
    int postSmall = small - useBig;
    if (postSmall == 0 || postBig <= 1)
        return ret;

    int useBoth = min(postBig / 3, postSmall / 3);
    ret += useBoth*2;
    postBig -= useBoth * 3;
    postSmall -= useBoth * 3;
    if (postBig <= 1)
        return ret;
    if (1 <= postSmall)
        ret += 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int a, b;
    for (int i=0; i<t; i++) {
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}
