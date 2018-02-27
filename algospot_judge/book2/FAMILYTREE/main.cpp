#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct SegmentTree
{
	int arrSize;
	vector<int> tree;
	SegmentTree(vector<int>& locArr) {
		arrSize = locArr.size();
		tree.resize(arrSize*4, 0);
		init(locArr, 0, arrSize-1, 1);
	}
	int query(int left, int right) {
		return query(left, right, 0, arrSize-1, 1);
	}
private:
	void init(vector<int>& locArr, int left, int right, int n) {
		if (left==right) {
			tree[n] = locArr[left];
			return;
		}
		int mid = (left+right)/2;
		init(locArr, left, mid, 2*n);
		init(locArr, mid+1, right, 2*n+1);
		tree[n] = tree[2*n] < tree[2*n+1] ? tree[2*n] : tree[2*n+1];
	}
	int query(int left, int right, int nodeLeft, int nodeRight, int n) {
		if (right < nodeLeft || nodeRight < left) return 10000000;
		if (left <= nodeLeft && nodeRight <= right) return tree[n];
		int nodeMid = (nodeLeft+nodeRight)/2;
		return min(query(left, right, nodeLeft, nodeMid, 2*n), query(left, right, nodeMid+1, nodeRight, 2*n+1));
	}
};


vector<int> childs[100000];
int numPerson, numCouple;
int locInArr[100001], depth[100000];
vector<int> parent;
vector<int> segArr;
SegmentTree *st;

void fillSegArr(vector<int>& segArr, vector<int> *childs, int n, int d) {
	segArr.push_back(n);
	locInArr[n] = segArr.size() - 1;
	depth[n] = d;
	if (childs[n].empty())
		return;
	for (int i=0; i<childs[n].size(); i++) {
		fillSegArr(segArr, childs, childs[n][i], d+1);
		segArr.push_back(n);
	}
}

int solve(int p1, int p2) {
	int loc;
	if (locInArr[p1] < locInArr[p2])
		loc = st->query(locInArr[p1], locInArr[p2]);
	else
		loc = st->query(locInArr[p2], locInArr[p1]);
	return depth[p1] + depth[p2] - depth[segArr[loc]]*2;
}
void init() {
	for (int i=0; i<100000; i++)
		childs[i].clear();
	for (int i=1; i<parent.size(); i++) {
		childs[parent[i]].push_back(i);
	}
	parent.clear();
	segArr.clear();
	fillSegArr(segArr, childs, 0, 0);
	vector<int> locArr(segArr.size());
	for (int i=0; i<segArr.size(); i++) {
		locArr[i] = locInArr[segArr[i]];
	}
	st = new SegmentTree(locArr);
}

int main() {
	ios_base::sync_with_stdio(false);
	int C, p1, p2;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numPerson >> numCouple;
		parent.resize(numPerson);
		parent[0] = 0;
		for (int j=1; j<numPerson; j++) {
			cin >> parent[j];
		}
		init();
		for (int j=0; j<numCouple; j++) {
			cin >> p1 >> p2;
			sols.push_back(solve(p1, p2));
		}
	}
	for (int i=0; i<sols.size(); i++) {
		cout <<sols[i] <<endl;
	}
}
