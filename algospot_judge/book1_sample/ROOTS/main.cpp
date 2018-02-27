// Retrospection(mistake):
// 1. making invariant of bisection method to lo <= 0. (It should be f(lo) <= 0) 
#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cmath>
using namespace std;

double calFx(const vector<double>& equation, double x) {
	double fx = 0;
	for (int k=0; k<equation.size(); k++) {
		fx += equation[k]*pow(x, k);
	}
	return fx;
}
// equation exp example:0 1 2 3 4 5
// 3<=equation.size()<=6
// ret: sols in ascending order
vector<double> solve(const vector<double>& equation) {
	vector<double> sol;
	if (equation.size() == 3) {
		double a = equation[2];
		double b = equation[1];
		double c = equation[0];
		double det = b*b-4*a*c;
		assert(0<det);
		sol.push_back((-b-sqrt(det))/(2*a));
		sol.push_back((-b+sqrt(det))/(2*a));
		if (sol[1] < sol[0])
			swap(sol[0], sol[1]);
		return sol;
	}
	vector<double> diffEq;
	for (int i=1; i<equation.size(); i++) {
		diffEq.push_back(equation[i]*i);
	}
	vector<double> diffSol = solve(diffEq);

	double lo, hi, mid, fx;
	for (int i=0; i<=diffSol.size(); i++) {
		if (i == 0)
			lo = -10;
		else
			lo = diffSol[i-1];
		if (i==diffSol.size())
			hi = 10;
		else
			hi = diffSol[i];
		if (calFx(equation, lo) * calFx(equation, hi) >= 0)
			continue;
		for (int j=0; j<100; j++) {
			if (0<calFx(equation, lo))
				swap(lo, hi);
			mid = (lo+hi)/2;
			fx = calFx(equation, mid);
			if (fx<=0) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		sol.push_back((lo+hi)/2);
	}
	return sol;
}

int main() {
	int C, order;
	vector<double> equation;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> order;
		equation.resize(order+1);
		for (int j=0; j<=order; j++) {
			cin >> equation[j];
		}
		reverse(equation.begin(), equation.end());
		vector<double> sol = solve(equation);
		for (int j=0; j<sol.size(); j++) {
			cout << fixed << setprecision(12) << sol[j];
			if (j!=sol.size()-1)
				cout << " ";
		}
		cout << endl;
	}
}
