// Start from 06:35PM Feb, 2018
// End at 06:54PM Feb, 2018
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, d;
	cin >> n >> d;
	vector<int> nums(n);
	for (int i=0; i<n; i++)
		cin >> nums[i];
	int minRemove = 100;
	for (int loIdx = 0; loIdx<n; loIdx++) {
		int numRemove = 0;
		for (int j=0; j<n; j++) {
			if (nums[j]<nums[loIdx] || d<(nums[j]-nums[loIdx])) {
				numRemove++;
			}
		}
		minRemove = min(minRemove, numRemove);
	}
	cout << minRemove << endl;
}
