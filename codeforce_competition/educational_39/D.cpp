// Start at 00:32AM March 07, 2018
// End at 01:54AM March 07, 2018
// Retrospection: 
// 1. 0 input.
// 2. hours[0][~] (should be hours[i][~])
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define INF 0x76543210
using namespace std;

int n, m, k;
vector<vector<int> > hours;
vector<string> s;
int cache[501][501];
int numOne[500];

int getMin(int from, int remainK) {
	if (from == n) return 0;
	int &ret = cache[from][remainK];
	if (ret != -1) return ret;
	int minVal = INF;
	for (int i=0; i<=numOne[from]; i++) {
		if (remainK < i) break;
		minVal = min(minVal, hours[from][i] + getMin(from+1, remainK-i));
	}
	ret = minVal;
	return ret;
}

void init() {
	memset(cache, -1, sizeof(cache));
	hours = vector<vector<int> >(n);
	for (int i=0; i<n; i++) {
		numOne[i] = count(s[i].begin(), s[i].end(), '1');
		hours[i] = vector<int>(numOne[i]+1);
		if (numOne[i] == 0) {
			hours[i][0] = 0;
			continue;
		}
		vector<int> leftPos(numOne[i]);
		int idx = 0;
		for (int j=0; j<m; j++) {
			if (s[i][j] == '1') {
				leftPos[idx++] = j;
			}
		}
		vector<int> rightPos(numOne[i]);
		idx = 0;
		for (int j=m-1; 0<=j; j--) {
			if (s[i][j] == '1') {
				rightPos[idx++] = j;
			}
		}
		// left remove, right remove.
		vector<vector<int> > dp(numOne[i], vector<int>(numOne[i], 0));
		dp[0][0] = rightPos[0]-leftPos[0]+1;
		hours[i][0] = dp[0][0];
		for (int j=1; j<numOne[i]; j++) {
			for (int left = 0; left<=j; left++) {
				if (left == 0) {
					dp[left][j-left] = dp[left][j-left-1] - (rightPos[j-left-1] - rightPos[j-left]);
				} else if (left == j) {
					dp[left][j-left] = dp[left-1][j-left] - (leftPos[left] - leftPos[left-1]);
				} else {
					dp[left][j-left] = min(dp[left][j-left-1] - (rightPos[j-left-1] - rightPos[j-left]),
						dp[left-1][j-left] - (leftPos[left] - leftPos[left-1]));
				}
			}
			hours[i][j] = INF;
			for (int left=0; left<=j; left++) {
				hours[i][j] = min(hours[i][j], dp[left][j-left]);
			}
		}
		hours[i][numOne[i]] = 0;
	}
}

int main() {
	cin >> n >> m >> k;
	s = vector<string>(n);
	for (int i=0; i<n; i++) {
		cin >> s[i];
	}
	init();
	cout << getMin(0, k) << endl;
}
