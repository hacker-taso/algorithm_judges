#include<iostream>
#include<algorithm>
using namespace std;

int L[5000], M[5000], G[5000];
int K;
int cityCnt;

bool decide(int posUpperLimit) {
	int cnt = 0;
	int firstPos = 0;
	int standard = 0;
	for (int i=0; i<cityCnt; i++) {
		firstPos = L[i]-M[i];
		if (posUpperLimit < firstPos)
			continue;
		standard = min(posUpperLimit, L[i]);
		cnt += (standard - firstPos) / G[i] + 1;
	}
	return K <= cnt;
}

int solve() {
	int maxL = 0;
	for (int i=0; i<cityCnt; i++) {
		maxL = max(L[i], maxL);
	}

	int lo=0, hi = maxL+1, mid;
	for (int i=0; i<100; i++) {
		mid = (hi+lo)/2;
		if (decide(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main() {
	int C, sols[200];
	ios_base::sync_with_stdio(false);
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> cityCnt >> K;
		for (int j=0; j<cityCnt; j++) {
			cin >> L[j] >> M[j] >> G[j];
		}
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
