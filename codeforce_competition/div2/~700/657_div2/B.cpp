#include<iostream>
#include<algorithm>
using namespace std;

// ls(left side) = m+c-b, rs(right side) = n*a
void solve(int l, int r, long long m) {
    long long ls_max = m + r - l;
    long long ls_min = m + l - r;
    for (int a=l; a<=r; a++) {
        long long remain = ls_max % a;
        long long ls_cand = ls_max - remain;
        if (ls_min <= ls_cand && ls_cand <= ls_max) {
            long long c_minus_b = ls_cand - m;
            long long c;
            if (c_minus_b < 0)
                c = l;
            else
                c = r;
            long long b = c - c_minus_b;
            cout << a << " " << b << " " << c << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int l, r;
    long long m;
    for (int i=0; i<t; i++) {
        cin >> l >> r >> m;
        solve(l, r, m);
    }
}
