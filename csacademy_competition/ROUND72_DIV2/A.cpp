#include <iostream>
#include<algorithm>

using namespace std;

int main() {
    int X;
    cin >> X;
    string s = to_string(X);
    string revS = s;
    reverse(revS.begin(), revS.end());
    if (s < revS)
        cout << 1 << endl;
    else
        cout << 0 <<endl;
    return 0;
}
