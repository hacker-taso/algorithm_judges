// Start at 10:39PM Feb 27, 2018
// End at 10:41 PM Feb 27, 2018
// Retrospection:
// This is a same problem with A1 but needs to be faster.
// I just needed to change array sizes but I got runtime error.
// It's because I didn't change the array size of query (query[100] to query[1000]).
#include<iostream>
#include<map>
#include<cstring>
using namespace std;

int numEngine, numQuery;
map<string, int> engineToIdx;

// nth Query, nth Engine (using nth engine on nth query)
int query[1000];
int dp[1001][100];

int getMinSwitch(int queryIdx, int engine) {
	int minSwitch = 10000;
	if (queryIdx == numQuery)
		return 0;
	if (engine == -1) {
		for (int i=0; i<numEngine; i++)
			minSwitch = min(getMinSwitch(0, i), minSwitch);
			return minSwitch;
	}
	int & ret = dp[queryIdx][engine];
	if (ret != -1) return ret;
	if (query[queryIdx] == engine) {
		ret = 10000;
		return ret;
	}
	if (queryIdx == (numQuery-1)) {
		ret = 0;
		return ret;
	}
	for (int i=0; i<numEngine; i++) {
		if (i == engine)
			minSwitch = min(getMinSwitch(queryIdx+1, i), minSwitch);
		else
			minSwitch = min(getMinSwitch(queryIdx+1, i)+1, minSwitch);
	}
	ret = minSwitch;
	return ret;
}

void init() {
	memset(dp, -1, sizeof(dp));
}

int main() {
	int C;
	string tmpS;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> numEngine;
		cin.ignore();
		engineToIdx.clear();
		for (int j=0; j<numEngine; j++) {
			getline(cin, tmpS);
			engineToIdx.insert(make_pair(tmpS, j));
		}
		cin >> numQuery;
		cin.ignore();
		for (int j=0; j<numQuery; j++) {
			getline(cin, tmpS);
			query[j] = engineToIdx[tmpS];
		}
		int sol = getMinSwitch(0, -1);
		cout << "Case #" << i+1 << ": " << sol <<endl;
	}
}
