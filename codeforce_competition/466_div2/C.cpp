// Start from 07:18PM Feb, 2018
// End at 07:35PM Feb, 2018
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	set<char> charSet;
	for (int i=0; i<s.size(); i++) {
		charSet.insert(s[i]);
	}
	vector<char> charList(charSet.begin(), charSet.end());
	sort(charList.begin(), charList.end());
	vector<int> charToIdx(128);
	for (int i=0; i<charList.size(); i++)
		charToIdx[charList[i]] = i;
	string sol = s.substr(0, k);
	if (s.size()<k) {
		sol += string(k-s.size(), charList[0]);
	} else {
		int i = sol.size()-1;
		int carry;
		do {
			if (charList.size()-1<charToIdx[sol[i]]+1) {
				carry = 1;
				sol[i] = charList[0];
			} else {
				carry = 0;
				sol[i] = charList[charToIdx[sol[i]]+1];
			}
			i--;
		} while (carry);
	}
	cout << sol << endl;
}
