// Retrospection:
// We can solve this by setting weight of edges already made to 0.
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<iomanip>
#define INF 0x26543210
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
	void findSameSet(int n, vector<int>& sames) {
		for (int i=0; i<v.size(); i++) {
			if (find(n) == find(i))
				sames.push_back(i);
		}
	}
};

int X[500], Y[500];
int numBuilding;
double dist[500][500];
disjointSet ds;

double solve() {
	int numAdded = 0;
	bool added[500];
	memset(added, 0, sizeof(added));
	// dist from tree, from node(in tree), to node(outside tree)
	pair<double, pair<int,int> > minWeight[500];
	for (int i=0; i<numBuilding; i++)
		minWeight[i] = pair<double, pair<int,int> >(INF, pair<int,int>(INF,INF));
	vector<int> allAdded;
	ds.findSameSet(0, allAdded);
	for (int i=0; i<allAdded.size(); i++) {
		added[allAdded[i]] = true;
		numAdded++;
	}
	for (int i=0; i<allAdded.size(); i++) {
		int node = allAdded[i];
		for (int j=0; j<numBuilding; j++) {
			if (added[j]) continue;
			if (dist[node][j] < minWeight[j].first) {
				minWeight[j] = pair<double, pair<int,int> >(dist[node][j], pair<int,int>(node,j));
			}
		}
	}
	double totalDist = 0;
	while (true) {
		if (numBuilding<=numAdded)
			break;
		pair<double,pair<int,int> > herePair = pair<double,pair<int,int> >(INF, pair<int,int>(INF, INF));
		for (int i=0; i<numBuilding; i++) {
			if (!added[i] && minWeight[i].first<herePair.first) {
				herePair = minWeight[i];
			}
		}
		totalDist += herePair.first;
		int n = herePair.second.second;
		allAdded.clear();
		ds.findSameSet(n, allAdded);
		for (int i=0; i<allAdded.size(); i++) {
			added[allAdded[i]] = true;
			numAdded++;
		}
		for (int i=0; i<allAdded.size(); i++) {
			int newNode = allAdded[i];
			for (int j=0; j<numBuilding; j++) {
				if (added[j]) continue;
				if (dist[newNode][j] < minWeight[j].first)
					minWeight[j] = pair<double, pair<int,int> >(dist[newNode][j], pair<int,int>(newNode,j));
			}
		}
	}
	return totalDist;
}

void caseAfterInit() {
	for (int i=0; i<numBuilding; i++) {
		for (int j=i; j<numBuilding; j++) {
			if (i==j)
				dist[i][j] = 0;
			else {
				dist[i][j] = hypot(X[i]-X[j],Y[i]-Y[j]);
				dist[j][i] = dist[i][j];
			}
		}
	}
}

int main() {
	int C, numAlreadyAdded, n1, n2;
	vector<double> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numBuilding >> numAlreadyAdded;
		ds = disjointSet(numBuilding);
		for (int j=0; j<numBuilding; j++)
			cin >> X[j];
		for (int j=0; j<numBuilding; j++)
			cin >> Y[j];
		for (int j=0; j<numAlreadyAdded; j++) {
			cin >> n1 >> n2;
			ds.merge(n1, n2);
		}
		caseAfterInit();
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << fixed << setprecision(10)<< sols[i] <<endl;
	}
}
