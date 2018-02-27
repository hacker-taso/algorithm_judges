#include<iostream>
#include<algorithm>
#include<complex>
using namespace std;

void init();
void reconstruct(int pos);
void parseGivenSentence(int strNumWords, string* givenSentenceStr);
double findMaxProb(int, int);
int allNumWords, numSentences;
string words[500];
double firstProb[500];
double adjProb[500][500];
double recogProb[500][500];
int strNumWords;
int givenSentence[100];
int sentenceIdx;
double cache[100][500];
//solution
int sols[20][100];
int solWordCnt[20];

int main() {
	std::ios_base::sync_with_stdio (false);
	cin >> allNumWords >> numSentences;
	for (int i=0; i<allNumWords; i++) {
		cin >> words[i];
	}
	for (int i=0; i<allNumWords; i++) {
		cin >> firstProb[i];
		firstProb[i] = log(firstProb[i]);
	}
	for (int i=0; i<allNumWords; i++) {
		for (int j=0; j<allNumWords; j++) {
			cin >> adjProb[i][j];
			adjProb[i][j] = log(adjProb[i][j]);
		}
	}
	for (int i=0; i<allNumWords; i++) {
		for (int j=0; j<allNumWords; j++) {
			cin >> recogProb[i][j];
			recogProb[i][j] = log(recogProb[i][j]);
		}
	}
	string givenSentenceStr[100];
	for (sentenceIdx=0; sentenceIdx<numSentences; sentenceIdx++) {
		init();
		cin >> strNumWords;
		solWordCnt[sentenceIdx] = strNumWords;
		for (int j=0; j<strNumWords; j++) {
			cin >> givenSentenceStr[j];
		}
		parseGivenSentence(strNumWords, givenSentenceStr);
		findMaxProb(0, -1);
		reconstruct(0);
	}
	for (int i=0; i<numSentences; i++) {
		for (int j=0; j<solWordCnt[i]; j++) {
			cout << words[sols[i][j]];
			if (j+1 != solWordCnt[i])
				cout << " ";
		}
		cout << endl;
	}
}

void init() {
	for (int i=0; i<100; i++) {
		for (int j=0; j<500; j++) {
			cache[i][j] = 100;
		}
	}
}

void reconstruct(int pos) {
	if (pos == strNumWords) {
		return;
	}
	double maxProb = -1e200;
	int maxProbWordIdx = -1;
	if (pos == 0) {
		for (int i=0; i<allNumWords; i++) {
			int recognizedWord = givenSentence[pos];
			if (maxProb < firstProb[i]+recogProb[i][recognizedWord]+findMaxProb(pos+1, i)) {
				maxProb = firstProb[i]+recogProb[i][recognizedWord]+findMaxProb(pos+1, i);
				maxProbWordIdx = i;
			}
		}
		sols[sentenceIdx][0] = maxProbWordIdx;
	} else {
		int recognizedWord = givenSentence[pos];
		int beforeWord = sols[sentenceIdx][pos-1];
		for (int wordIdx=0; wordIdx<allNumWords; wordIdx++) {
			if (maxProb < adjProb[beforeWord][wordIdx]+recogProb[wordIdx][recognizedWord]+findMaxProb(pos+1, wordIdx)) {
				maxProb = adjProb[beforeWord][wordIdx]+recogProb[wordIdx][recognizedWord]+findMaxProb(pos+1, wordIdx);
				maxProbWordIdx = wordIdx;
			}
		}
		sols[sentenceIdx][pos] = maxProbWordIdx;
	}
	reconstruct(pos+1);
}

void parseGivenSentence(int strNumWords, string* givenSentenceStr) {
	for (int i=0; i<strNumWords; i++) {
		for (int j=0; j<allNumWords; j++) {
			if (givenSentenceStr[i] == words[j])
				givenSentence[i] = j;
		}
	}
}

double findMaxProb(int pos, int beforeWord) {
	double maxProb = -1e200;
	if (pos == 0) {
		int recognizedWord = givenSentence[pos];
		for (int i=0; i<allNumWords; i++) {
			maxProb = max(maxProb, firstProb[i]+recogProb[i][recognizedWord]+findMaxProb(pos+1, i));
		}
		return maxProb;
	}
	if (pos == strNumWords)
		return 0;
	double& ret = cache[pos][beforeWord];
	if (ret != 100) return ret;
	int recognizedWord = givenSentence[pos];
	for (int wordIdx=0; wordIdx<allNumWords; wordIdx++) {
		maxProb = max(maxProb, adjProb[beforeWord][wordIdx]+recogProb[wordIdx][recognizedWord]+findMaxProb(pos+1, wordIdx));
	}
	ret = maxProb;
	return ret;
}
