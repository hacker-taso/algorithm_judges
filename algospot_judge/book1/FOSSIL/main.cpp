#include<iostream>
#include<algorithm>
#include<iomanip>
#define INF_COORD 101
#define NEGINF_COORD -1
using namespace std;

int pointCnt1, pointCnt2;
double pointX1[100], pointY1[100];
double pointX2[100], pointY2[100];
double maxX1, maxX2, minX1, minX2;

double getBigY(double x, double* pointX, double* pointY, int pointCnt) {
	double X1, X2, Y1, Y2;
	for (int i=0; i<pointCnt; i++) {
		X1 = pointX[(i+1)%pointCnt]; X2 = pointX[i];
		if (X1 < x && x<= X2) {
			Y1 = pointY[(i+1)%pointCnt]; Y2 = pointY[i];
			return (x-X1)*(Y2-Y1)/(X2-X1)+Y1;
		}
	}
}

double getSmallY(double x, double* pointX, double* pointY, int pointCnt) {
	double X1, X2, Y1, Y2;
	for (int i=0; i<pointCnt; i++) {
		X1 = pointX[i]; X2 = pointX[(i+1)%pointCnt];
		if (X1 < x && x<= X2) {
			Y1 = pointY[i]; Y2 = pointY[(i+1)%pointCnt];
			return (x-X1)*(Y2-Y1)/(X2-X1)+Y1;
		}
	}
}

void solveInit() {
	maxX1 = NEGINF_COORD; minX1 = INF_COORD;
	for (int i=0; i<pointCnt1; i++) {
		maxX1 = max(maxX1, pointX1[i]);
		minX1 = min(minX1, pointX1[i]);
	}
	maxX2 = NEGINF_COORD; minX2 = INF_COORD;
	for (int i=0; i<pointCnt2; i++) {
		maxX2 = max(maxX2, pointX2[i]);
		minX2 = min(minX2, pointX2[i]);
	}
}

double solve() {
	solveInit();

	double right = min(maxX1, maxX2);
	double left = max(minX1, minX2);
	if (right <= left)
		return 0;

	double one, two;
	double bigY1[2], bigY2[2], smallY1[2], smallY2[2];
	double dist[2];
	for (int i=0; i<100; i++) {
		one = (left*2 + right)/3;
		two = (left + right*2)/3;
		bigY1[0] = getBigY(one, pointX1, pointY1, pointCnt1);
		bigY2[0] = getBigY(one, pointX2, pointY2, pointCnt2);
		smallY1[0] = getSmallY(one, pointX1, pointY1, pointCnt1);
		smallY2[0] = getSmallY(one, pointX2, pointY2, pointCnt2);
		dist[0] = min(bigY1[0], bigY2[0]) - max(smallY1[0], smallY2[0]);

		bigY1[1] = getBigY(two, pointX1, pointY1, pointCnt1);
		bigY2[1] = getBigY(two, pointX2, pointY2, pointCnt2);
		smallY1[1] = getSmallY(two, pointX1, pointY1, pointCnt1);
		smallY2[1] = getSmallY(two, pointX2, pointY2, pointCnt2);
		dist[1] = min(bigY1[1], bigY2[1]) - max(smallY1[1], smallY2[1]);
		if (dist[0] < dist[1])
			left = one;
		else
			right = two;
	}
	return max((dist[0]+dist[1]) / 2, 0.0);
}

int main() {
	int C;
	double sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> pointCnt1 >> pointCnt2;
		for (int j=0; j<pointCnt1; j++) {
			cin >> pointX1[j] >> pointY1[j];
		}
		for (int j=0; j<pointCnt2; j++) {
			cin >> pointX2[j] >> pointY2[j];
		}
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		cout << fixed << setprecision(10) << sols[i] << endl;
	}
}
