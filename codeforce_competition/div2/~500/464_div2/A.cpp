// Start at 07:05PM Feb 17, 2018
// End at 07:08PM Feb 17, 2018
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> loves(n, 0);
	for (int i=0; i<n; i++) {
		cin >> loves[i];
		loves[i]--;
	}
	for (int i=0; i<n; i++) {
		if (loves[loves[loves[i]]]==i) {
			cout << "YES" <<endl;
			return 0;
		}
	}
	cout << "NO" <<endl;
}
