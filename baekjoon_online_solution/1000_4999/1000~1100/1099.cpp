#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<numeric>
#include<map>
#include<cmath>
#include<string>
#include<map>
using namespace std;
#define INF 987654321
int dp[100];
int N;
string s;
vector<string> words;
vector<string> sortedwords;
int maxlen;
void init() {
  cin >> s >> N;
  words.resize(N);
  for (int i=0; i<N; i++)
    cin >> words[i];
}

vector<int> counts;
int dfs(int idx) {
  if (idx == s.size()) return 0;
  int& ret = dp[idx];
  if (ret != -1) return ret;
  int curret = INF;
  for (int j=1; j<=maxlen; j++) {
    if (s.size() < idx + j) break;
    string word2 = s.substr(idx, j);
    string sortedword2 = word2;
    sort(sortedword2.begin(), sortedword2.end());
    for (int k=0; k<words.size(); k++) {
      if (sortedwords[k] != sortedword2) continue;
      int curcnt = 0;
      for (int l=0; l<words[k].size(); l++) {
        curcnt += words[k][l] != word2[l];
      }
      int res = dfs(idx+j);
      if (res == INF) continue;
      curret = min(curret, curcnt + res);
    }
  }
  ret = curret;
  return ret;
}

void solve() {
  string word;
  sortedwords.resize(words.size());
  maxlen = 0;
  for (int i=0; i<words.size(); i++) {
    word = words[i];
    sort(word.begin(), word.end());
    sortedwords[i] = word;
    maxlen = max(maxlen, (int)word.size());
  }
  memset(dp, -1, sizeof(dp));
  int sol = dfs(0);
  if (sol == INF)
    cout << -1 <<endl;
  else
    cout << sol << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
