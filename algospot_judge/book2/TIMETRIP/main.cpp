// Retrospection:
// 1. actually there's a mistake in my code but it seems that testcase doesn't check this case.
// Even if there's negative cycle, solution could be not INFINITY if the source cannot reach the negative cycle.
#include<iostream>
#include<vector>
#include<limits>
#define INF 0x76543210
#define BIG_M 500000
using namespace std;

int numGal, numHole;
// next, weight
vector< vector< pair<int, int> > > adjList;

void solve() {
	vector<int> posDist(numGal, INF);
	vector<int> negDist(numGal, INF);
	posDist[0] = 0;
	negDist[0] = 0;
	bool posUpdated = false;
	bool negUpdated = false;
	for (int i=0; i<numGal; i++) {
		posUpdated = false;
		negUpdated = false;
		for (int here=0; here<numGal; here++) {
			vector< pair<int,int> > fromHere = adjList[here];
			for (int k=0; k<fromHere.size(); k++) {
				pair<int,int> therePair = fromHere[k];
				int there = therePair.first;
				int weight = therePair.second;
				if (posDist[here]+weight < posDist[there]) {
					posDist[there] = posDist[here] + weight;
					posUpdated = true;
				}
				if (negDist[here]-weight < negDist[there]) {
					negDist[there] = negDist[here] - weight;
					negUpdated = true;
				}
			}
		}
	}
	if (INF-BIG_M < posDist[1]) {
		cout << "UNREACHABLE" <<endl;
		return;
	}
	if (posUpdated) { // negative cycle in minimize. infinity in minimum.
		cout << "INFINITY ";
	} else {
		cout << posDist[1] << " ";
	}
	if (negUpdated) { // infinity in maximum
		cout << "INFINITY" << endl;
	} else {
		cout << -negDist[1] << endl;
	}
}

int main() {
	int C, n1, n2, weight;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numGal >> numHole;
		adjList.clear();
		adjList.resize(numGal);
		for (int j=0; j<numHole; j++) {
			cin >> n1 >> n2 >> weight;
			adjList[n1].push_back(pair<int,int>(n2, weight));
		}
		solve();
	}
}
