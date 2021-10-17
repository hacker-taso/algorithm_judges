// Start at 07:18PM Feb 17, 2018
// End at 09:01PM Feb 17, 2018
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n, sTime, eTime;
	cin >> n;
	vector<int> numPeople(n);
	for (int i=0; i<n; i++)
		cin >> numPeople[i];
	cin >> sTime >> eTime;
	vector<int> partialSum(n+1, 0);
	partialSum[0] = 0;
	for (int i=0; i<n; i++)
		partialSum[i+1] = partialSum[i]+numPeople[i];
	int maxPeople = 0;
	int maxT;
	for (int t=1; t<=n; t++) {
		int eIdx = (n+eTime-t-1)%n+1;
		int sIdx = (n+sTime-t)%n+1;
		if (sIdx<=eIdx) {
			int curPeople = partialSum[eIdx]-partialSum[sIdx-1];
			if (maxPeople < curPeople) {
				maxT=t;
				maxPeople = curPeople;
			}
		} else {
			int curPeople = partialSum[n]-partialSum[sIdx-1] + partialSum[eIdx];
			if (maxPeople < curPeople) {
				maxT=t;
				maxPeople = curPeople;
			}
		}
	}
	cout << maxT << endl;
}
