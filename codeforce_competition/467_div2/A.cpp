// Start at 01:05AM Feb 26, 2018
// End at 01:12AM Feb 26, 2018
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> scores(n);
	for (int i=0; i<n; i++)
		cin >> scores[i];
	int cnt = 0;
	sort(scores.begin(), scores.end());
	for (int i=0; i<n; i++) {
		if (scores[i] == 0 || (i+1!=n) && scores[i] == scores[i+1]) continue;
		cnt++;
	}
	cout << cnt << endl;
}
