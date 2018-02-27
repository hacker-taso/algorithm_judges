// Retrospection (mistake): 
// 1. I thought upper limit of solution is 100000000 because the maximum value of principal is this.
// But it is not true becuase balance could be more than 100000000 in second month 
// with balance+=balance*(interset/100/12).
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int month;
double interest, principal;

double remains(double monthly) {
	double balance = principal;
	for (int i=0; i<month; i++) {
		balance += balance*(interest/100/12);
		balance -= monthly;
	}
	return balance;
}

double solve() {
	double lo = 0, hi = 200000000, mid;
	for (int i=0; i<100; i++) {
		mid = (lo+hi)/2;
		if (0<remains(mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	return mid;
}

int main() {
	int C;
	vector<double> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> principal >> month >> interest;
		sols.push_back(solve());
	}

	for (int i=0; i<C; i++) {
		cout << fixed << setprecision(10) << sols[i] << endl;
	}
}
