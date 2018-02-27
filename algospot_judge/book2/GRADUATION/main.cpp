// Comment on the code long after writing this code:
// I should have implemented memoization.
// This code's upper limit of time complexity is
// (the number of subset of valid class) ^ (function call depth)
// = (2^11)^10 (Actually it would be much less than this)
#include<iostream>
#include<bitset>
#define INF 0x76543210
using namespace std;

int numClass, numRequired, numSemester, oneSemMax;
int prerequ[12], semesterCls[11];

void init() {
	for (int i=0; i<12; i++) { prerequ[i] = 0; }
	for (int i=0; i<11; i++) { semesterCls[i] = 0; }
}

// get total semester count that should be required more
// when we've already taken "taken" classes and current semester is semIdx.
// semIdx uses one-based indexing.
int getTotalSemCnt(int taken, int semIdx) {
	if (numRequired<=__builtin_popcount(taken))
		return 0;
	if (numSemester<semIdx)
		return INF;
	int curSemCls = semesterCls[semIdx];
	int validCls = 0;
	for (int cls=0; cls<numClass; cls++) {
		// open in currSem && not taken && prerequisite satisfied
		if ((curSemCls & (1<<cls)) && ((~taken) & (1<<cls)) && ((prerequ[cls] & taken) == prerequ[cls]) ) {
			validCls |= 1<<cls;
		}
	}
	int minTotalCnt = INF;
	if (__builtin_popcount(validCls)<=oneSemMax) {
		// attend or leave
		minTotalCnt = min(getTotalSemCnt(taken|validCls, semIdx+1) + 1, getTotalSemCnt(taken, semIdx+1));
	}
	else {
		// attend
		for (int subset=validCls; subset; subset=(subset-1)&validCls) {
			if (__builtin_popcount(subset)==oneSemMax)
				minTotalCnt = min(getTotalSemCnt(taken|subset, semIdx+1), minTotalCnt);
		}
		// leave
		minTotalCnt = min(minTotalCnt + 1, getTotalSemCnt(taken, semIdx+1));
	}
	return minTotalCnt;
}

int solve() {
	return getTotalSemCnt(0, 1);
}

int main() {
	int C, sols[50], numPrereqTmp, numClsTmp, tmp;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> numClass >> numRequired >> numSemester >> oneSemMax;
		for (int clsIdx=0; clsIdx<numClass; clsIdx++) {
			cin >> numPrereqTmp;
			for (int k=0; k<numPrereqTmp; k++) {
				cin >> tmp;
				prerequ[clsIdx] |= 1<<tmp;
			}
		}
		for (int semIdx=1; semIdx<=numSemester; semIdx++) {
			cin >> numClsTmp;
			for (int k=0; k<numClsTmp; k++) {
				cin >> tmp;
				semesterCls[semIdx] |= 1<<tmp;
			}
		}
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		if (100<sols[i])
			cout << "IMPOSSIBLE" << endl;
		else
			cout << sols[i] << endl;
	}
}
