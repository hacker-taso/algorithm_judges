#include<iostream>
using namespace std;
int main() {
	int l, r, a;
	cin >> l >> r >> a;
	int sol = 0;
	int pairs = min(l,r);
	sol = pairs*2;
	l-=pairs;
	r-=pairs;
	int remain = max(l,r);
	if (remain<=a) {
		a-=remain;
		sol += 2*remain;
		sol += (a/2)*2;
	} else {
		sol += a*2;
	}
	cout << sol << endl;
}
