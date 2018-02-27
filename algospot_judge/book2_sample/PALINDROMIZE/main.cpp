// Retrospection: When I find "reversed" from S, I initialized begin like this "begin=1" but it should have "begin=0".
// It's because I was too accustomed to write function to make prefix table.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void makePrefixTable(string& S, vector<int>& pt) {
	int matched = 0;
	int len = S.size();
	for (int begin=1; begin+matched<len;) {
		if (S[begin+matched] == S[matched]) {
			matched++;
			pt[begin+matched-1] = max(pt[begin+matched-1], matched);
		} else {
			if (matched == 0)
				begin++;
			else {
				begin = begin + (matched - pt[matched-1]);
				matched = pt[matched-1];
			}
		}
	}
}

int solve(string& S) {
	string reveresed = S;
	reverse(reveresed.begin(), reveresed.end());
	vector<int> pt(S.size(), 0);
	makePrefixTable(reveresed, pt);
	int matched=0;
	int len = S.size();
	for (int begin=0; begin+matched<len;) {
		if (S[begin+matched] == reveresed[matched]) {
			matched++;
		} else {
			if (matched == 0)
				begin++;
			else {
				begin = begin + (matched-pt[matched-1]);
				matched = pt[matched-1];
			}
		}
	}
	return len+len-matched;
}

int main() {
	int C;
	string S;
	vector<int> sols;
	ios_base::sync_with_stdio(false);
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> S;
		sols.push_back(solve(S));
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
