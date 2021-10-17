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
using namespace std;
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int V;
struct edge {
  int v2, w;
};
vector<vector<edge>> adj;
void init() {
  cin >> V;
  adj.resize(V);
  int tmp, tmp2, n;
  for (int i=0; i<V; i++) {
    cin >> n;
    adj[n-1].clear();
    while (true) {
      cin >> tmp;
      if (tmp == -1) break;
      cin >> tmp2;
      adj[n-1].push_back({tmp-1, tmp2});
    }
  }
}

int sol;
int dfs(int parent, int idx, int untilw) {
  int maxdist = 0;
  int top2[2] = {untilw, 0};
  for (int i=0; i<adj[idx].size(); i++) {
    auto [nv, w] = adj[idx][i];
    if (nv == parent) continue;
    int curdist = w + dfs(idx, nv, w+untilw);
    maxdist = max(curdist, maxdist);
    if (top2[0] < curdist) {
      top2[1] = top2[0];
      top2[0] = curdist;
    } else if (top2[1] < curdist)
      top2[1] = curdist;
  }
  sol = max(sol, top2[0] + top2[1]);
  return maxdist;
}

void solve() {
  sol = 0;
  dfs(-1, 0, 0);
  cout << sol << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  solve();
}
