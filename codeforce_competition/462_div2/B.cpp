// Start from 09:17PM Feb 14, 2017
// End at 09:30PM Feb 14, 2017
#include<iostream>
#include<vector>
using namespace std;

const int loopToNum[3] = {
	1, 4, 8
};

int main() {
	int k;
	cin >> k;
	vector<int> numVec;
	while (1<k) {
		numVec.push_back(loopToNum[2]);
		k-=2;
	}
	if (k==1)
		numVec.push_back(loopToNum[1]);
	if (18<numVec.size())
		cout << -1<<endl;
	else {
		long long num = 0;
		long long decimals[18];
		decimals[0] = 1;
		for (int i=1; i<18; i++) {
			decimals[i] = decimals[i-1]*10;
		}
		for (int i=0; i<numVec.size(); i++) {
			num += numVec[i] * decimals[i];
		}
		cout << num<<endl;
	}
}
