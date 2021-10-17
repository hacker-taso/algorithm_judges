#include<iostream>
#include<vector>
using namespace std;

string s;

void solve() {
    cout << 5 << endl;
    cout << "L 2" <<endl;
    cout << "L 2" << endl;
    cout << "R 4" << endl;
    cout << "R 2" << endl;
    cout << "R " << (9 + 4*(s.size()-3)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    solve();
}
