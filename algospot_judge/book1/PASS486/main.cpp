#include<iostream>
#define MAX_NUM 100*100*100*10
using namespace std;

int sieve[MAX_NUM+1] = {0, };
int numFactors, lo, hi;

int solve() {
	int cnt = 0;
	for (int i=lo; i<=hi; i++) {
		if (sieve[i]+2 == numFactors)
			cnt++;
	}
	return cnt;
}

void initSieve() {
	sieve[1] = -1;
	for (int i=2; i<=MAX_NUM; i++) {
		for (int j=i+i; j<=MAX_NUM; j+=i) {
			sieve[j]++;
		}
	}
}

int main() {
	initSieve();
	int C, sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numFactors >> lo >> hi;
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
