#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 0x76543210
using namespace std;

void initBeforeInput();
void initAfterInput();
int getMinScore(int, int);
int seqLen;
int seq[100];
int numberCnt;
int cache[101][10];
int scores[100][100];

int main() {
	int C;
	int sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		initBeforeInput();
		cin >> seqLen >> numberCnt;
		for (int j=0; j<seqLen; j++)
			cin >> seq[j];
		initAfterInput();
		sols[i] = getMinScore(0, numberCnt);
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}

void initBeforeInput() {
	memset(cache, -1, sizeof(cache));
}
void initAfterInput() {
	int diff, candidate1, candidate2;
	//sort
	sort(seq, seq+seqLen);
	//calculate means
	int means[100][100];
	for (int i=0; i<seqLen; i++) {
		means[i][i] = seq[i];
	}
	for (int i=0; i<seqLen; i++) {
		for (int j=i+1; j<seqLen; j++) {
			means[i][j] = means[i][j-1] + seq[j];
			means[i][j-1] = means[i][j-1]/(j-i);
		}
		means[i][seqLen-1] = means[i][seqLen-1]/(seqLen-i);
	}
	// calculate scores
	for (int i=0; i<seqLen; i++) {
		for (int j=i; j<seqLen; j++) {
			candidate1 = 0;
			for (int seqIndex=i; seqIndex<=j; seqIndex++) {
				diff = seq[seqIndex]-means[i][j];
				candidate1 += diff*diff;
			}
			candidate2 = 0;
			for (int seqIndex=i; seqIndex<=j; seqIndex++) {
				diff = seq[seqIndex]-(means[i][j]+1);
				candidate2 += diff*diff;
			}
			scores[i][j] = min(candidate1, candidate2);
		}
	}
}

int getMinScore(int start, int remainingCnt) {
	int& ret = cache[start][remainingCnt];
	if (ret!=-1) return ret;
	if (start == seqLen) {
		ret = 0;
		return ret;
	} else if (remainingCnt == 0) {
		ret = INF;
		return ret;
	}

	int minScore = INF;
	for (int i=start; i<seqLen; i++) {
		minScore = min(minScore, scores[start][i] + getMinScore(i+1, remainingCnt-1));
	}
	ret = minScore;
	return ret;
}
