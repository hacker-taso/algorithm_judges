#include<iostream>
#include<vector>
using namespace std;

struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n): tree(n, 0) {}
	int sum(int idx) {
		int s=0;
		idx++;
		while (0<idx) {
			s+= tree[idx];
			idx = idx & (idx-1);
		}
		return s;
	}
	int add(int pos, int val) {
		pos++;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += pos & -pos;
		}
	}
};

int main() {
	int C, len, tmp;
	long long sols[50] = {0,};
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> len;
		FenwickTree ft(1000001);
		for (int j=0; j<len; j++) {
			cin >> tmp;
			sols[i] += ft.sum(999999)-ft.sum(tmp);
			ft.add(tmp, 1);
		}
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
