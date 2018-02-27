#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int n,m;
	cin >> n >> m;
	double sol = 0x12345678, a,b;
	for (int i=0; i<n; i++) {
		cin >> a >> b;
		sol = min(sol, (double)a/b * m);
	}
	cout << fixed << setprecision(10) << sol <<endl;
}
