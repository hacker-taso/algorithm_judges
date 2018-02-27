#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int numPlayers, numEvents;
vector<int> alreadyWins;
vector< pair<int,int> > events;
vector< vector<int> > capacity;
vector< vector<int> > flow;
int totalFlow = 0;

int networkFlow(int s, int t) {
	int numNodes = capacity.size();
	while (true) {
		vector<bool> visited(numNodes, false);
		vector<int> parent(numNodes, -1);
		visited[0] = true;
		parent[0] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int n = q.front();
			q.pop();
			for (int i=0; i<numNodes; i++) {
				if (visited[i] || capacity[n][i]-flow[n][i] == 0) continue;
				q.push(i);
				visited[i] = true;
				parent[i] = n;
			}
		}
		if (!visited[t]) break;
		int n = t;
		while (parent[n] != n) {
			flow[parent[n]][n]++;
			flow[n][parent[n]]--;
			n = parent[n];
		}
		totalFlow++;
	}
	return totalFlow;
}

bool canWinWith(int totalWin) {
	if (totalWin<=*max_element(alreadyWins.begin()+1, alreadyWins.end()))
		return false;
	for (int i=0; i<numPlayers; i++) {
		int maxWin = (i==0?totalWin:totalWin-1);
		capacity[2+numEvents+i][1] = max(0, maxWin-alreadyWins[i]);
	}
	bool goodEnd = networkFlow(0, 1) == numEvents;
	return goodEnd && flow[2+numEvents][1] == capacity[2+numEvents][1];
}

int solve() {
	totalFlow=0;
	capacity.clear();
	capacity.resize(2+numPlayers+numEvents, vector<int>(2+numPlayers+numEvents, 0));
	flow.clear();
	flow.resize(2+numPlayers+numEvents, vector<int>(2+numPlayers+numEvents, 0));
	for (int i=0; i<numEvents; i++) {
		capacity[0][2+i] = 1;
		capacity[2+i][2+numEvents+events[i].first] = 1;
		capacity[2+i][2+numEvents+events[i].second] = 1;
	}
	for (int i=alreadyWins[0]; i<=alreadyWins[0]+numEvents; i++) {
		if (canWinWith(i))
			return i;
	}
	return -1;
}

int main() {
	int C;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numPlayers >> numEvents;
		alreadyWins.clear();
		alreadyWins.resize(numPlayers);
		for (int j=0; j<numPlayers; j++) {
			cin >> alreadyWins[j];
		}
		events.clear();
		events.resize(numEvents);
		for (int j=0; j<numEvents; j++) {
			cin >> events[j].first >> events[j].second;
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++)
		cout << sols[i] << endl;
}
