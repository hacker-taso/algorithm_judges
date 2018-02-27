// Retrospection (mistakes):
// 1. I thought finding smallest distance between position at first time. I think I didn't read direction carefully.
// 2. I mistakenly write down like this mid = lo; mid = hi.
// 3. I didn't initialize numChosen.(numChosen = 1)
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int numCam, numPos;
vector<double> posList, sols;

bool allHigherThanOrEqualTo(double x) {
	double prev = posList[0];
	int numChosen=1;
	for (int i=1; i<numPos; i++) {
		if (x<=posList[i]-prev) {
			numChosen++;
			prev = posList[i];
		}
	}
	if (numCam<=numChosen)
		return true;
	else
		return false;
}

double solve() {
	// final result will be in hi
	double lo=-1, hi=241, mid;
	for (int i=0; i<100; i++) {
		mid = (lo+hi)/2;
		if (allHigherThanOrEqualTo(mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	return hi;
}

int main() {
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numCam >> numPos;
		posList.clear();
		posList.resize(numPos, 0);
		for (int j=0; j<numPos; j++) {
			cin >> posList[j];
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << fixed << setprecision(2) << sols[i] <<endl;
	}
}
