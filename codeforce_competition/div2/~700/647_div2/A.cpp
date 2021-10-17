#include<iostream>
#include<algorithm>
using namespace std;


int solve(unsigned long long a, unsigned long long b) {
	int div;
	unsigned long long big = a, small = b;
	if (big<small)
		swap(big, small);
	int i=0;
	for (; i<100; i++) {
		if (big == small) 
			break;
		if (big % 2 != 0)
			return -1;
		big /= 2;
	}
	if (i==100)
		return -1;
	int three = i/3;
	i = i%3;
	int two = i/2;
	i = i%2;
	int one = i;
	return one+two+three;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	unsigned long long a, b;
	for (int i=0; i<t; i++) {
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
}
