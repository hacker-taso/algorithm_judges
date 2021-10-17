#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> a;
vector<int> b;

int solve() {
	vector<int> aIdx(n+1);
	for (int i=0; i<n; i++)
		aIdx[a[i]] = i;
	vector<int> dist(n);
	for (int i=0; i<n; i++) {
		dist[i] = i - aIdx[b[i]];
		if (dist[i] < 0)
			dist[i] = n + dist[i];
	}
	sort(dist.begin(), dist.end());
	int curCnt = 1;
	int maxCnt = 0;
	for (int i=1; i<n; i++) {
		if (dist[i-1] != dist[i]) {
			maxCnt = max(maxCnt, curCnt);
			curCnt = 0;
		}
		curCnt++;
	}
	maxCnt = max(maxCnt, curCnt);
	return maxCnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	a = vector<int>(n);
	b = vector<int>(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	cout << solve() << endl;
}
