// Start from 06:54PM Feb, 2018
// End at 07:14PM Feb, 2018
// need to be proven
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	long long n, k, A, B;
	cin >> n >> k >> A >> B;
	long long cost = 0;
	if (k==1) {
		cout << (long long)(n-1)*A <<endl;
		return 0;
	}
	while (1 < n) {
		if (n%k == 0) {
			if ((n-n/k)*A < B) {
				cost += A*(n-n/k);
			} else {
				cost += B;
			}
			n = n/k;
		} else {//operation A
			cost += A*(n%k);
			n -= n%k;
			if (n==0) {
				n = 1;
				cost -= A;
			}
		}
	}
	cout << cost << endl;
}
