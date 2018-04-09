#include<iostream>
#include<vector>
#include<cmath>
#define NCAND 3000000
using namespace std;

vector<bool> removed(NCAND, false);
vector<int> factors(NCAND, 1);

void remove2(int n) {
	for (int i=n; i<NCAND; i+=n)
		removed[i] = true;
}

void remove(int n) {
	int curFactor = 1;
	while (factors[n]!=1) {
		curFactor = factors[n];
		while (n%curFactor == 0) n/=curFactor;
		remove2(curFactor);
	}
}

void init() {
	for (int i=2; i<=sqrt(NCAND+0.01); i++) {
		if (factors[i] != 1) continue;
		for (int n=i; n<NCAND; n+=i) {
			if (factors[n] != 1) continue;
			factors[n] = i;
		}
	}
}

int main() {
	int n;
	init();
	cin >> n;
	vector<int> seq(n);
	for (int i=0; i<n; i++)
		cin >> seq[i];
	int i=0;
	int curVal;
	for (; i<n; i++) {
		if (!removed[seq[i]]) {
			cout << seq[i] << " ";
			remove(seq[i]);
		} else {
			curVal = seq[i];
			while (removed[curVal]) curVal++;
			cout << curVal << " ";
			remove(curVal);
			i++;
			break;
		}
	}
	curVal = 2;
	for (; i<n; i++) {
		while (removed[curVal]) curVal++;
		cout << curVal << " ";
		remove(curVal);
	}
	cout << endl;
}
