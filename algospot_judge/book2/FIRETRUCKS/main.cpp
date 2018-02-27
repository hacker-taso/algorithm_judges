#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define INF INT_MAX
using namespace std;

int V, E, numFired, numStation;
// weight, nodeNum
vector< vector< pair<int, int> > > adjList;
vector<int> fired;
vector<int> stations;

int solve() {
	vector<int> dist(V, INF);
	// -dist, node idx
	priority_queue<pair<int, int> > q;
	for (int i=0; i<stations.size(); i++) {
		int station = stations[i];
		dist[station] = 0;
		q.push(pair<int, int>(0, station));
	}
	while (!q.empty()) {
		pair<int,int> herePair = q.top();
		q.pop();
		int hereDist = -herePair.first;
		int here = herePair.second;
		if (dist[here] < hereDist) continue;
		for (int i=0; i<adjList[here].size(); i++) {
			pair<int,int> therePair = adjList[here][i];
			int edgeWeight = therePair.first;
			int there = therePair.second;
			if (dist[here]+edgeWeight < dist[there]) {
				dist[there] = dist[here]+edgeWeight;
				q.push(pair<int, int>(dist[here]+edgeWeight, there));
			}
		}
	}
	int distSum = 0;
	for (int i=0; i<fired.size(); i++) {
		distSum+=dist[fired[i]];
	}
	return distSum;
}

int main() {
	ios_base::sync_with_stdio(false);
	int C, n1, n2;
	int weight;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> V >> E >> numFired >>numStation;
		adjList.clear();
		adjList.resize(V);
		for (int j=0; j<E; j++) {
			cin >> n1 >> n2 >> weight;
			adjList[n1-1].push_back(pair<int, int>(weight, n2-1));
			adjList[n2-1].push_back(pair<int, int>(weight, n1-1));
		}
		fired.clear();
		fired.resize(numFired);
		for (int j=0; j<numFired; j++) {
			cin >> fired[j];
			fired[j]--;
		}
		stations.clear();
		stations.resize(numStation);
		for (int j=0; j<numStation; j++) {
			cin >> stations[j];
			stations[j]--;
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
