// Start at 00:35AM March 5, 2018
// End at 00:38AM March 5, 2018
#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int diff = a<b ? b-a : a-b;
	int one = diff/2;
	int two = diff - one;
	int sumOne = 0;
	int sumTwo = 0;
	for (int i=1; i<=one; i++) {
		sumOne += i;
	}
	for (int i=1; i<=two; i++) {
		sumTwo += i;
	}
	cout << sumOne + sumTwo <<endl;
}
