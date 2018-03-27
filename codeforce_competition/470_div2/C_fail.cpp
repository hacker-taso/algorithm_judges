// Using lazy propagation
// I cannot solve in this way.
#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct SegmentTree {
	int n;
	vector<long long> tree;
	vector<long long> lazy;
	SegmentTree(const vector<long long>& arr) {
		n = arr.size();
		tree = vector<long long>(4*n, 0);
		lazy = vector<long long>(4*n, 0);
		init(arr, 0, n-1, 1);
	}
	void init(const vector<long long>& arr, int left, int right, int nodeIdx) {
		if (left == right) {
			tree[nodeIdx] = arr[left];
			return;
		}
		int mid = (left+right)/2;
		init(arr, left, mid, nodeIdx*2);
		init(arr, mid+1, right, nodeIdx*2+1);
		tree[nodeIdx] = tree[nodeIdx*2] + tree[nodeIdx*2+1];
	}

	void propagate(int nodeLeft, int nodeRight, int nodeIdx) {
		if (lazy[nodeIdx]) {
			if (nodeLeft != nodeRight) {
				lazy[nodeIdx*2] += lazy[nodeIdx];
				lazy[nodeIdx*2+1] += lazy[nodeIdx];
			}
			tree[nodeIdx] += (nodeRight-nodeLeft+1)*lazy[nodeIdx];
			lazy[nodeIdx] = 0;
		}
	}

	void add(int left, int right, int nodeLeft, int nodeRight, int nodeIdx, int val) {
		propagate(nodeLeft, nodeRight, nodeIdx);
		if (nodeRight<left || right<nodeLeft) return;
		if (left <= nodeRight && nodeRight <= right) {
			lazy[nodeIdx] += val;
			propagate(nodeLeft, nodeRight, nodeIdx);
			return;
		}
		int nodeMid = (nodeLeft+nodeRight)/2;
		add(left, right, nodeLeft, nodeMid, nodeIdx*2, val);
		add(left, right, nodeMid+1, nodeRight, nodeIdx*2+1, val);
		tree[nodeIdx] += tree[nodeIdx*2]+tree[nodeIdx*2+1];
	}
	void add(int left, int right, int val) {
		add(left, right, 0, n-1, 1, val);
	}

	long long sum(int left, int right, int nodeLeft, int nodeRight, int nodeIdx) {
		propagate(left, right);
		if (nodeRight<left || right<nodeLeft) return;
		if (left <= nodeRight && nodeRight <= right) {
			return tree[nodeIdx];
		}
		int nodeMid = (nodeLeft+nodeRight)/2;
		return sum(left, right, nodeLeft, nodeMid, nodeIdx*2) + sum(left, right, nodeMid+1, nodeRight, nodeIdx*2+1);
	}
	long long sum(int left, int right) {
		sum(left, right, 0, n-1, 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int numDay;
	int tmp;
	cin >> numDay;
	vector<int> snows(numDay);
	for (int i=0; i<numDay; i++) {
		cin >> snows[i];
	}
	SegmentTree st(snows);

	vector<long long> sol;
	for (int i=0; i<numDay; i++) {
		st
		cin >> tmp;
		snowSet.insert(accum+snows[i]);
		for (multiset<long long>::iterator it = snowSet.begin(); it != snowSet.end(); ) {
			if (*it-accum<=tmp) {
				curVal += *it-accum;
				auto beforeIt = it;
				it++;
				snowSet.erase(beforeIt);
				continue;
			}
			break;
		}
		curVal += tmp*snowSet.size();
		accum+=tmp;
		sol.push_back(curVal);
	}
	for (int i=0; i<numDay; i++)
		cout << sol[i] << " ";
	cout <<endl;
}
