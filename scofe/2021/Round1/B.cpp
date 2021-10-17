/*
입력:
3
111

출력:
2

입력:
4
1101

출력:
1

입력:
5
11111

출력:
5
*/

#include <iostream>
#include<vector>
using namespace std;
int N;
string s;
vector<long long> dp;

long long solve() {
  dp = vector<long long>(N, 0);
  dp[0] = 1;
  dp[1] = (s[1] == '0') ? 0 : 1;
  for (int i=2; i<N; i++) {
    if (s[i] == '0') {
      dp[i] = 0;
      continue;
    }
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp.back();
}

int main() {
  cin >> N;
  cin >> s;
  cout << solve() << endl;
  return 0;
}
