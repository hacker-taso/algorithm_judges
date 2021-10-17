#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/*
	find the number of natural number X that satisfy this proposition:
 	For min <= X <= max, there is no natural number D, X % (D^2) = 0 ( 1 < D <=sqrt(X) )
	                   =>there is no natural number D,  X % D = 0 and (X / D) % D = 0 ( 1 < D < sqrt(X) )
	time complexity: O( (max - min)*sqrt(max) )  => Too big 	
	it isn't needed to check all natural number D which 1 < D < sqrt(X). 
	it is only needed to check all primary number  D which 1 < D < sqrt(X)
	the number of prime numeber between 1 and 1000000 : 78498
	the number of calculation: max 78498 * 1000000 * 2  => also too big

	instead use Seive of Eratosthenes (https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4)
	for 2: 1000000/2 calculation = 500000
	for 3: 1000000/3 calculation = 333333
	for 5: 200000
	for 7: 142857
	for 11: 76923
	... (approximately 160 numbers)
	for 997: 1003
	... (approximately 1100 numbers)
	for 9973: 100
  ... (approximately 77200 numbers)
  the number of calcuation: less than 500000 + 333333 + 200000 + 142857 + 76923*160 + 1003*1100 + 100*77200 = 22307170
	                          (less than 25 million. maybe more less than this)
*/
vector<long long> findPrimeNumberSqrs() {
	// Sieve of Eratosthenes
	vector<bool> primeNumberMap(1000001, true);
	primeNumberMap[0] = false;
	primeNumberMap[1] = false;
	for (int i=2; i<=1000; i++) {
		if (primeNumberMap[i]) {
			for (int j=i*i; j<=1000000; j+=i) {
				primeNumberMap[j] = false;
			}	
		}
	}

	vector<long long> primeNumberSqrs;
	for (long long i=0; i<=1000000; i++) {
		if (primeNumberMap[i]) {
			primeNumberSqrs.push_back(i*i);
		}
	}
	return primeNumberSqrs;
}

int main(){
	long long min;
	long long max;
	cin >> min >> max;

	vector<long long> primeNumberSqrs = findPrimeNumberSqrs();
	vector<long long>::size_type primeNumberSqrCnt = primeNumberSqrs.size();

	int numCnt = max - min + 1;
	long long primeSqr;
	vector<bool> squareNoNoMap(numCnt, true);
	for (vector<long long>::size_type i=0; i<primeNumberSqrCnt; i++) {
		primeSqr = primeNumberSqrs[i];
		for (long long j=((min-1)/primeSqr)*primeSqr + primeSqr; j<=max; j+=primeSqr) {
			squareNoNoMap[j-min] = false;
		}
	}
	
	int squareNoNoCnt = 0;
	for (vector<bool>::size_type i=0; i<numCnt; i++) {
		if (squareNoNoMap[i]) {
			squareNoNoCnt++;
		}
	}
	cout << squareNoNoCnt << endl;
}

