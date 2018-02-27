// Retrospection(Something I learnt): priority_queue<int, vector<int>, less<int> > makes max-heap.
#include<iostream>
#include<queue>
#define MOD 20090711
using namespace std;

struct Generator {
	int seed, a, b;
	Generator(int _a, int _b) {
		seed=1983;a=_a;b=_b;
	}
	int getNext() {
		int cur = seed;
		seed = ((long long)cur*a + b) % 20090711;
		return cur;
	}
};

int len, a, b;

int solve() {
	// less means max-heap, greater means min-heap
	priority_queue<int, vector<int>, less<int> > smalls;
	priority_queue<int, vector<int>, greater<int> > bigs;
	Generator g(a,b);
	int v = g.getNext();
	// top of smalls should always be median.
	smalls.push(v);
	int s = v;
	for (int i=1; i<len; i++) {
		v = g.getNext();
		if (v<smalls.top())
			smalls.push(v);
		else
			bigs.push(v);
		if (1<(int)smalls.size()-(int)bigs.size()) {
			bigs.push(smalls.top());
			smalls.pop();
		}
		if (smalls.size() < bigs.size()) {
			smalls.push(bigs.top());
			bigs.pop();
		}
		s= (s+smalls.top())%MOD;
	}
	return s;
}

int main() {
	int C, sols[20];
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> len >> a >> b;
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
