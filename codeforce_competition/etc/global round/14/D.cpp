#include<iostream>
#include<vector>
#include<cstring>
#include<limits>
#include<algorithm>
using namespace std;
int n, l, r;
vector<int> ls;
vector<int> rs;
int lcolorcnt[200001];
int rcolorcnt[200001];
int diffcnt[200001];

int solve() {
  memset(lcolorcnt, 0, sizeof(lcolorcnt));
  memset(rcolorcnt, 0, sizeof(rcolorcnt));
  memset(diffcnt, 0, sizeof(diffcnt));
  int cost = 0;
  // preproc
  for (int l: ls)
    lcolorcnt[l-1]++;
  for (int r: rs)
    rcolorcnt[r-1]++;
  // remove same color
  for (int i=0; i<n; i++) {
    if (rcolorcnt[i] < lcolorcnt[i]) {
      lcolorcnt[i] = lcolorcnt[i] - rcolorcnt[i];
      rcolorcnt[i] = 0;
    } else {
      rcolorcnt[i] = rcolorcnt[i] - lcolorcnt[i];
      lcolorcnt[i] = 0;
    }
  }
  int* targetcnt = lcolorcnt;
  int* opcnt = rcolorcnt;
  int diff = l-r;
  if (l < r) {
    targetcnt = rcolorcnt;
    opcnt = lcolorcnt;
    diff = r - l;
  }
  // move sock from l to r or r to l
  for (int i=0; i<n && diff != 0; i++) {
    if (2 <= targetcnt[i]) {
      int cur = min(targetcnt[i] - targetcnt[i]%2, diff);
      diff -= cur;
      targetcnt[i] -= cur;
      cost += cur/2;
    }
  }
  for (int i=0; i<n && diff !=0; i++) {
    if (0 < targetcnt[i]) { // always 1
      diff -= 2;
      targetcnt[i] = 0;
      opcnt[i] = 1;
      cost += 1;
    }
  }
  // cnt unmatched and cost += cnt/2
  int cnt = 0;
  for (int i=0; i<n; i++) {
    cnt += lcolorcnt[i];
    cnt += rcolorcnt[i];
  }
  cost += cnt/2;

  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> n >> l >> r;
    ls.resize(l);
    rs.resize(r);
    for (int j=0; j<l; j++)
      cin >> ls[j];
    for (int j=0; j<r; j++)
      cin >> rs[j];
    cout << solve() << endl;
  }
}
