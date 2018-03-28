// Start at 08:20PM March 27, 2018
// End at 08:20PM March 27, 2018
// It took about 4 hours.
// Retrospection: integer overflow. INF was 0x76543210 but distance can be bigger value.
#include<iostream>
#include<queue>
#include<cstring>
#include<tuple>
#include<iomanip>
#define INF 0x76543210000ul
using namespace std;

int numHorse, numQuery;
int ponyDist[100], ponySpeed[100];
int adjMat[100][100];
int u, k;
double sol[100];
// from i to j minimum.
double minTime[100][100];
// pony i, from i to j.
double onePonyTime[100][100];
double solve() {
	return minTime[u][k];
}

void init() {
	for (int i=0; i<numHorse; i++)
		for (int j=0; j<numHorse; j++)
			if (i == j) onePonyTime[i][i] = 0;
			else onePonyTime[i][j] = INF;
	for (int k=0; k<numHorse; k++) {
		// time, pair(here, dist)
		double onePonyTimeTmp[100][100];
		for (int i=0; i<numHorse; i++)
			for (int j=0; j<numHorse; j++)
				if (i == j) onePonyTimeTmp[k][k] = 0;
				else onePonyTimeTmp[i][j] = INF;
		priority_queue<tuple<double, int, long long>, vector<tuple<double, int, long long > >, greater<tuple<double, int, long long> > > q;
		q.push(make_tuple(0, k, 0));
		while (!q.empty()) {
			double t;int here; long long dist;
			tie(t, here, dist)= q.top();
			q.pop();
			if (onePonyTimeTmp[k][here] < t) continue;
			for (int there=0; there<numHorse; there++) {
				if (adjMat[here][there] == -1) continue;
				if (ponyDist[k] < dist+adjMat[here][there]) continue;
				if (t+(double)adjMat[here][there]/ponySpeed[k] < onePonyTimeTmp[k][there]) {
					onePonyTimeTmp[k][there] = t+(double)adjMat[here][there]/ponySpeed[k];
					q.push(make_tuple(onePonyTimeTmp[k][there], there, dist+adjMat[here][there]));
				}
			}
		}
		for (int j=0; j<numHorse; j++)
			onePonyTime[k][j] = onePonyTimeTmp[k][j];
	}
	for (int i=0; i<numHorse; i++)
		for (int j=0; j<numHorse; j++)
			minTime[i][j] = onePonyTime[i][j];
	for (int k=0; k<numHorse; k++) {
		for (int i=0; i<numHorse; i++) {
			for (int j=0; j<numHorse; j++) {
				minTime[i][j] = min(minTime[i][j], minTime[i][k] + minTime[k][j]);
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> numHorse >> numQuery;
		for (int j=0; j<numHorse; j++)
			cin >> ponyDist[j] >> ponySpeed[j];
		for (int j=0; j<numHorse; j++) {
			for (int k=0; k<numHorse; k++)
				cin >> adjMat[j][k];
		}
		init();
		for (int j=0; j<numQuery; j++) {
			cin >> u >> k;
			u--;
			k--;
			sol[j] = solve();
		}
		cout << "Case #" << i+1 << ":";
		for (int j=0; j<numQuery; j++)
			cout << " " << fixed << setprecision(9) << sol[j];
		cout << endl;
	}
}
