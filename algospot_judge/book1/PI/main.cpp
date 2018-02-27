#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 0x12345678
void init();
int getScore(int);
int numSeq[10000];
int numLen;
int cache[10000];
int pieceCache[10000][3];

int main() {
	int C;
	int sols[50];
	string numSeqStr;
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> numSeqStr;
		numLen = numSeqStr.size();
		for (int j=0; j<numLen; j++) {
			numSeq[j] = numSeqStr[j] - '0';
		}
		sols[i] = getScore(0);
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}

void init() {
	memset(cache, -1, sizeof(cache));
	memset(pieceCache, -1, sizeof(pieceCache));
}

// end is outside of array
int getPieceScore(int start, int end) {
	int& ret = pieceCache[start][end-start-3];
	if (ret != -1) return ret;

	bool allSame = true, alternate = true, arithSeq = true;
	int firstDiff = numSeq[start+1]-numSeq[start];
	for (int i=start; i<end-1; i++) {
		if (numSeq[i] != numSeq[i+1])
			allSame = false;
		if (numSeq[i+1] - numSeq[i] != firstDiff)
			arithSeq = false;
		if (i <end-2 && numSeq[i] != numSeq[i+2])
			alternate = false;
	}
	if (allSame)
		ret = 1;
	else if (arithSeq && (firstDiff == 1 || firstDiff == -1))
		ret = 2;
	else if (alternate)
		ret = 4;
	else if (arithSeq)
		ret = 5;
	else
		ret = 10;
	return ret;
}

int getScore(int start) {
	int& ret = cache[start];
	if (ret != -1) return ret;
	int remainLen = numLen - start;
	if (remainLen < 3) {
		ret = INF;
		return ret;
	}
	if (remainLen == 3 || remainLen == 4 || remainLen == 5) {
		ret = getPieceScore(start, numLen);
		return ret;
	}
	int minScore = getScore(start+3) + getPieceScore(start, start+3);
	minScore = min(minScore, getScore(start+4) + getPieceScore(start, start+4));
	minScore = min(minScore, getScore(start+5) + getPieceScore(start, start+5));
	ret = minScore;
	return ret;
}
