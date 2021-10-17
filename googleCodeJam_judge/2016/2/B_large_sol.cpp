// I've read the solution for "for (int start=N-K; start<=N; start++)" part.
// learned: make the formula as a linear function
// and prove that the members are only on left and right side.
// learned2: exp and log functions are slow.
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int N, K;
// curIdx, yes cnt : maxLogPs
double dp[201][201];
double ps[201];

double solve() {
  sort(ps, ps+N);
  double maxps = 0;
  for (int start=N-K; start<=N; start++) {
    int st = start%N;
    memset(dp, 0, sizeof(dp));
    dp[st][0] = 1-ps[st];
    dp[st][1] = ps[st];
    for (int i=1; i<K; i++) { // i: cur idx
      for (int y=0; y<=i; y++) { // y: prev y count
        if (K < y*2) continue;
        dp[(start+i)%N][y+1] += dp[(start+i-1)%N][y]*ps[(start+i)%N]; // cur y
        dp[(start+i)%N][y] += dp[(start+i-1)%N][y]*(1-ps[(start+i)%N]); // cur n
      }
    }
    maxps = max(maxps, dp[(start+K-1)%N][K/2]);
  }
  return maxps;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    cin >> N >> K;
    for (int j=0; j<N; j++)
      cin >> ps[j];
    cout << "Case #" << i << ": " << fixed << setprecision(9) << solve() << endl;
  }
}
