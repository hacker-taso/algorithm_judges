// mistake1: local declaration again for global variables.
// my first thinking: move all seat to left from the small round.
// But this makes problem when seats are like below. (curr)
//     3
//   2 4
// 1 1 3
// becomes =>
//     3
// 1 3
// 1 2 4
// But it can become
// 1 3 4
// 1 2 3
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;
int minRound, minPromo;
int N, C, M;
// tickets[p] = customers
vector<vector<int>> tickets;
// cFilled[c][r] = customer c with round r is filled.

void solve() {
  minRound = 0;
  int customers = 0;
  vector<int> cCnts(C, 0);
  for (int p=0; p<N; p++) {
    for (int c: tickets[p]) { // total M loop (including upper loop)
      cCnts[c]++;
      minRound = max(cCnts[c], minRound);
    }
    customers += tickets[p].size();
    minRound = max(minRound, customers/(p+1) + (0<customers%(p+1)));
  }
  minPromo = 0;
  for (int p=0; p<N; p++) {
    minPromo += max((int)tickets[p].size()-minRound, 0);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int T, P, B;
  cin >> T;
  for (int i=1; i<=T; i++) {
    cin >> N >> C >> M;
    tickets = vector<vector<int>>(N);
    for (int j=0; j<M; j++) {
      cin >> P >> B;
      tickets[P-1].push_back(B-1);
    }
    solve();
    cout << "Case #" << i << ": " << minRound << " " << minPromo <<endl;
  }
}
