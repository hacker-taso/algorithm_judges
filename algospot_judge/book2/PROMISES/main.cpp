#include<iostream>
#include<vector>
#define INF 0x26543210
using namespace std;

int numExisting, numWillBuild, V;
vector< vector<int> > existing;
vector< pair<int,int> > willBuildD;
vector<int> willBuildW;

void floyd() {
	for (int k=0; k<V; k++) {
		for (int i=0; i<V; i++) {
			for (int j=0; j<V; j++) {
				existing[i][j] = min(existing[i][j], existing[i][k]+existing[k][j]);
			}
		}
	}
}

bool tryUpdate(int n1, int n2, int weight) {
	bool updated = false;
	if (existing[n1][n2]<=weight) return false;
	for (int i=0; i<V; i++) {
		for (int j=0; j<V; j++) {
			if (existing[i][n1] + weight + existing[n2][j] < existing[i][j]) {
				existing[i][j] = existing[i][n1] +weight + existing[n2][j];
				updated = true;
			}
			if (existing[i][n2] + weight + existing[n1][j] < existing[i][j]) {
				existing[i][j] = existing[i][n2] +weight + existing[n1][j];
				updated = true;
			}
		}
	}
	return updated;
}

int solve() {
	int useless = 0;
	floyd();
	for (int i=0; i<willBuildD.size(); i++) {
		pair<int,int> nPair = willBuildD[i];
		int weight = willBuildW[i];
		if (!tryUpdate(nPair.first, nPair.second, weight)) {
			useless++;
		}
	}
	return useless;
}

int main() {
	int C, n1, n2, weight;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> V >> numExisting >> numWillBuild;
		existing.clear();
		existing.resize(V, vector<int>(V, INF));
		for (int j=0; j<V; j++)
			existing[j][j] = 0;
		for (int j=0; j<numExisting; j++) {
			cin >> n1 >> n2 >> weight;
			existing[n1][n2] = min(weight, existing[n1][n2]);
			existing[n2][n1] = min(weight, existing[n2][n1]);
		}
		willBuildD.clear();
		willBuildD.resize(numWillBuild);
		willBuildW.clear();
		willBuildW.resize(numWillBuild);
		for (int j=0; j<numWillBuild; j++) {
			cin >> n1 >> n2 >> weight;
			willBuildD[j] = pair<int,int>(n1, n2);
			willBuildW[j] = weight;
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
