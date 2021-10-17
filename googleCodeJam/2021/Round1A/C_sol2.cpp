#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
long long int dfs(int i, int curS1, int curS2, int);
// idx, curScore1, curScore2
long long int df[121][121][121][121];
long long int N, Q, firstTCnt, firstFCnt;
vector<string> qs;
vector<int> scores;

void init() {
  memset(df, -1, sizeof(df));
  firstTCnt = 0;
  firstFCnt = 0;
}

long long int gcd(long long int p, long long int q) {
  if (q==0)
    return p;
  return gcd(q, p%q);
}

void solve(int problemIdx) {
  string sol;
  long long int numer = 0;
  long long int answerCnt = 0;
  for (int i=0; i<Q; i++) {
    init();
    swap(qs[0][0], qs[0][i]);
    swap(qs[1][0], qs[1][i]);
    swap(qs[2][0], qs[2][i]);
    answerCnt = dfs(0, 0, 0, 0);
    if (firstFCnt < firstTCnt) {
      numer += firstTCnt;
      sol += 'T';
    } else {
      numer += firstFCnt;
      sol += 'F';
    }
  }
  long long int g = gcd(answerCnt, numer);
  long long int denom = answerCnt/g;
  numer = numer/g;
  cout << "Case #" << (problemIdx+1) << ": " << sol << " " << numer << "/" << denom << endl;
}

long long int dfs(int i, int curS1, int curS2, int curS3) {
  long long int& ret = df[i][curS1][curS2][curS3];
  if (ret != -1)
    return ret;
  if (i == Q) {
    ret = curS1 == scores[0] && curS2 == scores[1] && curS3 == scores[2];
    return ret;
  }
  // if T is true
  long long int a = dfs(i+1, curS1 + (qs[0][i] == 'T'), curS2 + (qs[1][i] == 'T'), curS3 + (qs[2][i] == 'T'));
  // if F is true
  long long int b = dfs(i+1, curS1 + (qs[0][i] == 'F'), curS2 + (qs[1][i] == 'F'), curS3 + (qs[2][i] == 'F'));
  if (i == 0) {
    firstTCnt = a;
    firstFCnt = b;
  }
  ret = a+b;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T, nTmp;
  N = 3;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> nTmp >> Q;
    qs.resize(N);
    scores.resize(N);
    for (int j=0; j<nTmp; j++)
      cin >> qs[j] >> scores[j];
    for (int i=nTmp; i<N; i++) {
      qs[i] = qs[0];
      scores[i] = scores[0];
    }
    solve(i);
  }
}