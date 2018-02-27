#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
#include<iomanip>
using namespace std;

int V, E;
vector< vector< pair<int, double> > > adjList;

//return noise (not in log form)
double solve() {
	double hereDist, edgeDist;
	int hereNode, thereNode;
	pair<double, int> here;
	pair<int, double> there;
	vector<double> dist(V, INFINITY);
	dist[0] = 0;
	priority_queue< pair<double, int> > q;
	q.push(pair<double, int>(0, 0));
	while(!q.empty()) {
		here = q.top();
		q.pop();
		hereDist = -here.first;
		hereNode = here.second;
		if (dist[hereNode] < hereDist) continue; // already checked with smaller or same dist
		for (int i=0; i<adjList[hereNode].size(); i++) {
			there = adjList[hereNode][i];
			edgeDist = there.second;
			thereNode = there.first;
			if (hereDist+edgeDist < dist[thereNode]) {
				dist[thereNode] = hereDist+edgeDist;
				q.push(pair<double, int>(-(hereDist+edgeDist), thereNode));
			}
		}
	}
	return exp(dist[V-1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	int C, n1, n2;
	double weight;
	vector<double> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> V >> E;
		adjList.clear();
		adjList.resize(V);
		for (int j=0; j<E; j++) {
			cin >> n1 >> n2 >> weight;
			adjList[n1].push_back(pair<int, double>(n2, log(weight)));
			adjList[n2].push_back(pair<int, double>(n1, log(weight)));
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << fixed << setprecision(10) <<sols[i]<<endl;
	}
}
