// I've read the editorial.
// I thought too complicatedly.
// I thought I should solve this problem by solving finding a longest simple path in the graph.
// But I think it would be very difficult problem.
#include <iostream>
#include <vector>
#include <algorithm>
#include<numeric>

using namespace std;
vector<vector<int> > adjList;

vector<bool> visited;

void dfs(int here) {
    if (visited[here]) return;
    visited[here] = true;
    for (unsigned i=0; i<adjList[here].size(); i++) {
        int there = adjList[here][i];
        if (visited[there]) continue;
        dfs(there);
        cout << here+1 << " " << there+1 << endl;
    }
}

int main() {
    int N, tmp;
    cin >> N;
    adjList = vector<vector<int> >(N, vector<int>());
    visited = vector<bool>(N, 0);
    vector<bool> pointed(N, 0);
    for (int i=0; i<N; i++) {
        cin>> tmp;
        adjList[i].push_back(tmp-1);
        pointed[tmp-1] = 1;
    }
    vector<int> sources(N); iota(sources.begin(), sources.end(), 0);
    auto last = partition(sources.begin(), sources.end(), [&](int i) {
        return !pointed[i];
    });
    for_each(sources.begin(), last, [&](int source) {
        dfs(source);
    });
    return 0;
}