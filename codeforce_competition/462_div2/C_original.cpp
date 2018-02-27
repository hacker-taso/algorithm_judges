// Start from 09:17PM Feb 14, 2017
// End at 09:30PM Feb 14, 2017
// need to check complexity
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> seq(n);
	for (int i=0; i<n; i++) {
		cin >> seq[i];
	}
	vector<int> ps1(n+1);
	vector<int> ps2(n+1);
	ps1[0] = 0;
	ps2[0] = 0;
	for (int i=1; i<=n; i++) {
		ps1[i] = ps1[i-1] + (seq[i-1]==1);
		ps2[i] = ps2[i-1] + (seq[i-1]==2);
	}
	int maxVal = 0;
	for (int i=0; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			for (int k=j; k<=n; k++) {
				maxVal = max(maxVal, ps1[i]+(ps2[j]-ps2[i])+(ps1[k]-ps1[j])+(ps2[n]-ps2[k]));
			}
		}
	}
	cout << maxVal <<endl;
}
