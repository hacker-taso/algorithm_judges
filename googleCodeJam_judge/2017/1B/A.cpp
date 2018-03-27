// Start at 09:06PM March 26, 2018
// End at 09:27PM March 26, 2018
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

double goal;
int numHorse;
// pos, speed
vector<pair<double, double> > horses;

double solve() {
	sort(horses.begin(), horses.end(), greater<pair<double,double> >());
	double maxGoalTime = 0;
	for (int i=0; i<numHorse; i++) {
		double initPos = horses[i].first;
		double speed = horses[i].second;
		double goalTime = (goal-initPos)/speed;
		maxGoalTime = max(goalTime, maxGoalTime);
	}
	return goal/maxGoalTime;
}

int main() {
	int T;
	double tmp1;
	double tmp2;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> goal >> numHorse;
		horses = vector<pair<double,double> >();
		for (int j=0; j<numHorse; j++) {
			cin >> tmp1 >> tmp2;
			horses.push_back(make_pair(tmp1, tmp2));
		}
		cout << "Case #" << i+1 << ": " <<fixed << setprecision(9)<< solve() << endl;
	}
}
