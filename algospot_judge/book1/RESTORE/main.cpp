#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF 0x76543210
int pieceCnt;
// descending order in string length
string pieces[15];
// before str, curUsedMap
int cache[15][1<<15];
int twoStrCache[15][15];

int getIncreasedLen(int originStrIdx, int addedStrIdx) {
	int& ret = twoStrCache[originStrIdx][addedStrIdx];
	if (ret != -1) return ret;

	const string& originStr = pieces[originStrIdx];
	const string& addedStr = pieces[addedStrIdx];

	int candidate;
	int overlapCnt = 0;
	// we don't need to care about cases where addedStr includes originStr and vice versa.
	for (candidate=0; candidate<addedStr.size(); candidate++) {
		int i=0;
		for (; i<candidate+1; i++) {
			if (originStr[originStr.size() - candidate - 1 + i] != addedStr[i])
				break;
		}
		if (i==candidate+1)
			overlapCnt = candidate+1;
	}
	ret = addedStr.size() - overlapCnt;
	return addedStr.size() - overlapCnt;
}

int getMinLen(int beforePieceIdx, int usedMap) {
	int &ret = cache[beforePieceIdx][usedMap];
	if (ret != -1) return ret;

	int increasedLen;
	int candidate = INF;
	for (int i=0; i<pieceCnt; i++) {
		if ((usedMap & (1<<i)) == 0) {
			increasedLen = getIncreasedLen(beforePieceIdx, i);
			candidate = min(candidate, getMinLen(i, usedMap | (1<<i)) + increasedLen);
		}
	}
	if (candidate == INF)
		candidate = 0;
	ret = candidate;
	return ret;
}

string makeMinStrPart(int beforePieceIdx, int usedMap) {
	int nextIdx = 0;
	int minLenCandidate;
	int minLen = INF;
	for (int i=0; i<pieceCnt; i++) {
		if ((usedMap & (1<<i)) == 0) {
			minLenCandidate = (int)getIncreasedLen(beforePieceIdx, i)+ getMinLen(i, usedMap | (1<<i));
			if (minLenCandidate < minLen) {
				minLen = minLenCandidate;
				nextIdx = i;
			}
		}
	}
	if (minLen == INF)
		return "";
	int increasedLen = getIncreasedLen(beforePieceIdx, nextIdx);
	return pieces[nextIdx].substr(pieces[nextIdx].size()-increasedLen, increasedLen) + makeMinStrPart(nextIdx, usedMap | (1<<nextIdx));
}

string getMinStr() {
	// remove included pieces
	for (int i=0; i<pieceCnt; i++) {
		for (int j=i+1; j<pieceCnt; j++) {
			if (pieces[i].find(pieces[j]) != string::npos) {
				for (int k = j; k<pieceCnt-1; k++) {
					pieces[k] = pieces[k+1];
				}
				pieceCnt--;
				j--;
			}
		}
	}
	int minLen = INF;
	int minStrIdx = 0;
	for (int i=0; i<pieceCnt; i++) {
		if ((int)pieces[i].size()+getMinLen(i, 1<<i) < minLen) {
			minLen = (int)pieces[i].size()+getMinLen(i, 1<<i);
			minStrIdx = i;
		}
	}
	return pieces[minStrIdx] + makeMinStrPart(minStrIdx, 1<<minStrIdx);
}

void init() {
	memset(cache, -1, sizeof(cache));
	memset(twoStrCache, -1, sizeof(twoStrCache));
}

bool compareLen(const std::string& a, const std::string& b)
{
    return (a.size() > b.size()); 
}

int main() {
	int C;
	string sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		init();
		cin >> pieceCnt;
		for (int j=0; j<pieceCnt; j++) {
			cin >> pieces[j];
		}
		sort(pieces, pieces+pieceCnt, compareLen);
		sols[i] = getMinStr();
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
