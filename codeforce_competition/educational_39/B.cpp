// Start at 00:07AM March 07, 2018
// Suspend during 00:15AM~00:20AM March 07, 2018
// End at 00:32AM March 07, 2018
#include<iostream>
using namespace std;
int main() {
	unsigned long long n, m;
	cin >> n >> m;
	while (n!=0 && m!=0) {
		if (n>=2*m) {
			n = n % (2*m);
		} else if (m>=2*n) {
			m = m % (2*n);
		} else if (2*n>m) {
			break;
		}
	}
	cout << n << " " << m << endl;
}
