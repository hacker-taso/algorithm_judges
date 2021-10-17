#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> above(n);
	vector<int> total(n);
	total[0] = 1;
	for (int i=0; i<n; i++) {
		cin >> above[i];
	}
	vector<int> maxVal(n);
	vector<int> maxIdx(n);
	maxVal[0] = above[0];
	maxIdx[0] = 0;
	for (int i=1; i<n; i++) {
		if (maxVal[i-1]<above[i]) {
			maxVal[i] = above[i];
			maxIdx[i] = i;
		} else {
			maxVal[i] = maxVal[i-1];
			maxIdx[i] = maxIdx[i-1];
		}
	}
	int i=n-1;
	while (true) {
		int nextIdx = maxIdx[i];
		int nextMax = maxVal[i];
		for (int j=nextIdx+1; j<=i; j++) {
			
		}
	}
	cout << below <<endl;
}
