// I've read the editorial: https://codeforces.com/blog/entry/90236
#include<iostream>
#include<vector>
#include<cstring>
#include<limits>
#include<algorithm>
using namespace std;
int n, M;
// [len][manual cnt]
long long dp[401][401];
long long C[401][401];

int ncr(int n, int r) {
  long long& ret = C[n][r];
  if (ret != -1) return ret;
  if (n==r || r == 0) return 1;
  ret = (ncr(n-1, r-1) + ncr(n-1, r))%M;
  return ret;
}

int solve() {
  memset(C, -1, sizeof(C));
  memset(dp, -1, sizeof(dp));
  // only manual
  dp[1][1] = 1;
  for (int i=2; i<=400; i++) {
    dp[i][i] = dp[i-1][i-1]*2 % M;
  }
  // pre [1 computer(auto)] right. pre: any, right: only manual
  for (int prelen=1; prelen<=400; prelen++) {
    for (int right=1; prelen+1+right<=400; right++) {
      int len = prelen + 1 + right;
      for (int premc=1; premc<=prelen; premc++) {// total mc=premc+right
        if (dp[prelen][premc] == -1) continue;
        int totalmc = premc+right;
        long long cur = dp[prelen][premc] * dp[right][right] % M;
        cur = cur * ncr(totalmc, right) % M;
        if (dp[len][totalmc] == -1) dp[len][totalmc] = 0;
        dp[len][totalmc] = (dp[len][totalmc] + cur)%M;
      }
    }
  }
  long long sum = 0;
  for (int mc=0; mc<=n; mc++) {
    if (dp[n][mc] == -1) continue;
    sum = (sum + dp[n][mc]) %M;
  }
  return sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> M;
  cout << solve() << endl;
}
