#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int t, n, x;
const string FIRST_PLAYER = "Ayush";
const string SECOND_PLAYER = "Ashish";
int adj[1001][1001];

void init() {
	memset(adj, 0, sizeof(adj));
}

void solve() {
	// x가 이미 leaf인 경우는 이김
	int x_degree = 0;
	for (int i=1; i<=n; i++)
		x_degree += (adj[x][i] == 1);
	if (x_degree <= 1) {
		cout << FIRST_PLAYER << endl;
		return;
	}

	// x를 leaf가 되게하면 짐 (x를 포함한 트리가 x중심인 3개 노드가 되게하면 이김)
	if ((n-3)%2 == 1)
		cout << FIRST_PLAYER << endl;
	else
		cout << SECOND_PLAYER << endl;

}

int main() {
	ios_base::sync_with_stdio(false);
	int u, v;
	cin >> t;
	for (int i=0; i<t; i++) {
		init();
		cin >> n >> x;
		for (int j=0; j<n-1; j++) {
			cin >> u >> v;
			adj[u][v] = 1;
			adj[v][u] = 1;
		}
		solve();
	}
}
