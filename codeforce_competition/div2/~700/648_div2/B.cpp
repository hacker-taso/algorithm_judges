#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> a;
vector<int> b;
const string yes="Yes";
const string no="No";
string solve() {
	bool alreadySorted = true;
	for (int i=0; i<n-1; i++) {
		if (a[i] > a[i+1]){
			alreadySorted = false;
			break;
		}
	}
	if (alreadySorted)
		return yes;
	bool allOne = true;
	bool allZero = true;
	for (int i=0; i<n; i++) {
		if (b[i] == 1) {
			allZero = false;
		}
		if (b[i] == 0) {
			allOne = false;
		}
	}
	if (allZero || allOne)
		return no;
	return yes;
}

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n;
		a = vector<int>(n);
		b = vector<int>(n);
		for (int j=0; j<n; j++) {
			cin >> a[j];
		}
		for (int j=0; j<n; j++) {
			cin >> b[j];
		}
		cout << solve() << endl;
	}
}
