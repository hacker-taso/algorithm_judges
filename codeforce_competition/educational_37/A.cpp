// 11:35 ~11:54
#include<iostream>
#include<vector>
using namespace std;

vector<int> opens;
int n,k;

int solve() {
	vector<bool> map(n, 0);
	for (int s=0; s<1000; s++) {
		bool satisfied = true;
		for (int i=0; i<n; i++) {
			if (!map[i]) {
				satisfied = false;
				break;
			}
		}
		if (satisfied) return s;
		for (int i=0; i<k; i++) {
			if (0<=opens[i]-s-1)
				map[opens[i]-s-1] = 1;
			if (opens[i]+s-1<n)
				map[opens[i]+s-1] = 1;
		}
	}
}

int main() {
	int C;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> n >> k;
		opens = vector<int>(k, 0);
		for (int j=0; j<k; j++) {
			cin >> opens[j];
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
