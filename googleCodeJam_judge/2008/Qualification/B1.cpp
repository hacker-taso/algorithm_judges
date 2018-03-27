// I read the editorial.
#include<iostream>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int turnAroundT, nAtoB, nBtoA;
int nFrom[2];
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >, 
	greater<pair<pair<int, int>, int> > > scheduleQ;

void init() {
	memset(nFrom, 0, sizeof(nFrom));
	scheduleQ = priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int> >, 
	greater<pair<pair<int, int>, int> > >();
}

void doUntilComplete() {
	priority_queue<int, vector<int>, greater<int> > q[2];
	while (!scheduleQ.empty()) {
		pair<pair<int, int>, int> cur = scheduleQ.top();
		scheduleQ.pop();
		int from = cur.second;
		int to = !from;
		if (q[from].empty() || cur.first.first<q[from].top()) {
			nFrom[from]++;
		} else {
			q[from].pop();
		}
		q[to].push(cur.first.second+turnAroundT);
	}
}

int main() {
	int C;
	stringstream ss;
	cin >> C;
	string tmpS, tmpS2;
	for (int i=0; i<C; i++) {
		init();
		cin >> turnAroundT;
		cin >> nAtoB;
		cin >> nBtoA;
		for (int j=0; j<nAtoB; j++) {
			cin >> tmpS;
			ss = stringstream(tmpS);
			getline(ss, tmpS2, ':');
			int departure = stoi(tmpS2)*60;
			getline(ss, tmpS2, ':');
			departure += stoi(tmpS2);
			cin >> tmpS;
			ss = stringstream(tmpS);
			getline(ss, tmpS2, ':');
			int arrival = stoi(tmpS2)*60;
			getline(ss, tmpS2, ':');
			arrival += stoi(tmpS2);
			scheduleQ.push(make_pair(make_pair(departure, arrival), 0));
		}
		for (int j=0; j<nBtoA; j++) {
			cin >> tmpS;
			ss = stringstream(tmpS);
			getline(ss, tmpS2, ':');
			int departure = stoi(tmpS2)*60;
			getline(ss, tmpS2, ':');
			departure += stoi(tmpS2);
			cin >> tmpS;
			ss = stringstream(tmpS);
			getline(ss, tmpS2, ':');
			int arrival = stoi(tmpS2)*60;
			getline(ss, tmpS2, ':');
			arrival += stoi(tmpS2);
			scheduleQ.push(make_pair(make_pair(departure, arrival), 1));
		}
		doUntilComplete();
		cout << "Case #" << i+1 << ": " << nFrom[0] << " " << nFrom[1] << endl;
	}
}
