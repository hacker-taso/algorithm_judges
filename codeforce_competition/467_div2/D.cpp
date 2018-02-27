// Start at 02:37AM Feb 26, 2018
// End at 00:05AM Feb 26, 2018
#include<iostream>
using namespace std;

int V, E, s;
vector<vector<int> > adjList;
vector<bool> seen;
vector<int> order;
void dfs(int here) {
	seen[here] = true;
	for (int there = 0; there < adjList[here].size(); there++) {
		if (!seen[adjList[here][there]]) {
			dfs(adjList[here][there]);
		}
	}
	order.push_back(here);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> V >> E;
	seen = vector<bool>(V, false);
	int numE;
	adjList = vector<vector<int> >(V);
	for (int i=0; i<V; i++) {
		cin >> numE;
		adjList[i] = vector<int>(numE);
		for (int j=0; j<numE; j++)
			cin >> adjList[i][j];
	}
	cin >> s;
	s = s-1;
	dfs(s-1);
	reverse(order.begin(), order.end());
	
}
