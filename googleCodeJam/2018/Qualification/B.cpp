#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int seq[100000];

void solve() {
	vector<int> odds;
	vector<int> evens;
	for (int i=0; i<N; i++) {
		if (i%2 == 1)
			odds.push_back(seq[i]);
		else
			evens.push_back(seq[i]);
	}
	sort(odds.begin(), odds.end());
	sort(evens.begin(), evens.end());
	for (int i=0; i<N; i++) {
		if (i%2 == 1)
			seq[i] = odds[i/2];
		else
			seq[i] = evens[i/2];
	}
	for (int i=0; i<N-1; i++) {
		if (seq[i+1]<seq[i]) {
			cout << i << endl;
			return;
		}
	}
	cout << "OK" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> N;
		for (int j=0; j<N; j++)
			cin >> seq[j];
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
