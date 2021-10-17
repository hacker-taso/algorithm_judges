// 답봄
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> board;
int n, m;

void solve() {
    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            board[y][x] += (board[y][x]%2 + (y+x)%2)%2;
        }
    }
    for (int y=0; y<n; y++) {
        for (int x=0; x<m; x++) {
            cout << board[y][x];
            if (x+1 < m)
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> m;
        board = vector<vector<int>>(n, vector<int>(m));
        for (int j=0; j<n; j++)
            for (int k=0; k<m; k++)
                cin >> board[j][k];
        solve();
    }
}
