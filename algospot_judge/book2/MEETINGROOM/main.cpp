// Retrospection(mistakes):
// 1. When I perform tarjan method, I thought I can cut this method from parent when discover[n]<=smallest.
// But the condition should be discover[n]==smallest.
// 2. I didn't print "POSSIBLE" string.
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define INF 0x76543210
using namespace std;

vector< vector<int> > adjList;
vector< pair<int, int> > meetings;
int numTeams, numMeetings, numNodes;

bool isConflicting(int m1, int m2) {
	return !(meetings[m1].second <= meetings[m2].first ||
		meetings[m2].second <= meetings[m1].first);
}

void makeGraph() {
	numNodes = numMeetings*2;
	adjList.clear();
	adjList.resize(numNodes);
	// !m(A)[0]->m(A)[1]  and  !m(A)[1]->m(A)[0]
	// m(A)[0]->!m(A)[1]  and  m(A)[1]->!m(A)[0]
	for (int t=0; t<numTeams; t++) {
		// m(A)[0] !m(A)[0] m(A)[1] !m(A)[1]
		adjList[4*t+1].push_back(4*t+2);
		adjList[4*t+3].push_back(4*t+0);
		adjList[4*t].push_back(4*t+3);
		adjList[4*t+2].push_back(4*t+1);
	}
	// A->!B  and  B->!A (if meeting A and B is conflicting)
	for (int m1=0; m1<numMeetings; m1++) {
		for (int m2=m1+1; m2<numMeetings; m2++) {
			if (isConflicting(m1, m2)) {
				adjList[m1*2].push_back(m2*2+1);
				adjList[m2*2].push_back(m1*2+1);
			}
		}
	}
}

int sccCounter, nodeCounter;
stack<int> st;
vector<int> sccLabels;
vector<int> discover;

// return: smallest discover number of backward edge's dest node
int graphIter(int n) {
	discover[n] = nodeCounter++;
	st.push(n);
	int smallest = INF;
	for (int i=0; i<adjList[n].size(); i++) {
		int there = adjList[n][i];
		if (discover[there] == -1) {
			smallest = min(smallest, graphIter(there));
		} else if (sccLabels[there] == -1) {
			smallest = min(discover[there], smallest);
		}
	}
	if (discover[n]==smallest) {
		while (true) {
			int child = st.top();
			st.pop();
			sccLabels[child] = sccCounter;
			if (child == n)
				break;
		}
		sccCounter++;
	}
	return smallest;
}

void makeSccs() {
	sccCounter = 0;
	nodeCounter = 0;
	while(!st.empty()) st.pop();
	discover.clear();
	discover.resize(numNodes, -1);
	sccLabels.clear();
	sccLabels.resize(numNodes, -1);
	for (int i=0; i<numNodes; i++) {
		if (discover[i] != -1) continue;
		graphIter(i);
	}
}

void solve() {
	makeGraph();
	makeSccs();
	for (int i=0; i<numMeetings; i++) {
		if (sccLabels[2*i] == sccLabels[2*i+1]) {
			cout << "IMPOSSIBLE" <<endl;
			return;
		}
	}
	cout << "POSSIBLE" <<endl;

	vector< pair<int, int> > sortedGraph(numNodes);
	for (int i=0; i<numNodes; i++) {
		sortedGraph[i] = pair<int, int>(-sccLabels[i], i);
	}
	sort(sortedGraph.begin(), sortedGraph.end());
	vector<int> nodeAllocs(numNodes, -1);
	vector<bool> doMeeting(numMeetings, false);
	for (int i=0; i<numNodes; i++) {
		int nodeIdx = sortedGraph[i].second;
		bool isTrueNode = nodeIdx%2 == 0;
		int meetingIdx = nodeIdx/2;
		if (nodeAllocs[nodeIdx] != -1) continue;
		// allocate this node false
		nodeAllocs[nodeIdx] = false;
		if (isTrueNode) nodeAllocs[nodeIdx+1] = true;
		else nodeAllocs[nodeIdx-1] = true;
		doMeeting[meetingIdx] = isTrueNode ? false : true;
	}
	for (int i=0; i<numTeams; i++) {
		if (doMeeting[2*i]) {
			cout << meetings[2*i].first << " " << meetings[2*i].second <<endl;
		} else {
			cout << meetings[2*i+1].first << " " << meetings[2*i+1].second <<endl;
		}
	}
}

int main() {
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numTeams;
		numMeetings = numTeams*2;
		meetings.resize(numTeams*2);
		for (int j=0; j<numTeams; j++) {
			cin >> meetings[j*2].first >> meetings[j*2].second;
			cin >> meetings[j*2+1].first >> meetings[j*2+1].second;
		}
		solve();
	}
}
