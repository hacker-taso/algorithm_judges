#include<iostream>
using namespace std;

long long playCnt;
long long winCnt;

void solve() {
	long long initVal = winCnt*100/playCnt;
	long long lo = 0, hi = 2000000001, mid;
	for (int i=0; i<100; i++) {
		mid = (lo + hi)/2;
		if (initVal < (winCnt+mid)*100/(playCnt+mid))
			hi = mid;
		else
			lo = mid;
		if (lo+1 == hi)
			break;
	}
	if (hi == 2000000001)
		cout << -1 << endl;
	else
		cout << hi << endl;
}

int main() {
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> playCnt >> winCnt;
		solve();
	}
}
