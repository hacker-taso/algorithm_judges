#include<iostream>
#include<algorithm>
using namespace std;
#define NEG_INF 0x87654321
#define LEFT_GET 0
#define RIGHT_GET 1
#define LEFT_REMOVE 2
#define RIGHT_REMOVE 3

int seq[50];
int seqLen;
// start, len
int cache[50][51];

int Action[4][2] = { {+1, -1}, {0, -1}, {+2, -2}, {0, -2} };

void init() {
	for (int i=0; i<50; i++) {
		for (int j=0; j<51; j++) {
			cache[i][j] = NEG_INF;
		}
	}
}

// max(increase of my selection - max(nextState))
int getMaxScoreDiff(int startIdx, int remainLen) {
	if (remainLen == 0)
		return 0;
	int& ret = cache[startIdx][remainLen];
	if (ret != NEG_INF) return ret;

	int maxScore;
	int leftGetScore = seq[startIdx] - getMaxScoreDiff(startIdx + Action[LEFT_GET][0], remainLen + Action[LEFT_GET][1]);
	int rightGetScore = seq[startIdx+remainLen-1] - getMaxScoreDiff(startIdx + Action[RIGHT_GET][0], remainLen + Action[RIGHT_GET][1]);
	maxScore = max(leftGetScore, rightGetScore);
	if (1 < remainLen) {
		int leftRemoveScore = -getMaxScoreDiff(startIdx + Action[LEFT_REMOVE][0], remainLen + Action[LEFT_REMOVE][1]);
		maxScore = max(maxScore, leftRemoveScore);
		int rightRemoveScore = -getMaxScoreDiff(startIdx + Action[RIGHT_REMOVE][0], remainLen + Action[RIGHT_REMOVE][1]);
		maxScore = max(maxScore, rightRemoveScore);
	}
	ret = maxScore;
	return maxScore;
}

int main() {
	int C;
	int sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> seqLen;
		for (int j=0; j<seqLen; j++) {
			cin >> seq[j];
		}
		sols[i] = getMaxScoreDiff(0, seqLen);
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
