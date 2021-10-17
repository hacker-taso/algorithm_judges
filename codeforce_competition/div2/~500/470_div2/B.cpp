// Start at 00:47AM March 11, 2018
// End at 01:28AM March 11, 2018
// Retrospection: X1%i == 0
#include<iostream>
#include<cmath>
#include<cstring>
int factor[1000001];
using namespace std;
int main() {
	memset(factor, -1, sizeof(factor));
	int X2;
	cin >> X2;
	int copyX2 = X2;
	int biggestP2;
	for (int i=2; i<=1000000; i++) { // Retrospection
		if (factor[i] != -1) continue;
		for (int j=i; j<=1000000;j+=i) {
			if (factor[j] == -1)
				factor[j] = i;
		}
	}
	for (int i=2; i<=sqrt(X2+0.01); i++) {
		if (copyX2%i == 0) {
			biggestP2 = i;
			while (copyX2%i == 0) copyX2 = copyX2/i;
		}
	}
	biggestP2 = max(biggestP2, copyX2);
	int X1Lower = X2-biggestP2+1;
	int minX0 = 1e9;
	for (int X1=X1Lower; X1<=X2; X1++) {
		if (factor[X1] == X1) continue;
		int copyX1 = X1;
		int biggestP1 = 0;
		while (factor[copyX1] != copyX1) {
			biggestP1 = max(factor[copyX1], biggestP1);
			copyX1 /= factor[copyX1];
		}
		biggestP1 = max(copyX1, biggestP1);
		minX0 = min(minX0, X1-biggestP1+1);
	}
	cout << minX0 <<endl;
}
