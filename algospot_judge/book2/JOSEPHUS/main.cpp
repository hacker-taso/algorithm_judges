// Comment long after writing this code:
// Time complexity of this code is O(N^2).
// If I used linked list, then it would be O(NK).
// I think both are okay.
#include<iostream>
#include<vector>
using namespace std;

int sols[50][2];
int numPerson, K;

void solve(int tCaseIdx) {
	vector<int> people(numPerson);
	for (int i=0; i<numPerson; i++)
		people[i] = i+1;
	int erasedIdx = 0;
	people.erase(people.begin()+erasedIdx);
	while (2<people.size()) {
		erasedIdx = (erasedIdx+K-1)%people.size();
		people.erase(people.begin()+erasedIdx);
	}
	sols[tCaseIdx][0] = people[0];
	sols[tCaseIdx][1] = people[1];
}

int main() {
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numPerson >> K;
		solve(i);
	}
	for (int i=0; i<C; i++) {
		cout << sols[i][0] << " " <<sols[i][1] <<endl;
	}
}
