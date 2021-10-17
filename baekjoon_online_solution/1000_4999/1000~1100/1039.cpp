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
#include<unordered_set>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int N, K;
unordered_set<int> us[11];
vector<int> digits;
int sol = -1;
void init() {
  cin >> N >> K;
}
int numdigits;

int swapn(int n, int i, int j) {
  int ni = (n / digits[i])%10;
  int nj = (n / digits[j])%10;
  return n - ni * digits[i] - nj * digits[j] + ni * digits[j] + nj * digits[i];
}

void dfs(int curn, int nswap) {
  if (nswap == K) {
    sol = max(sol, curn);
    return;
  }
  if (us[nswap].find(curn) != us[nswap].end())
    return;
  us[nswap].insert(curn);
  for (int i=0; i<numdigits-1; i++) {
    for (int j=i+1; j<numdigits; j++) {
      if (j == numdigits-1 && (curn/digits[i])%10 == 0) continue;
      int newn = swapn(curn, i, j);
      dfs(newn, nswap+1);
    }
  }
}

void solve() {
  if (K == 0) {
    cout << N <<endl;
    return;
  }
  numdigits = to_string(N).size();
  digits.push_back(1);
  for (int i=1; i<=numdigits; i++)
    digits.push_back(digits[i-1]*10);
  dfs(N, 0);
  cout << sol << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
