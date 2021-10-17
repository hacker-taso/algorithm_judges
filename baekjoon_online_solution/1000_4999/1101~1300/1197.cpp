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
struct disjointSet {
  vector<int> v;
  vector<int> rank;
  disjointSet(int size=0): v(vector<int>(size)), rank(vector<int>(size)) {
    for (int i=0; i<size; i++) {
      v[i] = i;
      rank[i] = 1;
    }
  }
  int find(int n) {
    if (n==v[n]) return n;
    int r = find(v[n]);
    if (r!=n) v[n] = r;
    return r;
  }
  void merge(int n1, int n2) {
    int r1 = find(n1);
    int r2 = find(n2);
    if (r1 == r2) return;
    if (rank[r1] == rank[r2]) {
      v[r1] = v[r2];
      rank[r2]++;
    } else if (rank[r1] < rank[r2]) {
      v[r1] = v[r2];
    } else {
      v[r2] = v[r1];
    }
  }
};

struct edge {
  int w, v1, v2;
};
int V, E;
vector<edge> es;
void init() {
  es.clear();
  int v1, v2, w;
  cin >> V >> E;
  for (int i=0; i<E; i++) {
    cin >> v1 >> v2 >> w;
    es.push_back({w, v1, v2});
  }
}

struct e_comp {
  bool operator() (edge e1, edge e2) {
    return e1.w > e2.w;
  }
};

int solve() {
  int sol = 0;
  disjointSet ds(V+1);
  priority_queue<edge, vector<edge>, e_comp> pq;
  for (int i=0; i<E; i++)
    pq.push(es[i]);
  while(!pq.empty()) {
    auto [w, v1, v2] = pq.top();
    pq.pop();
    if (ds.find(v1) == ds.find(v2)) continue;
    sol += w;
    ds.merge(v1, v2);
  }
  return sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  init();
  cout << solve() << endl;
}
