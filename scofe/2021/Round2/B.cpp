#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;
int kruskal(vector<pair<int,int> >& selected);
int V, E;
vector<pair<int, int> > adjList[20000];
int main() {
    string s, t;
    int w;
    unordered_map<string, int> um;
    cin >> E;
    int cnt = 0;
    for (int i=0; i<E; i++) {
        cin >> s >> t >> w;
        if (um.find(s) == um.end())
            um.insert({s, cnt++});
        if (um.find(t) == um.end())
            um.insert({t, cnt++});
        int si = um.find(s)->second;
        int ti = um.find(t)->second;
        adjList[si].push_back({ti, w});
        adjList[ti].push_back({si, w});
    }
    V = cnt;
    vector<pair<int,int>> selected;
    int sol = kruskal(selected);
    cout << sol <<endl;
    return 0;
}

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


int kruskal(vector<pair<int,int> >& selected) {
    vector<pair<int, pair<int, int> > > edges;
    for (int u=0; u<V; u++) {
        for (int i=0; i<adjList[u].size(); i++) {
            int v=adjList[u][i].first;
            int w=adjList[u][i].second;
            edges.push_back(make_pair(w, make_pair(u, v)));
        }
    }
    sort(edges.begin(), edges.end());
    DisjointSet ds(V);
    int totalCost = 0;
    for (int i=0; i<edges.size(); i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;
            
        if (ds.find(u) == ds.find(v)) continue;
        selected.push_back(make_pair(u, v));
        ds.merge(u, v);
        totalCost += w;
    }
    return totalCost;
}