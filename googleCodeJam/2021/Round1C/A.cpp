// mistake: I only think about choosing two ranges.
//   I can choose only one range by domination
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<limits>
#include<iomanip>
using namespace std;
int N, K;
int tickets[30];

double solve() {
  sort(tickets, tickets+N);
  int lo = tickets[0]-1, hi = K - (tickets[N-1]);
  int domination = 0;
  if (hi < lo) swap(hi, lo);
  for (int i=1; i<N; i++) {
    int dist = tickets[i] - tickets[i-1] - 1;
    domination = max(dist, domination);
    int possible = dist/2 + dist%2;
    if (lo < possible)
      lo = possible;
    if (hi < lo) swap(hi, lo);
  }
  return (double)max(lo+hi, domination)/K;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    cin >> N >> K;
    for (int j=0; j<N; j++)
      cin >> tickets[j];
    cout << "Case #" << i << ": " << fixed << setprecision(9) << solve() <<endl;
  }
}
