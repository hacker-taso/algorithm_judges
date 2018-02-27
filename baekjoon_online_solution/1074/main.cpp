#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
/*
	solution: 
	1. Divide the array into 4 part. 
	2. Find the part where the coordinate belongs to among 4 part.
	3. Count the number of cells to reach this part.
	4. Repeat 1~3.
*/
int main() {
	int N, r, c;
	
	vector<int> nPowers(20);
	for (int i=0; i<20; i++) {
		nPowers[i] =  pow(2, i);
	}
	
	int nPowerHalf, sum;
	while (cin >> N >> r >> c) {
		sum=0;
		for (int i=N; 0<i; i--) {
			nPowerHalf = nPowers[i]/2;
			if (c < nPowerHalf && r < nPowerHalf) { // one part
			} else if ( r < nPowerHalf && nPowerHalf <= c) { // two part
				sum += nPowerHalf * nPowerHalf;
				c -= nPowerHalf;
			} else if ( nPowerHalf <= r && c < nPowerHalf) { // three part
				sum += 2 * nPowerHalf * nPowerHalf;
				r -= nPowerHalf;
			} else { // four part
				sum += 3 * nPowerHalf * nPowerHalf;
				c -= nPowerHalf;
				r -= nPowerHalf;
			}
		}
		cout << sum << endl;
	}
}

