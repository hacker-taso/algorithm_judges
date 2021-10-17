#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
int n;
const string players[2] = {"First", "Second"};

void solve() {
    int winner = 0; // 맨마지막 선공이 이김.
    for (int i=n-2; 0<=i; i--) {
        if (winner == 0) { // 다음 턴 선공이 이긴다면
            if (a[i] == 1) { // 1이면, 이번턴 후공이 다음턴 선공이 됨.
                winner = 1;
            } else { // 1이 아니면, 이번턴 선공이 다음턴 선공이 됨.
                winner = 0;
            }
        } else { // 다음턴 후공이 이긴다면.
            winner = 0; // 이번턴 선공이 이김.
        }
    }
    cout << players[winner] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        a = vector<int>(n);
        for (int j=0; j<n; j++)
            cin >> a[j];
        solve();
    }
}
