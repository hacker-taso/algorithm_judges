// I've read the editorial.
// Start at 01:28AM March 11, 2018
// End at 00:35AM March 11, 2018
// Retrospection:
// I couldn't find a way to the time complexity when I'm on the contest.
// The important idea was removing values from multiset in increasing order and aggregating not removed values in O(1).
// Because removing and inserting is performed just once on each day, removing and inserting just take O(n) in overall.
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int numDay;
	int tmp;
	cin >> numDay;
	vector<int> snows(numDay);
	for (int i=0; i<numDay; i++) {
		cin >> snows[i];
	}
	vector<long long> sol;
	long long accum = 0;
	multiset<long long> snowSet;
	for (int i=0; i<numDay; i++) {
		long long curVal = 0;
		cin >> tmp;
		snowSet.insert(accum+snows[i]);
		for (multiset<long long>::iterator it = snowSet.begin(); it != snowSet.end(); ) {
			if (*it-accum<=tmp) {
				curVal += *it-accum;
				auto beforeIt = it;
				it++;
				snowSet.erase(beforeIt);
				continue;
			}
			break;
		}
		curVal += tmp*snowSet.size();
		accum+=tmp;
		sol.push_back(curVal);
	}
	for (int i=0; i<numDay; i++)
		cout << sol[i] << " ";
	cout <<endl;
}
