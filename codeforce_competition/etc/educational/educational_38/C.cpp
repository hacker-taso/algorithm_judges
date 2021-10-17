// Start at 00:18AM Feb 17, 2018
// End at 1:43AM Feb 17, 2018
// Retrospection:
// It took ages because I thought l == ceil(n/(2*m-1)).
// It was l == floor(n/m). I should have checked with drawing picture.
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int x;
void solve() {
	if (x==0) {
		cout << 1 << " " << 1 <<endl;
		return;
	}
	for (int i=1; i<=sqrt(x+0.1); i++) {
		if (x%i == 0) {
			int a = i;
			int b = x/i;
			int n=a+b;
			if (n%2==1) continue;
			n/=2;
			int l=b-a;
			if (l%2==1 || l<=0) continue;
			l/=2;
			for (int m=n/(l+1); m<=n/l; m++) {
				if (m==0) continue;
				if (l==n/m) {
					cout << n << " " << m <<endl;
					return;
				}
			}
		}
	}
	cout << -1 <<endl;
}

int main() {
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> x;
		solve();
	}
}
