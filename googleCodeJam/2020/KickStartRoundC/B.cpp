#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int R, C;
bool stable;
vector<string> board;
int adj[26][26];

vector<int> seen, order;
void dfs(int here) {
    seen[here] = 1;
    for (int there=0; there<26; there++)
        if(adj[here][there] && !seen[there])
            dfs(there);
    order.push_back(here);
}

string solve() {
    stable = true;
    set<char> cand;
    for (int c=0; c<C; c++) {
        for (int r=0; r<R; r++) {
            cand.insert(board[r][c]);
            for (int r2=r+1; r2<R; r2++) {
                if (board[r2][c] != board[r][c]) {
                    adj[board[r][c]-'A'][board[r2][c]-'A'] = 1;
                }
            }
        }
    }
    seen = vector<int>(26, 0);
    order.clear();
    for(int i=0; i<26; i++) if (!seen[i] && cand.find(i+'A') != cand.end()) dfs(i);
    reverse(order.begin(), order.end());
    for (int i=0; i<order.size(); i++)
        for (int j=i+1; j<order.size(); j++)
            if(adj[order[j]][order[i]]) {
                stable = false;
                return "";
            }
    string sol = "";
    for (int i=0; i<order.size(); i++)
        sol.push_back(order[i] + 'A');
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i=0; i<T; i++) {
        memset(adj, 0, sizeof(adj));
        cin >> R >> C;
        board = vector<string>(R);
        for (int j = 0; j < R; j++)
            cin >> board[R-j-1];
        string sol = solve();
        cout << "Case #" << i+1 << ": ";
        if(stable)
            cout << sol << endl;
        else
            cout << -1 << endl;
    }
}