#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

double cache[1001][1001];
int numDay, wellLen;

void init() {
	for (int i=0; i<1001; i++) {
		for (int j=0; j<1001; j++) {
			cache[i][j] = -1;
		}
	}
}

double solve(int remainDay, int remainLen) {
	//todo base case
	if (remainLen<=0)
		return 1;
	else if (remainDay == 0)
		return 0;
	double& ret = cache[remainDay][remainLen];
	if (ret != -1) return ret;
	ret = 0.75 * solve(remainDay-1, remainLen-2) + 0.25*solve(remainDay-1, remainLen-1);
	return ret;
}

int main() {
	int C;
	vector<double> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> wellLen >> numDay;
		sols.push_back(solve(numDay, wellLen));
	}
	for (int i=0; i<C; i++) {
		cout << fixed << setprecision(10) << sols[i] <<endl;
	}
}
