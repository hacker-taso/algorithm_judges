// Retrospection long after writing this code:
// 1. I used a set data structure called "pre" to check cycle during topological sort.
// If visit a vertex which exists in "pre", then there should be a cycle.
// But JongMan book uses an approach that first, perform topological sort and then check existence of back edge.
// 2. I used adjacency list to express graph but JongMan book uses adjacency graph. I think both are fine.
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
#define NUM_CHAR 26
using namespace std;

vector<string> words;
int numWords;
vector<int> graph[NUM_CHAR];
vector<char> revOrder;
bool visited[26];

int ctoi(char c) { return c-'a';}
char itoc(int i) { return static_cast<char>(i+'a'); }

void initGraph() {
	int graphArr[NUM_CHAR][NUM_CHAR] = {0};
	for (int i=1; i<words.size(); i++) {
		int numIter = min(words[i-1].size(),words[i].size());
		for (int j=0; j<numIter; j++) {
			if (words[i-1][j] != words[i][j]) {
				graphArr[ctoi(words[i-1][j])][ctoi(words[i][j])] = 1;
				break;
			}
		}
	}

	for (char i=0; i<NUM_CHAR; i++)
		graph[i].clear();
	for (char i=0; i<NUM_CHAR; i++) {
		for (char j=0; j<NUM_CHAR; j++) {
			if (graphArr[i][j])
				graph[i].push_back(j);
		}
	}
}

bool topologicalSort(char c, set<int>& pre) {
	if (find(pre.begin(), pre.end(), c) != pre.end())
		return false;
	pre.insert(c);
	for (char i=0; i<graph[c].size(); i++) {
		if (!visited[graph[c][i]])
			if (!topologicalSort(graph[c][i], pre))
				return false;
	}
	visited[c] = 1;
	revOrder.push_back(itoc(c));
	return true;
}

void solve() {
	initGraph();
	memset(visited, 0, sizeof(visited));
	revOrder.clear();
	set<int> pre;
	for (char i=0; i<NUM_CHAR; i++) {
		if (!(graph[i].empty() || visited[i])) {
			pre.clear();
			if (!topologicalSort(i, pre)) {
				cout << "INVALID HYPOTHESIS" <<endl;
				return;
			}
		}
	}
	reverse(revOrder.begin(), revOrder.end());
	for (int i=0; i<revOrder.size(); i++)
		cout << revOrder[i];
	for (char i=0; i<NUM_CHAR; i++)
		if (!visited[i])
			cout << itoc(i);
	cout <<endl;
}

int main() {
	int C;
	cin>>C;
	for (int i=0; i<C; i++) {
		cin >> numWords;
		words.resize(numWords);
		for (int j=0; j<numWords; j++) {
			cin >> words[j];
		}
		solve();
	}
}
