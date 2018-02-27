#include<iostream>
using namespace std;
/*
	step1. convert goal number to binary number
	step2. count number of 1 in this binary number
	=
	step1. divide number by 2 until quotient become 0
	step2. count the number of time when remainder is 1
*/

int main(){
	int X;
	cin >> X;
	
	int ones = 0;
	int remainder;
	while (0 < X) {
		ones += X%2;
		X = X/2;
	}
	cout << ones << endl;
}

