// Start at 00:04AM March 01, 2018
// End at 00:09AM March 01, 2018
#include <iostream>

using namespace std;

int main() {
    string S;
    cin >> S;
    string sol;
    sol += S[0];
    for (int i=1; i<S.size(); i++) {
        if (S[i] == 'A' && S[i-1] != S[i] || S[i] == 'B') {
            sol += S[i];
        }
    }
    cout << sol << endl;
    return 0;
}