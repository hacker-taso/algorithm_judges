// I've read the editorial: https://codeforces.com/blog/entry/90236
// mistake: 1. not do vi=ds.find(vi) before using vi
// 2. did "list l = l2;". This copies l2 to l1.
// I failed to debug this code.
#include<iostream>
#include<vector>
#include<cstring>
#include<limits>
#include<list>
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
// w, i, v1, v2
struct node {
  long long a;
  int i;
};
struct edge {
  int ei, vi;
};
vector<list<edge>*> adj;

struct greater_than {
  bool inline operator() (const node& n, const node& n2) {
    return n.a < n2.a;
  }
};

void solve() {
  DisjointSet ds(n);
  priority_queue<node, vector<node>, greater_than> pq;
  long long sum = 0;
  for (int i=0; i<n; i++){
    sum += as[i];
    pq.push({as[i], i});
  }
  if (sum < (long long)x*(n-1)) {
    cout << "NO" << endl;
    return;
  }
  vector<int> sol;
  while (!pq.empty()) {
    auto [a, vi] = pq.top();
    vi = ds.find(vi);
    pq.pop();
    while (!adj[vi]->empty()) {
      auto [ei, vi2] = adj[vi]->back();
      vi2 = ds.find(vi2);
      adj[vi]->pop_back();
      if (vi != vi2) {
        long long na = as[vi]+as[vi2]-x;
        if (na < 0)
          continue;
        ds.merge(vi, vi2);
        adj[vi]->splice(adj[vi]->end(), *adj[vi2]);
        adj[ds.find(vi)] = adj[vi];
        vi = ds.find(vi);
        as[vi] = na;
        pq.push({na, vi});
        sol.push_back(ei);
        break;
      }
    }
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
  adj = vector<list<edge>*>(n, 0);
  for (int j=0; j<m; j++) {
    cin >> v1 >> v2;
    if (adj[v1-1] == 0)
      adj[v1-1] = new list<edge>();
    if (adj[v2-1] == 0)
      adj[v2-1] = new list<edge>();
    adj[v1-1]->push_back({j+1, v2-1});
    adj[v2-1]->push_back({j+1, v1-1});
  }
  solve();
}
