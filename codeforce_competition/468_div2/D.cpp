// I solved this after the contest finished.
// Start at 01:27AM March 5, 2018
// End at ~??M March 5, 2018
// Retrospection: =+ instead of +=
//2. I should have written like below. But I just wrote like "for(it = newPosCnts.begin(); it!=newPosCnts.end(); it++)"
/*
for (map<int,int>::iterator it = newPosCnts.begin(); it!=newPosCnts.end();) {
	newPosCnts[it->first] = it->second%2;
	if (newPosCnts[it->first] == 0) {
		int keyTmp = it->first;
		it++;
		newPosCnts.erase(keyTmp);
	}
	else
		it++;
}
*/
// 3. q.back() instead of q.front()
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

vector<vector<int> > adjList;

int main() {
	int n;
	cin >> n;
	adjList = vector<vector<int> >(n, vector<int>());
	int tmp;
	for (int i=1; i<n; i++) {
		cin >> tmp;
		adjList[tmp-1].push_back(i);
	}
	int sol = 0;
	// nodeNum, height
	queue<pair<int, int> >q;
	q.push(make_pair(0, 0));
	int curHeight = 0;
	int curNodeCnt = 0;
	while (!q.empty()) {
		int here, height;
		tie(here, height) = q.front();
		q.pop();
		if (height != curHeight) {
			sol += curNodeCnt%2;
			curHeight = height;
			curNodeCnt = 0;
		}
		curNodeCnt++;
		for (int i=0; i<adjList[here].size(); i++) {
			int there = adjList[here][i];
			q.push(make_pair(there, height+1));
		}
	}
	sol += curNodeCnt%2;
	cout << sol <<endl;
}
