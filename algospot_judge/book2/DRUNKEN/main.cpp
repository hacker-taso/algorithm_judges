#include<iostream>
#include<vector>
#include<algorithm>
#define INF 0x16543210
using namespace std;

int V, E;
vector<int> inspDelay;
vector< vector<int> > adjMat;
vector< vector<int> > W;

void floyd() {
	vector< pair<int,int> > sortedDelay(inspDelay.size());
	for (int i=0; i<inspDelay.size(); i++)
		sortedDelay[i] = pair<int,int>(inspDelay[i], i);
	sort(sortedDelay.begin(), sortedDelay.end());
	for (int v=0; v<V; v++) {
		int k = sortedDelay[v].second;
		for (int i=0; i<V; i++) {
			for (int j=0; j<V; j++) {
				adjMat[i][j] = min(adjMat[i][k]+adjMat[k][j], adjMat[i][j]);
				W[i][j] = min(adjMat[i][k]+adjMat[k][j]+inspDelay[k], W[i][j]);
			}
		}
	}
}

int solve(int n1, int n2) {
	return W[n1][n2];
}

int main() {
	int n1, n2, weight;
	cin >> V >> E;
	inspDelay.resize(V);
	for (int i=0; i<V; i++)
		cin >> inspDelay[i];
	adjMat.resize(V, vector<int>(V, INF));
	for (int i=0; i<V; i++) {
		adjMat[i][i] = 0;
	}
	for (int i=0; i<E; i++) {
		cin >> n1 >> n2 >> weight;
		adjMat[n1-1][n2-1] = weight;
		adjMat[n2-1][n1-1] = weight;
	}
	W=adjMat;
	floyd();
	int T;
	vector<int> sols;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> n1 >>n2;
		sols.push_back(solve(n1-1, n2-1));
	}
	for (int i=0; i<T; i++) {
		cout << sols[i] <<endl;
	}
}
