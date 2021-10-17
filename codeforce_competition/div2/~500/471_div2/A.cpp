// Start at 01:35AM March 24, 2018
// End at 01:47AM March 24, 2018
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	int H, D, C, N;
	int hh, mm;
	cin >> hh >> mm;
	cin >> H >> D >> C >> N;
	int time = hh * 60 + mm;
	int discountTime = 60*20;
	if (discountTime<=time) {
		cout << fixed << setprecision(4) << (double)ceil((double)H / N)*C/100 * 80 << endl;
		return 0;
	}
	double waitCost = (double)ceil((double)((discountTime - time) * D + H)/N)*C/100*80;
	double noWaitCost = ceil((double)H/N)*C;
	cout << fixed << setprecision(4) << min(waitCost, noWaitCost) << endl;
}
