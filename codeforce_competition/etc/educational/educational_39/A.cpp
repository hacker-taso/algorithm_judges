// Start at 00:05AM March 07, 2018
// End at 00:06AM March 07, 2018
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int tmp;
	int sum = 0;
	for (int i=0; i<n; i++) {
		cin >> tmp;
		sum += tmp < 0 ? -tmp : tmp;
	}
	cout << sum << endl;
}
