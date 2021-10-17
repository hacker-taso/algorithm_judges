// Retrospection: I couldn't find the reason why it makes wrong answers.
#include<iostream>
using namespace std;
// should be run in log or constant.
long long query;
long long n;

long long solve() {
	long long seqN = n;
	long long seqIdx = query;
	if (query%2 == 1)
		return (query+1)/2;
	long long sol = (seqN+1)/2;
	bool evenIdxPreserve = (seqN%2) == 1;
	seqN = seqN/2;
	seqIdx = seqIdx/2;
	int numLoop = 0;
	while (true) {
		numLoop++;
		if ((evenIdxPreserve && (seqIdx%2 == 0)) || ((!evenIdxPreserve) && (seqIdx%2 == 1))) {
			sol += (seqIdx+1)/2;
			return sol;
		}
		if (100 < numLoop)
			return n;
		if (evenIdxPreserve) {
			sol += seqN/2;
		} else {
			sol += (seqN+1)/2;
		}
		seqIdx = (seqIdx-1)/2 + 1;
		evenIdxPreserve = (evenIdxPreserve && (seqN%2 == 0)) || ((!evenIdxPreserve) && (seqN%2 == 1));
		seqN = seqN/2;
	}
}

int main() {
	int numQuery;
	cin >> n >> numQuery;
	for (int i=0; i<numQuery; i++) {
		cin >> query;
		cout << solve() << endl;
	}
}
