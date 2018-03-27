#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int L, N, A, B, C, D;
vector<string> dict;
int dictCnts[20000][26];
int cnts[1000000][26];
char S1, S2;
string S;

bool checked[20000];

void check(int curIdx) {
	for (int i=0; i<L; i++) {
		if (dict[i][dict[i].size()-1] != S[curIdx]) continue;
		if (curIdx-(int)dict[i].size()+1 < 0) continue;
		if (dict[i][0] != S[curIdx-(int)dict[i].size()+1]) continue;
		int j=0;
		for (; j<26; j++) {
			int cnt = 0;
			if (curIdx-(int)dict[i].size() == -1)
				cnt = cnts[curIdx][j];
			else
				cnt = cnts[curIdx][j]-cnts[curIdx-(int)dict[i].size()][j];
			if (dictCnts[i][j] != cnt) {
				break;
			}
		}
		if (j==26) checked[i] = true;
	}
}

int solve() {
	for (int i=0; i<N; i++) {
		if (i!=0)
			for (int j=0; j<26; j++)
				cnts[i][j] = cnts[i-1][j];
		cnts[i][S[i]-'a']++;
		check(i);
	}
	int cnt = 0;
	for (int i=0; i<L; i++) {
		cnt += checked[i];
	}
	return cnt;
}

void constructS() {
	S = "";
	S += string(1, S1) + string(1, S2);
	int x1 = S1, x2 = S2;
	int tmp;
	for (int i=2; i<N; i++) {
		tmp = ((long long)A*x1 + (long long)B*x2 + C)%D;
		x1 = x2;
		x2 = tmp;
		S += string(1, 97 + x2%26);
	}
}
void constructDictCnts() {
	memset(dictCnts, 0, sizeof(dictCnts));
	for (int i=0; i<L; i++) {
		for (int j=0; j<dict[i].size(); j++) {
			dictCnts[i][dict[i][j]-'a']++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		memset(checked, 0, sizeof(checked));
		memset(cnts, 0, sizeof(cnts));
		cin >> L;
		dict = vector<string>(L);
		for (int j=0; j<L; j++)
			cin >> dict[j];
		cin >> S1 >> S2 >> N >> A >> B >> C >> D;
		constructS();
		constructDictCnts();
		cout << "Case #" << i+1 << ": " << solve() << endl;
	}
}
