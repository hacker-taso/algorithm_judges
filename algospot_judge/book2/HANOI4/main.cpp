// note: I thought I should express a state using 4*12 bits (# of poles * # of disks)
// So, I needed to use map. But actually, I can express a state using 2*12 bits.
// So, I can use array to save state's distances.
#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cassert>
#include<cstring>
#define INF 0x76543210
using namespace std;

int dists[1<<24];
int numDish;

vector<int> getNextStates(const int state) {
	vector<int> nexts;
	int topDish[4] = {INF,INF,INF,INF};
	for (int i=numDish-1; 0<=i; i--) {
		topDish[(state >> (i*2)) & 3] = i;
	}
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			if (i==j || topDish[i] == INF) continue;
			if (topDish[i] < topDish[j]) { // if we can move i to j
				nexts.push_back(state ^ (i<< (topDish[i]*2)) ^ (j<<(topDish[i]*2)));
			}
		}
	}
	return nexts;
}

int incr(const int x) {
	if (x==0) return 0;
	else if(0<x) return x+1;
	else return x-1;
}


//debugging function
void printState(const int s) {
	for (int i=0; i<numDish; i++) {
		cout << "i:" << (i+1) << "," << (s>>(i*2) & 3) << endl;
	}
}

int solve(int initS) {
	memset(dists, 0, sizeof(dists));
	dists[initS] = 1;
	int goalS = (1<<(numDish*2))-1;
	dists[goalS] = -1;
	if (initS == goalS) return 0;
	queue<int> q;
	q.push(initS);
	q.push(goalS);
	while (!q.empty()) {
		int curS = q.front();
		int curDist = dists[curS];
		int nextDist = incr(curDist);
		q.pop();
		vector<int> nextStates = getNextStates(curS);
		for (int i=0; i<nextStates.size(); i++) {
		//printState(nextStates[i]);
			if (dists[nextStates[i]] == 0) {
				dists[nextStates[i]] = nextDist;
				q.push(nextStates[i]);
			} else if (dists[nextStates[i]] * curDist < 0) {
				return abs(dists[nextStates[i]]) + abs(curDist) - 1;
			}
		}
	}
	return -1;
}

int main() {
	int C;
	vector<int> sols;
	cin >>C;
	for (int i=0; i<C; i++) {
		cin >> numDish;
		int numDishLoc;
		int dishIdx;
		int initS = 0;
		for (int j=0; j<4; j++) {
			cin >> numDishLoc;
			for (int k=0; k<numDishLoc; k++) {
				cin >> dishIdx;
				initS |= j<<(dishIdx-1)*2;
			}
		}
		sols.push_back(solve(initS));
	}
	for (int i=0; i<C; i++) {
		assert (0<= sols[i]);
		cout << sols[i] <<endl;
	}
}
