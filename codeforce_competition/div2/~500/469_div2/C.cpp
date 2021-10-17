#include<iostream>
#include<vector>
#include<set>
using namespace std;
// 0 ~ 0 (with alter 1) zebra (including 0)
// print -1 if there's no sol
// one idx
// cnt -> seq
int main() {
	set<int> posSet[2];
	string s;
	ios_base::sync_with_stdio(false);
	cin >> s;
	for (int i=0; i<s.size(); i++) {
		if (s[i] == '0')
			posSet[0].insert(i+1);
		else
			posSet[1].insert(i+1);
	}
	vector<vector<int> > zebras;
	while (true) {
		vector<int> zebra;
		if (posSet[0].empty()) break;
		int curPos = *posSet[0].begin();
		zebra.push_back(curPos);
		posSet[0].erase(posSet[0].begin());
		int mood = 1;
		while (true) {
			set<int>::iterator onePosIt = posSet[1].lower_bound(curPos);
			if (onePosIt == posSet[1].end())
				break;
			int onePos = *onePosIt;
			set<int>::iterator zeroPosIt = posSet[0].lower_bound(onePos);
			if (zeroPosIt == posSet[0].end())
				break;
			int zeroPos = *zeroPosIt;
			zebra.push_back(onePos);
			zebra.push_back(zeroPos);
			posSet[1].erase(onePosIt);
			posSet[0].erase(zeroPosIt);
			curPos = zeroPos;
		}
		zebras.push_back(zebra);
	}
	if (!posSet[1].empty()) {
		cout << -1 << endl;
		return 0;
	}
	cout << zebras.size() <<endl;
	for (int i=0; i<zebras.size(); i++) {
		cout << zebras[i].size() << " ";
		for (int j=0; j<zebras[i].size(); j++)
			cout << zebras[i][j] << " ";
		cout << endl;
	}
}
