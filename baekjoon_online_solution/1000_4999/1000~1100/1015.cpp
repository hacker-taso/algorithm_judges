#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
/*
	A[x] is P[x]th smallest number.
*/
using namespace std;
int main() {
	int N;
	cin >> N;
 	vector<int> A(N);
	for (int i=0; i<N; i++) {
		cin >> A[i];
	}
	vector<int> sortedA(N);
	copy(A.begin(), A.end(), sortedA.begin());
	sort(sortedA.begin(), sortedA.end());
	vector<int> P(N);
	map<int, int> Acnt;
	int rank;
	for (int i=0; i<N; i++) {
		rank = distance(sortedA.begin(), find(sortedA.begin(), sortedA.end(), A[i]));
		P[i] = rank + Acnt[A[i]];
		Acnt[A[i]]++;
	}
	string outStr = to_string(P[0]);
	for (int i=1; i<N; i++) {
		outStr += " " + to_string(P[i]);
	}
	cout << outStr << endl;
}

