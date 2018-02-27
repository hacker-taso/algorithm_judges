// Retrospection: Habitually I wrote down like this: for (int i=begin; begin+matched<len; "begin++")
// Be careful that prefix table is zero base indexed.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void makePrefixTable(string& S, vector<int>& pt) {
	int len = S.size();
	int matched = 0;
	pt[0] = 0;
	for (int begin=1; begin+matched<len;) {
		if (S[matched] == S[begin+matched]) {
			matched++;
			pt[begin+matched-1] = max(pt[begin+matched-1], matched);
		} else {
			if (matched == 0) {
				begin++;
			} else {
				begin = begin + (matched-pt[matched-1]);
				matched = pt[matched-1];
			}
		}
	}
}

void solve(string& S) {
	vector<int> pt(S.size(), 0);
	makePrefixTable(S, pt);
	vector<int> output;
	int maxPrefixLen = pt[S.size()-1];
	while (maxPrefixLen != 0) {
		output.push_back(maxPrefixLen);
		maxPrefixLen = pt[maxPrefixLen-1];
	}
	output.push_back(S.size());
	sort(output.begin(), output.end());
	for (int i=0; i<output.size(); i++) {
		cout << output[i];
		if (i+1 != output.size())
			cout << " ";
	}
	cout <<endl;
}

int main() {
	string baba, mama;
	ios_base::sync_with_stdio(false);
	cin >> baba >> mama;
	string S = baba+mama;
	solve(S);
}
