#include<iostream>
#include<cmath>
/*
	 max(1 move) = 1 light year
	 max(2 move) = 1 + 1 = 2 light year
	 max(3 move) = 1 + 2 + 1 = 4 light year
	 max(4 move) = 1 + 2 + 2 + 1 = 6 light year
	 max(5 move) = 9 light year
	 max(6 move) = 12 light year
	 max(7 move) = 16 light year
	 ..
	 max(2n-1 move) = n^2
	 max(2n move) = n(n+1)
	 => for distance d,
	    if n(n-1) < d <= n^2, 2n-1 move
	    if n^2 < d <= n(n+1),   2n move
	    if n(n+1) < d <= (n+1)^2, 2n+1 move
*/
using namespace std;
int main(){
	int T;
	cin  >> T;
	int x,y;
	long long d;
	long long n;
	int k;
	for (int i=0; i<T; i++) {
		k=0;
		cin >> x >> y;
		d = y-x;
		n = static_cast<int>(sqrt(d));	
		if (d == n*n) {
			k = 2*n - 1;
		} else if (n*n < d && d <= n*(n+1)) {
			k = 2*n;
		} else if (n*(n+1) < d && d <= (n+1)*(n+1)) {
			k = 2*n + 1;
		}
		cout << k << endl;
	}
}

