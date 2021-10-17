// Start at 01:12AM Feb 26, 2018
// End at 01:52AM Feb 26, 2018
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int gr, maxH;
	cin >> gr >> maxH;
	while (gr<maxH) {
		bool found = true;
		int numIter = min((int)sqrt(maxH+0.5), gr);
		for (int i=2; i<=numIter; i++) {
			if (maxH%i == 0) {
				found = false;
				break;
			}
		}
		if (found) break;
		maxH--;
	}
	if (maxH == gr)
		cout << -1 <<endl;
	else
		cout << maxH <<endl;
}
