#include<iostream>
#include<vector>
using namespace std;

int n;
vector<string> board;

void solve() {
    vector<vector<pair<int,int>>>idxs(2);
    idxs[board[0][1] - '0'].push_back({0,1});
    idxs[board[1][0] - '0'].push_back({1,0});
    idxs[board[n-1][n-2] - '0'].push_back({n-1,n-2});
    idxs[board[n-2][n-1] - '0'].push_back({n-2,n-1});
    vector<pair<int, int>> sols;
    if (idxs[0].empty() || idxs[1].empty()) { // 다 같은 경우
        sols.push_back({1,2});
        sols.push_back({2,1});
    } else if (idxs[0].size() == 2) {
        if (board[0][1] != board[1][0]) {
            if (board[0][1] == board[n-1][n-2]) {
                sols.push_back({1,2});
                sols.push_back({n-1, n});
            } else if (board[1][0] == board[n-1][n-2]) {
                sols.push_back({2,1});
                sols.push_back({n-1, n});
            }
        }
    } else  {//3개 혹은 1개 
        if (board[0][1] == board[1][0]) {
            if (board[n-1][n-2] == board[0][1])
                sols.push_back({n, n-1});
            else if (board[n-2][n-1] == board[0][1])
                sols.push_back({n-1, n});
        } else if (board[n-1][n-2] == board[n-2][n-1]) {
            if (board[0][1] == board[n-1][n-2])
                sols.push_back({1, 2});
            else if (board[1][0] == board[n-1][n-2])
                sols.push_back({2, 1});
        }
    }
    cout << sols.size() <<endl;
    for (int i=0; i<sols.size(); i++)
        cout << sols[i].first << " " << sols[i].second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        board = vector<string>(n);
        for (int j=0; j<n; j++)
            cin >> board[j];
        solve();
    }
}
