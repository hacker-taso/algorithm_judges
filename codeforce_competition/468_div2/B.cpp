// Start at 00:38AM March 5, 2018
// End at 00:51AM March 5, 2018
// Retrospection: vector<int> newTeams(n/2);
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	if (b<a)
		swap(a, b);
	vector<int> teams(n);
	for (int i=0; i<n; i++)
		teams[i] = i+1;
	for (int round = 1; true; round++) {
		for (int i=1; i<teams.size(); i++) {
			if (teams[i-1] == a && teams[i] == b) {
				if (teams.size() == 2) {
					cout << "Final!" << endl;
					return 0;
				} else {
					cout << round <<endl;
					return 0;
				}
			}
		}
		vector<int> newTeams(teams.size()/2);
		for (int i=0; i<newTeams.size(); i++) {
			if (teams[i*2] == a || teams[i*2+1] == a) {
				newTeams[i] = a;
			} else if (teams[i*2] == b || teams[i*2+1] == b) {
				newTeams[i] = b;
			} else {
				newTeams[i] = teams[i*2];
			}
		}
		teams = newTeams;
	}
}
