// Retrospection long after writing this code: 
// 1. The only difference between lower_bound function and upper_bound function is when same value is found.
// 2. When erasing value using iterator, I can use tmp iterator.
// 3. I should be careful about execute --operation on s.begin().
#include<iostream>
#include<set>
using namespace std;

int numPerson;
int fst[50000], snd[50000];

int solve() {
	set<pair<int, int> >::iterator it, tIt;
	set<pair<int,int> > s;
	int cnt;
	s.insert(pair<int, int>(fst[0], snd[0]));
	int accum = 1;
	for (int i=1; i<numPerson; i++) {
		it = s.lower_bound(pair<int, int>(fst[i], snd[i]));
		if (it!=s.end() && snd[i] < it->second) { // cannot be added
			accum+=s.size();
			continue;
		}
		if (it==s.begin()) { // no smaller value
			s.insert(pair<int, int>(fst[i], snd[i]));
			accum+=s.size();
			continue;
		}
		it--;
		cnt = 0;
		while (it->second < snd[i]) {
			if (s.begin()==it) {
				s.erase(it);
				break;
			}
			tIt = it;
			tIt--;
			s.erase(it);
			it = tIt;
		}
		s.insert(pair<int, int>(fst[i], snd[i]));
		accum+=s.size();
	}
	return accum;
}

int main() {
	ios_base::sync_with_stdio(false);
	int C, sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numPerson;
		for (int j=0; j<numPerson; j++) {
			cin >> fst[j] >> snd[j];
		}
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
