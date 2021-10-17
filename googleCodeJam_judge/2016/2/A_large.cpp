//p s r s
// s   r
//   r
// 마지막에 이기는 move에 해당하는 조합은 하나밖에 없음. 배열의 문제임.
// dp[N][S] = dp[N-1][S]와 dp[N-1][P]를 이은것 (둘중 사전순으로 빠른게 앞에 가게)
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N, R, P, S;
#define PM 0
#define RM 1
#define SM 2
string dp[13][3];
void init() {
  dp[1][PM] = "PR";
  dp[1][RM] = "RS";
  dp[1][SM] = "PS";
  for (int i=2; i<=12; i++) {
    string r = dp[i-1][RM];
    string s = dp[i-1][SM];
    string p = dp[i-1][PM];
    if (r < s)
      dp[i][RM] = r + s;
    else 
      dp[i][RM] = s + r;
    if (r < p)
      dp[i][PM] = r + p;
    else
      dp[i][PM] = p + r;
    if (s < p)
      dp[i][SM] = s + p;
    else
      dp[i][SM] = p + s;
  }
}

string solve() {
  string s = "Z";
  int cnts[256] = {0};
  for (int i=0; i<3; i++) {
    memset(cnts, 0, sizeof(cnts));
    for (int j=0; j<dp[N][i].size(); j++)
      cnts[dp[N][i][j]]++;
    if (cnts['P'] != P || cnts['R'] != R || cnts['S'] != S)
      continue;
    s = min(s, dp[N][i]);
  }
  if (s == "Z")
    return "IMPOSSIBLE";
  return s;
}

int main() {
  init();
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    cin >> N >> R>> P >> S;
    cout << "Case #" << i << ": " << solve() << endl;
  }
}