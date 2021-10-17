#include<iostream>
#include<algorithm>
using namespace std;


string solve(string s) {
    string ret = "";
    string tmp = "";
    int i=0;
    bool zeroFound = false;
    for (int i=s.size()-1 ; 0<=i; i--) {
        if (zeroFound) {
            if (s[i] == '1') {
                tmp = "";
                continue;
            } else { // zero
                tmp += s[i];
            }
        } else {
            if (s[i] == '1') {
                ret += s[i];
            } else { // zero
                zeroFound = true;
                ret += s[i];
            }
        }
    }
    ret += tmp;
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int n;
    string s;
    for (int i=0; i<t; i++) {
        cin >> n;
        cin >> s;
        cout << solve(s) << endl;
    }
}
