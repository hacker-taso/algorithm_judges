#include<iostream>
#include<vector>
#include<limits>
#include<queue>
#define INF (numeric_limits<int>::max()-10)
using namespace std;

int nodeToDiff(int n) { return n-200; }
int diffToNode(int d) { return d+200; }
int sgn(int n) {
	if (n==0) return 0;
	else if(n<0) return -1;
	else return 1;
}

// weight(A's reqTime), node(express 200+A-B with smallest A)
vector< pair<int, int> > edges;
int numGame;

int solve() {
	vector<int> dist(400, INF);
	// -dist, node
	priority_queue< pair<int,int> > q;
	q.push( pair<int,int>(0, diffToNode(0)) );
	while(!q.empty()) {
		pair<int,int> herePair = q.top();
		q.pop();
		int hereDist = -herePair.first;
		int hereNode = herePair.second;
		int hereDiff = nodeToDiff(hereNode);
		if (dist[hereNode] < hereDist) continue;
		for (int i=0; i<edges.size(); i++) {
			int edgeWeight = edges[i].first;
			int thereNode = edges[i].second;
			int thereDiff = nodeToDiff(thereNode);
			if (sgn(hereDiff)==sgn(thereDiff)) continue;
			int nextNode = diffToNode(hereDiff+thereDiff);
			if (hereDist+edgeWeight<dist[nextNode]) {
				dist[nextNode] = hereDist+edgeWeight;
				q.push(pair<int,int>(-dist[nextNode], nextNode));
			}
		}
	}
	return dist[diffToNode(0)];
}

int main() {
	int C, aTime, bTime;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		vector<int> edgeIdxs(400, -1);
		cin >> numGame;
		edges.clear();
		for (int j=0; j<numGame; j++) {
			cin >> aTime >> bTime;
			int node = diffToNode(aTime-bTime);
			if (edgeIdxs[node] == -1) {
				edges.push_back(pair<int, int>(aTime, node));
				edgeIdxs[node] = edges.size()-1;
			} else {
				if (aTime < edges[edgeIdxs[node]].first)
					edges[edgeIdxs[node]] = pair<int, int>(aTime, node);
			}
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		if (sols[i] == INF)
			cout << "IMPOSSIBLE" <<endl;
		else
			cout << sols[i] <<endl;
	}
}
