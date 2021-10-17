#include<iostream>
#include<algorithm>
using namespace std;


string solve(int n) {
    if (n%4 == 0)
        return "YES";
    else
        return "NO";
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
