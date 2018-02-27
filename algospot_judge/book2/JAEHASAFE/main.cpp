#include<iostream>
#include<vector>
#include<algorithm>
#define INF 0x76543210
using namespace std;

int numRot;
string str[51];

vector<int> getPartialMatchTable(const string& str) {
	int begin = 1, matched = 0;
	vector<int> pmt(str.size(), 0);
	while (begin+matched < str.size()) {
		if (str[begin+matched] == str[matched]) {
			pmt[begin+matched] = matched+1;
			matched++;
		} else {
			if (matched == 0)
				begin++;
			else {
				begin = begin + matched - pmt[matched-1];
				matched = pmt[matched-1];
			}
		}
	}
	return pmt;
}

vector<int> findAll(const string& haystack, const string& needle) {
	vector<int> pmt = getPartialMatchTable(needle);
	int hSize = haystack.size(), nSize = needle.size();
	vector<int> founds;
	int matched = 0;
	for (int i=0; i<hSize; i++) {
		while (0 < matched && haystack[i]!=needle[matched]) {
			matched = pmt[matched-1];
		}
		if (haystack[i] == needle[matched]) {
			matched++;
			if (matched == nSize) {
				founds.push_back(i-matched+1);
				matched = pmt[matched-1];
			}
		}
	}
	return founds;
}

// los, his must be sorted in ascending order before call.
int findMinDist(const vector<int> los, const vector<int> his) {
	int minDist = INF;
	int l = 0, h = 0;
	while (l<los.size() && h<his.size()) {
		if (his[h]<los[l]) {
			h++;
			continue;
		}
		minDist = min(minDist, his[h] - los[l]);
		l++;
	}
	return minDist;
}

void solve() {
	int totalTick = 0;
	string haystack = str[0]+str[0]+str[0];
	vector<int> founds1 = findAll(haystack, str[0]);
	for (int i=1; i<=numRot; i++) {
		vector<int> founds2 = findAll(haystack, str[i]);
		if (i%2 == 1) { // cw (left to right)
			totalTick+=findMinDist(founds2, founds1);
		} else { // ccw (right to left)
			totalTick+=findMinDist(founds1, founds2);
		}
		founds1.swap(founds2);
	}
	cout << totalTick << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numRot;
		for (int j=0; j<=numRot; j++) {
			cin >> str[j];
		}
		solve();
	}
}