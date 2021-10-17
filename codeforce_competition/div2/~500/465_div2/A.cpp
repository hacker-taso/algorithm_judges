// Start at 1:35AM Feb 20, 2018
// End at 1:39AM Feb 20, 2018
#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int cnt=0;
	for (int i=1; i<n; i++) {
		if (n%i == 0)
			cnt++;
	}
	cout << cnt << endl;
}
