// Start from 07:35PM Feb, 2018
// End at 08:05PM Feb, 2018
// Retrospection: b[i]==0
#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	string b;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> b;
	int rMax = 1000000000, rMin = -1000000000;
	int lMax = 1000000000, lMin = -1000000000;
	for (int i=4; i<b.size(); i++) {
		if (b[i] != b[i-1]) { // cond 1 or cond 2.
			if (b[i] == '0') { // cond 1.
				rMax = min(rMax, min(min(min(a[i], a[i-1]), a[i-2]), min(a[i-3], a[i-4]))-1);
			} else { // cond 2.
				lMin = max(lMin, max(max(max(a[i], a[i-1]), a[i-2]), max(a[i-3], a[i-4]))+1);
			}
		}
	}
	cout << lMin << " " << rMax << endl;
}
