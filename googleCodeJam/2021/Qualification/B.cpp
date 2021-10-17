// 1 C CC J
// 2 C JJ J 
// 3 C JC J
// sol: 1 or 2 (same with removing ?)
// 4 C CC C
#include<iostream>
#include<vector>
using namespace std;
int CJ, JC;
string s;
int solve() {
    int sol = 0;
    char before = '?';
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '?' || s[i] == before)
            continue;
        if(before == 'C') {
            sol += CJ;
        } else if (before == 'J') {
            sol += JC;
        }
        before = s[i];
    }
    return sol;
}
int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> CJ >> JC >> s;
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
}