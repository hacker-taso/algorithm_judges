// Start at 00:35AM March 11, 2018
// End at 00:47AM March 11, 2018
// Retrospection: R y
#include<iostream>
#include<vector>
using namespace std;
vector<string> pasture;
int C, R;

bool check(int y, int x) {
	if (0<y && pasture[y-1][x] == 'W') {
		return false;
	}
	if (y<R-1 && pasture[y+1][x] == 'W') {
		return false;
	}
	if (0<x && pasture[y][x-1] == 'W') {
		return false;
	}
	if (x<C-1 && pasture[y][x+1] == 'W') {
		return false;
	}
	return true;
}

int main() {
	cin >> R >> C;
	pasture = vector<string>(R);
	for (int y=0; y<R; y++) {
		cin >> pasture[y];
	}
	for (int y=0; y<R; y++) {
		for (int x=0; x<C; x++) {
			if (pasture[y][x]=='.') {
				pasture[y][x] = 'D';
			}
			if (pasture[y][x]=='S' && !check(y, x)) {
				cout <<  "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" <<endl;
	for (int y=0; y<R; y++) {
		for (int x=0; x<C; x++) {
			cout << pasture[y][x];
		}
		cout <<endl;
	}
}
