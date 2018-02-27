#include<iostream>
using namespace std;
/*
	When the number of round X is n, then the number of round X+1 is n/2 if n is even number
	 																																	(n+1)/2 if n is odd number.
	the two people battle on X round if the number of one is n (which is odd) and the number of the other one is n+1

	time complexity of below code = O(logN)
*/
int main(){
	int N, K, I;
	cin >> N >> K >> I;

	int small, big;
	if (K < I) {
		small = K;
		big = I;
	} else {
		small = I;
		big = K;
	}

	int round = 1;
	while (!(small % 2 == 1 && small + 1 == big)) {
		small = small/2 + small%2;
		big = big/2 + big%2;
		round++;
	}
	cout << round << endl;
}

