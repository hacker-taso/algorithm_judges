// Read again
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n, U;
	cin >> n >> U;
	vector<double> Es(n);
	for (int i=0; i<n; i++) {
		cin >> Es[i];
	}
	bool found = false;
	for (int i=1; i<n; i++) {
		if (Es[i]-Es[i-1]<=U) {
			found = true;
			break;
		}
	}
	if (!found) {
		cout << -1 <<endl;
		return 0;
	}
	double maxVal = 0;
	for (int i=0; i<n-1; i++) {
		double d = Es[i+1]-Es[i];
		int lo=i+1, hi=n;
		while (lo+1<hi) {
			int mid = (lo+hi)/2;
			if (Es[mid]-Es[i]<=U) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		int k=lo;
		maxVal = max(maxVal, 1-d/(Es[k] - Es[i]));
	}
	cout << fixed << setprecision(9) << maxVal <<endl;
}
