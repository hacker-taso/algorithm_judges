#include<iostream>
#include<string>
using namespace std;
/*
	sum(s to s+k): (s+k)(s+k+1)/2 - s(s-1)/2 = (k+1)(k+2s)/2
	=> s = (2 * sum(s to s+k)/ (k+1) - k) / 2 = (2*N/(k+1) - k)/2			( and L <= k <= 100 )
*/
int main() {
	int N, L;
	cin >> N >> L;

	int s, k;
	bool exists = false;
	for (k=L-1; k<=99; k++) {
		s = (2*N/(k+1) - k)/2;
		if ( 0<=s && (k + 1)*(k + 2*s)/2 == N ) {
			exists = true;
			break;
		}
	}

	if (exists) {
		cout << s;
		for(int i=1; i<=k; i++) {
			cout << " " + to_string(s + i);
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}

