#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int numIngred;
int required[200];
int normRequired[200];
int already[200];

int GCD(int a, int b) {
	if (a==0) return b;
	GCD(b%a, a);
}

void solve() {
	int gcd;
	if (numIngred < 2)
		gcd = required[0];
	else
		gcd = GCD(required[0], required[1]);
	for (int i=2; i<numIngred; i++) {
		gcd = GCD(gcd, required[i]);
	}
	for (int i=0; i<numIngred; i++)
		normRequired[i] = required[i]/gcd;

	int coef = gcd;
	for (int i=0; i<numIngred; i++) {
		coef = max(coef, (int)ceill((double)already[i]/normRequired[i]));
	}
	for (int i=0; i<numIngred; i++) {
		cout << coef*normRequired[i] - already[i];
		if (i+1 != numIngred)
			cout << " ";
	}
	cout << endl;
}

int main() {
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numIngred;
		for (int j=0; j<numIngred; j++) {
			cin >> required[j];
		}
		for (int j=0; j<numIngred; j++) {
			cin >> already[j];
		}
		solve();
	}
}