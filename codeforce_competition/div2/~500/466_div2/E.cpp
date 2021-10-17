// Start from 08:12PM Feb, 2018
// End at 08:12PM Feb, 2018
#include<iostream>
#include<vector>
using namespace std;

long long dp1[100001];
vector<int> arr;

long long leftMin(int i) {
	if (i==0) return ~;
	

}

int main() {
	ios_base::sync_with_stdio(false);
	int n, c;
	cin >> n >> c;
	arr = vector<int>(n);
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
	cout << leftMin(n) << endl;
}
