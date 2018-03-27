// Start at 01:35AM March 24, 2018
// End at 01:35AM March 24, 2018
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int Q;
	cin >> Q;
	long long L, R;
	long long solL, solR;
	for (int i=0; i<Q; i++) {
		cin >> L >> R;
		long long cnt = 0;
		if (L == 1) {
			L++;
			cnt++;
		}
		long long one = floor(pow(R+0.01, (double)1/2));
		for (int i=3; i<64; i++) {
			two = floor(pow(R+0.01, (double)1/i));
			cnt += (one - two)*(i-2);
		}
		cout << cnt <<endl;
	}
}
