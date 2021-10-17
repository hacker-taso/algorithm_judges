// long long...
#include <string>
#include <iostream>
#include <vector>

using namespace std;
long long sol = 0;
vector<vector<int>> esVec;
vector<bool> visited;

// return just sum
long long sum(vector<int>& a, int u) {
  visited[u] = true;
  long long s = 0;
  bool cont = false;
  for (int i=0; i<esVec[u].size(); i++) {
    int v = esVec[u][i];
    if (visited[v])
      continue;
    cont = true;
    long long curSum = sum(a, v);
    sol += curSum < 0 ? -curSum : curSum;
    s += curSum;
  }
  return s + a[u];
}

long long solution(vector<int> a, vector<vector<int>> edges) {
  visited = vector<bool>(a.size(), false);
    esVec = vector<vector<int>>(a.size());
    for (auto edge: edges) {
      esVec[edge[0]].push_back(edge[1]);
      esVec[edge[1]].push_back(edge[0]);
    }
    long long s = 0;
    visited[0] = true;
    for (int i=0; i<esVec[0].size(); i++) {
      long long curSum = sum(a, esVec[0][i]);
      sol += curSum < 0 ? -curSum : curSum;
      s += curSum;
    }
    if (s==-a[0])
      return sol;
    return -1;
}