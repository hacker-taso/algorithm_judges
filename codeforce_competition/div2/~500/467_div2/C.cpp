// Start at 01:53AM Feb 26, 2018
// End at 02:51AM Feb 26, 2018
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	long long preserveT, checkingT;
	double needTime;
	cin >> preserveT >> checkingT >> needTime;
	long long range = (preserveT/checkingT * checkingT == preserveT) ? 
			preserveT : (preserveT/checkingT+1)*checkingT;
	double half = range - preserveT;
	double full = preserveT;
	double rangeEffect = full + (double)half/2;
	long long rangeNum = (long long)(needTime/rangeEffect);
	double sol = range*rangeNum;
	needTime -= rangeNum * rangeEffect;
	full = min(full, needTime);;
	needTime -= full;
	sol += full;
	if (1e-9<needTime) {
		sol += needTime*2;
	}
	cout << fixed << setprecision(10)<< sol <<endl;
}
