#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> russian;
multiset<int> korean;
int numPlayers;

int solve() {
	int numWin = 0;
	for (int i=0; i<numPlayers; i++) {
		multiset<int>::iterator it = korean.lower_bound(russian[i]);
		if (it == korean.end()) { // cannot win
			korean.erase(korean.begin());
		} else {
			numWin++;
			korean.erase(it);
		}
	}
	return numWin;
}

int main() {
	int C, tmp;
	vector<int> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numPlayers;
		russian.clear();
		russian.resize(numPlayers, 0);
		for (int j=0; j<numPlayers; j++) {
			cin >> russian[j];
		}
		korean.clear();
		for (int j=0; j<numPlayers; j++) {
			cin >> tmp;
			korean.insert(tmp);
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] <<endl;
	}
}
