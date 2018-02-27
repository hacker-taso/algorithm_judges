// Retrospection:
// 1. I've learned very good method to pre-calculate solution using relative size from this problem.
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int seqLen;
int seq[8];
map< vector<int>, int > dist;

int solve(int n) {
	vector< pair<int, int> > sortedIdxs;
	for (int i=0; i<n; i++) {
		sortedIdxs.push_back(pair<int, int>(seq[i], i));
	}
	sort(sortedIdxs.begin(), sortedIdxs.end());
	vector<int> regSeq;
	for (int i=0; i<n; i++) {
		regSeq.push_back(sortedIdxs[i].second);
	}
	return dist[regSeq];
}

void preCalc(int n) {
	vector<int> root;
	for (int i=0; i<n; i++) {
		root.push_back(i);
	}
	queue< vector<int> > q;
	q.push(root);
	dist[root] = 0;
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		int hereDist = dist[here];
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				reverse(here.begin()+i, here.begin()+j+1);
				if (!dist.count(here)) {
					dist[here] = hereDist+1;
					q.push(here);
				}
				reverse(here.begin()+i, here.begin()+j+1);
			}
		}
	}
}

void init() {
	for (int i=1; i<=8; i++)
		preCalc(i);
}

int main() {
	int C;
	vector<int> sols;
	cin >> C;
	init();
	for (int i=0; i<C; i++) {
		cin >> seqLen;
		for (int j=0; j<seqLen; j++) {
			cin >> seq[j];
		}
		sols.push_back(solve(seqLen));
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
