#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> S;

int solve() {
	for (int k=1; k<=1023; k++) {
		vector<int> S2(n);
		for (int i=0; i<n; i++) {
			S2[i] = S[i]^k;
		}
		sort(S.begin(), S.end());
		sort(S2.begin(), S2.end());
		bool same = true;
		for (int i=0; i<n; i++) {
			if (S[i] != S2[i]) {
				same = false;
				break;
			}
		}
		if (same == true)
			return k;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		S = vector<int>(n);
		for (int j=0; j<n; j++)
			cin >> S[j];
		cout << solve() << endl;
	}
}
