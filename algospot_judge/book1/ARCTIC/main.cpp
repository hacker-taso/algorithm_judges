#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
using namespace std;

int pointCnt;
double X[100], Y[100];
double biggestDist;
// dist, there
vector< pair<double, int> > dist[100];

void distInit() {
	double distTmp;
	biggestDist = -1;
	for (int i=0; i<pointCnt; i++) {
		dist[i].clear();
		for (int j=0; j<pointCnt; j++) {
			if (i!=j) {
				distTmp = sqrt(pow(X[i]-X[j], 2)+pow(Y[i]-Y[j], 2));
				biggestDist = max(biggestDist, distTmp);
				dist[i].push_back(pair<double, int>(distTmp, j));
			}
		}
		sort(dist[i].begin(), dist[i].end());
	}
}

bool decide(double distUpperLimit) {
	bool checked[100] = {0};
	queue<int> q;
	int curPoint;
	checked[0] = 1;
	q.push(0);
	while (!q.empty()) {
		curPoint = q.front();
		q.pop();
		for (vector< pair<double, int> >::iterator it=dist[curPoint].begin(); it != dist[curPoint].end(); it++) {
			if (it->first<=distUpperLimit) {
				if (checked[it->second] == 0) {
					q.push(it->second);
					checked[it->second] = 1;
				}
			}
			else
				break;
		}
	}
	if (count(checked, checked+pointCnt, true) == pointCnt)
		return true;
	else
		return false;
}

double solve() {
	distInit();
	double lo = 0, hi = biggestDist, mid;
	for (int i=0; i<50; i++) {
		mid = (lo + hi)/2;
		if (decide(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}

int main() {
	int C;
	double sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> pointCnt;
		for (int j=0; j<pointCnt; j++) {
			cin >> X[j] >> Y[j];
		}
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		cout << fixed << setprecision(2) << sols[i] << endl;
	}
}
