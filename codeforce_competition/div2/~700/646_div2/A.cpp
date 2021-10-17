#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr;
int t, x, n;

void solve() {
	// whether I can make "even sum with n-1 numbers" and 1 odd left.
	int n_even = 0;
	int n_odd = 0;
	for (int i=0; i<n; i++) {
		if (arr[i]%2 == 0)
			n_even++;
		else
			n_odd++;
	}
	int even_used = min(x-1, n_even);
	if ((x-even_used)%2 == 0 && 0<even_used)
		even_used = even_used-1;
	int n_odd_req = x - even_used;
	if (n_odd_req%2 == 1 && n_odd_req <= n_odd)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (int i=0; i<t; i++) {
		cin >> n >> x;
		arr = vector<int>(n);
		for (int j=0; j<n; j++) {
			cin >> arr[j];
		}
		solve();
	}
}
