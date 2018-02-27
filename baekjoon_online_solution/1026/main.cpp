#include<iostream>
#include<algorithm>
using namespace std;
/*
proposition:
	for natural number n, A[n-1] <= A[n] and B[n-1] <= B[n]
	min = A[n]B[0] + ... + A[0]B[n] = sum(a=0 to n, A[a]B[n-a])
sub-proposition:
	for arbitray a,a' such that 0<=a<=n, 0<=a'<=n, a <> a'
	A[a]B[n-a] + A[a']B[n-a'] <= A[a]B[n-a']+A[a']B[n-a]
proof:
	A[a](B[n-a]-B[n-a']) <= A[a'](B[n-a]-B[n-a'])
	if a < a' => A[a] <= A[a'], 0<=B[n-a]-B[n-a']
	if a' < a => A[a'] <= A[a], B[n-a]-B[n-a']<=0
*/
int main(){
	int n;
	cin >> n;
	int* A = new int[n];
	int* B = new int[n];
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	for(int i=0;i<n;i++){
		cin >> B[i];
	}
	sort(A,A+n,greater<int>());
	sort(B,B+n);
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += A[i]*B[i];
	}
	cout << sum;
}
