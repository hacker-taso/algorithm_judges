#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int cache[500];
int seqLen;
int seq[500];

void init() {
	memset(cache, -1, sizeof(cache));
}

int fromHere(int i) {
	if (seqLen<=i) return 0;
	int& ret = cache[i];
	if (ret != -1) return ret;
	int curNum = seq[i];
	int maxLen = 0;
	for (int j=i+1; j<seqLen; j++) {
		if (curNum < seq[j])
			maxLen = max(maxLen, fromHere(j));
	}
	ret = 1+maxLen;
	return ret;
}

int solve() {
	int maxLen = 0;
	for (int i=0; i<seqLen; i++) {
		maxLen = max(maxLen, fromHere(i));
	}
	return maxLen;
}

int main() {
	int C;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> seqLen;
		for (int j=0; j<seqLen; j++) {
			cin >> seq[j];
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
