#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define NUM_ARPH 26
#define TRAIL 0
#define CIRCUIT 1
#define NONE 2
using namespace std;

int ctoi(int c) { return c-'a'; }

int numWords;
vector<string> words;
int adjMat[NUM_ARPH][NUM_ARPH];
vector<string> wordsMat[NUM_ARPH][NUM_ARPH];
vector<string> solution;

void fillGraph() {
	for (int i=0; i<NUM_ARPH; i++) {
		for (int j=0; j<NUM_ARPH; j++)
			adjMat[i][j] = 0;
	}
	for (int i=0; i<numWords; i++) {
		adjMat[ctoi(words[i][0])][ctoi(words[i][words[i].size()-1])]++;
		wordsMat[ctoi(words[i][0])][ctoi(words[i][words[i].size()-1])].push_back(words[i]);
	}
}

int checkGraph(pair<int, int>& sourceSink) {
	int sink = -1, source = -1;
	int outCnt, inCnt;
	for (int i=0; i<NUM_ARPH; i++) {
		outCnt = 0;
		inCnt = 0;
		for (int j=0; j<NUM_ARPH; j++) {
			outCnt += adjMat[i][j];
			inCnt += adjMat[j][i];
		}
		if (inCnt-outCnt !=0) {
			if (inCnt-outCnt == 1) {
				if (sink == -1)
					sink = i;
				else
					return NONE;
			} else if (outCnt-inCnt == 1) {
				if (source == -1)
					source = i;
				else
					return NONE;
			} else
				return NONE;
		}
	}
	if (sink == -1 && source == -1)
		return CIRCUIT;
	else if (sink == -1 || source == -1)
		return NONE;
	else {
		sourceSink.first = source;
		sourceSink.second = sink;
		return TRAIL;
	}
}

void findCircuitOrTrail(int node) {
	string tmp;
	for (int i=0; i<NUM_ARPH; i++) {
		while (adjMat[node][i]) {
			adjMat[node][i]--;
			tmp = wordsMat[node][i].back();
			wordsMat[node][i].pop_back();
			findCircuitOrTrail(i);
			solution.push_back(tmp);
		}
	}
}

void printResult() {
	for (int i=solution.size()-1; 0<=i; i--) {
		cout << solution[i] << " ";
	}
	cout << endl;
}

void solve() {
	solution.clear();
	fillGraph();
	pair<int, int> sourceSink;
	int checkRes = checkGraph(sourceSink);
	switch (checkRes) {
		case TRAIL:
			for (int i=0; i<NUM_ARPH; i++) {
				if (adjMat[sourceSink.first][i]) {
					adjMat[sourceSink.first][i]--;
					string tmp = wordsMat[sourceSink.first][i].back();
					wordsMat[sourceSink.first][i].pop_back();
					findCircuitOrTrail(i);
					solution.push_back(tmp);
					printResult();
					return;
				}
			}
			break;
		case CIRCUIT:
			for (int i=0; i<NUM_ARPH; i++) {
				for (int j=0; j<NUM_ARPH; j++) {
					if (adjMat[i][j]) {
						adjMat[i][j]--;
						string tmp = wordsMat[i][j].back();
						wordsMat[i][j].pop_back();
						findCircuitOrTrail(j);
						solution.push_back(tmp);
						printResult();
						return;
					}
				}
			}
		case NONE:
			cout << "IMPOSSIBLE" <<endl;
			return;
	}
}

int main() {
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numWords;
		words.resize(numWords);
		for (int j=0; j<numWords; j++) {
			cin >> words[j];
		}
		solve();
	}
}
