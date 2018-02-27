#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

int classCnt;
int minClassCnt;
int ranks[1000];
int students[1000];
vector< pair<double,int> > clsIdxOrdered;

bool decide(double upperLimitCulRank) {
	clsIdxOrdered.clear();
	for (int i=0; i<classCnt; i++) {
		clsIdxOrdered.push_back(pair<double, int>((double)students[i]*upperLimitCulRank-ranks[i], i));
	}
	sort(clsIdxOrdered.begin(), clsIdxOrdered.end(), greater< pair<double, int> >());
	double sum =0;
	for (int i=0; i<minClassCnt; i++) {
		sum += clsIdxOrdered[i].first;
	}
	return 0<=sum;
}

double solve() {
	double lo = 0, hi = 1.01, mid;
	for (int i=0; i<100; i++) {
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
		cin >> classCnt >> minClassCnt;
		for (int j=0; j<classCnt; j++) {
			cin >> ranks[j] >> students[j];
		}
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		cout << fixed << setprecision(10) << sols[i] << endl;
	}
}
