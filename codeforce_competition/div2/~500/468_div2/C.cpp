// Start at 00:51AM March 5, 2018
// End at 01:27AM March 5, 2018
// Retrospection: output format
#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
	int n;
	cin >> n;
	int tmp;
	map<int, int> elemCnt;
	for (int i=0; i<n; i++) {
		cin >> tmp;
		elemCnt[tmp] += 1;
	}
	if (elemCnt.size()<3) {
		cout << n <<endl;
		for (map<int,int>::iterator it=elemCnt.begin(); it!=elemCnt.end(); ++it) {
			int num = it->first;
			for (int i=0; i<it->second; i++) {
				cout << num << " ";
			}
		}
		cout <<endl;
		return 0;
	} else {
		int cnts[3] = {0};
		int nums[3] = {0};
		int i = 0;
		for (map<int,int>::iterator it=elemCnt.begin(); it!=elemCnt.end(); ++it) {
			nums[i] = it->first;
			cnts[i] = it->second;
			i++;
		}
		int equalNum = 0;
		int minAC = min(cnts[0], cnts[2]); // a: 0, c: 2
		if (minAC*2 < (cnts[1]/2)*2) { // remove mid.
			equalNum += cnts[0] + cnts[2];
			cnts[0] += cnts[1]/2;
			cnts[2] += cnts[1]/2;
			cnts[1] -= (cnts[1]/2)*2;
			equalNum += cnts[1];
		} else { // remove a and c
			equalNum = cnts[1];
			cnts[0] -= minAC;
			cnts[2] -= minAC;
			cnts[1] += 2*minAC;
			equalNum += cnts[0]+ cnts[2];
		}
		cout << equalNum <<endl;
		for (int i=0; i<3; i++) {
			for (int j=0; j<cnts[i]; j++) {
				cout << nums[i] << " ";
			}
		}
		cout << endl;
	}
}
