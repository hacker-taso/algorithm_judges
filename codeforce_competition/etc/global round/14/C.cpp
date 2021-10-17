#include<iostream>
#include<vector>
#include<cstring>
#include<limits>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, x;
// h, idx
vector<pair<int, int>> hs;
vector<int> alloc;

void solve() {
  alloc = vector<int>(n, -1);
  // -th, tidx
  priority_queue<pair<int,int>> pq;
  for (int i=0; i<m; i++)
    pq.push({0, i});
  sort(hs.begin(), hs.end());
  for (int i=hs.size()-1; 0<=i; i--) {
    auto [bh, bidx] = hs[i];
    auto [th, tidx] = pq.top();
    th = -th;
    pq.pop();
    th += bh;
    alloc[bidx] = tidx;
    pq.push({-th, tidx});
  }
  int before = -1;
  while (!pq.empty()) {
    auto [th, tidx] = pq.top();
    th = -th;
    pq.pop();
    if (before == -1) {
      before = th;
      continue;
    }
    if (x < th - before) {
      cout << "NO" <<endl;
      return;
    }
    before = th;
  }
  cout << "YES" <<endl;
  for (int a: alloc) {
    cout << a+1 << " ";
  }
  cout << endl;
}

int main() {
  int T, tmp;
  cin >> T;
  for (int i=0; i<T; i++) {
    cin >> n >> m >> x;
    hs.resize(n);
    for (int j=0; j<n; j++) {
      cin >> tmp;
      hs[j] = {tmp, j};
    }
    solve();
  }
}
