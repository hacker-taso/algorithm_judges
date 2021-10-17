#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
string s;

int solve() {
    int ret = 0;
    int kickCnt = 0;
    for (int i=0; i+4<s.size(); i++) {
        if (s.substr(i, 4) == "KICK")
            kickCnt++;
        if (s.substr(i, 5) == "START")
            ret += kickCnt;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> s;
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
}