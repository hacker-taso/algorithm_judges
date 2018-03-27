// Start at 09:47PM March 26, 2018
// End at 11:39PM March 26, 2018
// Retrospection: while(q.empty()), q.pop(), node = parent[node];, second node=SINK;
// 2. I didn't think Euler circuit at first.
// 3. I didn't think the case when totalFlow == N but there's no euler circuit.
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define R 0
#define O 1
#define Y 2
#define G 3
#define B 4
#define V 5
#define SRC 0
#define SINK 1
#define INF 0x12345678
#define NUM_NODE 56
using namespace std;

int N;
int numHorses[6];
const bool possible[6][6] = {
	{0, 0, 1, 1, 1, 0}, // Red: Yellow, Green, Blue
	{0, 0, 0, 0, 1, 0}, // Orange: Blue
	{1, 0, 0, 0, 1, 1}, // Yellow: Red, Blue, Violet
	{1, 0, 0, 0, 0, 0}, // Green: Red
	{1, 1, 1, 0, 0, 0}, // Blue: Red, Orange, Yellow
	{0, 0, 1, 0, 0, 0} // Violet: Yellow
};
int flow[NUM_NODE][NUM_NODE];
int capacity[NUM_NODE][NUM_NODE];

void initCapacity() {
	memset(flow, 0, sizeof(flow));
	memset(capacity, 0, sizeof(capacity));
	// 2~7
	for (int i=0; i<6; i++)
		capacity[SRC][2+i] = numHorses[i];
	// 8~43, 44~49
	for (int i=0; i<6; i++) {
		for (int j=0; j<6; j++) {
			if (possible[i][j]) {
				capacity[2+i][8+i*6+j] = INF;
				capacity[8+i*6+j][44+j] = INF;
			} else {
				capacity[2+i][8+i*6+j] = 0;
				capacity[8+i*6+j][44+j] = 0;
			}
		}
	}
	// 44~49 -> SINK
	for (int i=0; i<6; i++)
		capacity[44+i][SINK] = numHorses[i];
}

int solveFlow() {
	int totalFlow = 0;
	while (true) {
		queue<int> q;
		q.push(SRC);
		vector<int> parent(NUM_NODE, -1);
		parent[SRC] = SRC;
		while (!q.empty() && parent[SINK] == -1) {
			int here = q.front();
			q.pop();
			if (here == SINK) break;
			for (int there=0; there<NUM_NODE; there++) {
				if (parent[there] != -1) continue;
				if (0 < capacity[here][there] - flow[here][there]) {
					parent[there] = here;
					q.push(there);
				}
			}
		}
		if (parent[SINK] == -1) break;
		int node = SINK;
		int minFlow = INF;
		while (parent[node] != node) {
			minFlow = min(minFlow, capacity[parent[node]][node] - flow[parent[node]][node]);
			node = parent[node];
		}
		node = SINK;
		while (parent[node] != node) {
			flow[parent[node]][node] += minFlow;
			flow[node][parent[node]] -= minFlow;
			node = parent[node];
		}
		totalFlow += minFlow;
	}
	return totalFlow;
}

string numToS(int n) {
	if (n == 0) return "R";
	if (n == 1) return "O";
	if (n == 2) return "Y";
	if (n == 3) return "G";
	if (n == 4) return "B";
	if (n == 5) return "V";
}

string sol;

void eulerCircuit(int curNode) {
	for (int j=0; j<6; j++) {
		while (0<flow[2+curNode][8+curNode*6+j]) {
			flow[2+curNode][8+curNode*6+j]--;
			eulerCircuit(j);
		}
	}
	sol+=numToS(curNode);
}

string solve() {
	initCapacity();
	int totalFlow = solveFlow();
	if (totalFlow < N)
		return "IMPOSSIBLE";
	sol = "";
	for (int i=0; i<6; i++) {
		for (int j=0; j<6; j++) {
			if (0<flow[2+i][8+i*6+j]) {
				eulerCircuit(i);
				sol = sol.substr(0, sol.size()-1);
				if (sol.size() < totalFlow)
					return "IMPOSSIBLE";
				return sol;
			}
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		memset(numHorses, 0, sizeof(numHorses));
		cin >> N;
		for (int j=0; j<6; j++)
			cin >> numHorses[j];
		cout << "Case #" << i+1 << ": " << solve() << endl;
	}
}
