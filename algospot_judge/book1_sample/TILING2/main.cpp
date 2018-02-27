#include<iostream>
#include<cstring>
#include<vector>
#define MOD 1000000007
using namespace std;

int cache[101];

void init() {
	memset(cache, -1, sizeof(cache));
}

int solve(int n) {
	int& ret = cache[n];
	if (ret != -1) return ret;
	if (n == 1) {
		ret = 1;
		return ret;
	} else if (n==2) {
		ret = 2;
		return ret;
	}
	ret = (solve(n-1) + solve(n-2))%MOD;
	return ret;
}

int main() {
	int C;
	vector<int> sols;
	int n;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> n;
		sols.push_back(solve(n));
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
