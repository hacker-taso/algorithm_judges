#include<iostream>
#include<vector>
using namespace std;
/*
	 I'll use Sieve of Eratosthenes.
	 ref. https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4
	 time complexity: O(n) (n is the number of numbers to be decided) 
*/
vector<bool> getPrimeNumberMap(){
	int maxNum = 1000;
	vector<bool> primeNumberMap(maxNum+1, true);
	primeNumberMap[0] = false;
	primeNumberMap[1] = false;
	for (vector<bool>::size_type i=2; i*i<=maxNum;i++){
		if(primeNumberMap[i]){
			for(int j=i*i; j<=maxNum; j+=i){
				primeNumberMap[j] = false;
			}
		}
	}
	return primeNumberMap;
}

int main() {
	vector<bool> primeNumberMap = getPrimeNumberMap();
	int N;
	cin >> N;
	int num;
	int primeCnt = 0;
	for(int i=0; i<N; i++){
		cin >> num;
		if (primeNumberMap[num])
			primeCnt++;
	}
	cout << primeCnt << endl;
}

