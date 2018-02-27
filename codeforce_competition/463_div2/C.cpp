// for (int x=0), linear diophantine equations positive solutions
// x should be updated but local x hided the result
// until 1:00
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int N, A, B, x, y=-1;
	cin >> N >> A >> B;
	for (x=0; x*A<=N; x++) {
		if ((N-x*A)%B == 0) {
			y = (N-x*A)/B;
			break;
		}
	}
	if (y==-1) {
		cout << -1 <<endl;
		return 0;
	}
	vector<int> perm(N, 0);
	for (int i=0; i<x; i++) {
		for (int a=0; a<A-1; a++) {
			perm[i*A+a] = i*A+a+1+1;
		}
		perm[i*A+A-1] = i*A+0+1;
	}
	int start = x*A;
	for (int i=0; i<y; i++) {
		for (int b=0; b<B-1; b++) {
			perm[start+i*B+b] = start+i*B+b+1+1;
		}
		perm[start+i*B+B-1] = start+i*B+0+1;
	}
	for (int i=0; i<N; i++)
		cout << perm[i] << " ";
	cout <<endl;
}
