// Retrospection(mistake):
// 1. mistake in exception handling code (I wrote like this: if (nexts[nextIdx] == 0) return keyLen;)
// 2. wrongly understanding problem. I thought I can make "THERE" with "THE" + "RE".
#include<iostream>
#include<vector>
#include<cstring>
#include<cassert>
#include<algorithm>
using namespace std;

int ctoi(char c) {return c-'A';}

vector<string> dictStrs;
struct TRI_NODE {
	TRI_NODE* nexts[26];
	int maxFreq;
	int minStrIdx;
	bool terminal;
	TRI_NODE(): maxFreq(0), minStrIdx(-1), terminal(false) {
		memset(nexts, 0, sizeof(nexts));
	}
	void insert(const char*key, const int freq, const int strIdx, int curLen) {
		/*if (minStrIdx==-1)
			minStrIdx = strIdx;*/
		if (maxFreq < freq || (maxFreq == freq && 0<strcmp(dictStrs[minStrIdx].c_str()+curLen, key))) {
			maxFreq = freq;
			minStrIdx = strIdx;
		}
		if (*key == 0) {
			terminal = true;
			return;
		}
		int nextIdx = ctoi(*key);
		if (nexts[nextIdx] == 0)
			nexts[nextIdx] = new TRI_NODE();
		nexts[nextIdx]->insert(key+1, freq, strIdx, curLen+1);
	}
	int countNumInput(const char*key, int curCount, int keyLen) {
		if (*key == 0) return curCount;
		int nextIdx = ctoi(*key);
		// NOT FOUND
		if (nexts[nextIdx] == 0) return curCount + keyLen;
		string& autoStr = dictStrs[minStrIdx];
		if (0<curCount && strcmp(autoStr.c_str()+curCount, key) == 0)
			return curCount+1;
		return nexts[nextIdx]->countNumInput(key+1, curCount+1, keyLen-1);
	}
};

int dictSize, inputCnt;
vector<int> freqs;
vector<string> queryStr;

bool compare(int i, int j) {
	return freqs[i]==freqs[j] ? dictStrs[i]<dictStrs[j] : freqs[j]<freqs[i];
}

int solve() {
	TRI_NODE* root = new TRI_NODE();
	root->maxFreq = 0x1234567;
	vector<int> idxs(dictStrs.size());
	for (int i=0; i<idxs.size(); i++)
		idxs[i] = i;
	//sort(idxs.begin(), idxs.end(), compare);
	for (int i=0; i<dictStrs.size(); i++) {
		root->insert(dictStrs[i].c_str(), freqs[i], i, 0);
		//root->insert(dictStrs[idxs[i]].c_str(), freqs[idxs[i]], idxs[i], 0);
	}
	int numIn = 0;
	for (int i=0; i<queryStr.size(); i++) {
		numIn += root->countNumInput(queryStr[i].c_str(), 0, queryStr[i].size());
		numIn+=1;// space
	}
	numIn -= 1; // last space
	return numIn;
}

int main() {
	ios_base::sync_with_stdio(false);
	int C;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> dictSize >> inputCnt;
		dictStrs.resize(dictSize);
		freqs.resize(dictSize);
		queryStr.resize(inputCnt);
		for (int j=0; j<dictSize; j++) {
			cin >> dictStrs[j] >> freqs[j];
		}
		for (int j=0; j<inputCnt; j++) {
			cin >> queryStr[j];
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
