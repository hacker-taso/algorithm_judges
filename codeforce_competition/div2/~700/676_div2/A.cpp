#include<iostream>
#include<vector>
using namespace std;

int a, b;

int solve() {
    int x=a&b;
    return (a^x) + (b^x);
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> a >> b;
        cout << solve() << endl;
    }
}
