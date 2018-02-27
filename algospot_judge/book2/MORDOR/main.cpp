// Retrospection long after writing this code:
// 1. operator () (int a, int b). (*obj)(a,b);
// 2. virtual func() = 0; in base.
// 3. class derived: public base {}
#include<iostream>
#include<vector>
#include<limits>
using namespace std;

class Most {
public:
	virtual int operator () (int a, int b) = 0;
};

class Max: public Most {
public:
	int operator () (int a, int b) {
		return max(a, b);
	}
};

class Min: public Most {
public:
	int operator () (int a, int b) {
		return min(a, b);
	}
};

struct SegmentTree {
	int arrLen;
	vector<int> tree;
	Most * op;
	int INF;

	SegmentTree() {}

	SegmentTree(const vector<int>& arr, Most* _op, int _INF) {
		op = _op;
		INF = _INF;
		arrLen = arr.size();
		tree.resize(arrLen*4, 0);
		init(1, 0, arrLen-1, arr);
	}
	int query(int left, int right) {
		return query(left, right, 0, arrLen-1, 1);
	}
private:
	void init(int node, int left, int right, const vector<int>& arr) {
		if (left == right) {
			tree[node] = arr[left];
			return;
		}
		int mid = (left+right)/2;
		init(node*2, left, mid, arr);
		init(node*2+1, mid+1, right, arr);
		tree[node] = (*op)(tree[node*2],tree[node*2+1]);
	}
	int query(int left, int right, int nodeLeft, int nodeRight, int n) {
		if (left <= nodeLeft && nodeRight <= right) return tree[n];
		if (right < nodeLeft || nodeRight<left) return INF;
		int nodeMid = (nodeLeft + nodeRight)/2;
		return (*op)(query(left, right, nodeLeft, nodeMid, 2*n),
			query(left, right, nodeMid+1, nodeRight, 2*n+1));
	}
};

int numSign, numPath;
SegmentTree *maxSt;
SegmentTree *minSt;

int solve(int left, int right) {
	int minimum = minSt->query(left, right);
	int maximum = maxSt->query(left, right);
	return maximum-minimum;
}

int main() {
	ios_base::sync_with_stdio(false);
	int C, tmp, left, right;
	vector<int> signs;
	cin >> C;
	vector<int> sols;
	for (int i=0; i<C; i++) {
		cin >> numSign >> numPath;
		signs.resize(numSign);
		for (int j=0; j<numSign; j++) {
			cin >> signs[j];
		}
		maxSt = new SegmentTree(signs, new Max(), numeric_limits<int>::min());
		minSt = new SegmentTree(signs, new Min(), numeric_limits<int>::max());
		for (int j=0; j<numPath; j++) {
			cin >> left >> right;
			sols.push_back(solve(left, right));
		}
	}
	for (int i=0; i<sols.size(); i++)
		cout << sols[i] <<endl;
}
