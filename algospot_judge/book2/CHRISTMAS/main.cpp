#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int numChildren, numBoxes;
int partialSum[100001];

pair<int, int> solve() {
	const int DIVISOR=20091101;
	vector<long long> cnts(numBoxes, 0);
	for (int i=0; i<=numChildren; i++) {
		cnts[partialSum[i]]++;
	}
	int firstSol = 0;
	for (int i=0; i<numBoxes; i++) {
		if (2<=cnts[i])
			firstSol = ((long long)firstSol + cnts[i]*(cnts[i] - 1)/2)%DIVISOR;
	}

	vector<int> prev(numBoxes, -1);
	vector<int> rangeCnt(numChildren+1, 0);
	rangeCnt[0] = 0;
	prev[0] = 0;
	int prevLoc;
	for (int i=1; i<=numChildren; i++) {
		if (prev[partialSum[i]] != -1) {
			prevLoc = prev[partialSum[i]];
			rangeCnt[i] = max(rangeCnt[prevLoc]+1, rangeCnt[i-1]);
		}
		else
			rangeCnt[i] = rangeCnt[i-1];
		prev[partialSum[i]] = i;
	}
	int secondSol = rangeCnt[numChildren];
	return pair<int, int>(firstSol, secondSol);
}

int main() {
	int C, tmp;
	pair<int, int> sols[200];
	ios_base::sync_with_stdio(false);
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numChildren >> numBoxes;
		partialSum[0] = 0;
		for (int j=1; j<=numChildren; j++) {
			cin >> tmp;
			partialSum[j] = (partialSum[j-1] + tmp)%numBoxes;
		}
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		cout << sols[i].first << " " << sols[i].second <<endl;
	}
}
