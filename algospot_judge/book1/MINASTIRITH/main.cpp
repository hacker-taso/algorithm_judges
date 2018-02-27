// At the first time, I chose wrong greedy algorithm. So, code is somewhat awkward.
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define _USE_MATH_DEFINES
using namespace std;
#define IMPOSSIBLE 0x76543210

int pointCnt;
double X[100];
double Y[100];
double R[100];
double startPoint = -1;
double leftPointRel[100];
double rightPointRel[100];

double getLeftPoint(int i) {
	double pointPos = atan2(Y[i], X[i]);
	double diff = 2*asin(R[i]/16);
	if (pointPos - diff < 0) {
		return 2*M_PI + pointPos - diff;
	} else if (2*M_PI < pointPos - diff) {
		return pointPos - diff - 2*M_PI;
	} else {
		return pointPos - diff;
	}
}

double getLeftPointRel(int i) {
	double absPos = getLeftPoint(i);
	if (0 <= absPos - startPoint)
		return absPos - startPoint;
	else
		return 2*M_PI + absPos - startPoint;
}

// it can exceed 2*PI
double getRightPointRel(int i) {
	double relLeftPos = getLeftPointRel(i);
	double diff = 2*asin(R[i]/16);
	return relLeftPos + diff*2;
}

bool myCompare(int i, int j) {
	return leftPointRel[i] < leftPointRel[j];
}

int solve() {
	int minSolCount = IMPOSSIBLE;
	// comparison with Jongman book:
	// Jongman book called a function n times.
	// I executed same code n times with for statement.
	for (int maxIdx=0; maxIdx<pointCnt; maxIdx++) {
		startPoint = getLeftPoint(maxIdx);
		// sort by left point with left point of maxIdx as start point
		for (int i=0; i<pointCnt; i++) {
			leftPointRel[i] = getLeftPointRel(i);
			rightPointRel[i] = getRightPointRel(i);
		}
		vector<int> incOrderPos;
		for (int i=0; i<pointCnt; i++) {
			if (maxIdx != i)
				incOrderPos.push_back(i);
		}
		sort(incOrderPos.begin(), incOrderPos.end(), myCompare);
		// iterate
		int curPointIdx = maxIdx;
		int maxRight = rightPointRel[curPointIdx];
		int maxRightIdx = curPointIdx;
		int targetIdx;
		double targetRight;
		int solCount = 1;
		bool nextExist = false;
		for (int i=0; i<pointCnt-1; i++) {
			targetIdx = incOrderPos[i];
			if (leftPointRel[targetIdx] <= rightPointRel[curPointIdx]) {
				nextExist = true;
				targetRight = rightPointRel[targetIdx];
				// found last point
				if (2*M_PI <= targetRight) {
					solCount++;
					minSolCount = min(solCount, minSolCount);
				} else if (maxRight < targetRight) {
					maxRightIdx = targetIdx;
					maxRight = targetRight;
				}
			} else {
				if (nextExist == false)
					break;
				curPointIdx=maxRightIdx;
				i--;
				solCount++;
				nextExist = false;
			}
		}
	}
	return minSolCount;
}

int main() {
	int C;
	int sols[50];
	ios_base::sync_with_stdio (false);
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> pointCnt;
		for (int j=0; j<pointCnt; j++) {
			cin >> X[j] >> Y[j] >> R[j];
		}
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		if (sols[i] == IMPOSSIBLE)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << sols[i] << endl;
	}
}
