// Retrospection: I've made a mistake on updating value.
// like this: nth = 0; outLen = nth ~~~~; (nth should be updated later in correct order.)
#include<iostream>
using namespace std;
#define X_NEXT 0
#define Y_NEXT 1
#define NTH_MAX 1000000000

string getPiece(int gen, int nth, int outLen, int curPatternIdx);
void fillGenLen();
const string patterns[2] = {"X+YF", "FX-Y"};
const string gen0 = "FX";
int genLen[51];

int main() {
	fillGenLen();
	int C;
	string sols[50];
	cin >> C;
	int goalGen, nth, outLen;
	for (int i=0; i<C; i++) {
		cin >> goalGen >> nth >> outLen;
		if (goalGen == 0) {
			sols[i] = gen0.substr(nth-1, outLen);
		} else if (goalGen == 1) {
			sols[i] = ("F"+patterns[0]).substr(nth-1, outLen);
		} else {
			if (nth==1) {
				sols[i] = "F";
				outLen--;
			}
			nth--;
			if (0<nth)
				sols[i] += getPiece(goalGen, nth-1, outLen, 0);
		}
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}

// nth: zero idx
string getPiece(int gen, int nth, int outLen, int curPatternIdx) {
	if (outLen <= 0)
		return "";
	if (gen == 1) {
		return patterns[curPatternIdx].substr(nth, outLen);
	}
	const string& pattern = patterns[curPatternIdx];
	string piece;
	int nextPatternIdx;
	for (int i=0; i<4; i++) {
		if (pattern[i] == 'X' || pattern[i] == 'Y') {
			nextPatternIdx = pattern[i] == 'X' ? X_NEXT : Y_NEXT;
			if (nth+outLen <= genLen[gen-1]) {
				piece += getPiece(gen-1, nth, outLen, nextPatternIdx);
				break;
			} else if (nth<genLen[gen-1] && genLen[gen-1]<nth+outLen) {
				piece += getPiece(gen-1, nth, outLen, nextPatternIdx);
				outLen = nth+outLen - genLen[gen-1];
				nth = 0;
			} else if (genLen[gen-1]<=nth) {
				nth -= genLen[gen-1];
			}
		} else { // +, F
			if (nth == 0 && 0<outLen) {
				piece += pattern[i];
				outLen -= 1;
			} else if (0 < nth) {
				nth -= 1;
			}
		}
	}
	return piece;
}

void fillGenLen() {
	int XYCnt[51] = {1};
	int etcCnt[51] = {1};
	genLen[0] = 2;
	const int MAX_VALUE = NTH_MAX+100;
	for (int i=1; i<=50; i++) {
		XYCnt[i] = min(MAX_VALUE, XYCnt[i-1]*2);
		etcCnt[i] = min(MAX_VALUE, etcCnt[i-1] + XYCnt[i]);
		genLen[i] = min(MAX_VALUE, XYCnt[i] + etcCnt[i]);
	}
	for (int i=0; i<=50; i++) {
		genLen[i] -= 1;
	}
}
