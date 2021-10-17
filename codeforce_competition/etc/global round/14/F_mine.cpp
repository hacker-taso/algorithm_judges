// my version after the contest ends.
#include<iostream>
#include<vector>
#include<cstring>
#include<limits>
#include<algorithm>
#include<queue>
using namespace std;
struct DisjointSet {
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n): parent(n), rank(n, 1) {
        for (int i=0; i<n; i++) parent[i] = i;
    }
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rank[v] < rank[u]) swap(u, v);
        parent[u] = v;
        if (rank[u] == rank[v]) rank[v]++;
    }
};
int n, m, x;
vector<long long> as;
vector<long long> ADD;
// w, i, v1, v2
vector<vector<int>> edges;
 
void solve() {
  DisjointSet ds(n);
  vector<int> sol;
  priority_queue<vector<int>> pq;
  for (vector<int> e: edges) {
    pq.push(e);
  }
  while (!pq.empty()) {
    vector<int> e = pq.top();
    pq.pop();
    if (ds.find(e[2]) == ds.find(e[3]))
      continue;
    int v1 = ds.find(e[2]);
    int v2 = ds.find(e[3]);
    int w = as[v1] + ADD[v1] + as[v2] + ADD[v2];
    if (w < x) {
      continue;
    }
    sol.push_back(e[1]);
    ds.merge(v1, v2);
    ADD[];
    as[ds.find(v1)] = w-x;
  }
  if (sol.size() != n-1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" <<endl;
  for (int s: sol) {
    cout << s << endl;
  }
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >>x;
  as.resize(n);
  for (int j=0; j<n; j++) {
    cin >> as[j];
  }
  int v1, v2;
  edges.resize(m);
  ADD = vector<long long>(n);
  for (int j=0; j<m; j++) {
    cin >> v1 >> v2;
    int w = as[v1-1] + as[v2-1];
    edges[j] = {w, j+1, v1-1, v2-1};
  }
  solve();
}