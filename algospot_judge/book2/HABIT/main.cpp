#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// assume group is grouped using prefix str[:t]
struct Comparator {
	int t;
	vector<int>& group; // & is very important.
	Comparator(vector<int>& group_, int t_): group(group_),t(t_){
		t=t_; group=group_;
	}
	bool operator () (int idx1, int idx2){
		if (group[idx1] != group[idx2]) return group[idx1] < group[idx2];
		return group[idx1+t] < group[idx2+t];
	}
};

vector<int> getSuffixArray(const string& str) {
	int l = str.size();

	int t=1;
	// grouped prefix until t
	vector<int> group(l+1, 0);
	for (int i=0; i<l; i++)
		group[i] = str[i];
	group[l] = -1;
	// suffArr[i]: index of i'th suffix string.
	vector<int> suffArr(l, 0);
	for (int i=0; i<l; i++)
		suffArr[i] = i;

	while (t<l) {
		Comparator compareUsing2T(group, t);
		// sort using prefix until 2t
		sort(suffArr.begin(), suffArr.end(), compareUsing2T);
		t *= 2;
		// already sort until prefix str[:l]
		if (l<=t)
			break;

		vector<int> newGroup(l+1, 0);
		newGroup[suffArr[0]] = 0;
		for (int i=1; i<l; i++) {
			if (compareUsing2T(suffArr[i-1], suffArr[i]))
				newGroup[suffArr[i]] = newGroup[suffArr[i-1]] + 1;
			else
				newGroup[suffArr[i]] = newGroup[suffArr[i-1]];
		}
		newGroup[l] = -1;
		group = newGroup;
	}
	return suffArr;
}

int getCommonPrefixLen(const string& str, const int idx1, const int idx2) {
	int len=0;
	while (idx1+len<str.size() && idx2+len<str.size()) {
		if (str[idx1+len] == str[idx2+len])
			len++;
		else
			break;
	}
	return len;
}

int solve(const int K, const string& script) {
	vector<int> suffArr = getSuffixArray(script);
	int maxHabitLen = 0;
	int strLen=script.size();
	for (int i=0; i+K-1<strLen; i++) {
		maxHabitLen = max(maxHabitLen, getCommonPrefixLen(script, suffArr[i], suffArr[i+K-1]));
	}
	return maxHabitLen;
}

int main() {
	ios_base::sync_with_stdio(false);
	int C, sols[50], K;
	string script;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> K;
		cin >> script;
		sols[i] = solve(K, script);
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
