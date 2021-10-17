#include<iostream>
#include<algorithm>
using namespace std;


string solve(string b) {
    string a = "";
    a += b[0];
    for (int i=1; i<b.length()-1; i+=2)
        a+=b[i];
    a += b[b.length()-1];
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    string b;
    for (int i=0; i<t; i++) {
        cin >> b;
        cout << solve(b) << endl;
    }
}
