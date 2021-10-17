#include<iostream>
#include<vector>
using namespace std;
#define MOD 1'000'000'007
#define MAXN 200'100
int N;
vector<int> arr;

struct Fenwick {
  vector<int> tree;
  Fenwick(int n): tree(n+1, 0) {}
  void add(int pos, int val) {
    pos++;
    while (pos < tree.size()) {
      tree[pos] = (tree[pos] + val) % MOD;
      pos += pos & -pos;
    }
  }
  int sum(int pos) {
    pos++;
    int ret = 0;
    while (0 < pos) {
      ret = (ret + tree[pos]) % MOD;
      pos = (pos & (pos-1));
    }
    return ret;
  }
};

int solve() {
  Fenwick sumtree(MAXN);
  Fenwick cnttree(MAXN);
  int ret = 1;
  bool isFirst = true;
  for (int n: arr) {
    int lcnt = 0; 
    int lsum = 0;
    if (0 < n) {
      lcnt = cnttree.sum(n-1);
      lsum = sumtree.sum(n-1);
    }
    int ldistsum = ((long long)lcnt*n - lsum) % MOD;
    if (ldistsum < 0) ldistsum += MOD;

    int rcnt = cnttree.sum(MAXN) - cnttree.sum(n);
    int rsum = (sumtree.sum(MAXN) - sumtree.sum(n)) % MOD;
    int rdistsum = (rsum - (long long)rcnt*n) % MOD;
    if (rdistsum < 0) rdistsum += MOD;

    int cost = (ldistsum + rdistsum) % MOD;
    if (!isFirst)
      ret = ((long long)ret * cost) % MOD;
    isFirst = false;
    cnttree.add(n, 1);
    sumtree.add(n, n);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> N;
  arr = vector<int>(N);
  for (int i=0; i<N; i++) {
    cin >> arr[i];
  }
  cout << solve() << endl;
}
