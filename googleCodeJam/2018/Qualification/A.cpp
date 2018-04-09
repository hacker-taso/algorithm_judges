#include<iostream>
#include<algorithm>
using namespace std;
int D;
string P;

int calcDamage() {
	int curPosVal = 1;
	int damage = 0;
	for (int i=0; i<P.size(); i++) {
		if (P[i] == 'S')
			damage += curPosVal;
		else
			curPosVal*=2;
	}
	return damage;
}

void solve() {
	if (calcDamage() <= D) {
		cout << 0 << endl;
		return;
	}
	int numLoop = 0;
	while (true) {
		numLoop++;
		int i = P.size()-2;
		for (; 0<=i; i--) {
			if (P[i] == 'C' && P[i+1]=='S') {
				swap(P[i], P[i+1]);
				if (calcDamage() <= D) {
					cout << numLoop << endl;
					return;
				}
				break;
			}
		}
		if (i==-1) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int i=0; i<T; i++) {
		cin >> D;
		cin >> P;
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
