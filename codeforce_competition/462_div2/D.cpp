// Start from 10:27PM Feb 14, 2017
// End at PM Feb 14, 2017
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main() {
	int k;
	long long p;
	cin >> k >> p;
	vector<double> coefs;
	vector<int> fx;
	coefs.push_back(1-p/k);
	double before = coefs[0];
	fx.push_back(coefs[0]*k+p);
	int i=0;
	for (; i<10000; i++) {
		coefs.push_back(1-before/k);
		before = coefs[i+1];
		if (k<coefs[i]+coefs[i+1]*k) {
			cout << -1 <<endl;
			return 0;
		}
		fx.push_back(coefs[i]+coefs[i+1]*k);
		if (coefs[i+1]<k) {
			fx.push_back(coefs[i]);
			break;
		}
	}
	if (i==10000)
		cout << -1 <<endl;
	else {
		cout << coefs.size();
	}
}
