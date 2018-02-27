// Start at 00:13AM Feb 17, 2018
// End at 00:18AM Feb 17, 2018
#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> seq(n);
	for (int i=0; i<n; i++)
		cin >> seq[i];
	int me = 1;
	int freind = 1000000;
	int maxDist = 0;
	for (int i=0; i<n; i++) {
		maxDist = max(maxDist, min(seq[i]-me, freind-seq[i]));
	}
	cout << maxDist<<endl;
}
