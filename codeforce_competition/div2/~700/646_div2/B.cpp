#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int t;
string s;

int solve() {
	// 4 cases accepted
	// 1 ~~~~~~ 0 ~~~~~~~
	// 0 ~~~~~~ 1 ~~~~~~~
	// 0 ~~~~~~~~~~
	// 1 ~~~~~~~~~~
	vector<int> nzl(s.size()); // n zero left
	vector<int> nzr(s.size());
	int len = s.size();
	nzl[0] = 0;
	for (int i=1; i<s.size(); i++)
		nzl[i] = nzl[i-1] + (s[i-1] == '0');
	nzr[len-1] = 0;
	for (int i=len-2; 0<=i; i--) {
		nzr[i] = nzr[i+1] + (s[i+1] == '0');
	}
	int m = 1000;
	for (int i=0; i<s.size(); i++) {
		// make 0~i-1 all zero and i+1 ~ len-1 all one (n_one(0, i-1) + n_zero(i+1, len-1))
		m = min(m, (i-nzl[i]) + nzr[i]);
		// make 0~i-1 all one and i+1 ~ len all zero (n_zero(0, i-1) + n_one(i+1, len-1))
		m = min(m, nzl[i] + (len-i-1-nzr[i]));
	}
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> s;
		cout << solve() << endl;
	}
}
