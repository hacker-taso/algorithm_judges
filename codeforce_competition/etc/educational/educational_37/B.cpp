// 11:55 ~ 12:22
#include<iostream>
#include<vector>
using namespace std;

vector<int> l, r;
int n;

void solve() {
	vector<int> drinkAt(n, -1);
	drinkAt[0] = l[0];
	int beforeDrinkTime = l[0];
	for (int i=1; i<n; i++) {
		if (beforeDrinkTime+1<=r[i]) {
			beforeDrinkTime = max(l[i], beforeDrinkTime+1);
			drinkAt[i] = beforeDrinkTime;
		} else {
			drinkAt[i] = 0;
		}
	}
	for (int i=0; i<n; i++) {
		cout << drinkAt[i] << " ";
	}
	cout << endl;
}

int main() {
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> n;
		l = vector<int>(n, 0);
		r = vector<int>(n, 0);
		for (int j=0; j<n; j++) {
			cin >> l[j] >> r[j];
		}
		solve();
	}
}
