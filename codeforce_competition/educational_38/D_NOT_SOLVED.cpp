// Start at Feb 17, 2018
// End at Feb 17, 2018
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, long long> > adjList[20000];
long long price[20000];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	int v, u;
	long long w;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		cin >> v >> u >> w;
		adjList[v-1].push_back(make_pair(u-1, w));
		adjList[u-1].push_back(make_pair(v-1, w));
	}
	for (int i=0; i<n; i++)
		cin >> price[i];
	for (int i=0; i<n; i++) {
		queue<int> q;
		vector<int> dist(n, -1);
		dist[i] = 0;
		q.push(i);
		while (!q.empty()) {
			int here = q.top();
			q.pop();
			for (int j=0; j<adjList[here].size(); j++) {
				if (dist[here]+adjList[here][j].second < dist[adjList[here][j].first]) {
					q.push(j);
					dist[j] = dist[here]+adjList[here][j].second;
				}
			}
		}
		int minVal = 0x1234567891234ul;
		for (int j=0; j<n; j++) {
			if (i==j) continue;

		}
	}
}
