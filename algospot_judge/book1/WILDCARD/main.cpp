#include<iostream>
#include<set>
#include<cstring>
using namespace std;

void init();
int isSatisfied(int, int);
string wildcard;
string filename;
int cache[101][101];

int main() {
	int C, N;
	set<string> sols[10];
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> wildcard;
		cin >> N;
		for (int j=0; j<N; j++) {
			init();
			cin >> filename;
			if (isSatisfied(0, 0)) {
				sols[i].insert(filename);
			}
		}
	}
	for (int i=0; i<C; i++) {
		for (set<string>::iterator it = sols[i].begin(); it!=sols[i].end(); it++) {
			cout << *it << endl;
		}
	}
}

void init() {
	memset(cache, -1, sizeof(cache));
}

int isSatisfied(int fIndex, int wIndex) {
	if (filename.size() == fIndex && wildcard.size() == wIndex) {
		return true;
	}
	int& ret = cache[fIndex][wIndex];
	if (ret != -1)
		return ret;

	if (filename.size() != fIndex && wildcard.size() == wIndex) {
		ret = false;
	} else if (filename.size() == fIndex && wildcard.size() != wIndex) {
		if (wildcard[wIndex] == '*')
			ret = isSatisfied(fIndex, wIndex+1);
		else
			ret = false;
	} else if (wildcard[wIndex] == '*') {
		bool satisfied = false;
		for (int newFIndex=fIndex; newFIndex<=filename.size(); newFIndex++) {
			if (isSatisfied(newFIndex,wIndex+1)){
				satisfied = true;
				break;
			}
		}
		ret = satisfied;
	} else if (wildcard[wIndex] == '?' || wildcard[wIndex] == filename[fIndex]) {
		ret = isSatisfied(fIndex+1, wIndex+1);
	} else {
		ret = false;
	}
	return ret;
}
