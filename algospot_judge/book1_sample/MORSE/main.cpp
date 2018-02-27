#include<iostream>
#include<vector>
#include<cstring>
#define MAX_KTH (1000000000+100)
using namespace std;

int numFirst, numSecond, k;
int bino[201][201];

int getNumComb(int numFirst, int numSecond) {
	return bino[numFirst+numSecond][numSecond];
}

string construct(int numFirst, int numSecond, int skip) {
	if (numFirst == 0) {
		if (numSecond == 0) return "";
		else return "o" + construct(numFirst, numSecond-1, skip-getNumComb(numFirst, numSecond-1));
	}
	if (skip == 0) return "-" + construct(numFirst-1, numSecond, skip);
	int numWithFirst = getNumComb(numFirst-1, numSecond);
	if (numWithFirst <= skip) {
		return "o" + construct(numFirst, numSecond-1, skip-numWithFirst);
	} else {
		return "-" + construct(numFirst-1, numSecond, skip);
	}
}

string solve() {
	return construct(numFirst, numSecond, k-1);
}

void calcBino() {
	for (int i=0; i<201; i++) {
		bino[i][i] = bino[i][0] = 1;
		for (int j=1; j<i; j++) {
			bino[i][j] = min(bino[i-1][j-1] + bino[i-1][j], MAX_KTH);
		}
	}
}

int main() {
	int C;
	vector<string> sols;
	cin >> C;
	calcBino();
	for (int i=0; i<C; i++) {
		cin >> numFirst >> numSecond >> k;
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
