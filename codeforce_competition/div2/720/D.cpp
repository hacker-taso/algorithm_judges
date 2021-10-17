#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<limits>
#include<iomanip>
#include<numeric>
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int n;
vector<vector<int>> adj;
vector<pair<int,int>> removed;
void init() {
  int tmp, tmp2;
  cin >> n;
  removed.clear();
  adj = vector<vector<int>>(n);
  for (int i=0; i<n-1; i++) {
    cin >> tmp >> tmp2;
    if (adj[tmp-1].size() == 2 || adj[tmp2-1].size() == 2) {
      removed.push_back({tmp, tmp2});
    } else {
      adj[tmp-1].push_back(tmp2-1);
      adj[tmp2-1].push_back(tmp-1);
    }
  }
}

void solve() {
  vector<int> added;
  int d1node = -1;
  for (int i=0; i<adj.size(); i++) {
    if (adj[i].size() == 1)
      d1node = i;
    if (adj[i].size() == 0)
      added.push_back(i);
  }
  cout << removed.size() <<endl;
  for (int i=0; i<removed.size(); i++) {
    cout << removed[i].first << " " << removed[i].second << " " << d1node+1 << " " << added[i]+1 << endl;
    d1node = added[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i=1; i<=T; i++) {
    init();
    solve();
  }
}
