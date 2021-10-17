#include<iostream>
using namespace std;

long long n, k;

bool solve() {
    if (k>100) return false;
    for (int i=1; i<=k; i++) {
        if ((n+1)%i) return false;
    }
    return true;
}

int main() {
    cin >> n >> k;
    if (solve()) {
        cout << "Yes"<<endl;
    } else {
        cout << "No" <<endl;
    }
}
