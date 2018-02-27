#include<iostream>
#include<vector>
#include<iomanip>
#define INF 0x76543210
using namespace std;

vector<double> prices;
int days, minTeam;
vector<double> partialSum;

void precalc() {
	partialSum.clear();
	partialSum.resize(days+1, 0);
	partialSum[0] = 0;
	for (int i=0; i<days; i++) {
		partialSum[i+1] = partialSum[i]+prices[i];
	}
}

double solve() {
	precalc();
	double minAvg = INF;
	for (int l=0; l<days; l++) {
		for (int r=l+minTeam; r<=days; r++) {
			minAvg = min((partialSum[r] - partialSum[l])/(r-l), minAvg);
		}
	}
	return minAvg;
}

int main() {
	int C;
	vector<double> sols;
	cin >>C;
	for (int i=0; i<C; i++) {
		cin >> days >> minTeam;
		prices.clear();
		prices.resize(days);
		for (int j=0; j<days; j++)
			cin >> prices[j];
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << fixed << setprecision(11) << sols[i] << endl;
	}
}
