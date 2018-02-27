#include<iostream>
#include<vector>
#include<queue>
#define INF 0x36543210
using namespace std;
// weight, dest node
vector< vector<pair<int, int> > > adjList;
int V, E;

// 0 and just one node have already added.
bool hasPath(int lo, int hi) {
	vector<bool> visited(V, 0);
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int n = q.front();
		q.pop();
		visited[n] = true;
		vector<pair<int,int> > theres = adjList[n];
		for (int i=0; i<theres.size(); i++) {
			int weight = theres[i].first;
			int there = theres[i].second;
			if (weight<lo || hi<weight || visited[there]) continue;
			q.push(there);
		}
	}
	return visited[V-1];
}

int solve() {
	int lo = 0, hi = 0;
	int sol = 1000;
	while (hi <= 1000) {
		if (hasPath(lo, hi)) {
			sol = min(sol, hi-lo);
			lo++;
		} else {
			hi++;
		}
	}
	return sol;
}

int main() {
	int C, n1, n2, speed;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> V >> E;
		adjList.clear();
		adjList.resize(V);
		for (int j=0; j<E; j++) {
			cin >> n1 >> n2 >> speed;
			adjList[n1].push_back(pair<int,int>(speed, n2));
			adjList[n2].push_back(pair<int,int>(speed, n1));
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
