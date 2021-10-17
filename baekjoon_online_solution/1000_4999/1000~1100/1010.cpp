#include<iostream>
using namespace std;
/*
	f(N,M) = if (N=1) then M
	         else sum(i=1 to M-N+1, f(N-1,M-i))

	f(1,30) = 30
	f(2,30) = 29 + 28 + ... + 1
	f(3,30) = (28 + 27 + ... + 1) + (27 + 26 + ... + 1) + ... + (2 + 1) + 1
	...
	time complexity for N,M: O(M^N)
	but if memoizing used, the time used can be asymptotically constant
*/
int memo[30][30];
int f(int n,int m){
	if(memo[n][m])
		return memo[n][m];

	if(n == 1)
		return m;

	int sum = 0;
	for(int i=n-1;i<=m-1;i++)
		sum+=f(n-1,i);
	memo[n][m] = sum;

	return sum;
}

int main(){
	int T;
	cin >> T;
	int N,M;
	for(int i=0;i<T;i++){
		cin >> N >> M;
		cout << f(N,M) << endl;
	}
}
