#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int C, N;
void solve() {
    if (C<N-1 || N*(N+1)/2-1<C) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    C -= N-1;
    vector<int> sol(N);
    for (int i=0; i<N; i++)
        sol[i] = i+1;
        
    for (int i=N-2; 0<=i; i--) {
        int curC = min(N-i-1, C);
        reverse(sol.begin()+i, sol.begin()+i+(curC+1));
        C -= curC;
        if (C==0)
            break;
    }
    
    for (int i=0; i<N; i++) {
        if (i == 0)
            cout << sol[i];
        else
            cout << " " << sol[i];
    }
    cout << endl;
}
int main() {
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N >> C;
        cout << "Case #" << i+1 << ": ";
        solve();
    }
}