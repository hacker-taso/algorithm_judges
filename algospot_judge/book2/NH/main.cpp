// Retrospection:
// 1. I have a tiny mistake and it made me to waste 3 hours.
// I wrote code like this: while (t!=root && t->nexts[c] != NULL) { t = t->fail; }
// But it should be like this: while (t!=root && t->nexts[c] == NULL) { t = t->fail; }
// I think I need to be careful in the case where "while loop" is used to make variable in some condition.
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MOD 10007
using namespace std;

int ctoi(char c) {
	return c-'a';
}

int curStateNum;
struct Trie {
	Trie*nexts[26];
	Trie*fail;
	// we don't need integer terminal in this problem.
	//int terminal;
	bool terminal;
	int stateNum;
	// we don't need output in this problem.
	//vector<int> output;
	Trie(): fail(NULL), terminal(false), stateNum(curStateNum++){
		memset(nexts, 0, sizeof(nexts));
	}

	// fill terminal and next
	void insert(const char* key) {
		if (*key == 0) {
			//terminal = strNum;
			terminal = true;
			return;
		}
		int next = ctoi(*key);
		if (nexts[next] == NULL)
			nexts[next] = new Trie();
		nexts[next]->insert(key+1);
	}
};

// don't need to fill "output" xxxxxxxxxxxxx
// we need to check output time.
void fillFailTransition(Trie* root) {
	root->fail = root;
	queue<Trie*> q;
	q.push(root);
	while (!q.empty()) {
		Trie* here = q.front();
		q.pop();
		for (int c=0; c<26; c++) {
			Trie* next = here->nexts[c];
			if (next == NULL) continue;
			q.push(next);
			if (here == root) {
				next->fail = root;
			} else {
				Trie*t = here->fail;
				while (t!=root && t->nexts[c] == NULL) { t = t->fail; }
				if (t->nexts[c]) next->fail = t->nexts[c];
				else next->fail = root;
			}
			next->terminal = next->fail->terminal | next->terminal;
		}
	}
}

int strLen, numPattern;
vector<string> patterns;
// int len, stateNum
int cache[101][1001];

int countPattern(int length, Trie* n) {
	int stateNum = n->stateNum;
	int &ret = cache[length][stateNum];
	if (ret != -1) return ret;
	if (n->terminal) {
		ret = 0; return ret;
	}
	if (length == 0) {
		ret = 1; return ret;
	}
	int retTmp = 0;
	for (int i=0; i<26; i++) {
		Trie * x = n;
		while (x->fail!=x && x->nexts[i] == NULL) x= x->fail;
		if (x->nexts[i] != NULL) x = x->nexts[i];
		retTmp = (retTmp+countPattern(length-1, x))%MOD;
	}
	ret = retTmp;
	return ret;
}

void init() {
	curStateNum = 0;
	memset(cache, -1, sizeof(cache));
}

int solve() {
	init();
	Trie*root = new Trie();
	for (int i=0; i<patterns.size(); i++)
		root->insert(patterns[i].c_str());
	fillFailTransition(root);
	return countPattern(strLen, root);
}

int main() {
	int C;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> strLen >> numPattern;
		patterns.resize(numPattern);
		for (int j=0; j<numPattern; j++) {
			cin >> patterns[j];
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
