#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int C, sols[300];
	int numParticipant;
	int Micro[10000];
	int Eat[10000];
	int microEndTime;
	int maxLen;
	pair<int, int> pairs[10000];
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numParticipant;
		microEndTime = 0;
		maxLen = 0;
		for (int j=0; j<numParticipant; j++) {
			cin >> Micro[j];
		}
		for (int j=0; j<numParticipant; j++) {
			cin >> Eat[j];
		}
		for (int j=0; j<numParticipant; j++) {
			pairs[j] = pair<int, int>(-Eat[j], j);
		}
		sort(pairs, pairs+numParticipant);
		for (int j=0; j<numParticipant; j++) {
			microEndTime = microEndTime + Micro[pairs[j].second];
			maxLen = max(maxLen, microEndTime + Eat[pairs[j].second]);
		}
		sols[i] = maxLen;
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
